#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Jogador {
    string idDoJogador;
    float pontos;
};

int main(){
    int opcao;
    vector<Jogador> jogadores;
    Jogador novoJogador;

    do{

        cout << "\n----MENU----\n";
        cout << "1 - Cadastrar jogador\n";
        cout << "2 - Buscar jogador por ID\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao){

            case 1: {
                novoJogador = Jogador();

                cout << "Digite o ID do jogador: ";
                cin >> novoJogador.idDoJogador;

                cout << "Digite os pontos do jogador: ";
                cin >> novoJogador.pontos;

                jogadores.push_back(novoJogador);

                cout << "Jogador registrado\n";

                break;
            }

            case 2: {
                if (jogadores.empty()){
                    cout << "Nenhum jogador registrado.\n";
                    break;
                }
                else{
                    string idBusca;
                    bool encontrado = false;
                    cout << "Digite o ID do jogador que queira encontrar: ";
                    cin >> idBusca;
                   
                    for (int i = 0; i < jogadores.size(); i++) {
                        if (jogadores[i].idDoJogador == idBusca){
                            cout << "Jogador encontrado\n";
                            cout << "ID: " << jogadores[i].idDoJogador << endl;
                            cout << "Pontos: " << jogadores[i].pontos << endl;
                            
                            encontrado = true;
                            break;
                        }
                    }

                    if (!encontrado) {
                        cout << "Jogador nao encontrado\n";
                    }
                }
                break;
            }

            case 3: {
                cout << "Saindo do programa.\n";
                break;
            }
        }


    } while (opcao != 3);

    return 0;
}