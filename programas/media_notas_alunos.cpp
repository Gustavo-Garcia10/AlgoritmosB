#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Aluno {
    string matricula;
    float nota1;
    float nota2;
};

int main(){

    vector<Aluno> alunos;
    int opcao;
    Aluno novoAluno;
    float media;

    do {
        cout << "\n---MENU---\n";
        cout << "1 - Cadastrar aluno\n";
        cout << "2 - Listar alunos com as medias\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            // Cadastrar aluno
            case 1: {
                cout << "\nDigite a matricula do aluno: ";
                cin >> novoAluno.matricula;

                cout << "Digite a nota 1: ";
                cin >> novoAluno.nota1;

                cout << "Digite a nota 2: ";
                cin >> novoAluno.nota2;

                // Adiciona o aluno ao vetor
                alunos.push_back(novoAluno);

                cout << "\nAluno cadastrado com sucesso!\n";

                break;
            }

            // Listar alunos
            case 2: {
                if (alunos.empty()) {
                    cout << "\nNenhum aluno cadastrado.\n";
                } else {
                    for (const Aluno& aluno : alunos) {
                        media = (aluno.nota1 + aluno.nota2) / 2;
                        cout << "\nMatricula: " << aluno.matricula;
                        cout << "\nNota 1: " << aluno.nota1;
                        cout << "\nNota 2: " << aluno.nota2;
                        cout << "\nMedia: " << media;
                        cout << "\n";
                    }
                }

                break;
            }

            case 3:
                cout << "Saindo do programa.\n";
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 3);
    return 0;
}