#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void exibirVetor(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << "\n\n";
}

// por referência (&): os números ficam no vetor de quem chamou
void popularVetor(vector<int> &v, int qtd, int inicio, int fim) {
    int numero;
    for (int i = 0; i < qtd; i++) {
        numero = (rand() % (fim - inicio + 1)) + inicio;
        v.push_back(numero);
    }
}

// método COM retorno: devolve true se o número existe no vetor
bool existeNoVetor(vector<int> v, int numero) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == numero) {
            return true;
        }
    }
    return false;
}

// EXERCÍCIO 2
// vetorA e vetorB POR VALOR (só leitura)
// vetorResultado POR REFERÊNCIA (&): o que for guardado aqui volta para o main
void exercicio2(vector<int> vetorA, vector<int> vetorB, vector<int> &vetorResultado) {
    for (int i = 0; i < vetorA.size(); i++) {
        if (existeNoVetor(vetorB, vetorA[i]) && !existeNoVetor(vetorResultado, vetorA[i])) {
            vetorResultado.push_back(vetorA[i]);
        }
    }
}

int main() {
    srand(time(NULL)); // uma única vez, no início do programa

    vector<int> vetorA, vetorB, vetorResultado;
    int n;

    cout << "Quantos numeros em cada vetor? ";
    cin >> n;

    // faixa pequena (1 a 20) para ter mais chance de números repetidos
    popularVetor(vetorA, n, 1, 20);
    popularVetor(vetorB, n, 1, 20);

    cout << "\nVetor A:\n";
    exibirVetor(vetorA);
    cout << "Vetor B:\n";
    exibirVetor(vetorB);

    exercicio2(vetorA, vetorB, vetorResultado);

    if (vetorResultado.size() == 0) {
        cout << "vetorResultado ficou vazio (nenhum numero em comum)\n";
    } else {
        cout << "vetorResultado (" << vetorResultado.size() << " numeros):\n";
        exibirVetor(vetorResultado);
    }

    return 0;
}
