#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Aluno {
    string codigo;
    float peso;
    float altura;
};

int main(){
    

    int opcao;
    vector<Aluno> alunos;

    do{

        cout << "\n---MENU---\n";
        cout << "1 - Cadastrar aluno\n";
        cout << "2 - Buscar aluno mais alto\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1: {
                Aluno aluno;
                cout << "Digite o codigo do aluno: ";
                cin >> aluno.codigo;
                cout << "Digite o peso do aluno: ";
                cin >> aluno.peso;
                cout << "Digite a altura do aluno: ";
                cin >> aluno.altura;
                alunos.push_back(aluno);
                break;
            }
            case 2: {
                float maiorAltura = 0;
                for(const auto& a : alunos) {
                    if(a.altura > maiorAltura) {
                        maiorAltura = a.altura;
                    }
                }
                for(const auto& a : alunos) {
                    if(a.altura == maiorAltura) {
                        cout << "Codigo: " << a.codigo << ", Peso: " << a.peso << ", Altura: " << a.altura << endl;
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