#include "disjointset.h"
#include <stdlib.h>


int* inicia_conjunto_vertices(int tamanho, int* altura){
    
    int* v_set = malloc(sizeof(*v_set)*tamanho);
    for (int i = 0; i < tamanho; i++){
        v_set[i] = i;
        altura[i] = 1;
    }
    
    return v_set;
}

int find(int i, int* v_set){

    while(i != v_set[i]){
        v_set[i] = v_set[v_set[i]];
        i = v_set[i];
    }
    
    return i;
}


void ds_union(int p, int q, int* v_set, int* altura) {
  int i = find(p, v_set); // Pendure a arvore menor sob a maior.
  int j = find(q, v_set); // Profundidade de ? acessos.
  if (i == j) return;
  if (altura[i] < altura[j]) { altura[i] = j; altura[j] += altura[i]; }
  else               { altura[j] = i; altura[i] += altura[j]; }
}
  
