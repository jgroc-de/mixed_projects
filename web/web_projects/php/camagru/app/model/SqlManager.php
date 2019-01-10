<?php

class SqlManager
{
    protected $container;

    public function __construct($container)
    {
        $this->container = $container;
    }

	protected function sqlRequest($request, $array = array(), $bool = False)
	{
		$db = $this->container->db;
        
        $obj = $db->prepare($request);
		$success = $obj->execute($array);
        if ($bool)
        {
            return $success;
        }
		else
			return $obj;
    }

    protected function sqlRequestFetch($request, $array = array())
    {
        return $this->sqlRequest($request, $array)->fetch();
        //return $tmp->fetch();
    }
}
