#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "saage.h"

void serialise_aux(FILE * f, Arbre A, int i){
    for(int j = 0; j <= i; j++){
        fprintf(f, "    ");
    }
    fprintf(f, "Valeur : %s\n", A->val);
    if(!A->fg)
        fprintf(f, "Gauche : NULL\n");
    else{
        fprintf(f, "Gauche :\n");
        serialise_aux(f, A->fg, i+1);
    }
    if(!A->fd)
        fprintf(f, "Droite : NULL\n");
    else{
        fprintf(f, "Droite :\n");
        serialise_aux(f, A->fd, i+1);
    }
}


int serialise(char * nom_de_fichier, Arbre A){
    FILE *f = fopen(nom_de_fichier, "w");
    int i =0;
    if(!f)
        return 0;
    serialise_aux(f, A, i);
    fclose(f);
    return 1;
}

void deserialise_aux(FILE * f, Arbre *A, int i){
    for(int j = 0; j <= i; j++){
        fscanf(f, "    ");
    }
    fscanf(f, "Valeur : ");
    fscanf(f, "%s", &(*A)->val);
    if(!(*A)->fg){
        fscanf(f, "Gauche : NULL");
        (*A)->fg = NULL;
    }
    else{
        fscanf(f, "Gauche :");
        deserialise_aux(f, (*A)->fg, i+1);
    }
    if(!(*A)->fd){
        fscanf(f, "Droite : NULL");
        (*A)->fd = NULL;
    }
    else{
        fscanf(f, "Droite :");
        deserialise_aux(f, (*A)->fd, i+1);
    }
}

int deserialise(char * nom_de_fichier, Arbre * A){
    FILE *f = fopen(nom_de_fichier, "w");
    int i = 0;
    if(!f)
        return 0;
    deserialise_aux(f, A, i);
    fclose(f);
    return 1;
}