#!/bin/bash
php ./vendor/friendsofphp/php-cs-fixer/php-cs-fixer -vvv --allow-risky fix src/
./vendor/bin/phpstan analyse src --level max
