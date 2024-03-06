#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _noeud{
    char * val;
    struct _noeud *fg, *fd;
} Noeud, *Arbre;

Noeud * alloue_noeud(char *s){
    Noeud * new = (Noeud *)malloc(sizeof(Noeud));
    if(!new){
        fprintf(stderr, "Erreur d'allocation");
        return NULL;
    }
    new->val = (char *)malloc(strlen(s) + 1);
    
    if(!new->val){
        fprintf(stderr, "Erreur d'allocation");
        free(new);
        return NULL;
    }
    strcpy(new->val, s);
    new->fg = NULL;
    new->fd = NULL;
    return new;
    
}

int aux(FILE * f, Arbre *A){
    char  ligne[100]; // stocke la ligne de texte
    char ind[10]; //stocke valeur ou gauche ou droite
    char dp[3]; // stocke le caractere :" "
    char val[50]; // stocke la potentiel valeur du noeud
    if(!fgets(ligne,512,f))
        return 1;
    sscanf(ligne, "%s %s %s",ind, dp, val);
    if(strcmp(ind, "Valeur") == 0){
        printf("val : %s\n", val);
        (*A) = alloue_noeud(val);
        if(!*A){
            fprintf(stderr,"Erreur d'allocation");
            free(*A);
            return -1;
        }

    }
    if(strcmp(ind, "Gauche") == 0){
        if(strcmp(val, "NULL") == 0)
            (*A)->fg = NULL;
        else 
            aux(f, &((*A)->fg));
    }
    if(strcmp(ind, "Droite") == 0){
        if(strcmp(val, "NULL") == 0)
            (*A)->fd = NULL;
        else 
            aux(f, &(*A)->fd);
    }else{
        aux(f, &(*A)->fg);
        aux(f, &(*A)->fd);
        return 0;
    }
    return 0;
}


int deserialise(char * nom_de_fichier, Arbre * A){
    FILE *f = fopen(nom_de_fichier, "r");
    if(!f){
        return 0;
    }
    
    aux(f,A);
    fclose(f);
    return 1;
}

int main(){
    FILE * f = fopen("c.saage", "r");
    if(!f){
        return 0;
    }

    Arbre a = NULL;

    deserialise("c.saage", &a);
    return 0;
}