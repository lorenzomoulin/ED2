#include <stdio.h>
#include <stdlib.h>
#include "w_fit.h"
#include "b_fit.h"

int compare(const void* a, const void* b){    return ( *(int*)b - *(int*)a );}

int main(int argc, char** argv){
    int N_arq;
    unsigned long long min_discos = 0;
    
    FILE* arq;
    if ((arq = fopen(argv[1], "r")) == NULL){   printf("ERRO AO LER ARQUIVO\n");   return -1;}
    
    fscanf(arq, "%d", &N_arq);
    int arquivos[N_arq];
    for (int i = 0; i < N_arq; i++){ fscanf(arq, "%d", &arquivos[i]); min_discos += arquivos[i];}
    //for (int i = 0; i < N_arq; i++){ printf("%d ", arquivos[i]);}
    min_discos /= 1000000;
    printf("minimo de discos: %lld\n\n", min_discos);
    //inicia heap com um disco
    //insere(1000000);
    
    //resolve worst-fit
    printf("UNORDERED WORSTFIT\n");
    worst_fit(arquivos, N_arq);
    printf("UNORDERED BESTFIT\n");
    best_fit(arquivos, N_arq);
    qsort(arquivos, N_arq, sizeof(int), compare);
    printf("WORSTFIT\n");
    worst_fit(arquivos, N_arq);
    printf("BESTFIT\n");
    best_fit(arquivos, N_arq);
    
    return 0;
}
