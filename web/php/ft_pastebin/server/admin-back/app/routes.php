<?php

$app->post('/admin', App\Controller\Admin::class . ':logIn');
$app->get('/logged', App\Controller\Admin::class . ':isLogged');
$app->group('', function ()
{
	$this->get('/admin/admins', App\Controller\Admin::class . ':admins');
	$this->post('/admin/addAdmin', App\Controller\Admin::class . ':addAdmin');
	$this->get('/admin/delAdmin/{id}', App\Controller\Admin::class . ':delAdmin');
	$this->post('/admin/updateAdmin', App\Controller\Admin::class . ':updateAdmin');
	$this->get('/admin/getDB', App\Controller\Admin::class . ':getDB');
	$this->get('/admin/delete/{id}', App\Controller\Admin::class . ':delete');
	$this->get('/admin/logout', App\Controller\Admin::class . ':logOut');
	$this->post('/admin/update', App\Controller\Admin::class . ':update');
})->add(new \App\Middlewares\authMiddleware);
