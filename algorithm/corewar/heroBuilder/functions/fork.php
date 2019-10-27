<?php

namespace Functions;

/**
 * add
 */
class fork extends CommonCorewar
{
    const OPCODE = '0C';
    const NAME = 'fork ';

	/**
	 * params comport 3 parts
	 * 2 for and
	 * 1 to store the result (registre)
	 */	
	protected function checkValidity(array $params)
	{
	    try {
            $this->count($params, 1);
        } catch (\Exception $exception) {
	        var_dump($exception);
        }
	}
}
