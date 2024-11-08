//
// Created by wesan on 08/11/2024.
//

void jogar(Pilha* pesca, Pilha* descarte, ListaOrdenada* maos[5]) {
    Carta mao_jogo[5];

    for (int i = 0; i < 5; i++) {
        mao_jogo[i] = desempilhar(pesca);
    }

    int cartas_colocadas = 0;
    while (cartas_colocadas < 25) {
        printf("Estado Atual do Jogo:\n");
        exibir_maos(maos);
        exibir_descarte(descarte);

        printf("Sua Mão de Jogo:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d: %d%c ", i + 1, mao_jogo[i].valor, mao_jogo[i].naipe);
        }
        printf("\n");

        int carta_escolhida = capturar_escolha("Escolha uma carta para jogar", 1, 5) - 1;
        int destino = capturar_escolha("Escolha onde colocar a carta (1-5 para Mãos, 6 para Descarte)", 1, 6);

        if (destino >= 1 && destino <= 5) {
            inserir_ordenado(maos[destino - 1], mao_jogo[carta_escolhida]);
        } else {
            empilhar(descarte, mao_jogo[carta_escolhida]);
        }

        mao_jogo[carta_escolhida] = (pesca->topo != NULL) ? desempilhar(pesca) : desempilhar(descarte);

        cartas_colocadas++;
    }
}

void finalizar_jogo(ListaOrdenada* maos[5]) {
    int pontuacao_total = 0;

    printf("\nResultado Final:\n");
    for (int i = 0; i < 5; i++) {
        int pontos = calcular_pontuacao(maos[i]);
        printf("Mão %d: %s com %d pontos\n", i + 1, descrever_mao(pontos), pontos);
        pontuacao_total += pontos;
    }
    printf("Pontuação Total: %d\n", pontuacao_total);
}


