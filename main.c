/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdio.h>
#include "arbres_binaires.h"
#include "greffe.h"




int main(){
    /*
    //Arbre A1
    Arbre a = alloue_noeud("arbre");
    a->fg = alloue_noeud("binaire");
    a->fd = alloue_noeud("ternaire");
    Arbre b = alloue_noeud("binaire");
    b->fg = alloue_noeud("lexicographique");
    b->fd = alloue_noeud("n-aire");
    */
   
    // Arbre A2 
    Arbre a = alloue_noeud("Anemone");
    a->fg = alloue_noeud("Camomille");
    a->fd = alloue_noeud("Camomille");
    a->fd->fg = alloue_noeud("Dahlia");
    a->fd->fg->fd = alloue_noeud("Camomille");
    a->fd->fg->fd->fg = alloue_noeud("Iris");
    a->fd->fg->fd->fd = alloue_noeud("Jasmin");

    Arbre b = alloue_noeud("Camomille");
    b->fg = alloue_noeud("Lilas");
    b->fd = alloue_noeud("Rose");

    /*
    // Arbre A3
    Arbre a = alloue_noeud("Intel Core i9");
    a->fg = alloue_noeud("Apple M3 Max");
    a->fg->fd = alloue_noeud("AMD Ryzen 9");
    a->fg->fd->fg = alloue_noeud("Intel Core i9");
    a->fd = alloue_noeud("Intel Core i9");
    a->fd->fg = alloue_noeud("Intel Core i9");

    Arbre b = alloue_noeud("Intel Core i9");
    b->fg = alloue_noeud("Intel Core i9"):
    b->fg->fg = alloue_noeud("Apple M3 Max");
    b->fg->fd = alloue_noeud("AMD Ryzen 9");
    
    */
    expansion(&a, b);
    affiche(a);
    return 0;
}

