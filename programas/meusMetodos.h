#ifndef MEUS_METODOS_H
#define MEUS_METODOS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

// retorna true se o arquivo existir e puder ser aberto para leitura
bool existeArquivo(string nomeArquivo) {
    ifstream arquivo(nomeArquivo.c_str());
    return arquivo.good();
}

// recebe uma copia da frase e devolve ela toda em maiusculo
string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.length(); i++) {
        frase[i] = toupper((unsigned char) frase[i]);
    }
    return frase;
}

// procura o nome na lista, devolve a posicao ou -1 se nao encontrar
int buscarNaLista(string nome, string listaNomes[], int quantidadeNomes) {
    for (int i = 0; i < quantidadeNomes; i++) {
        if (listaNomes[i] == nome) {
            return i;
        }
    }
    return -1;
}

// insere o nome no final da lista se ainda nao existir e se houver espaco
// quantidadeNomes por referencia (ponteiro): o main fica com o valor atualizado
bool inserirLista(string nome, string listaNomes[], int *quantidadeNomes, int tamanho) {
    if (*quantidadeNomes >= tamanho) {
        cout << "Lista cheia, nao foi possivel inserir." << endl;
        return false;
    }
    if (buscarNaLista(nome, listaNomes, *quantidadeNomes) != -1) {
        return false;
    }
    listaNomes[*quantidadeNomes] = nome;
    (*quantidadeNomes)++;
    return true;
}

// le os nomes da base de dados, coloca na lista e devolve quantos nomes foram carregados
int conectarBase(string listaNomes[], string nomeBaseDados, int tamanho) {
    int quantidadeNomes = 0;

    ifstream procuradorArquivo(nomeBaseDados.c_str());
    if (!procuradorArquivo) {
        // primeira execucao: a base ainda nao existe
        return 0;
    }

    string linha;
    while (getline(procuradorArquivo, linha)) {
        // remove o \r de arquivos salvos no Windows
        if (!linha.empty() && linha[linha.length() - 1] == '\r') {
            linha.erase(linha.length() - 1);
        }
        // a gravacao comeca com \n, entao a primeira linha pode vir vazia
        if (linha.empty()) {
            continue;
        }
        inserirLista(paraMaiusculo(linha), listaNomes, &quantidadeNomes, tamanho);
    }

    procuradorArquivo.close();
    return quantidadeNomes;
}

// exibe todos os nomes da lista
void exibirListaNomes(string listaNomes[], int quantidadeNomes) {
    cout << "---NOMES CADASTRADOS---" << endl;
    for (int i = 0; i < quantidadeNomes; i++) {
        cout << i + 1 << " - " << listaNomes[i] << endl;
    }
    cout << endl;
}

#endif
