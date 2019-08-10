<?php

namespace App\Controller;

use App\Repository\ResourceRepository;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\Routing\Annotation\Route;

class GetResourceController extends AbstractController
{
    /**
     * @var ResourceRepository
     */
    private $repository;

    public function __construct(ResourceRepository $repository)
    {
        $this->repository = $repository;
    }

    /**
     * @Route("/resources")
     */
    public function invoke()
    {
        return new JsonResponse($this->repository->findAll());
    }
}
