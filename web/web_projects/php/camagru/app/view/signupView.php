<?php

ob_start();
?>
	<section class="form">
		<div>Remplissez tous les champs:</div>

		<form method="post" action="index.php?action=signup">

			<div>
				<label>pseudo</label>
                <input type="text"
                    name="pseudo"
                    value=""
                    maxlength="30"
                    required>
                <br>
			</div>
			<div>
				<label>mot de passe</label>
                <input type="password"
                    name="passwd"
                    pattern="(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,}"
                    title="6 characteres minimum dont au moins un chiffre, une majuscule et une minuscule"
                    required><br>
			</div>
			<div>
				<label>email</label>
                <input type="email"
                    name="email"
                    required>
                <br>
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
