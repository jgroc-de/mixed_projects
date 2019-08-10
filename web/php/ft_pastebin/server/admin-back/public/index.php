<?php

// To help the built-in PHP dev server, check if the request was actually for
// something which should probably be served as a static file
//if (PHP_SAPI === 'cli-server' && $_SERVER['SCRIPT_FILENAME'] !== __FILE__) {
//    return false;
//}
date_default_timezone_set("Europe/Paris");

require __DIR__ . '/../vendor/autoload.php';

session_start();

$settings = require __DIR__ . '/../app/settings.php';
$app = new \Slim\App(['settings' => $settings]);

$app->options('/{routes:.+}', function ($request, $response, $args) {
	return $response;
});

$app->add(function ($req, $res, $next) {
	$response = $next($req, $res);
	return $response
		->withHeader('Access-Control-Allow-Origin', 'http://localhost:4242')
	//	->withHeader('Access-Control-Allow-Origin', 'http://localhost:8082')
		->withHeader('Access-Control-Allow-Credentials', 'true')
		->withHeader('Access-Control-Allow-Headers', 'X-Requested-With, Content-Type, Accept, Origin, Authorization')
		->withHeader('Access-Control-Allow-Methods', 'GET, POST, PUT, DELETE, PATCH, OPTIONS');
});

require __DIR__ . '/../app/container.php';

require __DIR__ . '/../app/routes.php';

$app->run();
