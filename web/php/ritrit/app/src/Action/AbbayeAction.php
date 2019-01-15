<?php
namespace App\Action;

use Slim\Views\Twig;
use Psr\Log\LoggerInterface;
use Slim\Http\Request;
use Slim\Http\Response;

final class AbbayeAction
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
        $this->logger->info("Home page action dispatched");
        
        $this->view->render($response, 'home.twig');
        return $response;
    }

    public function ganagobie(Request $request, Response $response, array $args)
    {
        $this->logger->info("ganagobie page action dispatched");
        $twigVar = [
            'name' => 'Notre-dame - Ganagobie',
            'h2' => 'Formulaire de réservation',
            'url' => 'https://www.abbaye-ganagobie.com/'
        ];
        
        $this->view->render(
            $response,
            'abbaye.twig',
            $twigVar
        );
        return $response;
    }

    public function solesmes(Request $request, Response $response, array $args)
    {
        $this->logger->info("solesmes page action dispatched");
        $twigVar = [
            'name' => 'Saint-Pierre - Solesmes',
            'h2' => 'Formulaire de réservation',
            'url' => 'http://www.abbayedesolesmes.fr/'
        ];
        
        $this->view->render(
            $response,
            'abbaye.twig',
            $twigVar
        );
        return $response;
    }

    public function camagru(Request $request, Response $response, array $args)
    {
        $this->logger->info("camagru page action dispatched");
        $twigVar = [
            'name' => 'Saint-Camagru - Camagru',
            'h2' => 'Formulaire de réservation',
            'url' => 'http://jgroc2s.free.fr/'
        ];
        
        $this->view->render(
            $response,
            'abbaye.twig',
            $twigVar
        );
        return $response;
    }
}
