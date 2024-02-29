/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdio.h>
#include "arbres_binaires.h"
#include "greffe.h"




int main(){
    Arbre a = cree_A_3();
    Arbre b = alloue_noeud("Intel Core i9");
    b->fg = alloue_noeud("Intel Core i9");
    b->fg->fg = alloue_noeud("Apple M3 Max");
    b->fg->fd = alloue_noeud("AMD Ryzen 9");
    expansion(&a, b);
    creePDF("A3.dot", "A3.pdf", a);
    return 0;
}

