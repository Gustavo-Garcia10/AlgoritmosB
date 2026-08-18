#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "meusTipos.h"

int main() {
    vector<Cliente> clientes;

    int opcao, quantidadeClientes = 0;

    string codigo, idade, telefone;
    do {
    cout << "---MENU DE CLIENTES---\n";
    cout << "1 - Cadastrar cliente\n";
    cout << "2 - Listar clientes\n";
    cout << "3 - Sair\n";
    cout << "Escolha uma opcao: ";

    cin >> opcao;
    cin.ignore(); // Limpar o buffer do cin

    if (opcao == 1) {
        cout << "Digite o codigo do cliente: ";
        getline(cin, codigo);
        cout << "Digite a idade do cliente: ";
        getline(cin, idade);
        cout << "Digite o telefone do cliente: ";
        getline(cin, telefone);

        // Adicionando cliente
        clientes.push_back({codigo, idade, telefone});
        quantidadeClientes++;
    } else if (opcao == 2) {
        if (quantidadeClientes == 0) {
            cout << "Nenhum cliente cadastrado.\n";
        } else {
            for (const auto& cliente : clientes) {
                cout << "Codigo: " << cliente.codigo << endl;
                cout << "Idade: " << cliente.idade << endl;
                cout << "Telefone: " << cliente.telefone << endl;
                cout << endl;
            }
        }
    } else if (opcao == 3) {
        cout << "Saindo do programa.\n";
    } else {
        cout << "Opcao invalida. Tente novamente.\n";
    }

    } while (opcao != 3);

    return 0;
}