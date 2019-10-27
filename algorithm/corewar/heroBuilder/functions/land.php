<?php

namespace Functions;

/**
 * logical and
 */
class land extends CommonCorewar
{
    const OPCODE = '06';
    const NAME = 'and ';

	/**
	 * params comport 3 parts
	 * 2 for and
	 * 1 to store the result (registre)
	 */	
	protected function checkValidity(array $params)
	{
		$this->count($params, 3);
		$this->isRegister($params[2], 2);
	}
}
