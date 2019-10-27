<?php

$test = require __DIR__."/vendor/autoload.php";

$name = 'zork2000';
$comment = 'zork from an ancient futur';
try {
$ASMData = (new Hero\Zork2000($name, $comment))
	->build()
    ->getData()
;
} catch (\exception $e) {
	echo $e . PHP_EOL;
	exit;
}
file_put_contents($name . '.s', $ASMData);
echo file_get_contents($name . '.s');
