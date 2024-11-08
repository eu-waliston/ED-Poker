//
// Created by wesan on 08/11/2024.
//

//
// Created by wesan on 08/11/2024.
//

void teste_pontuacao() {
    ListaOrdenada* mao_teste = inicializar_lista();
    inserir_ordenado(mao_teste, criar_carta(10, 'C'));
    inserir_ordenado(mao_teste, criar_carta(11, 'C'));
    inserir_ordenado(mao_teste, criar_carta(12, 'C'));
    inserir_ordenado(mao_teste, criar_carta(13, 'C'));
    inserir_ordenado(mao_teste, criar_carta(1, 'C'));

    int pontuacao = calcular_pontuacao(mao_teste);
    printf("Pontuação da mão: %d\n", pontuacao);
}

int main() {
    teste_pontuacao();
    return 0;
}
