<?php
ob_start();
?>
<section class="picview">
    <div class="pic">
        <h2>Auteur: <?= htmlspecialchars($elem['pseudo']) ?></h2>
        <p>le <?= htmlspecialchars($elem['date2']) ?></p>
        <img src="<?= htmlspecialchars($elem['url']) ?>"
             alt="<?= htmlspecialchars($elem['title'])?>"
         >
         <div>
             <span id="like">
                 <?= htmlspecialchars($elem['nb_like']); ?> likes
             </span>

             <?php if (isset($_SESSION['pseudo'])): ?>

             <button onclick='addLike(<?= $elem["id"] ?>)'>+1</button>
             <span id="lol"></span>
             <div>
                 <textarea class="text"
                           rows="3"
                           cols="50"
                           placeholder="Troll this!"></textarea>
                 <div class="submit">
                     <button class="form" onclick='addComment(<?= $elem["id"] ?>)'>
                         <i class="fa fa-paper-plane"></i>
                         Troller
                     </button>
                 </div>
             </div>

             <?php endif; ?>

         </div>
    </div>
    <div class="comment">

        <?php while ($com = $comment->fetch()): ?>

        <div>	
            <h3><?= htmlspecialchars($com['pseudo'])?></h3>
            <p>le <?= htmlspecialchars($com['date2'])?><br>
            <?= htmlspecialchars($com['content'])?></p>
        </div>

        <?php endwhile; ?>

    </div>
</section>
<?php
$content = ob_get_clean();
require 'template.php';
