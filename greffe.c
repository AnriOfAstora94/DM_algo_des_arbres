/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "greffe.h"


int copie(Arbre * dest, Arbre source){
    if(!source)
        return 1;

    (*dest) = alloue_noeud(source->val);
    if(!(*dest)){
        fprintf(stderr, "Echec allocation");
        free(*dest);
        return 0;
    }

    if(!copie(&(*dest)->fg, source->fg) || !copie(&(*dest)->fd, source->fd)){// Si une copie échoue on s'arrête.
        liberer(dest); // on libère l'arbre
        return 0;
    }
    return 1;
}

void greffeG(Arbre * G, Noeud * n){
    if(!*G)
        return;
    if(!(*G)->fg)
        copie((*G)->fg, n->fg);
    else
        greffeG(&(*G)->fg, n);
        //greffeD(&(*G)->fg, n);
}


void greffeD(Arbre *G, Noeud * n){
    if(!*G)
        return;
    if(!(*G)->fd)
        copie((*G)->fd, n->fd);
    else
        greffeD(&(*G)->fd, n);
        greffeG(&(*G)->fd, n);

}

int expansion(Arbre * A, Arbre B){
    if(!*A)
        return 0;
    if(strcmp((*A)->val, B->val) == 0 /*&& gauche ou droite ne renvoie R*/){
            Arbre G = NULL;
            copie(&G, B);
            greffeG(&G, B);
            greffeD(&G, B);

    }
    return 1;
}