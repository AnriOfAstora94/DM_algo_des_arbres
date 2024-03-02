/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdio.h>
#include "arbres_binaires.h"
#include "greffe.h"
#include "saage.h"




int main(){
    Arbre a = cree_A_1();
    Arbre b = alloue_noeud("binaire");
    b->fg = alloue_noeud("lexicographique");
    b->fd = alloue_noeud("n-aire");
    expansion(&a, b);
    //creePDF("A2.dot", "A2.pdf", a);
    serialise("t.txt", a);
    
    return 0;
}

