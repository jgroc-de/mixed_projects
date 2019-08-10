<?php
namespace App\Model;

use Psr\Log\LoggerInterface;

class LinkModel
{
	private $container;

	public function __construct($container)
	{
		$this->container = $container;
	}

	public function login($user, $pass) 
	{
		$req = $this->container['db']->prepare('SELECT id FROM admins WHERE login = ? AND pass = ?');
		$req->execute(array($user, $pass));
		return count($req->fetchAll()) >= 1;
	}

	public function admins()
	{
		$req = $this->container['db']->query('SELECT id,login,date FROM admins');
		return $req->fetchAll();
	}

	public function addAdmin($user, $pass) 
	{
		$req = $this->container['db']->prepare('INSERT INTO admins (login, pass)
		VALUES (?, ?)');
		return $req->execute(array($user, $pass));
	}

	public function delAdmin($id) 
	{
		$req = $this->container['db']->prepare('DELETE FROM admins WHERE id = ?');
		return $req->execute(array($id));
	}

	public function updateAdmin(array $data)
    {
		$req = $this->container['db']->prepare('
			UPDATE admins
			SET login = ?, pass = ?
			WHERE id = ?');
		return $req->execute(array($data['login'], $data['pass'], $data['id']));
    }

    public function setLink(array $post)
	{
		$req = $this->container['db']->prepare('
			INSERT INTO links (title, author, language, count, expire, private, text, date)
			VALUES (?, ?, ?, ?, ?, ?, ?, NOW())
		');
		$req->execute(array($post['title'], $post['author'], $post['language'], intval($post['count']), $post['date'], $post['private'], $post['text']));
		return $this->container['db']->lastInsertId();
    }
	
	public function getData($id)
    {
		$req = $this->container['db']->prepare('SELECT * FROM links WHERE id = ?');
		$req->execute(array($id));
		return $req->fetch();
    }
	
	public function getAllData()
    {
		$req = $this->container['db']->query('SELECT * FROM links');
		return $req->fetchAll();
    }
	
	public function getAllDataPublic($id)
	{
		$req = $this->container['db']->prepare('SELECT * FROM links WHERE private = 0 ORDER BY date DESC LIMIT 10 OFFSET :id');
		$req->bindValue('id', ((int) $id) * 10, \PDO::PARAM_INT); 
		$req->execute();
		return $req->fetchAll();
    }
	
	public function update(array $data)
    {
		$req = $this->container['db']->prepare('
			UPDATE links
			SET title = ?, author = ?, language = ?, count = ?, expire = ?, private = ?, text = ?, date = ?
			WHERE id = ?');
		//execute dans l'ordre des clefs du tableau
		return $req->execute(array($data['title'], $data['author'], $data['language'], intval($data['count']), $data['expire'], $data['private'], $data['text'], $data['date'], $data['id']));
    }

	public function decreaseCount($id)
    {
		$req = $this->container['db']->prepare('
			UPDATE links
			SET count = count - 1
			WHERE id = ?');
		return $req->execute(array($id));
    }

	public function delete($id)
    {
		$req = $this->container['db']->prepare('DELETE FROM links WHERE id = ?');
		return $req->execute(array($id));
    }
}
