//construir um programa que leia N nomes completos de pessoas e os exiba na tela

#include <iostream>
#include <vector>
#include <string>
#define N 5

using namespace std;

int main(){
    vector<string> nome(N);
    int i;
    for (i = 0; i < N; i++)
    {
        cout << "Digite um nome: " << endl;
        getline(cin,nome[i]);
    }
    cout << "----NOMES----" << endl;
    for (i = 0; i < N; i++)
    {
        cout << "nome " << i+1 << " " << nome[i] << endl;

    }

    return 1;
}