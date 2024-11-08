//
// Created by wesan on 08/11/2024.
//


int capturar_escolha(char* prompt, int min, int max) {
    int escolha;
    do {
        printf("%s (%d-%d): ", prompt, min, max);
        scanf("%d", &escolha);
    } while (escolha < min || escolha > max);
    return escolha;
}