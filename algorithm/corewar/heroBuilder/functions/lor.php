<?php

namespace Functions;

/**
 * logical or
 */
class lor extends CommonCorewar
{
    const OPCODE = '07';
    const NAME = 'or ';
	
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
