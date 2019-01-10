<?php

class CamagruManager extends SqlManager
{
    public function getFilters()
    {
        $tab = array();

        $request = $this->container->db->query('SELECT * FROM filter');
        while ($elemt = $request->fetch())
			$tab[] = $elemt;
		return $tab;
	}
}
