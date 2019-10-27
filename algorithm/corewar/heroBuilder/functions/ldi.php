<?php

namespace Functions;

/**
 * store indirect
 *
 * Additionne les deux derniers, utilise cette somme comme une adresse ou sera copiéela valeur du premier paramètre
 */
class ldi extends CommonCorewar
{
    const OPCODE = '0A';
    const NAME = 'ldi ';

    /**
     * ca prend 2 index
    et 1 registre, additionne les 2 premiers, traite ca comme une adresse, y lit une
    valeur de la taille d’un registre et la met dans le 3eme
     */
	protected function checkValidity(array $params)
	{
		$this->count($params, 3);
		$this->isRegister($params[2], 2);
		$this->isNotIndirect($params[1], 1);
		$this->isNotIndirect($params[0], 0);
	}
}
