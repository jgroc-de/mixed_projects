<?php

namespace Hero;

use Functions\Block;

abstract class Hero
{
	const REGISTRE_NB = 16;
	const FFFF = 65535;
	const FF = 256;
    public $rand = 0;

    public $data;
	private $registre = [];
	private $functionNames = [];
	/** @var Block[] */
	protected $blocks = [];

	public function __construct(string $name, string $comment)
	{
		$this->writeName($name);
		$this->writeComment($comment);
		$this->initRegistre();
	}

	abstract public function build(): Hero;

    public function initBlock(string $name): Block
    {
        $name = $this->setName($name);
        $block = new Block($name);
        $this->blocks[] = $block;

        return $block;
    }

	private function initRegistre()
	{
		$i = self::REGISTRE_NB;
		while ($i--) {
			$this->registre[] = 0;
		}
		//numero du joueur est stocké dans r1
		$this->registre[0] = rand(-2, -1);
	}

	public function getData(): string
    {
        foreach ($this->blocks as $block) {
            $this->data .= $block->data;
        }

        return $this->data;
    }

	private function writeName(string $name)
	{
		$this->data = '.name "'. $name . '"' . PHP_EOL;
	}

	private function writeComment(string $comment)
	{
		$this->data .= '.comment "'. $comment . '"' . PHP_EOL . PHP_EOL;
	}

	protected function setName(string $name): string
	{
		if (!isset($this->functionNames[$name])) {
			$this->functionNames[$name] = 0;
		} else {
			++$this->functionNames[$name];
		}

		return $name . $this->functionNames[$name];
	}

	protected function rand2048()
    {
        if (!$this->rand) {
            $this->rand = rand(9, 16) * 4096;
        }

        return $this->rand;
    }
}
