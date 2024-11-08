//
// Created by wesan on 08/11/2024.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int valor; // 1-13 (Ás a Rei)
    char naipe; // 'C' (Copas), 'E' (Espadas), 'O' (Ouros), 'P' (Paus)
} Carta;

typedef struct Node {
    Carta carta;
    struct Node* prox;
} Node;

// Estrutura para as pilhas e listas de cartas
typedef struct {
    Node* topo;
} Pilha;

typedef struct {
    Node* inicio;
} ListaOrdenada;

// Funções de inicialização
Pilha* inicializar_pilha() {
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    nova_pilha->topo = NULL;
    return nova_pilha;
}

ListaOrdenada* inicializar_lista() {
    ListaOrdenada* lista = (ListaOrdenada*)malloc(sizeof(ListaOrdenada));
    lista->inicio = NULL;
    return lista;
}