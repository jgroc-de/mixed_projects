<?php

function dirToArray($dir) {
  
    $result = array();
 
    $cdir = scandir($dir);
    foreach ($cdir as $key => $value)
    {
       if (!in_array($value,array(".","..")))
       {
          if (is_dir($dir . DIRECTORY_SEPARATOR . $value))
          {
             $result[$value] = dirToArray($dir . DIRECTORY_SEPARATOR . $value);
          } elseif (!in_array($value, ['index.html'])) {
             $result[] = $value;
          }
       }
    }
   
    return $result;
 }
 
 function exploreDir(string $baseDir, array $dirs) {
    foreach ($dirs as $key => $value) {
        $path = "$baseDir/$key";
        if ($value === 'README') {
            $content = file_get_contents("$baseDir/$value");
            if (!(
                strpos($content, "Demande") === 0
                || strpos($content, "Non") === 0
                || strpos($content, "Tu") === 0
                || strpos($content, "Toujours") === 0
            )) {
                echo $content;
            }
        } elseif (is_array($value)) {
            exploreDir($path, $value);
        }
    }
 }

$baseDir = '192.168.56.101';
$dirs = dirToArray($baseDir);
exploreDir($baseDir, $dirs);