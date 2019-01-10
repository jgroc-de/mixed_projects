<?php

ob_start();
?>
<section class="form">
<div>Modifier vos informations personnelles:</div>
<form method="post" action="index.php?action=settings">
    <div>
        <label>pseudo</label>
        <input type="text"
               name="pseudo"
               value="<?= $user['pseudo'] ?>"
               maxlength="30"
               required>
    </div>
    <div>
        <label>mot de passe</label>
        <input type="password"
               name="passwd"
               pattern="(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,}"
               title="6 characteres minimum dont au moins un chiffre, une majuscule et une minuscule"
               required>
        <br>
    </div>
    <div>
        <label>email</label>
        <input type="email"
               name="email"
               value="<?= $user['email'] ?>"
               required>
        <br>
    </div>
    <div>
        <label>notification mail</label>
        <input type="checkbox"
               name="alert" <?php if ($user['alert']) echo "checked"?>>
    </div>
    <div class="submit">
        <button type="submit">
            <i class="fa fa-paper-plane">
            </i>
            Envoyer
        </button>
    </div>
</form>
</section>
<?php

$content = ob_get_clean();

require 'template.php';?>
