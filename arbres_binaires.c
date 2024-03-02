/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arbres_binaires.h"



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

Arbre cree_A_1(){
    Arbre a = alloue_noeud("arbre");
    a->fg = alloue_noeud("binaire");
    a->fd = alloue_noeud("ternaire");
    return a;
}

Arbre cree_A_2(){
    Arbre a = alloue_noeud("Anemone");
    a->fg = alloue_noeud("Camomille");
    a->fd = alloue_noeud("Camomille");
    a->fd->fg = alloue_noeud("Dahlia");
    a->fd->fg->fd = alloue_noeud("Camomille");
    a->fd->fg->fd->fg = alloue_noeud("Iris");
    a->fd->fg->fd->fd = alloue_noeud("Jasmin");
    return a;
}

Arbre cree_A_3(){
    Arbre a = alloue_noeud("Intel Core i9");
    a->fg = alloue_noeud("Apple M3 Max");
    a->fg->fd = alloue_noeud("AMD Ryzen 9");
    a->fg->fd->fg = alloue_noeud("Intel Core i9");
    a->fd = alloue_noeud("Intel Core i9");
    a->fd->fg = alloue_noeud("Intel Core i9");
    return a;
}

int construit_arbre(Arbre *a){

    return 1;
}


void ecrireDebut(FILE *f){
    fprintf(f,"digraph arbre {\n");
    fprintf(f, "node [shape=record, height=.1]\n");
    fprintf(f,"edge [tailclip=false, arrowtail = dot, dir=both];\n");
}

void ecrireFin(FILE *f){
    fprintf(f,"}\n");
}

void ecrireArbre(FILE *f, Arbre a){
if (a != NULL){
    fprintf(f,"n%p [label=\"<gauche > | <valeur > %s | <droite >\"]",a,a->val);
    if (a->fd != NULL){
        fprintf(f,"n%p:droite:c -> n%p:valeur\n",a,a->fd);
        ecrireArbre(f,a->fd);
    }
    if (a->fg != NULL){
        fprintf(f,"n%p:gauche:c -> n%p:valeur\n",a,a->fg);
        ecrireArbre(f,a->fg);
    }
    }
    return;
}

void dessine(FILE *f, Arbre a){
    ecrireDebut(f);
    ecrireArbre(f, a);
    ecrireFin(f);
}


void creePDF(char *dot, char *pdf, Arbre a){
    FILE *out=fopen(dot,"w");
    dessine(out,a);
    fclose(out);
    int len = strlen(dot) + strlen(pdf) + 15; char cmd[len];
    strcpy(cmd, "dot -Tpdf ");
    strcat(cmd, dot);
    strcat(cmd, " -o ");
    strcat(cmd, pdf);
    system(cmd); 
}


