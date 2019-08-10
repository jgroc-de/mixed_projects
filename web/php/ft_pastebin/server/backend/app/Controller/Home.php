<?php
namespace App\Controller;

use Psr\Log\LoggerInterface;
use Slim\Http\Request;
use Slim\Http\Response;

class Home extends Route
{
	public function checkParam(array $post)
	{
		if (!isset($post['title']))
			return ("title not set");
		if (!isset($post['author']))
			return ("author not set");
		if (!isset($post['language']))
			return ("language not set");
		if (!isset($post['count']))
			return ("count not set");
		if (!isset($post['date']))
			return ("date not set");
		if (!isset($post['private']))
			return ("private not set");
		if (!isset($post['text']))
			return ("text not set");
		if ($post['title'] == '')
			return ("title empty");
		if ($post['author'] == '')
			return ("author empty");
		if ($post['language'] == '')	
			return ("language empty");
		if (!is_int($post['count']))
			return ("count not int");
		$date = explode('-', $post['date']);
		if (count($date) != 3 || !checkdate(intval($date[1]), intval($date[2]), intval($date[0])))
			return ("date not correct");
		$n = intval($post['private']);
		if (!is_int($post['private']) ||
			($post['private'] != '0' && $post['private'] != '1'))
			return ("private not correct");
		if ($post['text'] == '')
			return ("text not correct");
		return ("");
	}

	public function genLink(Request $request, Response $response, $args)
	{
		$post = $request->getParsedBody();
		$post = json_decode($post['data'], true);
		$error = $this->checkParam($post);
		if ($error == "")
		{
			$post['date'] = implode(' ', array($post['date'], "23:59:59"));
			$date = explode('-', $post['date']);
			$str = $this->container['links']->setLink($post);
			if ($str != '')
				return $response->write(json_encode(array('link' => $str)));
			else
				return $response->withStatus(401);
		}
		else
			return $response->write(json_encode(array('error' => $error)));
    }
	
	public function getPaste(Request $request, Response $response, $args)
	{
		$tab = $this->container['links']->getData($args['id']);
		if (isset($tab['id']))
		{
			if ($tab['count'] <= 1)
				$this->container['links']->delete($args['id']);
			else
				$this->container['links']->decreaseCount($args['id']);
			return $response->write(json_encode($tab));
		}
		else
			return $response->withStatus(404);
	}
	
	public function getPublicData(Request $request, Response $response, $args)
	{
		$tab = $this->container['links']->getAllDataPublic($args['id']);
		if (!$tab)
			return $response->write(json_encode(array("key" => "stop")));
		else
			return $response->write(json_encode($tab));
	}
}
