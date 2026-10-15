#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

// por referência (&): as alterações feitas aqui ficam no vetor do main
void popularVetor(vector<int> &v, int qtd, int inicio, int fim) {
    int numero;
    for (int i = 0; i < qtd; i++) {
        numero = (rand() % (fim - inicio + 1)) + inicio;
        v.push_back(numero);
    }
}

// por valor: recebe uma cópia, só lê os dados
void exibirVetor(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

// método com retorno: diz se o número existe no vetor
bool contem(vector<int> v, int numero) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == numero) {
            return true;
        }
    }
    return false;
}

// exercício 1: sem retorno, vetores por valor, só exibe
void exercicio1(vector<int> vetorA, vector<int> vetorB) {
    vector<int> jaExibidos;

    cout << "Numeros que aparecem nos dois vetores: ";
    for (int i = 0; i < vetorA.size(); i++) {
        if (contem(vetorB, vetorA[i]) && !contem(jaExibidos, vetorA[i])) {
            cout << vetorA[i] << "\t";
            jaExibidos.push_back(vetorA[i]);
        }
    }
    if (jaExibidos.size() == 0) {
        cout << "nenhum";
    }
    cout << endl;
}

// exercício 2: vetorResultado por referência, e os dados dele são retornados
vector<int> exercicio2(vector<int> vetorA, vector<int> vetorB, vector<int> &vetorResultado) {
    for (int i = 0; i < vetorA.size(); i++) {
        if (contem(vetorB, vetorA[i]) && !contem(vetorResultado, vetorA[i])) {
            vetorResultado.push_back(vetorA[i]);
        }
    }
    return vetorResultado;
}

int main() {
    srand(time(NULL));

    int n;
    cout << "Quantos numeros em cada vetor? ";
    cin >> n;

    vector<int> vetorA, vetorB;
    popularVetor(vetorA, n, 1, 20);
    popularVetor(vetorB, n, 1, 20);

    cout << "Vetor A: ";
    exibirVetor(vetorA);
    cout << "Vetor B: ";
    exibirVetor(vetorB);

    cout << endl << "--- Exercicio 1 ---" << endl;
    exercicio1(vetorA, vetorB);

    cout << endl << "--- Exercicio 2 ---" << endl;
    vector<int> vetorResultado;
    vector<int> retornado = exercicio2(vetorA, vetorB, vetorResultado);
    cout << "vetorResultado: ";
    exibirVetor(retornado);

    return 1;
}
