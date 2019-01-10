<?php
//seed=8607777714024093700
//seed=-8607777714024093700

class tile
{
    public $x;
    public $y;
    public $str;
    public $dir = [];
    
    public function __construct(string $tile, int $i, int $j)
    {
        $this->str = $tile;
        $this->x = $i;
        $this->y = $j;
        $this->dir[0] = $tile[0] == '1'? [0, -1] : [];
        $this->dir[1] = $tile[1] == '1'? [1, 0] : [];
        $this->dir[2] = $tile[2] == '1'? [0, 1] : [];
        $this->dir[3] = $tile[3] == '1'? [-1, 0] : [];
    }
	
	public function ft_print(int $i = 0)
	{
		if ($i == 0)
			echo " ($this->y,$this->x) $this->str";
		else
			error_log(var_export("$this->str ", true));
		/*else
		{
			$str = "   "; 
			if ($this->str[0]== '1' && $this->str[2] == '1')
			{
				$str[1] = '|';
			}
			else if ($this->str[2]== '1')
			{
				$str[1] = ';';
			}
			else
			{
				$str[1] = '!';
			}
			if ($this->str[1]== '1')
			{
				$str[3] = '_';
			}
			if ($this->str[3]== '1')
			{
				$str[0] = '_';
			}
			echo " $str";
		}*/
	}
}

class player
{
    // the total number of quests for a player (hidden and revealed)
    public $x;
    public $y;
    public $qCount;
    //public $questsList;
    public $tile;
	public $id;
    
    public function __construct(int $id)
    {
        fscanf(STDIN, "%d %d %d %s",
            $this->qCount,
            $this->x,
            $this->y,
            $tile
		);
		$this->tile = new tile($tile, $id, $id);
		if ($id == -1)
			$this->id = 0;
		else
			$this->id = 1;
    }

	public function ft_print()
	{
		//error_log(var_export("player [$this->id] : ($this->y,$this->x). $this->qCount remaininig\n", true));
		echo "player [$this->id] : ($this->y,$this->x). $this->qCount remaininig\n";
		$this->tile->ft_print();
		echo "\n";
	}
}

class item
{
    public $name;
	public $tile;
    public $owner;
	public $activ = 0;
    
    public function __construct(array $board)
    {
        fscanf(STDIN, "%s %d %d %d", $this->name, $y, $x, $this->owner);
		foreach ($board as $line)
		{
			foreach ($line as $tile)
			{
				if ($tile->x == $x && $tile->y == $y)
					$this->tile = $tile;
			}
		}
    }

	public function activate(string $name, int $owner)
	{
		if ($this->name == $name && $this->owner == $owner)
		{
			$this->activ = 1;
			return 1;
		}
		return 0;
	}
	
	public function ft_print()
	{
		//error_log(var_export("$this->name $this->y $this->x $this->owner", true));
		$tile = $this->tile;
		echo "item $this->name: ($tile->y,$tile->x) own by $this->owner\n";
	}
}

class game
{
    public $board = [];
    public $player = [];
    public $items = [];
	const MOVE = [
		" UP" => [0, -1],
		" RIGHT" => [1, 0],
		" DOWN" => [0, 1],
		" LEFT" => [-1, 0]
	];
	const OPP = [2, 3, 0, 1];
    	
	public function ft_print($option = 7)
	{
		if ($option & 1)
		{
			echo "-- board --\n";
			foreach ($this->board as $line)
			{
				foreach ($line as $tile)
				{
					$tile->ft_print();
					echo ":";
				}
				echo "\n";
				echo "\n";
			}
			echo "\n";
		}
		if ($option & 2)
		{
			echo "-- players --\n";
			foreach ($this->player as $line)
			{
				$line->ft_print();
			}
			echo "\n";
		}
		if ($option & 4)
		{
			echo "-- items --\n";
			foreach ($this->items as $line)
			{
				$line->ft_print();
			}
		}
		echo "\n-- end --\n\n\n";
	}

    public function __construct()
    {
        $this->setBoard();
        $this->player[0] = new player(-1);
        $this->player[1] = new player(-2);
        $this->setItems();
        $this->setQuests();
    }
    
    public function setBoard()
    {
        for ($y = 0; $y < 7; $y++)
        {
            $line = explode(" ", fgets(STDIN));
            $this->board[$y] = [];
            foreach ($line as $x => $tile)
                $this->board[$y][$x] = new tile($tile, $x, $y);
        }
    }
    
    public function setItems()
    {
		// the total number of items available on board and on player tiles
		fscanf(STDIN, "%d", $numItems);
        $this->items = [];
        for ($i = 0; $i < $numItems; $i++)
            $this->items[] = new item($this->board);
    }
    
    public function setQuests()
    {
		// the total number of revealed quests for both players
		fscanf(STDIN, "%d", $numQuests);
        for ($i = 0; $i < $numQuests; $i++)
		{
        	fscanf(STDIN, "%s %d", $name, $owner);
			foreach ($this->items as $item)
			{
				if ($item->activate($name, $owner))
					break ;
			}
		}
    }
    
    public function getCurrentQuests(int $owner)
    {
        $quests = [];
        foreach ($this->items as $item)
        {
            if ($item->activ && $item->owner == $owner)
                $quests[] = $item;
        }
        return $quests;
	}

	public function limit(int $pos)
	{
		if ($pos > 6)
			$pos = 0;
		else if ($pos < 0)
			$pos = 6;
		return $pos;
	}

	public function distance(array $list, $quest, int &$min, int &$pas)
	{
		$out = false;
		foreach($list as $tile)
		{
			$dist = abs($tile->x - $quest->x) + abs($tile->y - $quest->y);
			if (($dist < $min) || ($dist == $min && count($list) < $pas))
			{
				$pas = count($list);
				$min = $dist;
				$out = true;
			}
		}
		return $out;
	}
	
	public function nextTile(int $x, int $y, $quest, int $i)
	{
		$paths = [];
		foreach (($this->board[$y][$x])->dir as $j => $dir)
		{
			if ($dir)
			{
				$x1 = $this->limit($x + $dir[0]);
				$y1 = $this->limit($y + $dir[1]);
				if (($this->board[$y1][$x1])->dir[SELF::OPP[$j]])
				{
					$save = $this->board[$y][$x];
					$this->board[$y][$x] = new tile("0000", $x, $y);
					$paths[] = $this->path_rec($x1, $y1, $quest, $i);
					$this->board[$y][$x] = $save;
				}

			}
		}
		return $paths;
	}

	public function cutPath(&$row, $quest)
	{
		$min = 100;
		foreach ($row as $i => $tile)
		{
			$dist = abs($tile->x - $quest->x) + abs($tile->y - $quest->y);
			if ($dist < $min)
			{
				$min = $dist;
				$key = $i;
			}
		}
		return array_slice($row, $key + 1);
	}

	public function shortestPath($paths, $quest)
	{
		$min = abs($this->player[0]->x - $quest->x) + abs($this->player[0]->y - $quest->y);
		$pas = 1000;
		$row = [];
		foreach ($paths as $j => $path)
		{
			if ($this->distance($path, $quest, $min, $pas))
			{
				$row = $path;
			}
		}
		return $row;
	}

	public function path_rec(int $x, int $y, $quest, int $i)
	{
		$row = [];
		if ($i++ != 20)
		{
			$paths = $this->nextTile($x, $y, $quest, $i);
			foreach ($paths as $i => $row)
				$this->cutPath($paths[$i], $quest);
			$row = $this->shortestPath($paths, $quest);
		}
		array_unshift($row, $this->board[$y][$x]);
		return $row;
	}

	public function removeItem($remove)
	{
		$save = $this->items;
		$this->items = [];
		foreach ($save as $item)
		{
			if (!($item->owner == $remove->owner && $item->name == $remove->name))
				$this->items[] = $item;
		}
	}
}

class move extends game
{
    public function getPath()
    {
		$quests = $this->getCurrentQuests(0);
		$min = 100;
		$pas = 1000;
		$path = [];
		$list = [];
		$i = 0;
		foreach ($quests as $quest)
		{
			if ($quest->tile->x >= 0)
			{
				$list[] = $this->path_rec($this->player[0]->x, $this->player[0]->y, $quest->tile, 0);
				if ($this->distance($list[$i], $quest->tile, $min, $pas))
				{
					$pas = 1000;
					$key = $i;
					$path = $list[$i];
				}
				$i++;
			}
		}
		/*if ($min == 0 && isset($key))
		{
			$this->player[0]->x = $quests[$key]->tile->x;
			$this->player[0]->y = $quests[$key]->tile->y;
			$this->removeItem($quests[$key]);
			$path = array_merge($path, $this->getPath());
		}*/
		return $path;
    }

	public function getAnswer(array $path)
	{
		$str = "";
		if ($path)
		{
			$prev = $path[0];
			foreach ($path as $i => $current)
			{
				if ($i == 20)
					break ;
				if ($i != 0)
				{
					$x = abs($prev->x - $current->x);
					$x = $prev->x > $current->x ? -$x : $x;
					$y = abs($prev->y - $current->y);
					$y = $prev->y > $current->y ? -$y : $y;
					$str .= array_search([$x, $y], SELF::MOVE);
					$prev = $current;
				}
			}
		}
        return $str;
	}

	public function getMove()
	{
		return $this->getAnswer($this->getPath());
	}
}

class push extends game
{
	public function updateTile(int $d, int $i = -1, int $j = -1)
	{
		if ($i >= 0)
		{
			foreach ($this->board[$i] as $k => $tile)
			{
				$tile->x = $k;
				$tile->y = $i;
			}
			if ($this->player[0]->y == $i)
				$this->player[0]->x = $this->limit($this->player[0]->x + $d);
		}
		else
		{
			for ($k = 0; $k < 7; $k++)
			{
				($this->board[$k][$j])->x = $j;
				($this->board[$k][$j])->y = $k;
			}
			if ($this->player[0]->x == $j)
				$this->player[0]->y = $this->limit($this->player[0]->y + $d);
		}
		$this->player[0]->tile->x = -1;
		$this->player[0]->tile->y = -1;
	}

	public function out(int &$min, int &$pas, int $min2, int $pas2, string $str)
	{
		if ($str != "" && ($min2 < $min || ($min2 == $min && $pas2 < $pas)))
		{
			$min = $min2;
			$pas = $pas2;
			return ($str);
		}
		else
			return ("");
	}

	public function pushRight($i)
	{
		array_unshift($this->board[$i], $this->player[0]->tile);
		$this->player[0]->tile = array_pop($this->board[$i]);
		$this->updateTile(1, $i);
	}
	
	public function pushLeft($i)
	{
		array_push($this->board[$i], $this->player[0]->tile);
		$this->player[0]->tile = array_shift($this->board[$i]);
		$this->updateTile(-1, $i);
	}

	public function pushUp($i)
	{
		for ($j = 6; $j > -1; $j--)
		{
			$tmp = $this->board[$j][$i];
			$this->board[$j][$i] = $this->player[0]->tile;
			$this->player[0]->tile = $tmp;
		}
		$this->updateTile(-1, -1, $i);
	}

	public function pushDown($i)
	{
		for ($j = 0; $j < 7; $j++)
		{
			$tmp = $this->board[$j][$i];
			$this->board[$j][$i] = $this->player[0]->tile;
			$this->player[0]->tile = $tmp;
		}
		$this->updateTile(1, -1, $i);
	}

	public function simulation(int $line, &$min, &$pas)
	{
		$quests = $this->getCurrentQuests(0);
		$path = [];
		$list = [];
		$ans = "";
		$i = 0;
		$player = $this->player[0];
		foreach ($quests as $quest)
		{
			if ($quest->tile->x >= 0)
			{
				//print_r($quest);
				$list[] = $this->path_rec($this->player[0]->x, $this->player[0]->y, $quest->tile, 0);
				if ($this->distance($list[$i], $quest->tile, $min, $pas))
				{
					//$pas = 1000;
					$ans = "{$line} ";
					$path = $list[$i];
				}
				$i++;
			}
		}
		return ($ans);
	}

	public function pushTile()
	{
		$str = "";
		$min = 100;
		$pas = 1000;
		for ($i = 0; $i < 1; $i++)
		{
			//echo "\n\nRIGHT: $i ****\n";
			$min2 = 100;
			$pas2 = 100;
			$this->pushRight($i);
			$tmp = $this->simulation($i, $min2, $pas2);
			$this->pushLeft($i);
			$str = $this->out($min, $pas, $min2, $pas2, $tmp);
			//echo "\n\nLEFT: $i****\n";
			$min2 = 100;
			$pas2 = 100;
			$this->pushLeft($i);
			$tmp = $this->simulation($i, $min2, $pas2);
			$this->pushRight($i);
			$str = $this->out($min, $pas, $min2, $pas2, $tmp);
			//echo "\n\nUP: $i ****\n";
			$min2 = 100;
			$pas2 = 100;
			$this->pushUp($i);
			$tmp = $this->simulation($i, $min2, $pas2);
			$this->pushDown($i);
			$str = $this->out($min, $pas, $min2, $pas2, $tmp);
			//echo "\n\nDOWN: $i ****\n";
			$min2 = 100;
			$pas2 = 100;
			$this->pushDown($i);
			$tmp = $this->simulation($i, $min2, $pas2);
			$this->pushUp($i);
			$str = $this->out($min, $pas, $min2, $pas2, $tmp);
		}
		return ($str);
	}
}

$turn = 0;
//while ($turn++ < 2)
while(1)
{
    fscanf(STDIN, "%d", $turnType);
    if ($turnType % 2 == 0)
	{
    	$game = new push;
	//	$game->ft_print();
        $str = $game->pushTile();
        //echo "PUSH {$str}\n";
		echo "PUSH 0 DOWN\n";
	}
    else
    {
    	$game = new move;
        $str = $game->getMove();
		if ($str)
        	echo "MOVE{$str}\n";
		else
			echo "PASS\n";
    }
}
////error_log(var_export($y1, true));
// PUSH <id> <direction> | MOVE <direction> | PASS
