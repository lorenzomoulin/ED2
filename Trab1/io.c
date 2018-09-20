#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "io.h"

void gera_mst(aresta* a, int N, const char* problema){
    FILE* f;
    char ext[5] = ".mst";
    char arq[100];
    strcpy(arq, problema); //= strcpy(arq);
    strcat(arq,ext);
    int soma = 0;
    
    if ((f = fopen(arq, "w")) == NULL){
        printf("Erro ao abrir arquivo mst!\n");
        exit(-1);
    }
    fprintf(f, "NAME: %s\n", problema);
    fprintf(f, "TYPE: MST\n");
    fprintf(f, "DIMENSION: %d\nMST_SECTION\n", N);
    
    for (int i = 0; i < N-1; i++){
        fprintf(f, "%d %d\n", retorna_i(a, i) + 1, retorna_j(a, i) + 1);
        //printf("peso da aresta %d %d: %d\n", retorna_i(a, i) , retorna_j(a, i) , retorna_peso(a,i));
        soma += retorna_peso(a, i);
    }
    printf("peso mst: %d\n", soma);
    fprintf(f, "EOF");
    
    fclose(f);
    //free(a);
}

int calcula_pos(int i, int j, int N){
    int soma = 0;
    for (int k = 0; k < i; k++){soma+=N-1-k;}
    soma += j - i + 1;
    return soma;
}

int bs(aresta* a, int inicio, int fim, int i, int j){
    int meio = inicio/2 + fim/2;
    if (retorna_i(a, meio)==i && retorna_j(a,meio) == j)
        return retorna_peso(a, meio);
    //if (inicio == fim)
    if (retorna_i(a, meio) < i)
        bs (a, meio+1, fim, i, j);
    else if(retorna_i(a, meio) == i){
        if(retorna_j(a, meio) < j)
            bs (a, meio+1, fim, i, j);
         else
            bs (a, inicio, meio-1, i, j);
    }     
    else
        bs (a, inicio, meio-1, i, j);

}

void gera_tour(aresta* a, int N, const char* problema, float* x, float* y, int* l){
    FILE* f;
    char ext[7] = ".tour";
    char arq[100];
    strcpy(arq, problema);
    strcat(arq, ext);
    //char arq[100] = strcat(problema,".mst");
    if ((f = fopen(arq, "w")) == NULL){
        printf("Erro ao abrir arquivo tour!\n");
        exit(-1);
    }
    
    //int* tour;
    //if((tour = calloc(sizeof(*tour), 2*N))==NULL){printf("deu merda\n");}
    aresta *d = gera_distancias(x, y, N);
    int* tour = caminha(a, N);
    free(a);
    //aresta* d = gera_distancias(x, y, N);
    fprintf(f, "NAME: %s\n", problema);
    fprintf(f, "TYPE: TOUR\n");
    fprintf(f, "DIMENSION: %d\nTOUR_SECTION\n", N);
    int soma = 0;
    
   //for (int i = 0; i < N*(N-1)/2; i++){printf("distancia de %d ate %d: %d\n", retorna_i(d, i) , retorna_j(d, i) , retorna_peso(d,i));}
    
    for (int i = 0; i < N-1; i++){
        fprintf(f, "%d\n", tour[i]+1);
        if(tour[i] < tour[i+1]){
           // printf("cidade i:%d j:%d \n", retorna_i(d, calcula_pos(tour[i], tour[i+1], N)-2), retorna_j(d, calcula_pos(tour[i], tour[i+1], N))-2);
           int res = calcula_pos(tour[i], tour[i+1], N);
           //printf("%d\n", res);
           soma += retorna_peso(d, res-2);
        }
        else{
            //printf("cidade i:%d j:%d \n", retorna_i(d, calcula_pos(tour[i+1], tour[i], N)-2), retorna_j(d, calcula_pos(tour[i+1], tour[i], N))-2);
            int res = calcula_pos(tour[i+1], tour[i], N);
            //printf("%d\n", res);
            soma += retorna_peso(d, res-2);
        }
       // printf("cidade %d\n", tour[i]);
    }
    fprintf(f, "%d\n", tour[N-1]+1);
    
    int res = calcula_pos(tour[0], tour[N-1], N);
    soma += retorna_peso(d, res-2);
    printf("len tour:%d\n", soma);
    fprintf(f, "EOF");
    free (tour);
    
    free(d);
    fclose(f);

}
