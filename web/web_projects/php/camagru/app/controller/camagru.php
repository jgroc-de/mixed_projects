<?php

function camagru($c, $options)
{
    $options['camagru'] = true;

    if (!isset($_SESSION['pseudo']))
    {
        $target = 'index.php?action=login&action2=camagru';
		require 'app/view/loginView.php';
    }
    else
    {
        $pics = $c->picture->getPicsByLogin($_SESSION['id']);
		$listFilter = $c->camagru->getFilters();	
        $options['script'] = 'public/js/camagruView.js';
		require 'app/view/camagruView.php';
	}
}
