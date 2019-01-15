<?php
return [
    // Slim Settings
    'determineRouteBeforeAppMiddleware' => false,
    'displayErrorDetails' => false,

    // View settings
    'view' => [
        'template_path' => __DIR__ . '/templates',
        'twig' => [
            'cache' => false, //__DIR__ . '/../cache/twig',
            'debug' => true,
            'auto_reload' => true,
        ],
    ],

    // monolog settings
    'logger' => [
        'name' => 'app',
        'path' => __DIR__ . '/../log/app.log',
    ],

    // database settings
    'db' => [
    ]
];
