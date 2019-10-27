<?php

namespace Functions;

class Block
{
	public $name;
	public $data;

	public function __construct($name)
	{
		$this->name = $name;
		$this->data .= $name . ':' . PHP_EOL;
	}

    public function aff(array  $arguments = [])
    {
        $this->data .= (new aff($arguments))->data;

        return $this;
    }

    public function live(array  $arguments = [])
    {
        $this->data .= (new live($arguments))->data;
        return $this;
    }

    public function zjmp(array  $arguments = [])
    {
        $this->data .= (new zjmp($arguments))->data;
        return $this;
    }

    public function add(array  $arguments = [])
    {
        $this->data .= (new add($arguments))->data;
        return $this;
    }

    public function sub(array  $arguments = [])
    {
        $this->data .= (new sub($arguments))->data;
        return $this;
    }

    public function st(array  $arguments = [])
    {
        $this->data .= (new st($arguments))->data;
        return $this;
    }

    public function sti(array  $arguments = [])
    {
        $this->data .= (new sti($arguments))->data;
        return $this;
    }

    public function fork(array  $arguments = [])
    {
        $this->data .= (new fork($arguments))->data;
        return $this;
    }

    public function lfork(array  $arguments = [])
    {
        $this->data .= (new lfork($arguments))->data;
        return $this;
    }

    public function and(array  $arguments = [])
    {
        $this->data .= (new land($arguments))->data;
        return $this;
    }

    public function or(array  $arguments = [])
    {
        $this->data .= (new lor($arguments))->data;
        return $this;
    }

    public function xor(array  $arguments = [])
    {
        $this->data .= (new lxor($arguments))->data;
        return $this;
    }

    public function ld(array  $arguments = [])
    {
        $this->data .= (new ld($arguments))->data;
        return $this;
    }

    public function lld(array  $arguments = [])
    {
        $this->data .= (new lld($arguments))->data;
        return $this;
    }

    public function ldi(array  $arguments = [])
    {
        $this->data .= (new ldi($arguments))->data;
        return $this;
    }

    public function lldi(array  $arguments = [])
    {
        $this->data .= (new lldi($arguments))->data;
        return $this;
    }

	public function setCarryOn(string $register)
    {
        $this->data .= (new add([$register, $register, $register]))->data;
        return $this;
    }

    public function infiniteLoop()
    {
        $this->data .= (new zjmp(['%:' . $this->name]))->data;
        return $this;
    }

    public function __toString()
    {
        return $this->name;
    }

    //protection: on reset le register $register des assaillants
    public function resetRegister(string $register)
    {
        $this->and([$register, '%0', $register]);
        return $this;
    }

    //permettra d'écrire en dur le bon live à lancer, quelquesoit le proprio du process
    public function fakeLive()
    {
        $this->live(['%-' . rand(1, 4)]);
        return $this;
    }

    public function writeRegister(array $registerList, int $index)
    {
        $this
            ->st([$registerList[0], $index])
            ->st([$registerList[1], --$index])
            ->st([$registerList[2], --$index])
            ->st([$registerList[3], --$index])
            ;
        return $this;
    }
}
