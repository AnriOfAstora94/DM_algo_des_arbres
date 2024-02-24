/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdio.h>
#include "arbres_binaires.h"
#include "greffe.h"




int main(){
    char s[10] = "binaire";
    char c[10] = "binaire";
    char d[10] = "ternaire";
    Arbre a = alloue_noeud(s);
    a->ind = 1;
    a->fg = alloue_noeud(c);
    a->fg->ind = 2;
    a->fd = alloue_noeud(c);
    a->fg->fg = alloue_noeud(d);
    a->fg->fd = alloue_noeud(d);
    Noeud * nd = recherche_plus_profond(a, "binaire");
    affiche(a);
    printf("%d\n", nd->ind);
    return 0;
}

