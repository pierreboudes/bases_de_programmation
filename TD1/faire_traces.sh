#!/bin/bash
for i in `ls progs/*.ail`;
do ../mini-assembleur/bin/amiltrace $i ${i%.ail}.tex;
done
