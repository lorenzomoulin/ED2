#ifndef UTILS_H
#define UTILS_H

typedef struct aresta aresta;

/* Calcula distancia euclideana da cidade i até a cidade j no R2
*inputs: vetores de coordenadas x e y e as cidades i e j;
*output: distância arredondada
*pre-condicao: os vetores devem possuir pelo menos 2 elementos
*pos-condicao: nenhuma
*/
int euclideana(float* x, float* y, int i, int j);

/* Gera matriz simetrica com as distancias de todas as cidades considerando que d(i,j) = d(j,i)
*inputs: vetores de coordenadas x e y e quantidade de cidades
*output: matriz com todas as distancias
*pre-condicao: os vetores devem possuir pelo menos 2 elementos
*pos-condicao: matriz de inteiros devidamente alocada com N*(N-1)/2 elementos
*/
int** gera_distancias(float* x, float* y, int N);

/**/

#endif
