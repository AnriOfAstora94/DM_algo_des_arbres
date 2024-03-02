/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdio.h>
#include "arbres_binaires.h"
#include "greffe.h"




int main(){
    Arbre a = cree_A_2();
    Arbre b = alloue_noeud("Camomille");
    b->fg = alloue_noeud("Lilas");
    b->fd = alloue_noeud("Rose");
    expansion(&a, b);
    creePDF("A2.dot", "A2.pdf", a);
    return 0;
}

