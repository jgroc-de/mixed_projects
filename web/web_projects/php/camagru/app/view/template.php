<!DOCTYPE html>
<html lang="fr">
<?php $description = "Bienvenue sur ce petit site type image-board/instagram. Vous pouvez vous prendre en photo dans l'onglet /b et faire un petit montage avec les filtres proposés.";
?>
    <head>
<?php if ($options['last']):?>
        <!-- Global site tag (gtag.js) - Google Analytics -->
        <script async src="https://www.googletagmanager.com/gtag/js?id=UA-120607595-1"></script>
        <script>
            window.dataLayer = window.dataLayer || [];
            function gtag(){dataLayer.push(arguments);}
            gtag('js', new Date());

            gtag('config', 'UA-120607595-1');
        </script>
<?php endif; ?>
		<meta charset="utf-8"/>
        <meta name="msvalidate.01" content="B2AA06B53F92EF6BD747E53031323DE7" />
<?php if ($options['last']):?>
<meta name="description" content="<?= $description ?>">
<?php endif; ?>
        <meta name="keywords" lang="fr" content="image-board photo-montage">
		<title>Camagru</title>
		<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway">
		<link href="public/css/main.css" rel="stylesheet" type="text/css"/>
		<link href="public/css/auxiliary.css" rel="stylesheet" type="text/css"/>
		<link href="public/css/camagru.css" rel="stylesheet" type="text/css"/>
		<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
        <link rel="stylesheet" media="screen and (max-width: 750px) and (min-width: 532px)" href="public/css/medRes.css" />
        <link rel="stylesheet" media="screen and (max-width: 531px)" href="public/css/lowRes.css" />
    </head>
	<body>
	
    <header>
        <h1>
            <a href="index.php" style="background:none;padding:0;">
                <b>Camagru</b>
            </a>
            <em <?php
if (isset($elem) && isset($_SESSION['id'])):?>onclick="changeTitle(<?= $elem['id'] ?>)"<?php endif;
echo ">";
if ($options['title2']) echo $options['title2'] ?></em>
        </h1>
    </header>
    <nav class="navbar">
<?php if (!isset($_SESSION['pseudo'])): ?>
        <span>plz log in or sign up: </span>
        <div>
            <a <?php if ($options['login']) echo 'style="background:darkgrey" '; else echo 'style="background:#b6e5af" ';?> href="index.php?action=login">Login</a>
            <a <?php if ($options['signup']) echo 'style="background:darkgrey" ';?>href="index.php?action=signup">Signup</a>
<?php else: ?>
            <span><?= $_SESSION['pseudo'] ?></span>
        <div> 
            <a style="background:#f9ccca" href="index.php?action=logout">logout</a>
            <a <?php if ($options['settings']) echo 'style="background:darkgrey" ';?>href="index.php?action=settings">settings</a>
        <?php endif; ?>
            <a <?php if ($options['last']) echo 'style="background:darkgrey" ';?>href="index.php">Last pictures</a>
            <a <?php if ($options['trend']) echo 'style="background:darkgrey" ';?>href="index.php?action=listPicsByLike">Trending Pictures</a>
            <a <?php if ($options['camagru']) echo 'style="background:darkgrey" ';?>href="index.php?action=camagru">/b/</a>
        </div>
    </nav>
<?php
if (function_exists('flashMessage'))
    flashMessage();
echo $content;
?>
    <footer>
        <hr>
        <?php if ($options['last'] || $options['signup']) echo '<div>' .  $description . '</div>';?>
        <em>© jgroc-de 2018</em>
    </footer>
<?php if ($options['script']): ?>        
    <script src="<?= $options['script'] ?>"></script>
<?php endif;?>
    </body>
</html>
