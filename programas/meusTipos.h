#ifndef MEUS_TIPOS_H
#define MEUS_TIPOS_H

#include <string>

using namespace std;

// usado em loja_cadastro_clientes.cpp
struct Cliente {
    string codigo;
    string idade;
    string telefone;
};

// usado em estacionamento_cobranca.cpp
// horarios no formato HH:MM
struct Veiculo {
    string placa;
    string cor;
    string horaEntrada;
    string horaSaida;
};

#endif
