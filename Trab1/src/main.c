#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct city {
    int node_id;
    float x;
    float y;
} tCity;

typedef struct io {
    char* name;
    char* type;
    int dimension;
} tIO;

int main(int argc, char** argv) {
    
    tIO input;
    char nome[100];
    char type[100];
    char dimension[100];
    char buffer[100];
    char num[100], x[100], y[100];
    char* diretorio = argv[1];
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
        fscanf(arq, "NAME: %s\n", nome);
        //pula as linhas de comentario
        do {
            fscanf(arq, "%s", buffer);
        } while (strcmp("TYPE:", buffer) != 0);
        //le o tipo
        fscanf(arq, "%s\n", type);
        //le a dimensao
        fscanf(arq, "DIMENSION: %s\n", dimension);
        //pula linha edge weight type
        fgets(buffer, 100, arq);
        //pula linha do node coord section
        fgets(buffer, 100, arq);

        printf("%s\n", nome);
        printf("%s\n", type);
        printf("%s\n", dimension);

        tCity cidades[atoi(dimension)];
        int idx = 0;
        while (fscanf(arq, "%s %s %s", &num, &x, &y) == 3) {
            cidades[idx].node_id = atoi(num);
            cidades[idx].x = atof(x);
            cidades[idx].y = atof(y);
            printf("%d %.1f %.1f\n", cidades[idx].node_id, cidades[idx].x, cidades[idx].y);
            idx++;
        }

    }
    fclose(arq);
    return (EXIT_SUCCESS);
}

