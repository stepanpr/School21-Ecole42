# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 02:23:28 by emabel            #+#    #+#              #
#    Updated: 2020/11/16 07:16:56 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

RUN apk update

# установка пакетов
RUN apk add --no-cache telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ \
        php7 php7-fpm php7-opcache php7-gd php7-mysqli \
        php7-zlib php7-curl php7-mbstring php7-json php7-session \
        openrc nginx php-fpm

# создание пользователя и директорий для nginx
RUN adduser -D -g 'www' www
RUN mkdir /www && chown -R www:www /var/lib/nginx && chown -R www:www /www && mkdir -p /run/nginx
WORKDIR /www/

# устанавливаем wordpress
ADD https://wordpress.org/latest.tar.gz  ./
RUN tar -xvf latest*tar* --strip-components 1
RUN rm -rf ./latest*tar*

# копируем конфигурации и скрипт
ADD wp-config.php ./
COPY localhost.conf /etc/nginx/conf.d/default.conf
ADD start.sh ./

# назначаем порт
EXPOSE 5050

# старт
ENTRYPOINT ["sh", "start.sh"]