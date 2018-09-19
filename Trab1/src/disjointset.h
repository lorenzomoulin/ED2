#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#include <stdbool.h>



int* inicia_conjunto_vertices(int tamanho, int* altura);

int find(int i, int* v_set);

void ds_union(int p, int q, int* v_set, int* altura);

#endif
