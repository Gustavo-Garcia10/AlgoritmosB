#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 4

int main(){
    int vetor[TAMANHO];
    
    printf("Ola turma de algoritmos!\n");
    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o valor do elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    for (int i = 0; i < TAMANHO; i++){
        printf("O valor do elemento %d: %d\n", i + 1, vetor[i]);
    }

    return 0;
}