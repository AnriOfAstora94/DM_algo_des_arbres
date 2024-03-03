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

void supprimeEspace(char * chaine){


}

int main(){
    FILE * f = fopen("c.txt", "r");
    if(!f){
        return 0;
    }
    char  c[100];
    char rep[100];
    Arbre * a = NULL;
    if(fscanf(f, "Valeur : ")){
        printf("flop\n");
        return -1;
    }
    if(fscanf(f, "%s ", c) == 1){
        printf("%s ", c);
    }
    return 0;
}