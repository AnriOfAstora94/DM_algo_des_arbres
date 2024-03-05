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

    /*
    Arbre b = alloue_noeud("Intel Core i9");
    b->fg = alloue_noeud("Intel Core i9");
    b->fg->fg = alloue_noeud("Apple M3 Max");
    b->fg->fd = alloue_noeud("AMD Ryzen 9");
    */
    expansion(&a, b);
    Arbre c = NULL;
    //creePDF("A2.dot", "A2.pdf", a);
    serialise("c.txt", a);
    deserialise("c.txt", &c);
    creePDF("A2.dot", "A2.pdf", c);
    

    return 0;
}

