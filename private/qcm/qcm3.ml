(************************************************)
(*                                              *)
(*        Mélangeur automatique de QCM          *)
(*       Jean-Yves Moyen, novembre 2008         *)
(*                                              *)
(************************************************)

(************************************************)
(*                                              *)
(*             Variables globales               *)
(*                                              *)
(************************************************)

(*  Variable globale à modifier au besoin.      *
 *  C'est mal. À terme, il faut penser à        *
 *  utiliser Arg et à parser la ligne de        *
 *  commande                                    *)

let nb_qcm = 180  (* Nombre de QCM à générer *)
let nb_ques = 20  (* nombre de questions par QCM *)

let input = "questions3.tex" (* fichier d'entrée *)
let output_dir = "enonces"  (* répertoire où mettre les résultats *)
let output = "sujet_"       (* préfixe des fichiers de sortie *)

(*  Les résultats sont générés, 1 fichier par QCM, avec des noms de la *
 *  forme : sujet_XXX.tex                                              *)

(************************************************)
(*                                              *)
(*                   Types                      *)
(*                                              *)
(************************************************)

type reponse = string

type question = 
    { intitule : string ;
      choix : reponse list ;
      meta : (string * int) list ;
    }

type qcm = question list



(************************************************)
(*                                              *)
(*  Validité des QCM par test des métadonées    *)
(*                                              *)
(************************************************)

let get_meta m q = try List.assoc m q.meta  with _ -> 0

(* Modifier la fonction suivante pour tester la validité d'un QCM.   *
 * Test brutal et génération de QCM jusqu'à obtenir quelque chose de * 
 * valide. Donc vraisemblablement loin d'être optimal...             *
 *                                                                   *
 * Utiliser "get_meta m q" pour retrouver la méta donnée associée à  *
 * la chaîne m pour la question q.                                   *
 * Utiliser les itérateurs sur les listes pour calculer la propriété *
 * souhaitée.                                                        *)
let dif1 q = (get_meta "difficile" q) = 1
let debut1 q = (get_meta "debut" q) = 1
let facile1 q = (get_meta "facile" q) = 1

let is_valid qcm =  ((List.length (List.filter dif1 qcm))>=3) 
                    && ((List.length (List.filter dif1 qcm))<=5) 
                    && ((List.length (List.filter debut1 qcm))>=7)
                    && ((List.length (List.filter debut1 qcm))<=10)
                    && ((List.length (List.filter facile1 qcm))>=6)
                    && ((List.length (List.filter facile1 qcm))<=9)

(* let is_valid qcm = true  *pour shunter* *)

(* Exemples de tests de validité                                     *)

(* Exactement 1 question de "level" 3 dans le QCM :
   (List.length (List.filter (fun q -> (get_meta "level" q)=3)))=1     *)

(* Au moins une question de chaque "set" (entre 1 et 9 :
  List.for_all 
    (List.map (fun n -> List.exists (fun q -> (get_meta "set" q)=n)) 
   [1;2;3;4;5;6;7;8;9])                                              *)

    

(************************************************)
(*                                              *)
(*                  Sorties                     *)
(*                                              *)
(************************************************)


(* Modifier aussi les deux variables suivantes. "headers" sera placé  *
 * au début de chaque QCM. Changer notamment la matière, le semestre, *
 * au besoin.                                                         *
 * "footers" est placé à la fin de chaque QCM. On peut par exemple    *
 * rajouter des questions ouvertes qui seront présentes sur chaque    *
 * QCM (comme ici).                                                   *
 *                                                                    *
 * Attention !                                                        *
 * La chaîne sera interprétée par Caml avant le passage à LaTeX. Il   *
 * faut donc penser à doubler les '\' !                               *)


let headers = "%% *-* LateX mode *-*

\\documentclass[a4paper,10pt,landscape]{article}
\\usepackage[scale=0.95]{geometry}
\\usepackage[french]{babel}
\\usepackage[utf8]{inputenc}
\\usepackage{amsmath,amsthm,amssymb}
\\usepackage{stmaryrd}
\\usepackage{multicol}
\\usepackage{moreverb}
\\newcommand{\\important}[1]{\\begin{center}
    \\setlength{\\fboxrule}{1pt}\\setlength{\\fboxsep}{2mm}\\fbox
    {\\begin{minipage}{0.9\\textwidth} #1
    \\end{minipage}}\\end{center}}

\\begin{document}
\\noindent
%\\vspace{-.2cm}
\\rule{\\linewidth}{0.5mm}\\\\
\\vspace{-.2cm}
Licence 1 \\hfill {{\\Large\\bf Éléments d'informatique -- contrôle continue}} \\hfill 
\\shortstack{\\small Prénom : \\hspace{3cm} Nom : \\hspace{4cm} \\\\ N$^{\\circ}$ etu : \\hspace{3cm}\\hfill.}
\\\\
\\rule{\\linewidth}{0.5mm}
\\vspace{-0.8cm}
 \\setlength{\\columnseprule}{1pt}
\\begin{multicols}{3}
%\\raggedcolumns
\\noindent
\\textbf{\\small Barème~: $1$ points par réponse juste (unique) ; $-0,5$ points par réponse fausse. Durée : $20$ minutes.}

\\begin{enumerate}
"

let footers ="\\end{enumerate}
\\vfill
\\end{multicols}
\\newpage
\\Huge FIN
\\end{document}

%%% Local Variables: %%%
%%% mode: latex %%%
%%% ispell-local-dictionary: \"fr\" %%%
%%% TeX-master: nil %%%
%%% End: %%%"


let output_reponse oc (r:reponse) =
  output_string oc ("  \\item[$\\Box$]"^r^"\n")

let output_question oc q =
  output_string oc ("\\item "^q.intitule^"\n");
  output_string oc "  \\begin{enumerate}\n";
  List.iter (output_reponse oc) q.choix;
  output_string oc "  \\end{enumerate}\n\\pagebreak[3]\n"
  

let output_qcm oc = (* Sort les n premières questions du QCM *)
  let rec allez_tuture (q:qcm) =
    function
	0 -> ()
      | n -> output_question oc (List.hd q); allez_tuture (List.tl q) (n-1)
  in allez_tuture

(************************************************)
(*                                              *)
(*                 Entrées                      *)
(*                                              *)
(************************************************)

exception Ill_Formed_QCM of int*string

let line = ref 0

let my_read_line ic =
  incr line;
  input_line ic

let input_multi_line_reponse ic s =
  let rec allez_tuture rep =
    let ligne = my_read_line ic in
      if (String.length ligne) > 0
      then
	match ligne.[0] with
	    '!' | '+' -> raise (Ill_Formed_QCM (!line, "Rep. multi-ligne non terminée."))
	  | '#' -> allez_tuture rep (* commentaire *)
	  | ' ' -> allez_tuture (rep^"\n"^ligne) (* suite de la
  réponse *)
	  | '-' -> (ligne.[0]<-' ';(rep^"\n"^ligne)) (* fin de la réponse *)
	  | _ -> raise (Ill_Formed_QCM (!line, "Choix non termines."))
      else (* ligne vide *)
	allez_tuture (rep^"\n")
  in
    s.[0]<-' ';allez_tuture s

let input_reponses ic =
  let rec allez_tuture l =
    let ligne = my_read_line ic in
      if (String.length ligne) > 0
      then
	match ligne.[0] with
	    '!' -> l (* fin des réponses *)
	  | '#' -> allez_tuture l (* commentaire *)
	  | ' ' -> allez_tuture (ligne::l) (* nouvelle réponse *)
	  | '+' -> allez_tuture ((input_multi_line_reponse ic ligne)::l)
	  | _ -> raise (Ill_Formed_QCM (!line, "Choix non termines."))
      else (* ligne vide *)
	allez_tuture l
  in ((allez_tuture []):reponse list)

let input_question ic meta s =
  let rl = input_reponses ic in
    { intitule = s ; choix = rl ; meta = meta}

let rem_first s=
  String.sub s 1 (String.length s - 1)

let input_multi_line_question ic meta s =
  let rec allez_tuture ques =
    let ligne = my_read_line ic in
      if (String.length ligne) > 0
      then
	match ligne.[0] with
	    '!' | '+' -> raise (Ill_Formed_QCM (!line, "Ques. multi-ligne non terminée."))
	  | '#' -> allez_tuture ques (* commentaire *)
	  | '-' -> ques^"\n"^(rem_first ligne) (* fin de la question *)
	  | _ -> allez_tuture (ques^"\n"^ligne) (* suite de la question *)
      else (* ligne vide *)
	allez_tuture (ques^"\n")
  in
    input_question ic meta (allez_tuture (rem_first s))

open Genlex
let mini_lex = make_lexer ["@";"META";":";"="]

let rec stream_to_list s =
  match Stream.peek s with
      None -> []
    | Some a -> Stream.junk s;a::(stream_to_list s)

let rec parse =
  function
      [] -> []
    | (Kwd "@")::r | (Kwd "META")::r | (Kwd ":")::r -> parse r
    | (Ident s)::(Kwd "=")::(Int n)::r -> (s,n)::(parse r)
    | _ -> raise (Ill_Formed_QCM (!line, "Méta donnée incorrecte"))

let input_meta s = parse (stream_to_list (mini_lex (Stream.of_string s)))
(*  let meta_l =  (stream_to_list (mini_lex (Stream.of_string s)))
  in match meta_l with
      (Kwd "#")::(Kwd "META")::_ -> parse meta_l
    | _ -> []
*)
let input_qcm ic =
  let rec allez_tuture meta l =
    try
      let ligne = my_read_line ic in
	if (String.length ligne) > 0
	then
	  match ligne.[0] with
	      '@'  -> allez_tuture ((input_meta ligne)@meta) l (* méta donnée *)
            | '#' -> allez_tuture meta l (* commentaire *)
	    | '!' | ' ' | '-' -> raise (Ill_Formed_QCM (!line, "Question absente ?"))
	    | '+' -> allez_tuture [] ((input_multi_line_question ic meta
					 ligne)::l)
	    | _ -> allez_tuture [] ((input_question ic meta ligne)::l)
	else (* ligne vide *)
	  allez_tuture meta l
    with
	End_of_file -> l (* fin du fichier *)
  in
    try
      ((allez_tuture [] []):qcm)
    with
	Ill_Formed_QCM (n,s) ->
	  failwith ("Erreur ligne "^(string_of_int n)^" : "^s^"\n")


(************************************************)
(*                                              *)
(*                 Shuffle                      *)
(*                                              *)
(************************************************)

let rec random_insert a n =
  function
      [] -> [a]
    | b::r -> 
	if Random.int (n+1) = 0
	then
	  a::b::r
	else
	  b::(random_insert a (n-1) r)

let shuffle_list l=
  let rec allez_tuture l_mel n =
    function
	[] -> l_mel
      | a::r -> allez_tuture (random_insert a n l_mel) (n+1) r
  in
    allez_tuture [] 0 l

let rec (shuffle_reponses:qcm->qcm) =
  function
      [] -> []
    | q::r -> { intitule = q.intitule ; choix = shuffle_list
	  q.choix ; meta = q.meta}::(shuffle_reponses r)

let shuffle_qcm q =
  ((shuffle_list (shuffle_reponses q)):qcm)

let rec get_firsts n =
  function
      l when n=0 -> []
    | a::r -> a::(get_firsts (n-1) r)
    | _ -> failwith "Pas assez de questions"

let rec shuffle_ok q n =
Printf.printf "essai %d\n" n;
  let q' = get_firsts nb_ques (shuffle_qcm q) in
    if (is_valid q')
    then q'
    else shuffle_ok q (n+1)

(************************************************)
(*                                              *)
(*                  Main                        *)
(*                                              *)
(************************************************)

let _ = 
  Random.self_init();
  let ic = open_in input in
  let qcm = input_qcm ic in
    close_in ic;
    for i=1 to nb_qcm do
      let shuffled = shuffle_ok qcm 1 in
      let oc = open_out (output_dir ^ "/" ^ output ^ (string_of_int i) ^ ".tex") in
	output_string oc headers;
	output_qcm oc shuffled nb_ques;
	output_string oc footers;
	close_out oc
    done
