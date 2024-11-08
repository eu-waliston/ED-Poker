//
// Created by wesan on 08/11/2024.
//

int main() {
    Carta baralho[52];
    Pilha* pesca = inicializar_pilha();
    Pilha* descarte = inicializar_pilha();
    ListaOrdenada* maos[5];
    for (int i = 0; i < 5; i++) {
        maos[i] = inicializar_lista();
    }

    int semente;
    printf("Digite a semente para embaralhamento: ");
    scanf("%d", &semente);

    inicializar_baralho(baralho);
    embaralhar(baralho, semente);
    distribuir_cartas(baralho, pesca);

    jogar(pesca, descarte, maos);
    int pontos = pontuacao_final(maos);

    printf("Pontuação final: %d\n", pontos);

    return 0;
}
