# Exercícios de Algoritmos em C e C++

Coleção de exercícios de lógica de programação feitos em C e C++: menus com `switch`, vetores, `struct`, funções com passagem por valor e por referência, e leitura/escrita de arquivos.

## Programas

### Cadastros com menu (`struct` + `vector`)

| Arquivo | O que faz |
|---|---|
| [academia_aluno_mais_alto.cpp](academia_aluno_mais_alto.cpp) | Cadastra alunos (código, peso, altura) e mostra o mais alto |
| [banco_contas_e_depositos.cpp](banco_contas_e_depositos.cpp) | Cadastra contas bancárias, faz depósitos e lista os saldos |
| [biblioteca_livros_apos_2020.cpp](biblioteca_livros_apos_2020.cpp) | Cadastra livros e filtra os publicados depois de 2020 |
| [concessionaria_busca_por_preco.cpp](concessionaria_busca_por_preco.cpp) | Cadastra carros e busca os que custam até um preço máximo |
| [consumo_energia_media_rua.cpp](consumo_energia_media_rua.cpp) | Calcula a média de consumo de energia da rua e lista as casas acima da média |
| [esports_busca_jogador.cpp](esports_busca_jogador.cpp) | Cadastra jogadores e busca pelo ID |
| [estacionamento_cobranca.cpp](estacionamento_cobranca.cpp) | Controla entrada e saída de veículos e calcula o valor (R$ 5 por hora iniciada) |
| [loja_cadastro_clientes.cpp](loja_cadastro_clientes.cpp) | Cadastra e lista clientes de uma loja |
| [media_notas_alunos.cpp](media_notas_alunos.cpp) | Cadastra alunos com duas notas e mostra a média de cada um |
| [minimercado_valor_estoque.cpp](minimercado_valor_estoque.cpp) | Cadastra produtos e calcula o valor total investido no estoque |
| [rh_filtro_funcionarios.cpp](rh_filtro_funcionarios.cpp) | Lista funcionários com mais de 40 anos e salário acima de R$ 5.000 |

### Vetores

| Arquivo | O que faz |
|---|---|
| [ler_e_exibir_vetor.c](ler_e_exibir_vetor.c) | Lê os valores de um vetor e mostra na tela |
| [menu_operacoes_vetor.c](menu_operacoes_vetor.c) | Menu que preenche um vetor com números aleatórios, ordena (bubble sort) e calcula média, mediana, maior e menor |
| [menu_operacoes_vetor.cpp](menu_operacoes_vetor.cpp) | Mesmo programa acima, em C++ |
| [vetores_elementos_em_comum.cpp](vetores_elementos_em_comum.cpp) | Mostra os números que aparecem em dois vetores, comparando passagem por valor e por referência |

### Strings

| Arquivo | O que faz |
|---|---|
| [ler_e_exibir_nomes.cpp](ler_e_exibir_nomes.cpp) | Lê N nomes completos e mostra na tela |
| [extrair_sobrenome.cpp](extrair_sobrenome.cpp) | Separa o sobrenome de cada nome completo |

### Arquivos

| Arquivo | O que faz |
|---|---|
| [exibir_arquivo_texto.cpp](exibir_arquivo_texto.cpp) | Abre um arquivo de texto e mostra o conteúdo |
| [gravar_nomes_em_arquivo.cpp](gravar_nomes_em_arquivo.cpp) | Grava nomes em maiúsculo em um arquivo novo (não sobrescreve um que já existe) |
| [cadastro_nomes_persistente.cpp](cadastro_nomes_persistente.cpp) | Cadastro de nomes sem repetição, salvo em `base.dat` e carregado ao abrir o programa |
| [remover_stop_words/](remover_stop_words/remover_stop_words.cpp) | Remove as stop words (artigos, preposições etc.) de um texto e grava o resultado em outro arquivo |

### Headers

| Arquivo | Conteúdo |
|---|---|
| [meusMetodos.h](meusMetodos.h) | Funções de apoio para arquivos e listas de nomes (`existeArquivo`, `paraMaiusculo`, `conectarBase`, `inserirLista`, `exibirListaNomes`) |
| [meusTipos.h](meusTipos.h) | Structs `Cliente` e `Veiculo` |
| [remover_stop_words/util.h](remover_stop_words/util.h) | Funções de string (`split`, conversões para maiúsculo) e data/hora |

## Como compilar e executar

C++:

```bash
g++ academia_aluno_mais_alto.cpp -o academia
./academia
```

C:

```bash
gcc menu_operacoes_vetor.c -o menu_vetor
./menu_vetor
```

O programa de stop words abre o `stop_words.txt` pelo nome, então ele precisa ser executado de dentro da pasta `remover_stop_words`. Quando ele pedir o arquivo, digite `texto_original.txt`. O resultado é gravado em `texto_sem_stop_words.txt`.
