<?php

namespace Hero;

use Functions\Block;

class Zork2000 extends Hero
{
    public function build(): Hero
	{
		$init = $this->initBlock('init');
        $live0 = $this->initBlock('live');
        $sword0 = $this->initBlock('sword');
		$sword1 = $this->initBlock('sword');
		$sword2 = $this->initBlock('sword');
		$shield0 = $this->initBlock('shield');
        $frontShield = $this->initBlock('shield');
        $rearShield0 = $this->initBlock('shield');
        $rearShield1 = $this->initBlock('shield');
        $setLive0 = $this->initBlock('setlive');

		$this->init($init, $live0);
		$this->setPlayerNumberInR15($live0);

		$this->initAttacker($sword0, $shield0, $sword2);
		$this->attack1($sword1);
		$this->attack2($sword2);

        $this->initProtector($shield0, $frontShield);
        $this->rearShieldFactory($rearShield0, $rearShield1);
        $this->rearShieldFire($rearShield1);
        $this->setLive($setLive0);

		return $this;
	}

	public function setLive(Block $block)
    {
        $block->fakeLive();
    }

	public function rearShieldFire(Block $block)
    {
        $params = ['r4', 'r2', 'r1', 'r3'];
        $block
            ->fakeLive()
            ->writeRegister($params, $this->rand2048() - 503)
            ->writeRegister($params, $this->rand2048() - 473)
            ->writeRegister($params, $this->rand2048() -350)
            ->and(['r16', 'r16', 'r16']) //for carry ?
            ->zjmp(['%:' . $block->name])
            ;
    }

    public function rearShieldFactory(Block $block, Block $target)
    {
        $block
            ->ld([656, 'r2'])
            ->ld([16842752, 'r3'])
            ->sub(['r5', 'r6', 'r5'])
            ->fork(['%:' . $target->name])
            ->setCarryOn('r16')
            ->infiniteLoop()
        ;
    }

	protected function initProtector(Block $block, Block $target)
    {
        $block->ld([-10, 'r5'])
            ->fork(['%:' . $target->name])
        ;
    }

	private function attack2(Block $block)
	{
		$block
            //0B(sti) 54(3 registre) 0A(r10) 0C(r12)
            ->ld(['%' . hexdec('0B540A0C'), 'r10'])
		    ->ld(['%-350', 'r13'])
		    ->setCarryOn('r16')
            ->st(['r10', $this->rand2048() - 505])
            ->zjmp(['%' . ($this->rand2048() - 510)])
        ;
	}

	private function attack1(Block $block)
	{
		$block
            ->ld(['%' . hexdec('0D09' . dechex($this->rand2048() - 355)), 'r10'])  //0D(r13) 09(zjmp) XX XX
            ->ld(['%-346', 'r13'])
            ->setCarryOn('r16')
            ->st(['r10', $this->rand2048() - 474])
            ->zjmp(['%' . ($this->rand2048() - 484)])
        ;
	}

    private function initAttacker(Block $block, Block $target1, Block $target2)
    {
        $block
            ->fakeLive()
            ->fork(['%:'. $target1])
            ->ld(['%' . hexdec('03700b01'), 'r11']) //03(st) 70 0b(r11) 01
            //operations sur les negs pour eviter les 00 00 00 XX
            ->ld(['%-1', 'r6'])
            //pourrait etre dans live0, à la fin: ici, ralenti le demarrage du process de defense
            ->fork(['%:'. $target2])
        ;
    }

    private function setPlayerNumberInR15(Block $block)
    {
        $block
            //store in r15 my player number
            ->ld(['%' . ($this->rand2048() - 5), 'r15'])
        ;
    }

	private function init(Block $block, Block $target)
	{
		$block
//            ->resetRegister('r16')
		    //store my player number in live0 + 2
		    ->sti(['r1', '%:' . $target, '%2'])
            //erase previous code
            ->st(['r16', '-7'])
            ->st(['r16', '-11'])
        ;
    }
}
