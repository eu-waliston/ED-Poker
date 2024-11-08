#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int valor; // 1-13 para Ás a Rei
    char naipe; // 'C' para Copas, 'E' para Espadas, etc.
} Carta;

typedef struct Node {
    Carta carta;
    struct Node* prox;
} Node;

// Função para criar uma nova carta
Carta criar_carta(int valor, char naipe) {
    Carta nova_carta;
    nova_carta.valor = valor;
    nova_carta.naipe = naipe;
    return nova_carta;
}

// Função para embaralhar (parte do código fornecido pelo mpoquer.tar)
// função shuffle() será incluída posteriormente

// Função principal do jogo (será expandida)
void iniciar_jogo() {
    // inicialização das pilhas e listas encadeadas
    // lógica de distribuição e jogadas
    printf("Jogo iniciado!\n");
}

int main() {
    Carta baralho[52];
    Pilha* pesca = inicializar_pilha();
    Pilha* descarte = inicializar_pilha();
    ListaOrdenada* maos[5];
    for (int i = 0; i < 5; i++) maos[i] = inicializar_lista();

    embaralhar(baralho, 52);
    for (int i = 0; i < 30; i++) empilhar(pesca, baralho[i]);

    jogar(pesca, descarte, maos);
    finalizar_jogo(maos);

    return 0;
}