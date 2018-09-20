#include "utils.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "disjointset.h"
#include "list.h"


int num_visitas;

struct aresta{
    int peso, i, j;
};

int euclideana(float* x, float* y, int i, int j){
    float dx = x[i] - x[j];
    float dy = y[i] - y[j];
    return round( sqrt( dx*dx + dy*dy));
}

aresta* gera_distancias(float* x, float* y, int N){
    
    aresta* d;
    int num_arestas = N*(N-1)/2;
    if ((d = calloc(sizeof(aresta),  num_arestas)) == NULL) {
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

aresta* kruskal(int N, aresta* d){
    //aresta* d = gera_distancias(x, y, N);
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
    //free(d);
    //free(x);
    //free(y);
    return mst;
}

int* caminha(aresta* mst, int N){    
    //gerando lista de adjacencias
    lista** adj = calloc(sizeof(adj), N);
    int* tamanho = calloc(sizeof(*tamanho), N);
    bool* visitados = calloc(sizeof(*visitados), N);
    int* listatour = calloc(sizeof(*listatour), 2*N);
    
    for (int i = 0; i < N; i++){
        adj[i] = inicializa();
        tamanho[i] = 0;
        visitados[i] = false;
    }
    for (int i = 0; i < N-1; i++){
        adj[mst[i].i] = insere_comeco(mst[i].j, adj[mst[i].i]);
        tamanho [mst[i].i]++;
        adj[mst[i].j] = insere_comeco(mst[i].i, adj[mst[i].j]);
        tamanho [mst[i].j]++;
    }
    
    //int listatour[2*N]; //= malloc(sizeof(*listatour)*2*N);
    
    /*for (int i = 0; i < N; i++){
        printf("vertice %d: ", i);
        imprime(adj[i]);
    }*/
    listatour[0] = 0;
    num_visitas++;
    visitados[0] = true;
    tour(adj, 0, listatour, tamanho, visitados);
    
    free(tamanho);
    free(visitados);
    for (int i = 0; i < N; i++){
        destroi_lista(adj[i]);
        //printf("cidade %d\n", listatour[i]);
    }
    free(adj);
    return listatour;
}

void tour (lista** adj, int pos, int* listatour, int* tamanho, bool* visitados){
    if (tamanho[pos] == 1){
        if (!visitados[retorna_v(adj[pos])]){
            listatour[num_visitas++] = retorna_v(adj[pos]);
            visitados[retorna_v(adj[pos])] = true;
            //printf("numero de visitas:%d visitado: %d\n",num_visitas, listatour[num_visitas-1]);
            //tour(adj, );
        }
        tour(adj, retorna_v(adj[pos]), listatour, tamanho, visitados);
        //listatour[num_visitas++] = retorna_v(adj[pos]);
        return;
    }
    lista* aux = adj[pos];
    
    while (aux != NULL){
        if (!visitados[retorna_v(aux)]){   
            listatour[num_visitas++] = retorna_v(aux);
            visitados[retorna_v(aux)] = true;
            //printf("numero de visitas:%d visitado: %d\n",num_visitas, listatour[num_visitas-1]);

            tour(adj, retorna_v(aux), listatour, tamanho, visitados);
            
        }
        aux = retorna_prox(aux);
    }
    
    return;
}

/*int* tour_otimo(aresta* a, int N){
    

}*/


int retorna_peso(aresta* a, int i){return a[i].peso;}

int retorna_i(aresta* a, int i){return a[i].i;}

int retorna_j(aresta* a, int i){return a[i].j;}
