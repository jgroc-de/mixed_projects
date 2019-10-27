<?php

namespace Functions;

/**
 * store
 *
 * store in a variable or a memory address
 */
class ld extends CommonCorewar
{
    const OPCODE = '02';
    const NAME = 'ld ';
    const CARRY = true;

    /**
Prend un paramètre quelconque et un registre. Charge la valeur du premier
paramètre dans le registre
     */
	protected function checkValidity(array $params)
	{
	    try {
            $this->count($params, 2);
            $this->isRegister($params[1], 1);
        } catch (\Exception $e) {
	        echo $e->getMessage();
        }
	}
}
