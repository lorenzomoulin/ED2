#include "utils.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct aresta{
    int peso, i, j;
};

int euclideana(float* x, float* y, int i, int j){
    return round( sqrt( pow(x[i] - x[j], 2.0) + pow(y[i] - y[j], 2.0)));
}

int** gera_distancias(float* x, float* y, int N){
    
    int** d;
    if ((d = malloc(sizeof(*d)*N)) == NULL) {
        printf("Erro ao alocar matriz de distancias!\n\n");
        exit(-1);
    }
    
    for (int i = 0; i < N; i++){
        if ((d[i] = malloc(sizeof(**d)*(i+1))) == NULL){
            printf("Erro ao alocar matriz de distancias!\n\n");
            exit(-1);
        }
    }
    
    for (int i = 0; i < N; i++)
        for(int j = 0; j < i+1; j++)
            d[i][j] = euclideana(x, y, i, j);   
    
    return d;
}


