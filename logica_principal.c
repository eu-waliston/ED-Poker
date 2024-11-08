//
// Created by wesan on 08/11/2024.
//

void jogar(Pilha* pesca, Pilha* descarte, ListaOrdenada* maos[5]) {
    Carta mao_jogo[5]; // mão de jogo com 5 cartas

    // Inicialmente, enchemos a mão de jogo com as 5 primeiras cartas
    for (int i = 0; i < 5; i++) {
        mao_jogo[i] = desempilhar(pesca);
    }

    // Loop de jogadas até completar as mãos
    int cartas_colocadas = 0;
    while (cartas_colocadas < 25) {
        // Exibir a mão de jogo e as opções do jogador
        printf("Mão de Jogo: ");
        for (int i = 0; i < 5; i++) {
            printf("%d%c ", mao_jogo[i].valor, mao_jogo[i].naipe);
        }
        printf("\nEscolha uma carta para colocar em uma das 5 mãos (1-5) ou no descarte (6): ");

        int escolha_mao, carta_escolhida;
        scanf("%d %d", &carta_escolhida, &escolha_mao);

        if (escolha_mao >= 1 && escolha_mao <= 5) {
            inserir_ordenado(maos[escolha_mao - 1], mao_jogo[carta_escolhida - 1]);
        } else if (escolha_mao == 6) {
            empilhar(descarte, mao_jogo[carta_escolhida - 1]);
        }

        mao_jogo[carta_escolhida - 1] = (pesca->topo != NULL) ? desempilhar(pesca) : desempilhar(descarte);

        cartas_colocadas++;
    }
}