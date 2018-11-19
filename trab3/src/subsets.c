#include <stdio.h>
#include <stdlib.h>
#include "key.h"

typedef unsigned char uc;
typedef long long ll;

void decrypt(uc *enc_pass, Key T[N]){
    Key enc = init_key(enc_pass);
    uc temp[C];
    for (int i = 0; i < C - 1; i++) temp[i] = 'a';
    temp[C - 1] = 'b';
    Key unity = init_key(temp);
    temp[C - 1] = 'a';
    Key sum = init_key(temp);
    int max = 1 << 5*C;
    for (int i = 0; i < max; i++){
        Key temp2 = init_key(sum.digit);
        temp2 = subset_sum(sum, T);
        if(compare(temp2, enc))   print_key_char(sum);
        sum = add(sum, unity);
    }
}

int main(int argc, char** argv){
    Key password;                  // A senha fornecida pelo usuário.
    Key encrypted;                 // A senha criptografada.
    Key T[N];                      // A tabela T.

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
    unsigned char buffer[C+1];     // Buffer temporário.
    for (int i = 0; i < N; i++) {
        scanf("%s", buffer);
        T[i] = init_key(buffer);
    }

    // Calcula a soma de subconjunto.
    //encrypted = subset_sum(password, T);
    decrypt(argv[1], T);
    // Exibe o resultado.
    //printf("\n   ");
    //print_key(encrypted);
    //printf("\n");
    //for(int i = 0; i < N; i++)
        //print_key(T[i]);
    
    return 0;
}
