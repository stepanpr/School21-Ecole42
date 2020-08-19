# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/08 17:32:26 by emabel            #+#    #+#              #
#    Updated: 2020/08/19 05:45:10 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

LABEL meta='ft_server/21(42)school/emabel'
MAINTAINER emabel

#рабочая директория (для комманд COPY, ADD, RUN, ENTRYPOINT)
WORKDIR /start

#обновление системных файлов
RUN apt-get update -y && apt-get upgrade -y

#установка пакетов
RUN apt-get install -y vim
RUN apt-get install -y nginx
RUN apt-get install -y openssl
RUN apt-get install -y default-mysql-server
RUN apt-get install -y php7.3 php-mysql php7.3-fpm php-cli php-mbstring php-json php-common \
php-soap php-gd php-xml php-xmlrpc php-curl php-zip php-ldap php-intl
RUN apt-get install -y wordpress
ADD https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz phpmyadmin.tar.gz

# NGINX
#копируем файл с настройками хоста
#создаем символьную ссылку в каталоге содержащем подключенные хосты "sites-enabled"
#открываем 80 и 443 порты
COPY    ./srcs/emabel_host /etc/nginx/sites-available/emabel_host
RUN     ln -s /etc/nginx/sites-available/emabel_host /etc/nginx/sites-enabled/emabel_host
EXPOSE  80 443 

# SSL
#создаем самоподписанный спетификат на основе OpenSSL
#копируем "ssl-patch.conf" (путь) "ssl-params.conf" в директорию содаржащую сниппеты
#копируем усиленный DH ключ 
RUN     openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /etc/ssl/private/emabel-ssl.key \
        -out /etc/ssl/certs/emabel-ssl.crt \
        -subj '/C=RU/ST=Moscow/L=Moscow/O=42/OU=21/CN=emabel'
COPY 	./srcs/ssl-patch.conf ./srcs/ssl-params.conf /etc/nginx/snippets/
COPY 	./srcs/dhparam.pem /etc/ssl/certs/

# phpMyAdmin
#распаковка архива
#удаление архива
#перемещение phpMyAdmin на сервер
#копируем конфиг 
RUN     tar -xvzf phpmyadmin.tar.gz
RUN		rm phpmyadmin.tar.gz
RUN     mv phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin
COPY    ./srcs/config.inc.php /var/www/html/phpmyadmin/

# MySQL
#копируем файл инициализирующий БД в WORKDIR "init"
COPY	./srcs/init_database.sql ./

# WordPress
#копируем скачанный wordpress на сервер
#удаление оригинального файла конфигурации
#копируем настроенный файл конфигурации
#для каталога с контентом даём права на запись
RUN     cp -r /usr/share/wordpress /var/www/html/
RUN     rm /var/www/html/wordpress/wp-config.php 
COPY    ./srcs/wp-config.php /var/www/html/wordpress/
# RUN     chown -R www-data /var/www/html/wordpress
RUN 	chmod g+w /var/www/html/wordpress/wp-content

#копируем скрипты в WORKDIR "init"
#устанавливаем права для скриптов
#разрешаем доступ к каталогу веб-сервера группе www-data (дефолтное имя nginx)
#копируем index.html на сервер
COPY	./srcs/start.sh ./srcs/autoindex.sh ./
RUN		chmod +x *.sh
RUN		chown -R www-data /var/www/html
COPY	./srcs/index.html /var/www/html/

#обозначаем точку входа в контейнер
ENTRYPOINT bash start.sh
