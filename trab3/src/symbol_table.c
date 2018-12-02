#include "key.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Key *dp;
Key unity;
ll max = 1 << C*5;

int at(ll num){  return log2(num);}

void modified_subset_sum(Key T[N], ll num) {
    int idx = at(num);
    ll power = 1 << idx;
    dp[power] = add(dp[0], T[N - idx - 1]);
    dp[num] = add(dp[power], dp[num - power]);
}

void optimal(uc *enc_pass, Key T[N]){
    Key enc = init_key(enc_pass);
    uc temp[C];
    
    for (int i = 0; i < C - 1; i++) temp[i] = 'a';
    temp[C - 1] = 'b';
    
    unity = init_key(temp);
    temp[C - 1] = 'a';
    
    Key sum = init_key(temp);
    dp[0] = sum;
    sum = add(sum, unity);
    
    for (ll i = 1; i < max; i++){
        if (i < MAX){
            modified_subset_sum(T, i);
            if (compare(dp[i], enc)){
                print_key_char(sum);
                printf("\n");
            }
        }
        else{
            Key temp2;
            temp2 = subset_sum(sum, T);
            if(compare(temp2, enc))   print_key_char(sum);
        }
        
        sum = add(sum, unity);
    }
}

int main(int argc, char** argv){
    Key T[N];                      // A tabela T.
    printf("N: %d\n\n", N);
    if (argc != 2) {
        fprintf(stderr, "Usage: ./brute [password] < [table.txt]\n");
        exit(EXIT_FAILURE);
    }

    //password = init_key((unsigned char *) argv[1]);
    // Exibe a senha informada.
    //printf("   ");
    //print_key(password);
    //printf("\n");

    // Lê a tabela T.
    uc buffer[C+1];     // Buffer temporário.
    for (int i = 0; i < N; i++) {
        scanf("%s", buffer);
        T[i] = init_key(buffer);
    }

    // Calcula a soma de subconjunto.
    //encrypted = subset_sum(password, T);
    clock_t init = clock();
    dp = malloc(sizeof(Key)*MAX);
    optimal((uc *)argv[1], T);
    clock_t end = clock();
    printf("tempo de execucao com %d caracteres: %.3f\n", C, (double)(end - init) / CLOCKS_PER_SEC);
    // Exibe o resultado.
    
    return 0;
}
