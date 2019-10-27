<?php

namespace Functions;

/**
 * add
 */
class lfork extends CommonCorewar
{
    const OPCODE = '0F';
    const NAME = 'lfork ';

	/**
	 * params comport 3 parts
	 * 2 for and
	 * 1 to store the result (registre)
	 */	
	protected function checkValidity(array $params)
	{
		$this->count($params, 1);
	}
}
