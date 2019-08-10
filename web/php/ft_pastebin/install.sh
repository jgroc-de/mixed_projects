# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    install.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llelievr <llelievr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/05 16:42:02 by llelievr          #+#    #+#              #
#    Updated: 2019/01/06 21:46:32 by llelievr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

apt-get update
apt-get install -y apache2
apt-get install -y php7.0 php7.0-mysql php7.0-zip php7.0-mbstring php7.0-json
apt-get install -y mysql-server
mysql < /vagrant/sql/default-user.sql
mysql < /vagrant/sql/pastebin.sql
apt-get install -y curl vim htop unzip
cd ~ && curl -sS https://getcomposer.org/installer -o composer-setup.php
php composer-setup.php --install-dir=/usr/local/bin --filename=composer
if ! [ -L /var/www ]; then
	rm -rf /var/www
	ln -fs /vagrant/server /var/www
fi
chmod -R 777 /var/www/backend/log
chmod -R 777 /var/www/admin-back/log
rm -r /etc/apache2/sites-available
mkdir /etc/apache2/sites-available
cp /vagrant/apache-config/apache-config-back.conf /vagrant/apache-config/apache-config-back-admin.conf /vagrant/apache-config/apache-config-admin.conf /vagrant/apache-config/apache-config-front.conf /etc/apache2/sites-available/
a2enmod rewrite
a2ensite apache-config-back.conf
a2ensite apache-config-back-admin.conf
a2ensite apache-config-front.conf
a2ensite apache-config-admin.conf
a2dissite 000-default.conf
service apache2 restart
chown -R vagrant:vagrant /var/www/backend
cd /var/www/backend && sudo -u vagrant composer update
chown -R root:root /var/www/backend
chown -R vagrant:vagrant /var/www/admin-back
cd /var/www/admin-back && sudo -u vagrant composer update
chown -R root:root /var/www/admin-back
echo "* * * * 0 sudo mysql < /vagrant/sql/update_db.sql" | crontab -
