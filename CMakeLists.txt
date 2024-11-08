cmake_minimum_required(VERSION 3.29)
project(EDPoker C)

set(CMAKE_C_STANDARD 11)

add_executable(EDPoker main.c
        cartas.c
        funcoes_auxiliares.c
        inicia_baralho.c
        distribui_cartas.c
        logica_principal.c
        pontuacao.c
        funcao_principal.c
        calcular_pontuacao.c
        teste_pontuacao.c
        teste_pontuacao.c
        teste_pontuacao.c
        capturar_escolha.c
        jogar.c
        exibir_mao.c)
