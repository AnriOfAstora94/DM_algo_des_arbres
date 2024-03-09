/*
Auteurs : PEGOURIE Benjamin/RABE Iarimbola
Date de création : 23/02/2024
*/

#include <stdio.h>
#include <string.h>
#include "arbres_binaires.h"
#include "greffe.h"
#include "saage.h"


int affiche_std(char * nom_fichier){
    FILE * f = fopen(nom_fichier, "r");
    if(!f){
        printf("Erreur ouverture du fichier\n");
        return 0;
    }
    char ligne[512];
    while (fgets(ligne, 512, f) != NULL) {
        printf("%s", ligne);
    }
    fclose(f);
    return 1;
}

int main(int argc, char ** argv){
    if(argc < 2){
        printf("Pas assez d'arguments\n");
        return 0;
    }

    if(strcmp(argv[1], "-E") == 0){
        /*
        int construit arbre ici
        serialise(Arbre);
        */
        return 1;
    }

    if((strcmp(argv[1], "-G") == 0) && argv[2] && argv[3]){  
        Arbre A = NULL;
        Arbre G = NULL;
        if(!deserialise(argv[2], &A) || !deserialise(argv[3], &G))
            return 0;
        expansion(&A, G);
        if(!serialise("res.saage", A))
            return 0;
        affiche_std("res.saage");
        liberer(&A);
    }
    

    return 1;
}

