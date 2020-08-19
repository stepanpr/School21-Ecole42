CREATE DATABASE emabel_database;										--создаем базу данных
CREATE USER 'emabel_user'@'localhost' IDENTIFIED BY 'emabel';			--создадим пользователя и пароль
GRANT ALL PRIVILEGES ON emabel_database.* TO 'emabel_user'@'localhost'; --даем полные права на новую базу новому пользователю
FLUSH PRIVILEGES;														--применяем изменения на сервере MySQL
use mysql;
update user set plugin='' where User='emabel_user';
flush privileges;
exit
