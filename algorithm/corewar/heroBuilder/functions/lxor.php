<?php

namespace Functions;

/**
 * logical or
 */
class lxor extends CommonCorewar
{
    const OPCODE = '08';
    const NAME = 'xor ';
	
	/**
	 * params comport 3 parts
	 * 2 for or
	 * 1 to store the result
	 */

	protected function checkValidity(array $params)
	{
		$this->count($params, 3);
		$this->isRegister($params[2], 2);
	}
}
