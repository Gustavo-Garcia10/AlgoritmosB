#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Funcionario {
    string codigo;
    int idade;
    float salario;
};

int main() {
    int opcao;
    int quantidadeFuncionarios = 0;
    vector<Funcionario> funcionarios;
    Funcionario novoFuncionario;

    do {
        cout << "\n----MENU----\n";
        cout << "1 - Cadastrar funcionario\n";
        cout << "2 - Contar e exibir quantos funcionarios tem mais de 40 anos e ganham mais de R$ 5.000,00.\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                novoFuncionario = Funcionario();

                cout << "Digite o codigo do funcionario: ";
                cin >> novoFuncionario.codigo;

                cout << "Digite a idade do funcionario: ";
                cin >> novoFuncionario.idade;

                cout << "Digite o salario do funcionario: ";
                cin >> novoFuncionario.salario;

                funcionarios.push_back(novoFuncionario);

                if (novoFuncionario.idade > 40 && novoFuncionario.salario > 5000) {
                    quantidadeFuncionarios++;
                }

                cout << "\nFuncionario registrado\n";
                break;
            }

            case 2: {
                cout << "Quantidade de funcionarios com mais de 40 anos e salario superior a 5000 reais: "
                     << quantidadeFuncionarios << endl;

                cout << "Funcionarios que atendem ao criterio:\n";
                bool encontrou = false;

                for (int i = 0; i < funcionarios.size(); i++) {
                    if (funcionarios[i].idade > 40 && funcionarios[i].salario > 5000) {
                        cout << "\nCodigo do funcionario: " << funcionarios[i].codigo << endl;
                        cout << "Idade do funcionario: " << funcionarios[i].idade << endl;
                        cout << "Salario do funcionario: " << funcionarios[i].salario << endl;
                        encontrou = true;
                    }
                }

                if (!encontrou) {
                    cout << "Nenhum funcionario encontrado.\n";
                }
                break;
            }

            case 3:
                cout << "Saindo do programa\n";
                break;

            default:
                cout << "Opcao invalida.\n";
                break;
        }
    } while (opcao != 3);

    return 0;
}
