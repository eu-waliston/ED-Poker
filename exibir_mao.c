//
// Created by wesan on 08/11/2024.
//

void exibir_mao(ListaOrdenada* mao) {
    Node* atual = mao->inicio;
    while (atual != NULL) {
        printf("%d%c ", atual->carta.valor, atual->carta.naipe);
        atual = atual->prox;
    }
    printf("\n");
}


void exibir_maos(ListaOrdenada* maos[5]) {
    for (int i = 0; i < 5; i++) {
        printf("Mão %d: ", i + 1);
        exibir_mao(maos[i]);
    }
}

void exibir_descarte(Pilha* descarte) {
    if (descarte->topo != NULL) {
        printf("Topo do Descarte: %d%c\n", descarte->topo->carta.valor, descarte->topo->carta.naipe);
    } else {
        printf("Descarte vazio.\n");
    }
}