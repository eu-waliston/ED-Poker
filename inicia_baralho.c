//
// Created by wesan on 08/11/2024.
//

void inicializar_baralho(Carta baralho[]) {
    char naipes[] = {'C', 'E', 'O', 'P'};
    int indice = 0;
    for (int n = 0; n < 4; n++) {
        for (int v = 1; v <= 13; v++) {
            baralho[indice].valor = v;
            baralho[indice].naipe = naipes[n];
            indice++;
        }
    }
}

void embaralhar(Carta baralho[], int semente) {
    srand(semente);
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}