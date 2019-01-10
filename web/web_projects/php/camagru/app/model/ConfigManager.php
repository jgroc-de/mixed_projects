<?php

class ConfigManager extends SqlManager
{
	protected function dbcreate()
	{
		global $DB_DSN, $DB;

		$DSN = explode(';', $DB_DSN, 2)[0];

		return new PDO($DSN, $DB['user'], $DB['password'], array(
			PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION
		));
	}
	
	public function	createDB($dbName)
	{
		global $DB;

		$db = $this->dbcreate();
		$db->exec('DROP DATABASE IF EXISTS ' . $DB['name']);
		$db->exec('CREATE DATABASE ' . $DB['name']);
	}
	
	public function	request($tab)
	{
		$db = $this->dbconnect();

		$db->exec($tab);
	}
}
