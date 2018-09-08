#include "utils.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "disjointset.h"

struct aresta{
    int peso, i, j;
};

int euclideana(float* x, float* y, int i, int j){
    return round( sqrt( pow(x[i] - x[j], 2.0) + pow(y[i] - y[j], 2.0)));
}

aresta* gera_distancias(float* x, float* y, int N){
    
    aresta* d;
    int num_arestas = N*(N-1)/2;
    if ((d = malloc(sizeof(*d)*num_arestas)) == NULL) {
        printf("Erro ao alocar vetor de arestas!\n\n");
        exit(-1);
    }

    int pos = 0;
    
        
    for (int i = 0; i < N-1; i++){
        for (int j = i + 1; j < N; j++){
            d[pos].peso = euclideana(x, y, i, j);
            d[pos].i = i;
            d[pos].j = j;
            pos++;
        }
    }
   
    /*for (int i = 0; i < num_arestas; i++){
        printf("Aresta %d %d: %d\n", d[i].i, d[i].j, d[i].peso);
        
    }*/
    
    return d;
}

//bool compara_aresta(aresta a, aresta b) {return a.peso < b.peso;}

void quicksort(aresta* arestas, int inicio, int fim){
    int i, j;
    i = inicio;
    j = fim-1;
    
    aresta pivo, aux;
    pivo = arestas[inicio/2 + fim/2];
    
    while(i <= j)
	{
		while(arestas[i].peso < pivo.peso && i < fim)
		{
			i++;
		}
		while(arestas[j].peso > pivo.peso && j > inicio)
		{
			j--;
		}
		if(i <= j)
		{
			aux = arestas[i];
			arestas[i] = arestas[j];
			arestas[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio)
		quicksort(arestas, inicio, j+1);
	if(i < fim)
		quicksort(arestas, i, fim);

}

aresta* kruskal(float* x, float* y, int N){
    aresta* d = gera_distancias(x, y, N);
    int num_arestas = N*(N-1)/2;
    quicksort(d, 0, num_arestas);
    int* altura;
    if ((altura = malloc(sizeof(*altura)*N)) == NULL){
        printf("Erro ao alocar altura!\n");
        exit(-1);
    }
    
    aresta* mst = malloc(sizeof(*mst)*(N-1));
    int qtd = 0;
    
    int* v = inicia_conjunto_vertices(N, altura);
    
    for (int i = 0; i < num_arestas && qtd < N-1; i++){
        if (find(d[i].i, v) != find(d[i].j, v)){
            mst[qtd] = d[i];
            qtd++;
            ds_union(d[i].i, d[i].j, v, altura);
        }
    }
    free(v);
    free(altura);
    free(d);
    free(x);
    free(y);
    return mst;
}

void destroy(aresta* a){free(a);}

int retorna_peso(aresta* a, int i){return a[i].peso;}

int retorna_i(aresta* a, int i){return a[i].i;}

int retorna_j(aresta* a, int i){return a[i].j;}

