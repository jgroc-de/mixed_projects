<?php
ob_start();
?>
<div class="lol">
    <div class="page">

<?php
if ($count != 0):
    for ($i = 0; $i <= $count; $i++): ?>

    <a <?php if ($i == $start) echo "id='active'";?> 
        href="index.php?action=listPics&amp;start=<?= $i ?>">
        <?= $i ?>
    </a>

<?php endfor;
endif; ?>
    </div>
</div>

<section>
<?php
    
while ($elem = $pics->fetch()): ?>

<div class="listPics">
    <a href="index.php?action=picture&amp;id=<?= htmlspecialchars($elem['id'])?>">
        <img class='page1'
             src="<?= htmlspecialchars($elem['url'])?>"
             alt="<?= htmlspecialchars($elem['title'])?>"
             title="<?= htmlspecialchars($elem['title'])?>">
        <div class='text'>
            <h2><?= htmlspecialchars($elem['title'])?></h2>
            <span>Par <?= htmlspecialchars($elem['pseudo'])?></span>
            <span>le <?= htmlspecialchars($elem['date2'])?></span>
        </div>
    </a>
</div>

<?php endwhile; ?>

</section>
<?php
$content = ob_get_clean();
require 'template.php';?>
