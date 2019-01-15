<?php
ob_start();
?>
<div id="camagru">
    <section class="montage">
        <div class="deco">
            <?php foreach ($listFilter as $filter): ?>

            <button onclick="display('<?= $filter['title'] ?>')" id="btn_<?= $filter['title']?>">
                <img src="<?= $filter['url'] ?>" alt="<?= $filter['title']?>">
            </button>
            <?php endforeach; ?>

        </div>
        <div class="video">
            <div id='miseEnPage'>
                <video id="video" poster="" autoplay></video>
                <?php foreach ($listFilter as $filter): ?>
                <img class="preview" id="<?= $filter['title'] ?>" src="<?= $filter['url'] ?>">
                <?php endforeach; ?>
            </div>
            <button id="snap" onclick="alert('il faut soit charger une image format png, soit activer la webcam, <.)')">Snap Photo</button>
            <form method="post" action="">
                <input type="file" id="file" accept=".png"/>
            </form>
            <div id="prev">
            </div>
        </div>
    </section>

    <section class="minimoi">
        <canvas style="display:none" id="canvas" width="640" height="480"></canvas>
        <div id="new">
        <?php foreach ($pics as $pic): ?>
            <img src="<?= $pic['url'] ?>"
                 id="<?= $pic['url']?>"
                 alt="<?= $pic['title']?>"
                 title="<?= $pic['title']?>"
                 onclick='deletePic("<?= $pic['url'] ?>")'>
        <?php endforeach; ?>
        </div>
    </section>
</div>
<?php
$content = ob_get_clean();
require 'template.php';?>
