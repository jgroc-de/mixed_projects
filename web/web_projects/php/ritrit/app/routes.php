<?php
// Routes

$app->get('/', App\Action\HomeAction::class)
    ->setName('homepage');

/*$app->get('/nd-dame_ganagobie', App\Action\AbbayeAction::class . ':ganagobie')
    ->setName('ganagobie');

$app->get('/st-pierre_Solesmes', App\Action\AbbayeAction::class . ':solesmes')
    ->setName('solesmes');
 */
$app->get('/camagru', App\Action\AbbayeAction::class . ':camagru')
    ->setName('camagru');

$app->post('/validation', App\Action\MailAction::class)
    ->setName('mail1');

$app->get('/termes_et_conditions', App\Action\TermsAction::class)
    ->setName('terms');
