<?php
return [
	// Slim Settings
	'determineRouteBeforeAppMiddleware' => false,
	'addContentLengthHeader' => false,
	'displayErrorDetails' => true,

	// monolog settings
	'logger' => [
		'name' => 'app',
		'path' => __DIR__ . '/../log/app.log',
	],

	// database settings
	'db' => [
		'host' => '127.0.0.1',
		'port' => '3306',
		'user' => 'site',
		'pass' => 'root00',
		'dbname' => 'pastebin'
	]
];
