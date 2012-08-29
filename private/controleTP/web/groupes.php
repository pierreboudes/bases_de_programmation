<?php
$tabgroupes = array(
    "12-10-2011 20:50" => array("sujet" => 42, "groupes" => array(43)),
    "13-10-2011 08:35" => array("sujet" => 7, "groupes" => array(6)),
    "13-10-2011 10:20" => array("sujet" => 6, "groupes" => array(8)),
    "13-10-2011 13:50" => array("sujet" => 5, "groupes" => array(5)),
    "13-10-2011 15:35" => array("sujet" => 4, "groupes" => array(4)),
    "14-10-2011 08:35" => array("sujet" => 3, "groupes" => array(7)),
    "14-10-2011 10:20" => array("sujet" => 2, "groupes" => array(3)),
    "14-10-2011 13:50" => array("sujet" => 1, "groupes" => array(1,2))
    );

function groupes() {
    global $tabgroupes;
    $duree = 60*90; /* 1,5h en secondes */
   foreach($tabgroupes as $date => $numeros) {
       $cible = strtotime($date);
       if (($cible <= time()) && (time() - $duree <= $cible)) {
	   return $numeros;
       };
   }
   return array("sujet" => 0, "groupes" => array(0));
}
?>