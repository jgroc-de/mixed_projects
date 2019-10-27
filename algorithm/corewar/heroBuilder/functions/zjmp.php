<?php

namespace Functions;

/**
 * z-jump
 *
 * use to goto new function
 * can reproduce while (or goto)
 * can be break - new function
 */
class zjmp extends CommonCorewar
{
    const OPCODE = '09';
	const NAME = 'zjmp ';

	/**
	 * $params[0] is the destination
	 * should be block or integer (+ or -)
	 * integer is interpreted % 512
	 */
	protected function checkValidity(array $params)
	{
        $this->count($params, 1);
        $this->isDirect($params[0], 0);
    }
}
