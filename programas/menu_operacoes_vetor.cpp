#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define TAM 10

/**
 * Programa para tratar um MENU de opções
 */
int main() {

    int opcao;
    int vetor[TAM];

    int i, j;
    int auxiliar;

    int qtd_elementos = 0;

    int media;
    int soma;

    float mediana;

    srand(time(NULL));

    do {

        cout << "MENU PRINCIPAL\n";
        cout << "1 - Popular vetor com numeros aleatorios\n";
        cout << "2 - Listar vetor populado\n";
        cout << "3 - Ordenar vetor\n";
        cout << "4 - Calcular media\n";
        cout << "5 - Mediana\n";
        cout << "6 - Maior e menor elemento\n";
        cout << "7 - Sair\n";
        cout << "Opcao: ";

        cin >> opcao;

        switch (opcao) {

            case 1:

                cout << "\nPopulando o vetor com numeros aleatorios\n\n";

                for (i = 0; i < TAM; i++) {

                    vetor[i] = rand() % 100;
                }

                qtd_elementos = TAM;

                break;

            case 2:

                cout << "\nListando o vetor\n\n";

                if (qtd_elementos > 0) {

                    for (i = 0; i < TAM; i++) {
                        cout << vetor[i] << " ";
                    }

                    cout << "\n\n";

                } else {

                    cout << "Vetor vazio.\n\n";
                }

                break;

            case 3:

                cout << "\nOrdenando o vetor\n\n";

                if (qtd_elementos > 0) {

                    for (i = 0; i < TAM - 1; i++) {

                        for (j = 0; j < TAM - 1 - i; j++) {

                            if (vetor[j] > vetor[j + 1]) {

                                auxiliar = vetor[j];

                                vetor[j] = vetor[j + 1];

                                vetor[j + 1] = auxiliar;
                            }
                        }
                    }

                    for (i = 0; i < TAM; i++) {
                        cout << vetor[i] << " ";
                    }

                    cout << "\n\n";

                } else {

                    cout << "Vetor vazio. Nada a ordenar.\n\n";
                }

                break;

            case 4:

                cout << "\nCalculando media\n\n";

                if (qtd_elementos > 0) {

                    soma = 0;

                    for (i = 0; i < TAM; i++) {
                        soma += vetor[i];
                    }

                    media = soma / qtd_elementos;

                    cout << "Media: " << media << "\n\n";

                } else {

                    cout << "Vetor vazio. Nada a calcular.\n\n";
                }

                break;

            case 5:

                cout << "\nCalculando mediana\n\n";

                if (qtd_elementos > 0) {

                    if (TAM % 2 == 0) {

                        mediana =
                            (vetor[TAM / 2 - 1] + vetor[TAM / 2]) / 2.0;

                    } else {

                        mediana = vetor[TAM / 2];
                    }

                    cout << "Mediana: " << mediana << "\n\n";

                } else {

                    cout << "Vetor vazio. Nada a calcular.\n\n";
                }

                break;

            case 6:

                cout << "\nEncontrando maior e menor elemento\n\n";

                if (qtd_elementos > 0) {

                    int maior = vetor[0];
                    int menor = vetor[0];

                    for (i = 1; i < TAM; i++) {

                        if (vetor[i] > maior) {
                            maior = vetor[i];
                        }

                        if (vetor[i] < menor) {
                            menor = vetor[i];
                        }
                    }

                    cout << "Maior elemento: " << maior << "\n";
                    cout << "Menor elemento: " << menor << "\n\n";

                } else {

                    cout << "Vetor vazio. Nada a calcular.\n\n";
                }

                break;

            case 7:

                cout << "\nSaindo do programa...\n";

                break;

            default:

                cout << "\nOpcao invalida. Redigite.\n\n";
        }

    } while (opcao != 7);

    return 0;
}