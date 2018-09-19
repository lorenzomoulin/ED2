#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct lista{
    int v;
    lista* prox;
};

lista* inicializa(){
    return NULL;
}

lista* insere_comeco(int j, lista* l){
    lista* novo;
    if ((novo = malloc(sizeof(*novo))) == NULL){
        printf("Não foi possivel alocar a estrutura\n\n");
        return l;
    }
    novo->v = j;
    novo->prox = l;
    l = novo;
    return l;

}

lista* insere_cidade(int j, lista* l){
    lista* novo;
    if ((novo = malloc(sizeof(*novo))) == NULL){
        printf("Não foi possivel alocar a estrutura\n\n");
        return l;
    }
    if (l == NULL){
        
        novo->v = j;
        novo->prox = NULL;
        l = novo;
        
    }
    
    else{
        lista* aux = l;
        while (aux->prox != NULL){aux = aux->prox;}
        novo->v = j;
        novo->prox = NULL;
        aux->prox = novo;
    }
    return l;
}

lista* retorna_ultimo(lista* l){
    lista* aux = l;
    if (l == NULL){
        return l;
    }
    while(aux->prox!=NULL){
        aux = aux->prox;
    }
    
    return aux;
}

int retorna_v(lista* a){return a->v;}


lista* retorna_prox(lista* a){return a->prox;}

void destroi_lista(lista* l){
    if (l == NULL)
        return;
    lista* aux;
    while(l->prox != NULL){
        aux = l;
        l = l->prox;
        free(aux);
    }
    free(l);
}

void ordena_lista(){

}

void imprime(lista* a){
    lista* aux = a;
    while(aux != NULL){
        printf("%d ", aux->v);
        aux = aux->prox;
    }
    printf("\n");
}
