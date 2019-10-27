<?php

namespace Hero;

use Functions\Block;

class Zork extends Hero
{
	public function build(): Hero
	{
		$initValue = new Block($this->setName('initvalue'));
		$sayLive = new Block($this->setName('saylive'));

		$this->initValue($initValue, $sayLive);
		$this->sayLive($sayLive);

		return $this;
	}

	private function initValue(Block $block, Block $sayLive)
	{
		//hard write for live
		$block->sti(['r1', '%:' . $sayLive->name, '%1']);

		//reset r1
		$block->resetRegister('r1');
	}

	private function sayLive(Block $block)
	{
		//say live
		$block->live(['%0']);
		$block->live(['%:' . $block->name]);
		//jump back to beginning of this function
		$block->zjmp(['%:' . $block->name]);
	}
}
