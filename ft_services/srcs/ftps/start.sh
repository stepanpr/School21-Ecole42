mkdir /etc/telegraf
cp /etc/telegraf.conf /etc/telegraf/telegraf.conf
sed -i "s~# database = \"telegraf\"~database = \"ftps\"~g" /etc/telegraf/telegraf.conf
sed -i "s~# urls = \[\"unix:///var/run/influxdb.sock\"\]~urls = \[\"http://influxdb:8086\"\]~g" /etc/telegraf/telegraf.conf
telegraf &

echo "emabel@student.21-school.ru" > /home/admin/ftps.txt
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf