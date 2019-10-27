<?php

namespace Functions;

abstract class CommonCorewar
{
	public $data;

	public function __construct(array $params = [])
	{
        try {
		    $this->checkValidity($params);
		    $this->write($this::NAME, $params);
        } catch (\Exception $e) {
            var_dump('lol');
            echo "Error in " . $e->getMessage() . ' trace ' . $e->getTraceAsString() . ' in ' .$e->getLine();
            exit;
        }
	}

	protected function checkValidity(array $params)
	{
	}

	protected function write(string $line, $params = [])
	{
		$this->data .= "\t\t" . $line;
		$count = count($params);

		$i = 0;
		while ($i !== $count) {
			$this->data .= $params[$i];
			if (++$i != $count) {
				$this->data .= ', ';
			}
		}
		$this->data .= PHP_EOL;
	}

	protected function isIndirect($param, $id)
	{
		++$id;
		if ($param[0] === 'r' || $param[0] === '%') {
			throw new \exception($this::NAME . ": parameter $id should be indirect");
		}
	}

	protected function isNotIndirect($param, $id)
	{
		++$id;
		if (!($param[0] === 'r' || $param[0] === '%')) {
			throw new \exception($this::NAME . ": parameter $id should NOT be indirect");
		}
	}

	protected function isRegister($param, $id)
	{
		++$id;
		if ($param[0] !== 'r') {
			throw new \exception($this::NAME . ": parameter $id should be register");
		}
	}

	protected function isNotRegister($param, $id)
	{
		++$id;
		if ($param[0] === 'r') {
			throw new \exception($this::NAME . ": parameter $id should NOT be register");
		}
	}

	protected function isDirect($param, $id)
	{
		++$id;
		if ($param[0] !== '%') {
			throw new \exception($this::NAME . ": parameter $id should be direct");
		}
	}

	protected function isNotDirect($param, $id)
	{
		++$id;
		if ($param[0] === '%') {
			throw new \exception($this::NAME . ": parameter $id should Not be direct");
		}
	}

	protected function count($params, $count)
	{
		if (count($params) != $count) {
			throw new \exception($this::NAME . ": $count params");
		}
	}
}
