<?php

namespace Functions;

/**
 * store
 *
 * Prend un registre et un registre ou un indirect, et stocke la valeur du registrevers le second paramètre
 *
 * utile pour coller du code dans la mémoire
 */
class st extends CommonCorewar
{
    const OPCODE = '03';
    const NAME = 'st ';

    /** Prend un registre et un registre ou un indirect, et stocke la valeur du registre
    vers le second paramètre */
	protected function checkValidity(array $params)
	{
		$this->count($params, 2);
		$this->isRegister($params[0], 0);
		$this->isNotDirect($params[1], 1);
	}
}
