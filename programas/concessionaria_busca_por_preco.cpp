#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Carro {
    string codigo;
    string ano;
    int preco;
};

int main(){
    
    int opcao;
    vector<Carro> carros;
    
    do{
        cout << "\n---MENU---\n";
        cout << "1 - Cadastrar carro\n";
        cout << "2 - Buscar por preco\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1: {
                Carro carro;
                cout << "Digite o codigo do carro: ";
                cin >> carro.codigo;
                cout << "Digite o ano do carro: ";
                cin >> carro.ano;
                cout << "Digite o preco do carro: ";
                cin >> carro.preco;
                carros.push_back(carro);
                break;
            }
            case 2: {
                cout << "\nDigite o preco maximo: ";
                int precoMax;
                cin >> precoMax;
                cout << "\n---CARROS ENCONTRADOS---\n";
                for(const auto& c : carros) {
                    if(c.preco <= precoMax) {
                        cout << "Codigo: " << c.codigo << ", Ano: " << c.ano << ", Preco: " << c.preco << endl;
                    }
                }
                break;
            }
            case 3:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while(opcao != 3);

    return 0;
}