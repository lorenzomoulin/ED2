#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    
    int N = atoi(argv[1]);
    float x[N], y[N];
    for (int i = 0; i < N; i++)
        scanf("%f %f\n", &x[i], &y[i]);
    printf("vetor x: ");
    for (int i = 0; i < N; i++)
        printf("%f ", x[i]);
    printf("\nvetor y: ");
    for (int i = 0; i < N; i++)
        printf("%f ", y[i]);
    
    int** d = gera_distancias(x, y, N);
    return 0;
}
