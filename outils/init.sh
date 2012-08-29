#!/bin/bash
# init.sh un script shell qui installe ses petits dans votre compte
# en essayant de rester respectueux de celui-ci.

# Installation d'un lien symbolique .emacs
if [ -f ~boudes/pub/EI/emacs/point_emacs -a ! -e ~/.emacs ]
  then 
    ln -s ~boudes/pub/EI/emacs/point_emacs ~/.emacs
    echo "Creation du .emacs (redirection par lien symbolique)"
  else 
    echo "Echec de la creation du .emacs"
fi

# Ajout d'un fichier a sourcer dans le .bashrc
if grep -q boudes .bashrc 
  then 
    echo "Le .bashrc etait deja install'e"
  else
    echo "Installation d'un greffon dans le .bashrc"
    cat <<EOF >> .bashrc
#Pour l'UE elements d'informatique
if [ -f ~boudes/pub/EI/bashrc ]
  then source ~boudes/pub/EI/bashrc
fi
EOF
# On source le fichier pour ce shell
   if [ -f ~boudes/pub/EI/bashrc ]
     then source ~boudes/pub/EI/bashrc
   fi 
fi
