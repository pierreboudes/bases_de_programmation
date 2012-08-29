<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr" dir="ltr">
<head>
<title>Contr�le de TP en �l�ments d'informatique</title>
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
<h1>Contr�le de TP en �l�ments d'informatique</h1>

<?php
require_once("groupes.php");
$debug = 0; /* Mettre � 1 pour r�glages */
?>
<div class="rendre">
  <p>
Aucun document autoris�, ni utilisation d'internet � l'exception du
  cours et des supports de cours. Les sessions des
  utilisateurs qui utiliseront un navigateur web pour autre chose que
  lire ce sujet seront ferm�es brutalement et sans sauvegarde !
  </p>
  <p><b>Votre programme doit compiler sans erreur.</b></p>
</div>

<p>
<?php echo " Il est ".date("H:i").". Votre sujet de contr�le :"; ?>
</p>

<?php
$sujetgroupes = groupes();
$sujet = $sujetgroupes["sujet"];
if ( (1 == $sujet) || $debug):
?>
<div class="sujet">
<p>
Soit un tableau d'entiers initialis� � des valeurs de votre
  choix et dont la taille sera fix�e par une constante symbolique
  N. Soit un second tableau d'entiers, non initialis�, de m�me taille, N.
</p>

<p>
�crire un programme qui :
<ol>
<li>affiche le contenu du premier tableau;</li>
<li>copie le contenu du premier tableau dans le second tableau puis
affiche le second tableau;</li>
<li>copie le contenu du premier tableau dans le second tableau <b>dans
l'ordre inverse</b> puis affiche le second tableau.</li>
</ol>
</p>
<p>
Le programme doit fonctionner correctement pour n'importe quelle
valeur de N.
</p>
</div>
<?php
endif;
?>


<?php
if ( (2 == $sujet) || $debug):
?>
<div class="sujet">
<p>
Soit une constante symbolique N valant 4.
</p>
<p>
�crire un programme qui :
<ul>
  <li>affiche une ligne de N �toiles comme ceci :
<pre>
****
</pre></li>
<li>puis affiche la figure (un carr�) de c�t� N suivante :
<pre>
****
****
****
****
</pre></li>
<li>puis affiche la figure de c�t� N suivante :
<pre>
----
***-
***-
***-
</pre></li>
</ul>
</p>
<p>
Le programme doit fonctionner correctement pour n'importe quelle
valeur positive de N.
</p>
</div>
<?php
endif;
?>


<?php
if ( (3 == $sujet) || $debug):
?>
<div class="sujet">
<p>
Soient deux tableaux d'entiers, tab1 et tab2, initialis�s � des valeurs de votre
  choix, de m�me taille, fix�e par une constante symbolique
  N. Soit un troisi�me tableau d'entiers, tab3, non initialis�, �galement de taille N.
</p>

<p>
�crire un programme qui :
<ol>
<li>affiche le contenu du premier tableau puis le contenu du deuxi�me
  tableau. Exemple (N = 4) :
<pre>
tableau 1: 4 3 5 2
tableau 2: 1 6 0 1
</pre>
</li> 
<li>Calcule la somme des deux premiers tableaux colonne par colonne et
stocke le r�sultat dans le troisi�me tableau, puis affiche le
troisi�me tableau. Exemple :
<pre>
tableau 3: 5 9 5 3
</pre>
</li>
</ol>
</p>
<p>
Le programme doit fonctionner correctement pour n'importe quelles
initialisations des deux premiers tableaux et n'importe quelle valeur
de N.
</p>
</div>
<?php
endif;
?>

<?php
if ( (4 == $sujet) || $debug):
?>
<div class="sujet">
<p>
Soient deux tableaux d'entiers, tab1 et tab2, initialis�s � des valeurs de votre
  choix, de m�me taille, fix�e par une constante symbolique
  N. Soit un troisi�me tableau d'entiers, tab3, non initialis�, �galement de taille N.
</p>

<p>
�crire un programme qui :
<ol>
<li>affiche le contenu du premier tableau puis le contenu du deuxi�me
  tableau. Exemple (N = 4) :
<pre>
tableau 1: 4 3 5 2
tableau 2: 1 6 0 1
</pre>
</li> 
<li>Calcule le maximum des deux premiers tableaux colonne par colonne et
stocke le r�sultat dans le troisi�me tableau, puis affiche le
troisi�me tableau. Exemple :
<pre>
tableau 3: 4 6 5 2
</pre>
</li>
</ol>
</p>
<p>
Le programme doit fonctionner correctement pour n'importe quelles
initialisations des deux premiers tableaux et n'importe quelle valeur
de N.
</p>
</div>
<?php
endif;
?>

<?php
if ( (5 == $sujet) || $debug): /* OK */
?>
<div class="sujet">
<p>
Soit un tableau d'entiers initialis� � des valeurs de votre
  choix et dont la taille sera fix�e par une constante symbolique
  N. Soit un entier <tt>x</tt>, initialis� � une valeur de votre choix.
</p>

<p>
�crire un programme qui :<ol>
<li>affiche le contenu du tableau</li>
<li>puis affiche uniquement les �l�ments du tableaux qui sont
sup�rieurs ou �gaux � <tt>x</tt>.
<li>puis compte le nombre d'entiers sup�rieurs ou �gaux � <tt>x</tt>
dans le tableau et affiche ce nombre � l'�cran.</li>
</ol>
</p>

<p>
Le programme doit fonctionner correctement pour n'importe quelle initialisation du tableau.
</p>
</div>
<?php
endif;
?>

<?php
if ( (6 == $sujet) || $debug): /* OK */
?>
<div class="sujet">
<p>
Soit une variable <tt>n</tt> enti�re initialis�e � une valeur
  positive.
</p>
<p>
�crire un programme qui :<ol>
<li>calcule et affiche le carr� de chacun des entiers de <tt>1</tt> �
  <tt>n</tt>. Exemple pour <tt>n</tt> = 5 :
</p>
<pre>
1 4 9 16 25
</pre>
</li>
<li>puis calcule la somme de ces carr�s. Exemple pour <tt>n</tt> = 5 :
<pre>
somme = 55.
</pre>
</li>
</ol>
<p>
Le programme doit fonctionner pour n'importe quelle valeur positive de <tt>n</tt>.
</p>
</div>
<?php
endif;
?>

<?php
if ( (7 == $sujet) || $debug):
?>
<div class="sujet">
<p>
Soit une constante symbolique N valant 4.
</p>
<p>
�crire un programme qui :
<ul>
  <li>affiche une ligne de N �toiles comme ceci :
<pre>
****
</pre></li>
<li>puis affiche la figure (un triangle) de c�t� N suivante :
<pre>
****
***
**
*
</pre></li>
<li>puis affiche la figure de c�t� N suivante :
<pre>
****
***-
**--
*---
</pre></li>
</ul>
</p>
<p>
Le programme doit fonctionner correctement pour n'importe quelle
valeur positive de N.
</p>
</div>
<?php
endif;
?>

<?php
if ($sujet == 0) :
?>
<div class="sujet">
  Pas de sujet.
</div>
<?php
endif;
?>

<?php
if ( (42 == $sujet) || $debug):
?>
<div class="sujet">
  Sujet 42.
</div>
<?php
endif;
?>

<div class="rendre">
<p>Vous rendrez votre travail sous la forme de deux fichiers :<ul>
<li>un fichier source en langage C, d'extension <tt>.c</tt>
  contenant votre programme et comportant en commentaires les
  algorithmes utilis�s.</li>
  <li>et un fichier format texte, d'extension <tt>.txt</tt>, d�crivant vos �tapes de travail (commandes du terminal employ�es, exemples utilis�s, probl�mes �ventuels); </li>
</ul></p>

<p>Pensez � �crire votre nom au d�but de chaque fichier (en commentaires). </p>
<?php
if  ( ($sujet != 0) || ($debug != 0) ) :
?>

<p>Pour envoyer un fichier vous pouvez utiliser le formulaire suivant (recommencer l'op�ration pour chaque fichier).</p> 
   <form enctype="multipart/form-data" action="devoir/file.php" method="post">
  <fieldset>
<legend>Identificateurs</legend>
      <input type="hidden" name="MAX_FILE_SIZE" value="100000" />
        <input type="hidden" name="monsujet" value="<?= $sujet ?>" />
        <label for="mongroupe">Num�ro de groupe : </label><input type="text" name="mongroupe"/>
      <label fo="monnumero">Num�ro d'�tudiant : </label><input type="text" name="monnumero"/>
  </fieldset>
  <fieldset>
<legend>Fichier � envoyer</legend>
      <label for="monfichier">Fichier :</label> <input type="file" name="monfichier" />
  </fieldset>
      <input type="submit" />
    </form>
<?php
endif;
?>
</div>

<div class="sujet">
<p>
Vous pouvez vous aider du programme suivant ("bonjour.c") pour r�aliser le programme demand�.
</p>
<textarea dir="ltr" rows="25" cols="70" readonly="readonly">
/* prenom nom numero etu  <-- a remplir */
/* Declaration de fonctionnalites supplementaires */
#include <stdlib.h> /* pour EXIT_SUCCESS */
#include <stdio.h> /* pour printf() */

/* Declaration des constantes et types utilisateur */

/* Declaration des fonctions utilisateur */

/* Fonction principale */
int main()
{
  /* Declaration et initialisation des variables */

  /* Commencons par dire bonjour */
  printf("Bonjour tout le monde !\n");

  /* Valeur fonction */
  return EXIT_SUCCESS;
}

/* Definition des fonctions utilisateur */
</textarea>
</div>
</body>
</html>
