/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arbres_binaires.h"


/*Noeud * recherche_plus_profond(Arbre a,  char * s){
    if(!a)
        return NULL;
    if(strcmp(a->val, s) == 0){
        Noeud * rgauche = recherche_plus_profond(a->fg, s);
        if(rgauche)
            return rgauche;
        Noeud * rdroite = recherche_plus_profond(a->fd, s);
        if(rdroite)
            return rdroite;
        else
            return a;
    }
    Noeud * gauche = recherche_plus_profond(a->fg, s);
    if(gauche)
        return gauche;
    else
        return recherche_plus_profond(a->fd, s);
}*/

Noeud * alloue_noeud(char *s){
    Noeud * new = (Noeud *)malloc(sizeof(Noeud));
    if(!new){
        fprintf(stderr, "Erreur d'allocation");
        free(new);
        return NULL;
    }
    new->val = (char *)malloc(strlen(s) + 1);
    if(!new->val){
        fprintf(stderr, "Erreur d'allocation");
        free(new->val);
        return NULL;
    }
    strcpy(new->val, s);
    new->fg = NULL;
    new->fd = NULL;
    return new;
}

void liberer(Arbre *A){
    if(*A){
        liberer(&(*A)->fg);
        liberer(&(*A)->fd);
        free((*A)->val);
        free(*A);
        *A = NULL;
    }
}

void affiche_aux(Arbre a){
    if(a){
        printf("%s ", a->val);
        affiche_aux(a->fg);
        affiche_aux(a->fd);
    }
}

void affiche(Arbre a){
    if(a){
        affiche_aux(a);
        printf("\n");
    }
}

