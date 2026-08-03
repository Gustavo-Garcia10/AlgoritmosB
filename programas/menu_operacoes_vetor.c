#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include <time.h>

/**
 * código para tratar um MENU de opções
 */
int main(){
    int opcao;
    int vetor[TAM];
    int i, j, auxiliar;
    int qtd_elementos = 0;
    int media, soma = 0;
    float mediana;
    do {
        printf("MENU PRINCIPAL\n");
        printf("1 - Popular vetor com numeros aleatorios\n");
        printf("2 - Listar vetor populado\n");
        printf("3 - Ordenar vetor\n");
        printf("4 - Calcular media\n");
        printf("5 - Mediana\n");
        printf("6 - Maior e menor elemento\n");
        printf("7 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Populando o vetor com numeros aleatorios\n\n");
                srand(time(NULL));
                for( i = 0; i < TAM; i++){
                    vetor[i] = rand() % 100;
                    qtd_elementos++;
                }
                break;
            case 2:
                printf("Listando o vetor com numeros aleatorios\n\n");
                if (qtd_elementos > 0){
                    for ( i = 0; i < TAM; i++){
                        printf("%d ", vetor[i]);
                    }
                    printf("\n\n");
                } else {
                    printf("Vetor vazio.\n\n");
                }
                break;
                case 3:
                printf("Ordenando o vetor com numeros aleatorios\n\n");
                if (qtd_elementos > 0){
                     for ( i = 0; i < TAM - 1; i++){
                    for ( j = 0; j < TAM - 1 - i; j++){
                        if (vetor[j] > vetor[j + 1]){
                            auxiliar = vetor[j];
                            vetor[j] = vetor[j + 1];
                            vetor[j + 1] = auxiliar;
                        }
                    }
                }
                for ( i = 0; i < TAM; i++){
                    printf("%d ", vetor[i]);
                }
                    printf("\n\n");
                } else {
                    printf("Vetor vazio. Nada a ordenar.\n\n");
                }
                break;
            case 4:
                printf("Calculando media\n\n");
                if (qtd_elementos > 0){
                    for ( i = 0; i < TAM; i++){
                        soma += vetor[i];
                    }
                    media = soma / qtd_elementos;
                    printf("Media: %d\n\n", media);
                } else {
                    printf("Vetor vazio. Nada a calcular.\n\n");
                }
                break;
            case 5:
                printf("Calculando mediana\n\n");
                if (qtd_elementos > 0){
                    if (TAM % 2 == 0) {
                        mediana = (vetor[TAM / 2 - 1] + vetor[TAM / 2]) / 2.0;
                    } else {
                                mediana = vetor[TAM / 2];
                }

                    printf("Mediana: %.2f\n", mediana);
                } else {
                    printf("Vetor vazio. Nada a calcular.\n\n");
                }
                break;
            case 6:
                printf("Encontrando maior e menor elemento\n\n");
                if (qtd_elementos > 0){
                    int maior = vetor[0];
                    int menor = vetor[0];
                    for ( i = 1; i < TAM; i++){
                        if (vetor[i] > maior){
                            maior = vetor[i];
                        }
                        if (vetor[i] < menor){
                            menor = vetor[i];
                        }
                    }
                    printf("Maior elemento: %d\n", maior);
                    printf("Menor elemento: %d\n\n", menor);
                } else {
                    printf("Vetor vazio. Nada a calcular.\n\n");
                }
                break;
            case 7:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opcao invalida. Redigite\n");
        }
    } while(opcao != 7);
    return 1;
}