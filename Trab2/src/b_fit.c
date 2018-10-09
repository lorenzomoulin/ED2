#include "b_fit.h"
#include <stdlib.h>
#include <stdio.h>

int* a;
int N;

void insere_min(){
    a[++N] = 1000000;
    fix_up_min(N);
}

void fix_up_min(int k){
    while (k > 1 && greater(a[k/2], a[k])) {
        exch(a[k], a[k/2]);
        k = k/2;
    }
}

void fix_down_min(int k){
    while (2*k <= N) {
    int j = 2*k;
    if (j < N && greater(a[j], a[j+1])){
      j++;
    }
    if (!greater(a[k], a[j])) {
      break;
    }
    exch(a[k], a[j]);
    k = j;
  }
}

int best_fit(int* arquivos, int N_arq){
    int num_discos = 1;
    a = inicializa(N_arq);
    for (int i = 0; i < N_arq; i++){
        if(arquivos[i] > a[1]){
            
        }
    }
    printf("%d\n", num_discos);
}
