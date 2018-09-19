#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "utils.h"
#include <time.h>

typedef struct io {
    char name[100];
    char type[3];
    int dimension;
    float* x;
    float* y;
} tIO;

int main(int argc, char** argv) {
    clock_t inicio = clock();
    char dimension[100];
    char buffer[100];
    char coordX[100], coordY[100];
    char* diretorio = argv[1];
    tIO arquivo;
    FILE *arq = fopen(diretorio, "r");

    if (argc < 2) { // caso nao coloque o nome do arquivo de entrada
        printf("Não colocou o nome do arquivo.");
        exit(1);
    }
    if (arq == NULL) { // caso nao consiga abrir o arquivo
        printf("Não foi possível abrir o arquivo.");
        exit(1);
    } else {
        //le o nome
        fscanf(arq, "NAME: %s\n", arquivo.name);
        //pula as linhas de comentario
        do {
            fscanf(arq, "%s", buffer);
        } while (strcmp("TYPE:", buffer) != 0);
        //le o tipo
        fscanf(arq, "%s\n", arquivo.type);
        //le a dimensao
        fscanf(arq, "DIMENSION: %s\n", dimension);
        //pula linha edge weight type
        fgets(buffer, 100, arq);
        //pula linha do node coord section
        fgets(buffer, 100, arq);

        arquivo.dimension = atoi(dimension);

        printf("%s\n", arquivo.name);
        printf("%s\n", arquivo.type);
        printf("%d\n", arquivo.dimension);

        float* x = malloc(arquivo.dimension * sizeof (x));
        float* y = malloc(arquivo.dimension * sizeof (y));

        int idx = 0;
        while (fscanf(arq, "%s %s %s", &buffer, &coordX, &coordY) == 3) {
            x[idx] = atof(coordX);
            y[idx] = atof(coordY);
           // printf("%d %.1f %.1f\n", idx, x[idx], y[idx]);
            idx++;
        }
        fclose(arq);
        aresta* d = gera_distancias(x, y, arquivo.dimension);
        aresta* mst = kruskal(arquivo.dimension, d);
        gera_mst(mst, arquivo.dimension, arquivo.name);
        free(d);
        int* tour; //= calloc(sizeof(*tour), 2*arquivo.dimension);
        //if (tour == NULL){printf("deu merda\n");}
        //aresta* g = gera_distancias(x, y, arquivo.dimension);
        gera_tour(mst, arquivo.dimension, arquivo.name, x, y, tour);
        //free(g);
        free(x);
        free(y);
        clock_t fim = clock();
        printf("tempo de execução: %.3lf\n", 1000.0*(fim-inicio)/CLOCKS_PER_SEC);

    }
    
    return (EXIT_SUCCESS);
}
