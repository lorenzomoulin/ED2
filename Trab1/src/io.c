#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

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
    for (int i = 0; i < N-1; i++)
        fprintf(f, "%d %d\n", retorna_i(a, i), retorna_j(a, i));
    fprintf(f, "EOF");
    
    fclose(f);
    free(a);
}
