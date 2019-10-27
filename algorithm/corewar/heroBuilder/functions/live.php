<?php

namespace Functions;

/**
 * equivalent of echo number
 */
class live extends CommonCorewar
{
    const OPCODE = '01';
    const NAME = 'live ';

	protected function checkValidity(array $params)
	{
		$this->count($params, 1);
		$this->isNotRegister($params[0], 0);
	}
}
