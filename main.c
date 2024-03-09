/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdio.h>
#include "arbres_binaires.h"
#include "greffe.h"
#include "saage.h"




int main(){
    Arbre a = cree_A_3();
    /*
    Arbre b = alloue_noeud("binaire");
    b->fg = alloue_noeud("lexicographique");
    b->fd = alloue_noeud("n-aire");
    */
    /*
   Arbre b = alloue_noeud("Camomille");
   b->fg = alloue_noeud("Lilas");
   b->fd = alloue_noeud("Rose");
   */
   
    Arbre b = alloue_noeud("Intel Core i9");
    b->fg = alloue_noeud("Intel Core i9");
    b->fg->fg = alloue_noeud("Apple M3 Max");
    b->fg->fd = alloue_noeud("AMD Ryzen 9");

    expansion(&a, b);
    creePDF("A2.dot", "A2.pdf", a);
    //serialise("c.saage", a);
    //deserialise("c.saage", &c);
    //creePDF("A2.dot", "A2.pdf", c);
    

    return 0;
}

