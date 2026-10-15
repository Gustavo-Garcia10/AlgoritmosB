//Construa um programa que leia n nomes completos de pessoas e os adicione em um vetor de n posicoes em que deve ser armazenado o nome completo e o sobrenome. Use a seguinte estrutura;
//typedef struct { string nomeCompleto; string sobreNome; } Pessoa;
//Dica: será preciso fazer uma função que extraia o sobrenome de um nome completo.

#include <iostream>
#include <string> 
#include <vector>
#define N 5

using namespace std;

typedef struct{
    string nomeCompleto;
    string sobreNome;
} Pessoa;

string extrairSobrenome(string nomeCompleto){
    int posicao = nomeCompleto.find_last_of(' ');

    return nomeCompleto.substr(posicao + 1);
}

int main(){
    
    vector<Pessoa> pessoas(N);

    cin.ignore();
    
    for(int i = 0; i < N; i++){
        cout << "\nDigite o nome completo da pessoa " << i + 1 << ": ";
        getline(cin, pessoas[i].nomeCompleto);

        pessoas[i].sobreNome = extrairSobrenome(pessoas[i].nomeCompleto);
    }

    for (int i = 0; i < N; i++){
        cout << "\nPessoa " << i+1 << endl;
        cout << "Nome completo: " << pessoas[i].nomeCompleto << endl;
        cout << "Sobrenome: " << pessoas[i].sobreNome << endl;
    }

    
    return 1;
}
