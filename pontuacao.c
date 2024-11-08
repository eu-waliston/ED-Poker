//
// Created by wesan on 08/11/2024.
//

int calcular_pontuacao(ListaOrdenada* mao) {
    // Avaliar combinação da mão (pares, trincas, sequência, etc.)
    int pontos = 0;
    // Aqui adiciona-se a lógica para cada combinação
    return pontos;
}

int pontuacao_final(ListaOrdenada* maos[5]) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += calcular_pontuacao(maos[i]);
    }
    return total;
}