#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Livro {
    string codigo;
    string anoDePublicacao;
    string quantidadeDePaginas;
};

int main(){

    int opcao;
    vector<Livro> livros;
    Livro novoLivro;
    do {
        cout << "\n---MENU---\n";
        cout << "1 - Cadastrar livro\n";
        cout << "2 - Filtrar livros: mostrar livros publicados apos o ano 2020\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            // Cadastrar livro
            case 1: {
                novoLivro = Livro();

                cout << "\nDigite o codigo do livro: ";
                cin >> novoLivro.codigo;

                cout << "Digite o ano de publicacao: ";
                cin >> novoLivro.anoDePublicacao;

                cout << "Digite a quantidade de paginas: ";
                cin >> novoLivro.quantidadeDePaginas;

                // Adiciona o livro ao vetor
                livros.push_back(novoLivro);

                cout << "\nLivro cadastrado com sucesso!\n";

                break;
            }

            // Filtrar livros
            case 2: {
                if (livros.empty()) {
                    cout << "\nNenhum livro cadastrado.\n";
                } else {
                    cout << "\nLivros publicados após 2020:\n";
                    for (const Livro& l : livros) {
                        if (l.anoDePublicacao > "2020") {
                            cout << "\nCodigo: " << l.codigo;
                            cout << "\nAno de Publicacao: " << l.anoDePublicacao;
                            cout << "\nQuantidade de Paginas: " << l.quantidadeDePaginas;
                            cout << "\n";
                        }
                    }
                }
                break;
            }

            // Sair
            case 3:
                cout << "\nSaindo do programa...\n";
                break;

            default:
                cout << "\nOpcao invalida. Tente novamente.\n";
        }

    } while (opcao != 3);
    return 0;
}