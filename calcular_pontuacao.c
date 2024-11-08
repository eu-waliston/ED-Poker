//
// Created by wesan on 08/11/2024.
//

#include <string.h>

// 1. Verificar Royal Straight Flush (RSF)

int eh_royal_straight_flush(ListaOrdenada* mao) {
    Node* atual = mao->inicio;
    if (!eh_flush(mao) || !eh_sequencia(mao, 10)) return 0; // precisa ser sequência de 10 a Ás
    return 1;
}

// 2. Verificar Straight Flush (SF)

int eh_straight_flush(ListaOrdenada* mao) {
    return eh_flush(mao) && eh_sequencia(mao, 0); // qualquer sequência de mesmo naipe, exceto RSF
}

// 3. Verificar Flush (FL)

int eh_flush(ListaOrdenada* mao) {
    Node* atual = mao->inicio;
    char naipe_inicial = atual->carta.naipe;
    while (atual != NULL) {
        if (atual->carta.naipe != naipe_inicial) return 0;
        atual = atual->prox;
    }
    return 1;
}

// 4. Verificar Straight (ST)

int eh_sequencia(ListaOrdenada* mao, int valor_inicial) {
    Node* atual = mao->inicio;
    int valor_esperado = valor_inicial > 0 ? 10 : atual->carta.valor;

    while (atual != NULL) {
        if (atual->carta.valor != valor_esperado) return 0;
        valor_esperado++;
        atual = atual->prox;
    }
    return 1;
}

// 5. Verificar Quatro de uma Espécie (4K), Full House (FH), Trinca (3K) e Dois Pares (2P)
// Para essas combinações, usaremos uma contagem de frequência das cartas por valor.

void contar_valores(ListaOrdenada* mao, int contagem[]) {
    memset(contagem, 0, 14 * sizeof(int));
    Node* atual = mao->inicio;
    while (atual != NULL) {
        contagem[atual->carta.valor]++;
        atual = atual->prox;
    }
}

int eh_quatro_iguais(int contagem[]) {
    for (int i = 1; i <= 13; i++) {
        if (contagem[i] == 4) return 1;
    }
    return 0;
}

int eh_full_house(int contagem[]) {
    int tem_trinca = 0, tem_par = 0;
    for (int i = 1; i <= 13; i++) {
        if (contagem[i] == 3) tem_trinca = 1;
        if (contagem[i] == 2) tem_par = 1;
    }
    return tem_trinca && tem_par;
}

int eh_trinca(int contagem[]) {
    for (int i = 1; i <= 13; i++) {
        if (contagem[i] == 3) return 1;
    }
    return 0;
}

int eh_dois_pares(int contagem[]) {
    int pares = 0;
    for (int i = 1; i <= 13; i++) {
        if (contagem[i] == 2) pares++;
    }
    return pares == 2;
}

int eh_par(int contagem[]) {
    for (int i = 1; i <= 13; i++) {
        if (contagem[i] == 2) return 1;
    }
    return 0;
}

// Função calcular_pontuacao
// Agora, vamos implementar a função calcular_pontuacao que usa as funções acima para determinar a pontuação de uma mão.

const char* descrever_mao(int pontuacao) {
    switch (pontuacao) {
        case 1000: return "Royal Straight Flush";
        case 750: return "Straight Flush";
        case 500: return "4 of a Kind";
        case 300: return "Full House";
        case 200: return "Flush";
        case 150: return "Straight";
        case 100: return "3 of a Kind";
        case 50: return "Two Pairs";
        case 25: return "Pair";
        default: return "High Card";
    }
}

int calcular_pontuacao(ListaOrdenada* mao) {
    int contagem[14];
    contar_valores(mao, contagem);

    if (eh_royal_straight_flush(mao)) return 1000;
    if (eh_straight_flush(mao)) return 750;
    if (eh_quatro_iguais(contagem)) return 500;
    if (eh_full_house(contagem)) return 300;
    if (eh_flush(mao)) return 200;
    if (eh_sequencia(mao, 0)) return 150;
    if (eh_trinca(contagem)) return 100;
    if (eh_dois_pares(contagem)) return 50;
    if (eh_par(contagem)) return 25;

    return 0; // High Card
}

int pontos = calcular_pontuacao(mao);
printf("Você fez: %s com %d pontos\n", descrever_mao(pontos), pontos);