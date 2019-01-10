<?php

ob_start();
if ($reinit): ?>
<section>
</section>
<?php elseif ($valid): ?>
<section class="form">
    <form method="post" action='index.php?action=reinit&amp;log=<?= $pseudo ?>&amp;key=<?= $key ?>'>
        <div>
            <label>mot de passe</label>
            <input type="password" name="passwd" required>
            <br>
        </div>
        <div class="submit">
            <button type="submit">
                <i class="fa fa-paper-plane"></i>
                Envoyer
            </button>
        </div>
    </form>
</section>

<?php else: ?>

<section class="form">
    <form method="post" action="index.php?action=reinit">
        <div>
            <label>pseudo</label>
            <input type="text" name="pseudo" value="<?= $pseudo ?>"required>
            <br>
        </div>
        <div class="submit">
            <button type="submit">
                <i class="fa fa-paper-plane"></i>
                Envoyer
            </button>
        </div>
    </form>
</section>

<?php endif;

$content = ob_get_clean();

require 'template.php';?>
