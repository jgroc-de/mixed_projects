<?php

namespace Functions;

/**
 * add
 */
class add extends CommonCorewar
{
    const OPCODE = '04';
    const NAME = 'add ';

	/**
	 * params comport 3 parts
	 * 2 for and
	 * 1 to store the result (registre)
	 */	
	protected function checkValidity(array $params)
	{
		$this->count($params, 3);
		$i = 0;
		foreach ($params as $param) {
			$this->isRegister($param, $i++);
		}
	}
}
