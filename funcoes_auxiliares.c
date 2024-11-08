//
// Created by wesan on 08/11/2024.
//

// Inserir uma carta na pilha (empilhar)
void empilhar(Pilha* pilha, Carta carta) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->carta = carta;
    novo_node->prox = pilha->topo;
    pilha->topo = novo_node;
}

// Retirar uma carta da pilha (desempilhar)
Carta desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha está vazia.\n");
        exit(1);
    }
    Node* topo = pilha->topo;
    Carta carta = topo->carta;
    pilha->topo = topo->prox;
    free(topo);
    return carta;
}

// Inserir carta em lista ordenada
void inserir_ordenado(ListaOrdenada* lista, Carta carta) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->carta = carta;
    novo_node->prox = NULL;

    if (lista->inicio == NULL || lista->inicio->carta.valor > carta.valor) {
        novo_node->prox = lista->inicio;
        lista->inicio = novo_node;
    } else {
        Node* atual = lista->inicio;
        while (atual->prox != NULL && atual->prox->carta.valor <= carta.valor) {
            atual = atual->prox;
        }
        novo_node->prox = atual->prox;
        atual->prox = novo_node;
    }
}