#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

int pai(int k, int* a){ return a[k / 2];}

int esquerda(int k, int* a){    return a[2 * k];}

int direita(int k, int* a){ return a[2 * k + 1];}

int* inicializa(int N){
    int* hp;
    if((hp = malloc(N * sizeof(*hp))) == NULL){ 
        printf("NAo foi possivel alocar a heap\n\n");
        exit(-1);
    }
    hp[1] = 1000000;
    return hp;
}
