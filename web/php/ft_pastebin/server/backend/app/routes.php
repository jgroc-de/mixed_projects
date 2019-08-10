<?php

$app->post('/', App\Controller\Home::class . ':genLink')->add(new \App\Middlewares\header);
$app->get('/home/{id}', App\Controller\Home::class . ':getPublicData');
//a laisser à la fin, sinon, couvre les autres routes
$app->get('/{id}', App\Controller\Home::class . ':getPaste');
