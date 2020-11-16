mkdir /etc/telegraf
cp /etc/telegraf.conf /etc/telegraf/telegraf.conf
sed -i "s~# database = \"telegraf\"~database = \"influxdb\"~g" /etc/telegraf/telegraf.conf
sed -i "s~# urls = \[\"unix:///var/run/influxdb.sock\"\]~urls = \[\"http://localhost:8086\"\]~g" /etc/telegraf/telegraf.conf
telegraf &

influxd run -config /etc/influxdb.conf