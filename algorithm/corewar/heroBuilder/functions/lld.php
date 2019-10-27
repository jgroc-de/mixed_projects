<?php

namespace Functions;

/**
 * store
 *
 * store in a variable or a memory address
 */
class lld extends CommonCorewar
{
    const OPCODE = '0D';
    const NAME = 'lld ';
    const CARRY = true;

    /** C’est la même chose
    que ld, mais sans % IDX_MOD. Modifie le carry. */
	protected function checkValidity(array $params)
	{
		$this->count($params, 2);
		$this->isRegister($params[1], 1);
	}

}
