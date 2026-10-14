#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void inicializarVetor(vector<int>& v, int qtd, int valor) {
    for(int i = 0; i < qtd; i++){
        v.push_back(valor);
    }
}

void exibirVetor(const vector<int>& v) {
    for(size_t i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

void popularvetor(vector<int>& v, int qtd, int inicio, int fim) {
    for (int i = 0; i < qtd; i++) {
        int numero = rand() % (fim - inicio + 1) + inicio;
        v.push_back(numero);
    }
}

void estatistica(const vector<int>& v, int &min, int &max) {
    min = v[0];
    max = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < min) min = v[i];
        if (v[i] > max) max = v[i];
    }
}

int main () {
    srand(time(NULL));
    vector<int> vetor;

    inicializarVetor(vetor, 10, 0);
    popularvetor(vetor, 10 , 100, 500);
    exibirVetor(vetor);

    int min, max;

    estatistica(vetor, min, max);
    cout << "Min: " << min << "\tMax: " << max << endl;

    return 0;
}
