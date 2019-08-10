<?php
namespace App\Controller;

use Psr\Log\LoggerInterface;
use Slim\Http\Request;
use Slim\Http\Response;

Abstract class Route
{
	protected $container;

	public function	__construct($container)
	{
		$this->container = $container;
	}
}
