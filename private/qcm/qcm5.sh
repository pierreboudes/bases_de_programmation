#!/bin/bash
rm enonces/*
ocaml qcm5.ml.text
cd enonces
for i in `ls`
do pdflatex $i
done
cd ..
cat > assemblage.tex <<EOF
\documentclass[a4paper,landscape]{article}
\usepackage{pdfpages}
\begin{document}
EOF
for i in `ls enonces/*.pdf`
do echo '\includepdf[pages=1]{'$i'}' >> assemblage.tex
done
echo '\end{document}' >> assemblage.tex
pdflatex assemblage.tex

cat > assemblage_page2.tex <<EOF
\documentclass[a4paper]{article}
\usepackage{pdfpages}
\begin{document}
EOF
for i in `ls enonces/*.pdf`
do echo '\includepdf[pages=last-last]{'$i'}' >> assemblage_page2.tex
done
echo '\end{document}' >> assemblage_page2.tex
pdflatex assemblage_page2.tex
