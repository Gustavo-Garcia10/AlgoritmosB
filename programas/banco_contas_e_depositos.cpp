#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Conta{
    string numeroDaConta;
    float saldo;
};

int main(){


    int opcao;
    vector<Conta> contas;

    do{

        cout << "\n---MENU---\n";
        cout << "1 - Cadastrar conta (saldo inicial)\n";
        cout << "2 - Depositar\n";
        cout << "3 - Mostrar todas as contas\n";
        cout << "4 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1: {
                Conta conta;
                cout << "Digite o numero da conta: ";
                cin >> conta.numeroDaConta;
                cout << "Digite o saldo inicial da conta: ";
                cin >> conta.saldo;
                contas.push_back(conta);
                break;
            }
            case 2: {
                cout << "\n----CONTAS E SALDOS CADASTRADOS----\n";
                string numeroConta;
                float valorDeposito;

                for(const auto& c : contas) {
                    cout << "Numero da conta: " << c.numeroDaConta << ", Saldo: " << c.saldo << endl;
                }

                cout << "Digite o numero da conta: ";
                cin >> numeroConta;
                cout << "Digite o valor do deposito: ";
                cin >> valorDeposito;

                for(auto& c : contas) {
                    if(c.numeroDaConta == numeroConta) {
                        c.saldo += valorDeposito;
                        cout << "Deposito realizado com sucesso!\n";
                        break;
                    }
                }
                break;
            }
            case 3: {
                cout << "\n---CONTAS CADASTRADAS---\n";
                for(const auto& c : contas) {
                    cout << "Numero da conta: " << c.numeroDaConta << ", Saldo: " << c.saldo << endl;
                }
                break;
            }
            case 4:
                cout << "Saindo do sistema\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while(opcao != 4);
    return 0;
}