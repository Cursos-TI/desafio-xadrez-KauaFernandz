#include <stdio.h>

int main(void) {
    /* Movimento da Torre usando while*/
    int torre = 0;                 /* posição atual da torre (coluna) */
    const int movimento = 5;       /* queremos mover 5 casas para a direita */

    printf("=== Torre ===\n");
    printf("Posição inicial da torre: %d\n", torre);
    while (torre < movimento) {
        torre += movimento;
        printf("Peça movimentada %d casas para a direita!\n", movimento);
    }
    printf("Movimento concluído. Posição final da torre: %d\n\n", torre);

    /* Movimento da Rainha usando do-while */
    int rainha = 8;                     /* posição inicial da rainha (coluna) */
    const int movimento_rainha = 8;     /* queremos mover 8 casas para a esquerda */
    int destino;

    printf("=== Rainha ===\n");
    printf("Posição inicial da rainha: %d\n", rainha);
    do {
        destino = rainha - movimento_rainha;
        if (destino < 0) {
            rainha = 0;
            printf("Movimento ultrapassaria a borda. A rainha vai para a posição 0.\n");
        } else {
            rainha = destino;
            printf("Peça movimentada %d casas para a esquerda!\n",
                   movimento_rainha);
        }
    } while (0);
    printf("Movimento concluído.\nPosição final da rainha: %d\n\n", rainha);

    /* Movimento do Bispo usando for:
       O bispo deve mover 5 casas na diagonal para cima e à direita.
       Vamos representar a posição como (linha, coluna).
       Assumimos que "cima" decrementa a linha e "direita" incrementa a coluna.
    */
    int bispo_linha = 7;   /* exemplo: linha inicial (0..7) — 7 = fundo do tabuleiro */
    int bispo_coluna = 0;  /* exemplo: coluna inicial (0..7) — 0 = esquerda do tabuleiro */
    const int passos_bispo = 5; /* número de casas a mover na diagonal */

    printf("=== Bispo ===\n");
    printf("Posição inicial do bispo: (linha=%d, coluna=%d)\n", bispo_linha, bispo_coluna);

    for (int i = 0; i < passos_bispo; i++) {
        /* mover uma casa na diagonal: cima (linha--) e direita (coluna++) */
        bispo_linha -= 1;
        bispo_coluna += 1;

        /* imprimir a descrição do movimento da casa atual */
        printf("Passo %d: Cima, Direita -> posição atual = (linha=%d, coluna=%d)\n",
               i + 1, bispo_linha, bispo_coluna);

        /* opcional: evitar sair do tabuleiro (0..7) */
        if (bispo_linha < 0 || bispo_coluna > 7) {
            printf("Aviso: borda do tabuleiro atingida. Movimentos restantes serão interrompidos.\n");
            break;
        }
    }

    printf("Movimento do bispo concluído. Posição final: (linha=%d, coluna=%d)\n",
           bispo_linha, bispo_coluna);

    return 0;
}