#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "io.h"

void gera_mst(aresta* a, int N, const char* problema){
    FILE* f;
    //char arq[100] = strcat(problema,".mst");
    if ((f = fopen("berlin52.mst", "w")) == NULL){
        printf("Erro ao abrir arquivo mst!\n");
        exit(-1);
    }
    fprintf(f, "NAME: %s\n", problema);
    fprintf(f, "TYPE: MST\n");
    fprintf(f, "DIMENSION: %d\nMST_SECTION\n", N);
    
    for (int i = 0; i < N-1; i++){
        fprintf(f, "%d %d\n", retorna_i(a, i) + 1, retorna_j(a, i) + 1);
        printf("peso da aresta %d %d: %d\n", retorna_i(a, i) + 1, retorna_j(a, i) + 1, retorna_peso(a,i));
    }
    fprintf(f, "EOF");
    
    fclose(f);
    //free(a);
}

void gera_tour(aresta* a, int N, const char* problema){
    FILE* f;
    
    //char arq[100] = strcat(problema,".mst");
    if ((f = fopen("berlin52.tour", "w")) == NULL){
        printf("Erro ao abrir arquivo tour!\n");
        exit(-1);
    }
    int* tour = caminha(a, N);
    fprintf(f, "NAME: %s\n", problema);
    fprintf(f, "TYPE: MST\n");
    fprintf(f, "DIMENSION: %d\nTOUR_SECTION\n", N);
    
    for (int i = 0; i < N; i++){
        fprintf(f, "%d %d\n", retorna_i(a, i) + 1, retorna_j(a, i) + 1);
        printf("peso da aresta %d %d: %d\n", retorna_i(a, i) + 1, retorna_j(a, i) + 1, retorna_peso(a,i));
    }
    fprintf(f, "EOF");
    
    fclose(f);

}
