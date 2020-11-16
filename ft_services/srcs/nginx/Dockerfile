# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 03:02:05 by emabel            #+#    #+#              #
#    Updated: 2020/11/16 08:07:56 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

RUN apk update

# установка пакетов
RUN apk add --no-cache telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ \
        openrc nginx openssh openssl

# создание пользователя и группы 'www' для nginx
RUN adduser -D -g 'www' www

# создание директорий для nginx
RUN mkdir /www && chown -R www:www /var/lib/nginx && chown -R www:www /www && mkdir -p /run/nginx

# генерация keygen и создание ssh пользователя
RUN adduser -D admin && echo "admin:admin" | chpasswd 
RUN ssh-keygen -A

# создаем ssl сертификат
RUN openssl req -newkey rsa:2048 -x509 -sha256 -days 365 -nodes -subj \
    "/C=RU/ST=Moscow/L=Moscow/O=21school/OU=emabel/CN=localhost" -keyout \
	/etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt

# копируем конфигурацию, скприпт и index.html
COPY localhost.conf /etc/nginx/conf.d/default.conf
COPY index.html /www/
ADD start.sh ./

# назначаем порты
EXPOSE 80 443 22

# старт
ENTRYPOINT ["sh", "start.sh"]
