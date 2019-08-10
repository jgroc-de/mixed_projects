<?php

namespace App\Controller;

use App\Entity\Booking;
use App\Entity\Resource;
use App\Form\BookingType;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\Routing\Annotation\Route;

class BookingController extends AbstractController
{
    /**
     * @Route("/bookings", methods={"POST"}, name="create_booking")
     */
    public function bookings(Request $request): JsonResponse
    {
		// retrieves $_GET and $_POST variables respectively
		json_decode($request->getContent());
        $doctrine = $this->getDoctrine();
        $em = $this->getDoctrine()->getManager();

        $booking = new Booking();
		//$resource = $doctrine->getRepository(Resource::class)->find($ref);
        $form = $this->createForm(BookingType::class, $booking);
        $form->handleRequest($request);

        if ($form->isSubmitted() && $form->isValid()) {
            $em->flush();
        }

        $booking = $doctrine->getRepository(Booking::class)->findOneBy(['resource' => 'test']);

        return new JsonResponse($booking);
    }
}
