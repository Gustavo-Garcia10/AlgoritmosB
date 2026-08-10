#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

#include "meusTipos.h"


// Converte uma hora no formato HH:MM para minutos
int converterParaMinutos(const string &hora)
{
    int horas = stoi(hora.substr(0, 2));
    int minutos = stoi(hora.substr(3, 2));

    return horas * 60 + minutos;
}


int main()
{
    vector<Veiculo> garagem;

    int opcao;

    string placa, cor, horaEntrada, horaSaida;


    do
    {
        cout << "\nMenu de opcoes:\n";
        cout << "1 - Adicionar veiculo\n";
        cout << "2 - Listar veiculos\n";
        cout << "3 - Saida do veiculo\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";

        cin >> opcao;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch (opcao)
        {
            case 1:

                cout << "Digite a placa do veiculo: ";
                getline(cin, placa);

                cout << "Digite a cor do veiculo: ";
                getline(cin, cor);

                cout << "Digite a hora de entrada do veiculo [HH:MM]: ";
                getline(cin, horaEntrada);


                // Adiciona o veiculo na garagem
                garagem.push_back({placa, cor, horaEntrada, ""});

                cout << "\nVeiculo adicionado com sucesso!\n";

                break;

            case 2:

                cout << "\nVeiculos na garagem:\n";

                if (garagem.empty())
                {
                    cout << "Nenhum veiculo na garagem.\n";
                }
                else
                {
                    for (int i = 0; i < garagem.size(); i++)
                    {
                        cout << "\nPlaca: "
                             << garagem[i].placa;

                        cout << "\nCor: "
                             << garagem[i].cor;

                        cout << "\nHora de entrada: "
                             << garagem[i].horaEntrada;

                        cout << "\n";
                    }
                }

                break;

            case 3:
            {
                bool encontrado = false;


                cout << "Digite a placa do veiculo que esta saindo: ";
                getline(cin, placa);


                // Procura o veiculo
                for (int i = 0; i < garagem.size(); i++)
                {
                    if (garagem[i].placa == placa)
                    {
                        encontrado = true;

                        // Pede a hora de saida
                        cout << "Digite a hora de saida do veiculo [HH:MM]: ";
                        getline(cin, horaSaida);

                        // Converte entrada e saida para minutos
                        int entrada =
                            converterParaMinutos(garagem[i].horaEntrada);

                        int saida =
                            converterParaMinutos(horaSaida);

                        // Caso tenha atravessado a meia-noite
                        if (saida < entrada)
                        {
                            saida += 1440;
                        }

                        int tempoPermanencia = saida - entrada;


                        int horas = tempoPermanencia / 60;

                        int minutos = tempoPermanencia % 60;


                        // Cada 60 minutos custa R$ 5
                        // Minutos adicionais contam como outra hora
                        int quantidadeHoras =
                            ceil(tempoPermanencia / 60.0);


                        // Cobra pelo menos uma hora
                        if (quantidadeHoras < 1)
                        {
                            quantidadeHoras = 1;
                        }


                        double valorTotal =
                            quantidadeHoras * 5.0;


                        cout << "\n===== SAIDA DO VEICULO =====\n";

                        cout << "Placa: "
                             << garagem[i].placa << "\n";

                        cout << "Hora de entrada: "
                             << garagem[i].horaEntrada << "\n";

                        cout << "Hora de saida: "
                             << horaSaida << "\n";

                        cout << "Tempo de permanencia: "
                             << horas << " horas e "
                             << minutos << " minutos\n";

                        cout << "Quantidade de horas cobradas: "
                             << quantidadeHoras << "\n";

                        cout << "Valor total a pagar: R$ "
                             << valorTotal << "\n";


                        garagem.erase(garagem.begin() + i);

                        cout << "\nVeiculo removido da garagem com sucesso!\n";


                        break;
                    }
                }


                // Se nao encontrou a placa
                if (!encontrado)
                {
                    cout << "\nVeiculo nao encontrado na garagem.\n";
                }

                break;
            }

            case 0:

                cout << "Saindo do programa.\n";

                break;

            default:

                cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);

    return 1;
}