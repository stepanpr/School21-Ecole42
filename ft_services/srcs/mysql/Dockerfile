# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 03:34:12 by emabel            #+#    #+#              #
#    Updated: 2020/11/16 07:10:58 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

RUN apk update

# установка пакетов
RUN apk add --no-cache telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ \
        mariadb mariadb-client mysql-client

# копируем БД и скрипты
ADD start.sh ./
ADD wp-dump.sql ./
ADD db_init.sh ./

# назначаем порт
EXPOSE 3306

# старт
RUN chmod +x db_init.sh
ENTRYPOINT ["sh", "start.sh"]