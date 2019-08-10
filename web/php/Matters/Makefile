start:
	sudo docker-compose up --build -d
	sleep 3

stop:
	sudo docker-compose down -v
	sudo docker-compose rm -v

install: uninstall start composer.install db.install

uninstall: stop
	@sudo rm -rf postgres-data

reinstall: install

#Connects to the databatase
db.connect:
	sudo docker-compose exec postgres /bin/bash -c 'psql -U $$POSTGRES_USER'

db.install:
	sudo docker-compose exec php /bin/bash -c 'bin/console doctrine:migrations:migrate'

php.connect:
	sudo docker-compose exec php /bin/bash

phpunit.run:
	sudo docker-compose exec php vendor/bin/phpunit --config=phpunit.xml

composer.install:
	sudo docker-compose exec php composer install || exit 0
