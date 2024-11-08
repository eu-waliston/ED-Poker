# ELC1066 - ESTRUTURAS DE DADOS "A"

## Estruturas de Dados - 2024/2 - Tarefa 1 - Estruturas dinâmicas básicas

### Descrição:

Você deverá programar o jogo de paciência “Mãos de Pôquer”.

### Regras: 

O jogador recebe 30 cartas de um baralho (padrão, 52 cartas, sem coringas). O jogador deve montar 5 mãos de pôquer com estas cartas. Cada mão é pontuada de acordo com a tabela abaixo. A soma das mãos dá a pontuação final do jogador.

Mecânica de jogo:

Embaralha-se o baralho de 52 cartas. São retiradas as primeiras 30 cartas que formam o monte de Pesca.

Devem haver 5 listas ordenadas (Mãos) e uma pilha de Descarte.

O jogador, inicialmente, pega as 5 primeiras cartas da Pesca, formando sua Mão de Jogo. 

A partir daí, o jogo se desenrola da seguinte forma: o jogador deve colocar ao menos uma das cartas da Mão de Jogo em alguma das cinco Mãos ou no Descarte. Ao “baixar” uma carta, ele deve pegar uma nova da Pesca, ou a do topo do Descarte, tendo sempre, portanto, 5 cartas na Mão de Jogo.

Cartas que foram colocadas em alguma das Mãos não podem ser retiradas/movidas.

O jogo termina quando as 5 Mãos estiverem completas (5 cartas cada), independente de haverem ou não cartas na Pesca. Se não houverem mais cartas de Pesca e as Mãos ainda estiverem incompletas, o jogador deve completar as Mãos com as cartas de sua Mão de Jogo e/ou Descarte.

Ao final, são contados os pontos do jogador de acordo com a tabela de pontuação abaixo.

### Requisitos de Programação

Use linguagem C padrão. Seu código será testado em máquina com Linux, utilizando compilador C padrão ANSI (gcc -ansi). Escolha as estruturas dinâmicas que mais se adequam a cada caso (Pesca, Mãos, Mão de Jogo, Descarte).

O arquivo mpoquer.tar em anexo contém código que você deverá usar, especialmente a função de embaralhamento com uma semente dada pelo usuário (número inteiro positivo). Desta forma, é possível criar um ranking de pontuação consistente, visto que, para uma mesma semente, o embaralhamento irá ser sempre o mesmo, possibilitando ver quem fez mais pontos com as mesmas cartas iniciais.


### Relatório

Você deve entregar, além do código C, um relatório escrito relatando as estruturas dinâmicas escolhidas e justificando cada escolha.

### Tabela de Pontuação

Mão                                                                          Pontos

Royal Straight Flush (10, J, Q, K, A, mesmo naipe) - RSF                     1000

Straight Flush (sequência de 5 cartas de mesmo naipe, exceto RSF) - SF        750

4 of a Kind (4 cartas de mesmo valor) - 4K                                    500

Full House (uma trinca e um par) - FH                                         300

Flush (5 cartas de mesmo naipe) - FL                                          200

Straight (sequência de 5 cartas, mais de um naipe) - ST                       150

3 of a Kind (trinca simples) - 3K                                             100

Two Pairs (2 pares simples) - 2P                                              50

Pair (1 par simples) - 1P                                                     25

High Card (carta mais alta - em valorescrescentes, do 2 ao Ás)                0

