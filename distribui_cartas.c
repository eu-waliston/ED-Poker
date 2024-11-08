//
// Created by wesan on 08/11/2024.
//

void distribuir_cartas(Carta baralho[], Pilha* pesca) {
    for (int i = 0; i < 30; i++) {
        empilhar(pesca, baralho[i]);
    }
}