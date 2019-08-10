<?php
namespace App\Controller;

use Psr\Log\LoggerInterface;
use Slim\Http\Request;
use Slim\Http\Response;

class Admin extends Route
{
    public function logIn(Request $request, Response $response, $args)
    {
		$post = $request->getParsedBody();
		if (isset($post['user'])
			&& isset($post['password'])
			&& $this->container['links']->login($post['user'], $post['password']))
		{
			$_SESSION['user'] = $post['user'];
			return $response->withStatus(200);
		}
		else
		{
			return $response->withStatus(402);
		}
	}

	public function admins(Request $request, Response $response, $args)
	{
		return $response->write(json_encode($this->container['links']->admins()));
	}

	public function addAdmin(Request $request, Response $response, $args)
	{
		$post = $request->getParsedBody();
		if (isset($post['login']) && isset($post['pass']) && $this->container['links']->addAdmin($post['login'], $post['pass']))
			return $response->withStatus(200);
		else return $response->withStatus(424);
	}

	public function delAdmin(Request $request, Response $response, $args)
	{
		if (isset($args['id']) && $this->container['links']->delAdmin($args['id']))
			return $response->withStatus(200);
		else return $response->withStatus(424);
	}

	public function updateAdmin(Request $request, Response $response, $args)
	{
		$post = $request->getParsedBody();
		$post = json_decode($post['data'], true);
		if ($this->container['links']->updateAdmin($post))
			return $response->withStatus(200);
		else return $response->withStatus(424);
	}

	public function isLogged(Request $request, Response $response, $args)
	{
		return $response->write(json_encode(array('logged' => isset($_SESSION['user']), 'login' => $_SESSION['user'])));
	}

	public function getDB(Request $request, Response $response, $args)
	{
		return $response->write(json_encode($this->container['links']->getAllData()));
	}

	public function delete(Request $request, Response $response, $args)
	{
		if ($this->container['links']->delete($args['id']))
			return $response->withStatus(200);
		else
			return $response->withStatus(424);
	}

	public function logOut(Request $request, Response $response, array $args)
	{
		session_reset();
		session_destroy();
		return $response->withStatus(200);
	}

	public function update(Request $request, Response $response, array $args)
	{
		//envoyer les données dans l'order de la base sql, y compris id!
		//normalement, c'est exactement le même format que celui recu depuis la route getDB
		$post = $request->getParsedBody();
		$post = json_decode($post['data'], true);
		if ($this->container['links']->update($post))
			return $response->withStatus(200);
		else
			return $response->withStatus(424);
	}
}
//route setup pour setup la db
	/*public function setup(Request $request, Response $response, array $args)
	{
		$db = $this->container['settings']['db'];
		$pdo = new \PDO("mysql:host=127.0.0.1;port:3306;", $db['user'], $db['pass']);
		$pdo->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
		$pdo->setAttribute(\PDO::ATTR_DEFAULT_FETCH_MODE, \PDO::FETCH_ASSOC);
		$pdo->exec('DROP DATABASE IF EXISTS ' . $db['dbname']);
		$pdo->exec('CREATE DATABASE ' . $db['dbname']);
		$pdo->exec('USE ' . $db['dbname']);
		$file = file_get_contents(__DIR__ . '/../../database/pastebin.sql');
		$pdo->exec($file);
	}*/
