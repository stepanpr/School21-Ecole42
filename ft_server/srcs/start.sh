# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 12:41:20 by emabel            #+#    #+#              #
#    Updated: 2020/08/19 04:48:18 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

echo -en "\t\033[37;1;41m ft_server/21(42)school/emabel\033[0m\n"
echo -en "\t\033[32;5;1mSTART\033[0m" && sleep 1.3
echo -en "\033[32;1m.\033[0m" && sleep 1.2
echo -en "\033[32;1m.\033[0m" && sleep 0.9
echo -en "\033[32;1m.\033[0m" && sleep 0.6
echo -en "\033[32;1m.\033[0m" && sleep 0.5
echo -en "\033[32;1m.\033[0m" && sleep 0.4
echo -en "\033[32;1m.\033[0m" && sleep 0.3
echo -en "\033[32;1m.\033[0m" && sleep 0.3
echo -en "\033[32;1m.\033[0m" && sleep 0.2
echo -en "\033[32;1m.\033[0m" && sleep 0.1
echo -en "\033[32;1m.\033[0m" && sleep 0.05
echo -en "\033[32;1m>\033[0m\n" && sleep 0.05

service mysql start
mysql < init_database.sql
service restart mysql.service

service php7.3-fpm start

service nginx start

bash
