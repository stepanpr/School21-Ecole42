# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 18:05:53 by emabel            #+#    #+#              #
#    Updated: 2020/11/16 08:57:28 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

minikube stop && minikube delete

minikube start --vm-driver=virtualbox --cpus=2 --memory='3000' --disk-size 5000MB

# подключаем аддоны, устанавливаем melallb в кластере
minikube addons enable metallb
minikube addons enable dashboard
minikube addons enable metrics-server
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.4/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.4/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

eval $(minikube docker-env)
minikube dashboard &

# создаем поды из yaml-файлов базирующиеся на docker-образах 
kubectl apply -f srcs/metallb_configmap.yaml
kubectl apply -f srcs/influxdb.yaml
kubectl apply -f srcs/grafana.yaml
kubectl apply -f srcs/nginx.yaml
kubectl apply -f srcs/ftps.yaml
kubectl apply -f srcs/mysql.yaml
kubectl apply -f srcs/wordpress.yaml
kubectl apply -f srcs/phpmyadmin.yaml

# собираем docker-образы 
docker build -t inf_i srcs/influxdb
docker build -t grafana_i srcs/grafana
docker build -t nginx_i srcs/nginx
docker build -t ftp_i srcs/ftps
docker build -t mysql_i srcs/mysql
docker build -t wp_i srcs/wordpress
docker build -t pma_i srcs/phpmyadmin

printf "\e[93mnginx>\e[39m\e[0m \e[92m192.168.99.100:80\e[39m\e[0m\n"
printf "\e[93mphpmyadmin>\e[39m\e[0m \e[92m192.168.99.100:5000\e[39m\e[0m\n"
printf "\e[93mwordpress>\e[39m\e[0m \e[92m192.168.99.100:5050\e[39m\e[0m\n"
printf "\e[93mgrafana>\e[39m\e[0m \e[92m192.168.99.100:3000\e[39m\e[0m\n"
printf "\e[93mftps>\e[39m\e[0m \e[92m192.168.99.100:21\e[39m\e[0m\n"
printf "\e[93mmysql>\e[39m\e[0m \e[92mmysql:3306\e[39m\e[0m\n"
printf "\e[93minfluxdb>\e[39m\e[0m \e[92minfluxdb:8086\e[39m\e[0m\n"

## перезапуск сервисов
#kubectl exec deploy/mysql -- pkill mysql
#kubectl exec deploy/nginx -- pkill nginx

## HTTP-запрос по IP
#curl -I http://192.168.99.100

## подключение по SSH к виртуальному серверу
#ssh admin@192.168.99.100 -p 22