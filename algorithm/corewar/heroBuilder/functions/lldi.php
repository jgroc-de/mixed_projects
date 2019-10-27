<?php

namespace Functions;

/**
 * store indirect
 *
 * Additionne les deux derniers, utilise cette somme comme une adresse ou sera copiéela valeur du premier paramètre
 */
class lldi extends CommonCorewar
{
    const OPCODE = '0E';
    const NAME = 'lldi ';
    const CARRY = true;

    /** Pareil que ldi, mais n’applique aucun modulo aux adresses.
    Modifiera, par contre, le carry */
	protected function checkValidity(array $params)
	{
		$this->count($params, 3);
		$this->isRegister($params[2], 2);
		$this->isNotIndirect($params[1], 1);
		$this->isNotIndirect($params[0], 0);
	}
}
