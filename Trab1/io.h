#ifndef IO_H
#define IO_H
#include "utils.h"

void gera_mst(aresta* a, int N, const char* problema);

int calcula_pos(int i, int j, int N);

int bs(aresta* a, int inicio, int fim, int i, int j);

void gera_tour(aresta* a, int N, const char* problema, float* x, float* y, int* l);

#endif
