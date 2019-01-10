<?php

require 'app/lib/user.php';

function reinit($c, $options)
{
    $userManager = $c->user;
    $pseudo = "";
    $reinit = 0;
    $valid = 0;

    if (isset($_POST['pseudo']))
    {
        $pseudo = $_POST['pseudo'];
        $reinit = 1;
        if ($userManager->resetValidkey($pseudo))
        {
            $c->mail->sendReinitMail($userManager->getUser($pseudo));
        }
        else
            $_SESSION['flash'] = ["fail" => "Soldat inconnu"];
    }
    elseif (isset($_GET['log'], $_GET['key']))
    {
        $pseudo = $_GET['log'];
        $key = $_GET['key'];
        if ($userManager->pseudoInDb($pseudo) && $userManager->checkValidationMail($pseudo, $key))
        {
            logUser($userManager->getUser($pseudo));
            header('Location: /index.php?action=settings');
        }
        else
        {
            $_SESSION['flash'] = ['fail' => "Bimp! N'y aurait-il pas une petite erreur de typo dans votre pseudo?"];	
        }
    }
    require 'app/view/reinitView.php';
}
