#!/bin/bash
cd ..
# cours papier et slides
if [ $# -eq 0 ] 
then
  echo donner le numero du cours en argument
  exit
fi

i=$1;
    if [ -f "cours/cours${i}/slides/main.tex" ]
    then
	echo "pdf du cours de la semaine ${i}";
	cd cours/cours${i}/slides/;
	if grep  -q "pstricks" "main.tex"
	then 
#	    latex main.tex 1> /dev/null;
#	    dvips -q -P pdf main.dvi 1> /dev/null;
#	    ps2pdf main.ps 1> /dev/null;
	    sed 's/\documentclass\[/\documentclass[trans,/g' main.tex | \
	    sed 's/\documentclass{beamer}/\documentclass[trans]{beamer}/g' | \
	    latex -jobname papier 1> /dev/null;
	    dvips -q -P pdf papier.dvi 1> /dev/null;
	    ps2pdf papier.ps 1> /dev/null;  
        else
#            pdflatex main.tex 1> /dev/null;
	    sed 's/\documentclass\[/\documentclass[trans,/g' main.tex | \
	    sed 's/\documentclass{beamer}/\documentclass[trans]{beamer}/g' | \
	    pdflatex -jobname papier 1> /dev/null;
        fi
	cp main.pdf  "../../../pdf/cours${i}_slides.pdf";
	cp papier.pdf "../../../pdf/cours${i}_papier.pdf";
	cd ../../../;
    fi
    if [ -f "TDTP${i}/td${i}_body.tex" ]
    then
	echo "pdf du TDTP de la semaine ${i}";
	cd TD${i};
#	pdflatex "td${i}" 1> /dev/null;
#	pdflatex "td${i}_corr" 1> /dev/null;
	cp "td${i}.pdf" ../pdf/;
	cp "td${i}_corr.pdf" ../pdf/;
	cd ../;
    fi

