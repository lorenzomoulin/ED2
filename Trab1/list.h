#ifndef LIST_H
#define LIST_H

typedef struct lista lista;

lista* inicializa();

lista* retorna_ultimo(lista* l);

lista* insere_comeco(int j, lista* l);

lista* insere_cidade(int j, lista* l);

int retorna_v(lista* a);

lista* retorna_prox(lista* a);

void destroi_lista(lista* l);

void imprime(lista* a);

#endif
