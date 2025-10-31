#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main(void) {
    int torre = 0;      // posição atual da peça (coluna)
    const int movimento = 5; // queremos mover 5 casas para a direita

    // printf("Posição inicial da torre: %d\n", torre);

    // mover a peça exatamente 5 casas para a direita uma vez
    while (torre < movimento) {
        // mostra posição antes do movimento
        printf("Posição atual da torre: %d\n", torre);

        // realiza o movimento (adiciona 5)
        torre += movimento;

        // mostra resultado do movimento
        printf("Peça movimentada %d casas para a direita!\n", movimento);
    }

    printf("Movimento concluído. Posição final da torre: %d\n", torre);
    return 0;
}
