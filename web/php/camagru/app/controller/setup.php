<?php

function setup($c)
{
    if ($_SESSION['pseudo'] === 'troll2')
    {
        //$c->config->createDB($DB['name']);
        $c->config->request(file_get_contents($DB['export']));
    }
    header('Location: index.php');
}
