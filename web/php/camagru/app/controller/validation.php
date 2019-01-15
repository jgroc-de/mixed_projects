<?php

function validation($c)
{
    if (isset($_GET['log'], $_GET['key']))    
    {
        $c->user->checkValidationMail($_GET['log'], $_GET['key']);
    }
    require 'app/view/signupView.php';
}
