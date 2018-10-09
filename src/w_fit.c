#include "w_fit.h"
#include <stdlib.h>
#include <stdio.h>

int* a;
int N;

void imprime(int* b, int n){    for(int i = 1; i <= n; i++)  printf("%d ", b[i]);printf("\n");}
void insere_max(){
    a[++N] = 1000000;
    fix_up_max(N);
}

void fix_up_max(int k){
    while (k > 1 && less(a[k/2], a[k])) {
        exch(a[k], a[k/2]);
        k = k/2;
    }
}

void fix_down_max(int k){
    while (2*k <= N) {
    int j = 2*k;
    if (j < N && less(a[j], a[j+1])){
      j++;
    }
    if (!less(a[k], a[j])) {
      break;
    }
    exch(a[k], a[j]);
    k = j;
  }
}

int worst_fit(int* arquivos, int N_arq){
    int num_discos = 1;
    a = inicializa(N_arq);
    N++;
    imprime(a, N);
    for (int i = 0; i < N_arq; i++){
        if (arquivos[i] > a[1]){    insere_max();    num_discos++;}
        a[1] -= arquivos[i];
        fix_down_max(1);
        
        imprime(a, N);
    }
    N = 0;
    printf("%d\n", num_discos);
}

