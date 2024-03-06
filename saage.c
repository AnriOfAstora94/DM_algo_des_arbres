#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "saage.h"

void indente(FILE * f, int  i){
    if(i < 0)
        return;
    for(int j = 0; j < i; j++){
        fprintf(f, "    ");
    }
}
int serialise_aux(FILE * f, Arbre A, int i){
    if(!A)
        return 0;
    indente(f, i);
    fprintf(f, "Valeur : %s\n", A->val);
    if(!A->fg){
        indente(f, i);
        fprintf(f, "Gauche : NULL\n");
    }
    else{
        indente(f, i);
        fprintf(f, "Gauche : \n");
        serialise_aux(f, A->fg, i+1);
    }
    if(!A->fd){
        indente(f, i);
        fprintf(f, "Droite : NULL\n");
    }
    else{
        indente(f, i);
        fprintf(f, "Droite : \n");
        serialise_aux(f, A->fd, i+1);
    }
    return 1;
}


int serialise(char * nom_de_fichier, Arbre A){
    FILE *f = fopen(nom_de_fichier, "w");
    int i = 0;
    if(!f){
        fclose(f);
        return 0;
    }
    if(!serialise_aux(f, A, i)){ // si la sérialisation a échoué on supprime le fichier texte
        int len = 7 + strlen(nom_de_fichier);
        char cmd[len];
        strcpy(cmd, "rm -f ");
        strcat(cmd, nom_de_fichier);
        fclose(f);
        system(cmd);
        return 0;
    }
    fclose(f);
    return 1;
}

void suppr_Espaces_Debut(char *chaine) {
    size_t longueur = strlen(chaine);
    size_t i = 0;

    while (i < longueur && isspace(chaine[i])) {
        i++;
    }

    if (i > 0) {
        memmove(chaine, chaine + i, longueur - i + 1);
    }
}

int recherche_val(const char *chaine, char *resultat) {

    const char *motif = "Valeur :";
    size_t longueurMotif = strlen(motif);

    const char *positionMotif = strstr(chaine, motif);

    if (positionMotif == NULL) {
        return 0;
    }

    strcpy(resultat, positionMotif + longueurMotif);

    return 1;
}


int deserialise_aux(FILE * f, Arbre *A){
    char val[100];
    if(!f)
        return 0;
    char c[100];
    
    fgets(c, 512, f);
    suppr_Espaces_Debut(c);
    c[strcspn(c, "\n")] = '\0';

    recherche_val(c, val);
    *A = alloue_noeud(val);
    fgets(c, 512, f);
    suppr_Espaces_Debut(c);
    c[strcspn(c, "\n")] = '\0';

    if(!strcmp(c, "Gauche : "))
        deserialise_aux(f, &(*A)->fg);
    fgets(c, 512, f);
    suppr_Espaces_Debut(c);
    c[strcspn(c, "\n")] = '\0';

    if(!strcmp(c, "Droite : "))
        deserialise_aux(f, &(*A)->fd);
    return 1;
}


int deserialise(char * nom_de_fichier, Arbre * A){
    FILE *f = fopen(nom_de_fichier, "r");
    if(!f){
        fclose(f);
        return 0;
    }
    deserialise_aux(f, A);
    fclose(f);
    return 1;
}
