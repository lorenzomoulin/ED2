#ifndef UTILS_H
#define UTILS_H
#include <stdbool.h>
#include "list.h"

typedef struct aresta aresta;

/* Calcula distancia euclideana da cidade i até a cidade j no R2
*inputs: vetores de coordenadas x e y e as cidades i e j;
*output: distância arredondada
*pre-condicao: os vetores devem possuir pelo menos 2 elementos
*pos-condicao: nenhuma
*/
int euclideana(float* x, float* y, int i, int j);

/* Gera vetor de aresta com as distancias de todas as cidades considerando que d(i,j) = d(j,i)
*inputs: vetores de coordenadas x e y e quantidade de cidades
*output: vetor com todas as distancias
*pre-condicao: os vetores devem possuir pelo menos 2 elementos
*pos-condicao: vetor de inteiros devidamente alocado com N*(N-1)/2 elementos
*/
aresta* gera_distancias(float* x, float* y, int N);

/* Ordena vetor de arestas com relacao ao peso
*inputs: vetor de arestas e posicoes inicial e final
*output: nenhum
*pre-condicao: vetor nao vazio, 0 <= inicio <=fim
*pos-condicao: vetor ordenado
*/
void quicksort(aresta* arestas, int inicio, int fim);

int retorna_peso(aresta* a, int i);

int retorna_i(aresta* a, int i);

int retorna_j(aresta* a, int i);

/* Gera vetor de arestas que compoem a MST
*inputs: numero de vertices (N), vetor de arestas com todas as arestas do grafo
*output: vetor de arestas da MST
*pre-condicao: N > 0 e d nao vazio e ordenado por peso
*pos-condicao: vetor de arestas alocado
*/
aresta* kruskal(int N, aresta* d);

/*Gera vetor de vertices que fazem parte do tour (sem repeticao)
*inputs: vetor de arestas da MST e numero de vertices
*output: vetor de vertices do tour
*pre-condicao: mst nao vazia e de tamanho N - 1, N > 0
*pos-condicao: vetor de int alocado e de tamanho N
*/
int* caminha(aresta* mst, int N);
/* Funcao que caminha recursivamente em vetor de lista de vertices chamada dentro da caminha
*inputs: vetor de lista de vertices, 
*/
void tour(lista** adj, int pos, int* listatour, int* tamanho, bool* visitados);

#endif
