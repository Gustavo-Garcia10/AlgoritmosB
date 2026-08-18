#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estrutura que representa um produto
struct Produto {
    string codigo;
    int quantidade;
    float preco;
};

int main() {

    vector<Produto> produtos;
    int opcao;
    Produto novoProduto;
    
    do {
        cout << "\n---MENU---\n";
        cout << "1 - Cadastrar produto\n";
        cout << "2 - Exibir valor total investido\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            // Cadastrar produto
            case 1: {
                

                cout << "\nDigite o codigo do produto: ";
                cin >> novoProduto.codigo;

                cout << "Digite a quantidade: ";
                cin >> novoProduto.quantidade;

                cout << "Digite o preco: R$ ";
                cin >> novoProduto.preco;

                // Adiciona o produto ao vetor
                produtos.push_back(novoProduto);

                cout << "\nProduto cadastrado com sucesso!\n";

                break;
            }

            // Exibir valor total investido
            case 2: {
                float total = 0;

                // Percorre todos os produtos
                for (const Produto& produto : produtos) {
                    total += produto.quantidade * produto.preco;
                }

                cout << "\nValor total investido no estoque: R$ "
                     << total << endl;

                break;
            }

            // Sair
            case 3:
                cout << "\nSaindo do programa...\n";
                break;

            default:
                cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 3);

    return 0;
}