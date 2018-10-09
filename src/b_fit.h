#ifndef B_FIT_H
#define B_FIT_H

#include "heap.h"

void insere_min();

void fix_up_min(int);

void fix_down_min(int);

int busca_chave(int, int);

int busca_menor(int, int);

int best_fit(int*, int);
#endif
