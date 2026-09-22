#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "util.h"



int main(){
    ifstream arquivoStopWords;
    vector<string> listaStopWords;

    arquivoStopWords.open("stop_words.txt");
    if (!arquivoStopWords) {
        cout << "Aequivo de stop words nao localizado. Programa encerrado." << endl;
        exit(0);
    }
    //le o arquivo capturando as frases
    string linha;
    while (!arquivoStopWords.eof()){
        getline(arquivoStopWords,linha);
        //colocar a linha para maiusculo
        linha = paraMaiusculoStringComRetorno(linha);

        listaStopWords.push_back(linha);
    }
    arquivoStopWords.close();

    //rotina que exiba os stop words inseridos na listaStopWords
    for (int i = 0; i < listaStopWords.size(); i++){
        cout << listaStopWords[i] << ", ";
    }
    cout << "\n\n\n";
    
    ifstream arquivoTextoOriginal;
    string nomeArquivo;
    cout << "Digite caminho e nome do arquivo: ";
    cin >> nomeArquivo;
     arquivoTextoOriginal.open(nomeArquivo);

     if (!arquivoTextoOriginal) {
        cout << "Aequivo original para tratamento de stop words nao localizado. Programa encerrado." << endl;
        exit(0);
    }

    ofstream arquivoTextoSemStopWords;
    arquivoTextoSemStopWords.open("texto_sem_stop_words.txt");

    bool encontrou;
    string palavra;
    while (arquivoTextoOriginal >> palavra){
        palavra = paraMaiusculoStringComRetorno(palavra);


        encontrou = false;
        for (int i = 0; i <listaStopWords.size(); i++){
            if (palavra == listaStopWords[i]){
                encontrou = true;
                break;
            }
        }
        if (!encontrou){
            arquivoTextoSemStopWords << palavra;
        }
    }
    arquivoTextoOriginal.close();
    arquivoTextoSemStopWords.close();
    return 1;
}