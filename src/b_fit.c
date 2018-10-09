#include "b_fit.h"
#include "w_fit.h"
#include <stdlib.h>
#include <stdio.h>

int* a;
int N;
const int INFINITO = 9999999;

void insere_min(int espaco){
    a[++N] = espaco;
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

int busca_chave(int k, int chave){
    if (a[k] == chave)  return k;
    if (k > N)  return -1;
    int esq = busca_chave(2 * k, chave);
    int dir = busca_chave(2 * k + 1, chave);
    return (esq == -1)?dir:esq;
}

int busca_menor(int k, int peso){
    if (k > N) return INFINITO;
    if (a[k] >= peso)   return a[k];
    int esq = busca_menor(2 * k, peso);
    int dir = busca_menor(2 * k + 1, peso);

    return (esq < dir)?esq:dir;
}

int best_fit(int* arquivos, int N_arq){
    int num_discos = 1;
    a = inicializa(N_arq);
    N++;
    imprime(a, N);
    for (int i = 0; i < N_arq; i++){
        
        int menor_possivel = busca_menor(1, arquivos[i]);
        if (menor_possivel == INFINITO){
            insere_min(1000000 - arquivos[i]);
            num_discos++;                
        }
        else{
            int pos = busca_chave(1, menor_possivel);
            a[pos] -= arquivos[i];
            fix_up_min(pos);
        }
        imprime(a, N);
        
    }
    N = 0;
    printf("%d\n", num_discos);
}
