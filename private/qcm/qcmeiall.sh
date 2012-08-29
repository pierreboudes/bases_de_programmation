#!/bin/bash
rm enonces/* 
ocaml qcmall.ml
cd enonces
for i in `ls`
do pdflatex $i
done
cd ..
cat > assemblage.tex <<EOF
\documentclass[a4paper]{article}
\usepackage{pdfpages}
\begin{document}
EOF
for i in `ls enonces/*.pdf`
do echo '\includepdf[pages=-]{'$i'}' >> assemblage.tex
done
echo '\end{document}' >> assemblage.tex
pdflatex assemblage.tex

