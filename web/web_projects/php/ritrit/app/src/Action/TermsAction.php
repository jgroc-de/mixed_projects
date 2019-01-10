<?php
namespace App\Action;

use Slim\Views\Twig;
use Psr\Log\LoggerInterface;
use Slim\Http\Request;
use Slim\Http\Response;

final class TermsAction
{
    private $view;
    private $logger;
    private $container;

    public function __construct($container)
    {
        $this->container = $container;
        $this->view = $this->container['view'];
        $this->logger = $this->container['logger'];
    }

    public function __invoke(Request $request, Response $response, $args)
    {
        $this->logger->info("Terms page action dispatched");
        
        $this->view->render($response, 'term.twig');
        return $response;
    }
}
