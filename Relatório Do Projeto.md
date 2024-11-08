
# Relatório do Projeto: Jogo de Paciência “Mãos de Pôquer”

## Sumário
- [Introdução](#introdução)
- [Descrição do Jogo](#descrição-do-jogo)
- [Regras do Jogo](#regras-do-jogo)
- [Estruturas de Dados](#estruturas-de-dados)
- [Funções e Métodos Implementados](#funções-e-métodos-implementados)
- [Fluxo do Jogo](#fluxo-do-jogo)
- [Pontuação e Classificação das Mãos](#pontuação-e-classificação-das-mãos)
- [Considerações Finais e Possíveis Melhorias](#considerações-finais-e-possíveis-melhorias)

---

## Introdução

Este relatório documenta o desenvolvimento de um jogo de paciência baseado em “Mãos de Pôquer”, implementado na linguagem C. O objetivo do jogo é que o jogador forme 5 mãos de pôquer a partir de um monte de cartas, sendo cada mão pontuada conforme sua classificação. Este projeto foi desenvolvido para rodar em ambiente Linux, compilado com `gcc -ansi`.

## Descrição do Jogo

O jogo simula uma partida onde o jogador, com um baralho de 52 cartas (sem coringas), recebe um conjunto de 30 cartas aleatórias. O objetivo é montar 5 mãos de pôquer, cada uma contendo 5 cartas. A pontuação final é dada pela soma das pontuações das mãos.

### Objetivo

A meta do jogador é maximizar sua pontuação final formando as mãos de pôquer mais valiosas possíveis.

---

## Regras do Jogo

1. **Distribuição Inicial**:
    - O baralho é embaralhado, e as primeiras 30 cartas são colocadas no monte de **Pesca**.
    - O jogador recebe uma **Mão de Jogo** inicial de 5 cartas, retiradas do monte de Pesca.

2. **Jogadas**:
    - A cada rodada, o jogador deve baixar pelo menos uma carta da sua **Mão de Jogo** para uma das 5 **Mãos** ou para o **Descarte**.
    - Sempre que baixar uma carta, o jogador repõe sua **Mão de Jogo** pegando uma nova carta do monte de **Pesca** ou do **Descarte**, caso o monte de Pesca esteja vazio.
    - As cartas baixadas para uma **Mão** não podem ser movidas ou removidas.

3. **Condições de Término**:
    - O jogo termina quando todas as 5 Mãos contêm exatamente 5 cartas.

---

## Estruturas de Dados

### Cartas

Cada carta é representada por uma estrutura `Carta`, que contém os seguintes campos:
- `valor`: um inteiro representando o valor da carta (1 para Ás, 11 para Valete, etc.)
- `naipe`: um caractere (`'C'`, `'D'`, `'H'`, `'S'`) representando o naipe (Copas, Ouros, Espadas, Paus).

```c
typedef struct {
    int valor;
    char naipe;
} Carta;
```

### Estruturas Dinâmicas

Para modelar as diferentes áreas de jogo, foram utilizadas as seguintes estruturas dinâmicas:

- **Monte de Pesca**: Implementado como uma **pilha**, armazenando as cartas disponíveis para o jogador.
- **Mão de Jogo**: Implementada como um array fixo de 5 posições.
- **Descarte**: Implementado como uma **pilha**, onde o jogador pode colocar cartas que não deseja utilizar imediatamente.
- **Mãos**: Implementadas como **listas ordenadas**, permitindo que as cartas sejam organizadas automaticamente conforme são adicionadas.

---

## Funções e Métodos Implementados

### Funções de Manipulação de Cartas

- `embaralhar(Carta* baralho, int semente)`: embaralha o baralho usando uma semente aleatória fornecida pelo usuário.
- `inicializar_baralho()`: inicializa um baralho de 52 cartas sem coringas.

### Funções de Estrutura de Dados

- **Pilha**:
    - `inicializar_pilha()`: inicializa uma pilha vazia.
    - `empilhar(Pilha* pilha, Carta carta)`: empilha uma carta no topo.
    - `desempilhar(Pilha* pilha)`: remove e retorna a carta do topo.

- **Lista Ordenada**:
    - `inicializar_lista()`: inicializa uma lista ordenada vazia.
    - `inserir_ordenado(ListaOrdenada* lista, Carta carta)`: insere a carta em ordem crescente de valor.

### Funções de Pontuação

Para pontuar cada mão, foram implementadas verificações para as combinações de pôquer. Cada função retorna um valor booleano, indicando a presença ou ausência da combinação:

- `eh_royal_straight_flush`: verifica se a mão é um Royal Straight Flush.
- `eh_straight_flush`: verifica se a mão é um Straight Flush.
- `eh_flush`: verifica se todas as cartas têm o mesmo naipe.
- `eh_sequencia`: verifica se as cartas formam uma sequência.
- `eh_quatro_iguais`, `eh_full_house`, `eh_trinca`, `eh_dois_pares`, `eh_par`: verificam outras combinações de pôquer.

### Função de Pontuação Principal

- `calcular_pontuacao(ListaOrdenada* mao)`: calcula a pontuação total da mão, chamando as verificações mencionadas acima.

### Funções de Interação com o Usuário

- `capturar_escolha(char* prompt, int min, int max)`: solicita ao usuário uma entrada numérica dentro de um intervalo específico.
- `jogar(Pilha* pesca, Pilha* descarte, ListaOrdenada* maos[5])`: controla o fluxo do jogo, permitindo ao jogador baixar cartas e preencher as 5 mãos.

### Exibição e Feedback

- `exibir_mao(ListaOrdenada* mao)`: exibe as cartas de uma mão.
- `exibir_descarte(Pilha* descarte)`: exibe a carta do topo do descarte.
- `finalizar_jogo(ListaOrdenada* maos[5])`: calcula e exibe a pontuação final do jogador, detalhando a pontuação de cada mão.

---

## Fluxo do Jogo

1. **Inicialização**: O jogo começa com o embaralhamento e distribuição das cartas para o monte de Pesca.
2. **Jogada**:
    - O jogador escolhe uma carta da Mão de Jogo para baixar.
    - O jogador decide o destino da carta (uma das Mãos ou o Descarte).
    - O jogador repõe a carta baixada pegando uma nova carta do monte de Pesca ou do Descarte.
3. **Finalização**: Quando as 5 Mãos contêm 5 cartas cada, o jogo termina e a pontuação é calculada e exibida.

---

## Pontuação e Classificação das Mãos

A pontuação segue a seguinte tabela:

| Mão                  | Pontuação |
|----------------------|-----------|
| Royal Straight Flush | 1000      |
| Straight Flush       | 750       |
| 4 of a Kind          | 500       |
| Full House           | 300       |
| Flush                | 200       |
| Straight             | 150       |
| 3 of a Kind          | 100       |
| Two Pairs            | 50        |
| Pair                 | 25        |
| High Card            | 0         |

Cada mão é avaliada com a maior combinação presente, somando a pontuação para o resultado final.

---

## Considerações Finais e Possíveis Melhorias

### Resultados

Este projeto fornece uma implementação funcional do jogo de paciência “Mãos de Pôquer” com uma interface de terminal para entrada de dados do jogador, manipulação de cartas e cálculo de pontuação.

### Melhorias Sugeridas

1. **Interface Gráfica**: A implementação atual funciona em terminal. Uma versão gráfica tornaria o jogo mais intuitivo e visualmente agradável.
2. **Salvamento de Ranking**: Armazenar pontuações em um arquivo permitiria criar um ranking de jogadores.
3. **Aprimoramento de Estratégia**: Adicionar dicas ou sugestões de movimento ao jogador pode ajudar a maximizar a pontuação.
4. **Expansão para Vários Jogadores**: Permitir que múltiplos jogadores participem da mesma partida, com turnos alternados e uma classificação final.

### Conclusão

O projeto alcança o objetivo de implementar um jogo de paciência divertido e estratégico com base em mãos de pôquer. Ele foi construído com eficiência e simplicidade na linguagem C, utilizando estruturas dinâmicas para gerenciar as cartas do baralho e as ações do jogador. 
