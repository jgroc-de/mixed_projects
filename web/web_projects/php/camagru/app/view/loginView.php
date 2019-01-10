<?php
$pseudo = "";

if (isset($_POST['pseudo']))
    $pseudo = htmlspecialchars($_POST['pseudo']);
ob_start();
?>
<section class="form">
    <div>Entrez vos identifiants :</div>

    <form method="post" action="<?= $target ?>">
        <div>
            <label>pseudo</label>
            <input type="text"
                   name="pseudo"
                   value="<?= $pseudo ?>"
                   maxlength="30"
                   required
                   >
            <br>
        </div>
        <div>
            <label>mot de passe</label>
            <input type="password"
                   name="passwd"
                   pattern="(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,}"
                   title="6 characteres minimum dont au moins un chiffre, une majuscule et une minuscule"
                   required
                   >
            <br>
        </div>
        <div class="submit">
            <button type="submit">
                <i class="fa fa-paper-plane"></i>
                Envoyer
            </button>
        </div>
    </form>
    <div>Mot de passe oublié? 
        <a style="color: blue" href="index.php?action=reinit">réinitialiser votre mot de passe</a>
    </div>
</section>
<?php
$content = ob_get_clean();
require 'template.php';?>
