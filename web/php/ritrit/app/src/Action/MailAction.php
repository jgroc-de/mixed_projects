<?php
namespace App\Action;

use Slim\Views\Twig;
use Psr\Log\LoggerInterface;
use Slim\Http\Request;
use Slim\Http\Response;
use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\Exception;

final class MailAction
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
        $form = '';
        foreach ($_POST as $key => $value)
            $form = $form . '<br>' . $key . ': ' . $value; 
        $this->logger->info("Mail page action dispatched");
        $mail = new PHPMailer();                               //Passing `true` enables exceptions
        // To load the French version
        $mail->setLanguage('fr', '/optional/path/to/language/directory/');
        try {
            //Server settings
            //$mail->SMTPDebug = 2;                                  //Enable verbose debug output
            $mail->isSMTP();                                       //Set mailer to use SMTP
            $mail->Host = 'ssl://in.mailjet.com';   //Specify main and backup SMTP servers
            $mail->SMTPAuth = true;                                //Enable SMTP authentication
            $mail->Username = '5efbfbfd31e4c9200729b490c2ea90f0';                  //SMTP username
            $mail->Password = 'c6d13363a9a312a8121c1668bbf4caba';                            //SMTP password
            $mail->SMTPSecure = 'ssl';                             //Enable TLS encryption, `ssl` also accepted
            $mail->Port = 465;                                     //TCP port to connect to

            //Recipients
            $mail->setFrom('jerome.gds@gmail.com', 'Mailer');
            $mail->addAddress($_POST['email'], $_POST['name'] . ' ' . $_PST['surname']);      //Add a recipient
            //$mail->addAddress('ellen@example.com');                //Name is optional
            //$mail->addReplyTo('@example.com', 'Information');
            $mail->addCC('jerome.gds@gmail.com');
            //$mail->addBCC('bcc@example.com');

            //Attachments
            //$mail->addAttachment('/var/tmp/file.tar.gz');          //Add attachments
            //$mail->addAttachment('/tmp/image.jpg', 'new.jpg');     //Optional name

            //Content
            $mail->isHTML(true);                                   //Set email format to HTML
            $mail->Subject = 'Your email flight plan!';
            $mail->Body    = '<h3>Dear passenger ' . $_POST['name'] . ', welcome to Mailjet!</h3><br />May the delivery force be with you!<br>' . $form;
            $mail->AltBody = 'Dear passenger 1, welcome to Mailjet! May the delivery force be with you!';

            $mail->send();
            $message = 'success';
        } catch (Exception $e) {
            $message =  '<br>Message could not be sent.<br>Mailer Error: '. $mail->ErrorInfo;
        } 
        $this->view->render($response, 'validation.twig', ['message' => $message]);
        return $response;
    }
}
