#include <stdio.h> 
#include <stdlib.h>
typedef long long ll;

long long len = 1 << 32;

void gray(int n, int * g){
    
    //gray de 1 bit
    g[0] = 0; g[1] = 1;
    int i = 2;
    //printf("len: %d\n", len);
    //gera gray de 2 bits ate n
    for (i = 2; i <= n; i++){
        //printf("i: %d\n", i);
        //soma 2^(i-1) a todas as posicoes entre 2^(i-1) e 2^i - 1
        for (int j = (1 << (i - 1)); j < (1 << i); j++){
            //printf("j: %d, ", j);
            
            g[j] = g[(1 << i) - 1 - j] + (1 << (i - 1));
            //printf("g[%d]: %d \n",j, g[j]);
        }
    }
    //converte todos numeros gerados para binario e testa se eh valido
    for (i = 0; i < len; i++){
        int binary[n];
        for (int j = n-1; j >= 0; j--){
            int k = g[i] >> j;
            if (k & 1)
                binary[j] = 1;
            else
                binary[j] = 0;
        }
        for (int j = n - 1; j >= 0; j--)    printf("%d", binary[j]);
        printf("\n");
    }
    //for (int i = 0; i < len; i++)    printf("%d ", g[i]);
}

int main(){
    
    
    int *g = malloc(sizeof(int)*len);
    gray(32, g);
    printf("\n");
    return 0;
}
