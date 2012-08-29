#!/bin/bash

sortietex=$1.tex

echo "\\documentclass[10pt]{article}" > $sortietex;
echo "\\usepackage{moreverb}" >> $sortietex;
echo "\\usepackage{a4wide}" >> $sortietex;
echo "
\\usepackage{listings}
\\usepackage{xcolor}

\\lstset{%
  language={},
  emptylines=*3,
  showspaces=false,
  backgroundcolor=\\color{gray!25},
  basicstyle=\\ttfamily,
  breaklines=true,
  columns=fullflexible
}
"  >>$sortietex;
 
echo "\\begin{document}" >> $sortietex;

for i in `ls $1/* | sort -n -k 3`;
do
echo "" >> $sortietex;
echo "\\textbf{Traitement de :} \\verb|$i|" >> $sortietex;
echo "Traitement de $i";
echo "" >> $sortietex;
if [ "${i##*.}" == "c" ]
then
  echo "\\lstinputlisting[language=C,numbers=left,backgroundcolor=\\color{gray!10}]{$i}" >> $sortietex;
  echo "\\begin{verbatim}" >> $sortietex;

  gcc -Wall $i &> $1.log;
  compilation=$?;

  cat $1.log >> $sortietex;
  echo "\\end{verbatim}" >> $sortietex;
  if [ "$compilation" -eq 0 ]
  then
    echo "\\begin{boxedverbatim}" >> $sortietex;

    a.out &> $1.log;
    execution=$?;

    rm a.out;
    cat $1.log >> $sortietex;
    echo "\\end{boxedverbatim}" >> $sortietex;
    echo "" >> $sortietex;
    if [ "$execution" -eq 0 ]
    then
      echo "terminaison correcte" >> $sortietex;
    else
      echo "TERMINAISON ANORMALE" >> $sortietex;
    fi
  else
    echo "\\textbf{NE COMPILE PAS}" >> $sortietex;
  fi
  echo "" >> $sortietex;
  echo "" >> $sortietex;
else
    echo "\\lstinputlisting{$i}" >> $sortietex;
fi
done
echo "\\end{document}" >> $sortietex;

