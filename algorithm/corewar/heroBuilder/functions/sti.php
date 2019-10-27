<?php

namespace Functions;

/**
 * store indirect
 *
 * Additionne les deux derniers, utilise cette somme comme une adresse ou sera copiéela valeur du premier paramètre
 */
class sti extends CommonCorewar
{
    const OPCODE = '0B';
    const NAME = 'sti ';

    /**
     * un registre, et deux index (potentiellement des registres).
     * Additionne les deux derniers, utilise cette somme comme une adresse ou sera copiée
     * la valeur du premier paramètre.
     */
	protected function checkValidity(array $params)
    {
        $this->count($params, 3);
        $this->isRegister($params[0], 0);
        $this->isNotIndirect($params[1], 1);
        $this->isNotIndirect($params[2], 2);
	}
}