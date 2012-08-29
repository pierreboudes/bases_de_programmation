<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr" dir="ltr">
<head>
<title>Contrôle de TP en éléments d'informatique, envoie de fichier</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<style>
div.sujet {
  border: 1px solid green;
  background-color: rgb(240,240,240);
  width: 800px;
  padding: 5px;
  margin: 10px;
}

div.rendre {
  border: 1px solid red;
  background-color: rgb(240,240,240);
  width: 800px;
  padding: 5px;
  margin: 10px;
}

</style>
</head>
<body>
<div class="rendre">
<?php
require_once("../groupes.php");
$sujetgroupes = groupes();
  $mesgroupes = $sujetgroupes["groupes"];
$nomOrigine = $_FILES['monfichier']['name'];
$numeroGroupe = $_POST['mongroupe'];
$numeroEtu = $_POST['monnumero'];
$numeroSujet = $_POST['monsujet'];
$elementsChemin = pathinfo($nomOrigine);
$extensionFichier = $elementsChemin['extension'];
$extensionsAutorisees = array("c", "txt", "ods", "rtf", "text");
if ( !is_numeric($numeroGroupe) ) {
   echo "ceci n'est pas un numéro de groupe.";
}
else if (!(in_array($numeroGroupe, $mesgroupes))) {
 echo " Il est ".date("H:i").", vous n'êtes pas à un horaire de remise prévu pour votre groupe
  (le $numeroGroupe).";
}
else if ( !ctype_digit($numeroEtu) ) {
   echo "ceci n'est pas un numéro étudiant.";
}
else if (!(in_array($extensionFichier, $extensionsAutorisees))) {
    echo "Le fichier n'a pas l'extension attendue<br>";
} else {    
    // Copie dans le repertoire du script avec un nom
    // incluant l'heure a la seconde pres 
    $repertoireDestination = dirname(__FILE__)."/devoirsei/";
    $nomDestination = "s".$numeroSujet."_G".$numeroGroupe."_".$numeroEtu."_controle_du_".date("dHis").".".$extensionFichier;

    if (move_uploaded_file($_FILES["monfichier"]["tmp_name"], 
                                     $repertoireDestination.$nomDestination)) {
        echo "Le fichier <tt>.$extensionFichier</tt> a bien été reçu.<br/>";
        echo "Utiliser le bouton back (retour page précédente) pour
                                     préparer un second fichier.<br/>";
    } else {
        echo "Le fichier n'a pas été uploadé (trop gros ?) ou ".
                "Le déplacement du fichier temporaire a échoué".
                " vérifiez l'existence du répertoire ".$repertoireDestination;
    }
}
?>
</div>
</body>