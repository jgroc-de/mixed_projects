<?php
namespace App\Middlewares;

use \Psr\Http\Message\ServerRequestInterface as Request;
use \Psr\Http\Message\ResponseInterface as Response;

class port80
{
    /**
	 * middleware that block user if host != localhost:8081
	 * c'est con écirt comme, ca, a adapter!
     *
     * @param  \Psr\Http\Message\ServerRequestInterface $request  PSR7 request
     * @param  \Psr\Http\Message\ResponseInterface      $response PSR7 response
     * @param  callable                                 $next     Next middleware
     *
     * @return \Psr\Http\Message\ResponseInterface
     */
    public function __invoke(Request $request, Response $response, $next)
    {
		$head = $request->getHeaders();
        if ($head['HTTP_HOST'][0] != "localhost:8081")
        {
			return $response
				->write("trolololol")
				->withStatus(401);
        }
        else
        {
        	return $next($request, $response);
        }
    }
}
