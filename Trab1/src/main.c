#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int main(int argc, char** argv){
    
    int N = atoi(argv[1]);
    int num_arestas = N*(N-1)/2;
    float* x;
    float* y;
    x = malloc(N*sizeof(*x));
    y = malloc(N*sizeof(*y));
    for (int i = 0; i < N; i++)
        scanf("%f %f\n", &x[i], &y[i]);
    printf("vetor x: ");
    for (int i = 0; i < N; i++)
        printf("%f ", x[i]);
    printf("\nvetor y: ");
    for (int i = 0; i < N; i++)
        printf("%f ", y[i]);
    
    printf("\n");
    //aresta* d = gera_distancias(x, y, N);

    /*for (int i = 0; i < num_arestas; i++){
        printf("Aresta %d %d: %d\n", retorna_i(d,i), retorna_j(d,i), retorna_peso(d,i));
        
    }*/
    printf("\n");
    //quicksort(d, 0, num_arestas);
    aresta* d = kruskal(x, y, N);
    for (int i = 0; i < N-1; i++){
        printf("Aresta %d %d: %d\n", retorna_i(d,i), retorna_j(d,i), retorna_peso(d,i));
        
    }
    
    gera_mst(d, N, "berlin52");
    
    return 0;
}
