<?php

namespace Functions;

/**
 * equivalent of echo number
 */
class aff extends CommonCorewar
{
    const OPCODE = '10';
    const NAME = 'aff ';

    /**
     * Il y a un octet de codage des paramètres,
    même si c’est un peu bête car il n’y a qu’un paramètre, qui est un registre, dont
    le contenu est interprété comme la valeur ASCII d’un caractère à afficher sur la
    sortie standard. Ce code est modulo 256.
     */
	protected function checkValidity(array $params)
	{
		$this->count($params, 1);
		$this->isRegister($params[0], 0);
	}
}
