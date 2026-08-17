#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Imovel {
    string numeroDaCasa;
    float consumo;
};

int main(){

    vector<Imovel>imoveis;

    int opcao, quantidadeCasas = 0, consumoTotal = 0;
    float media;

    do{
        cout << "\n---MENU---\n";
        cout << "1 - Cadastrar imovel\n";
        cout << "2 - Calucular a media de consumo geral da rua\n";
        cout << "3 - Listar imoveis que consomem acima da media\n";
        cout << "4 - Sair\n";
        cout << "Escolha a opcao: ";
        cin >> opcao;

        switch(opcao) {

            case 1: {
                Imovel imovel;
                cout << "Digite o numero da casa: ";
                cin >> imovel.numeroDaCasa;
                cout << "Digite o consume em Kwh da casa: ";
                cin >> imovel.consumo;
                quantidadeCasas++;
                consumoTotal += imovel.consumo;
                imoveis.push_back(imovel);
                break;
            }
            case 2: {
                if(quantidadeCasas == 0){
                    cout << "Nenhuma casa registrada para calcular a media. Cadastre imoveis\n";

                }
                else{
                media = consumoTotal / quantidadeCasas;

                cout << "Media de consumo de energia em Kwh da rua: " << media << endl;
                }
                break;
            }
            case 3: {

                cout << "\n--IMOVEIS QUE CONSOMEM ACIMA DA MEDIA--\n";
                for (const auto& c : imoveis){
                    if(c.consumo > media){
                        cout << "Numero da casa: " << c.numeroDaCasa << " Consumo: " << c.consumo << endl;

                    }
                }
                break;
            }
            case 4: {
                cout << "Saindo do sistema\n";
                break;
            }
        }
    }while (opcao != 4);
    return 0;
}