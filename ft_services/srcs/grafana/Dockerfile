# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 02:49:43 by emabel            #+#    #+#              #
#    Updated: 2020/11/16 07:07:07 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

RUN apk update

# установка пакетов
RUN apk add --no-cache telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ \
        --repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat
ADD https://dl.grafana.com/oss/release/grafana-7.2.2.linux-amd64.tar.gz ./
RUN tar -xvf grafana*tar* --strip-components 1
RUN rm -rf ./grafana*tar*

# копируем БД графаны и скрипт
ADD grafana.db ./data/
ADD start.sh ./

# назначаем порт
EXPOSE 3000

# старт
ENTRYPOINT ["sh", "start.sh"]