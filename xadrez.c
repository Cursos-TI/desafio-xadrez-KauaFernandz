#include <stdio.h>

int main(void) {
    /* Movimento da Torre*/
    int torre = 0;
    const int movimento = 5; /* casas a mover */

    printf("=== Torre ===\n");
    printf("Posição inicial da torre: %d\n", torre);
    /* salto direto*/
    printf("Posição atual da torre: %d\n", torre);
    torre += movimento;
    printf("Peça movimentada %d casas para a direita!\n", movimento);

    printf("Movimento concluído. Posição final da torre: %d\n\n", torre);

    /* Movimento da Rainha*/
    int rainha = 8;
    const int movimento_rainha = 8;
    int destino = rainha - movimento_rainha;

    printf("=== Rainha ===\n");
    printf("Posição inicial da rainha: %d\n", rainha);
    if (destino < 0) {
        rainha = 0;
        printf("Movimento ultrapassaria a borda. A rainha vai para a posição 0.\n");
    } else {
        rainha = destino;
        printf("Peça movimentada %d casas para a esquerda! Nova posição: %d\n",
               movimento_rainha, rainha);
    }

    printf("Movimento concluído. Posição final da rainha: %d\n\n", rainha);

    /* Movimento do Bispo (5 casas na diagonal para cima e à direita) */
    int bispo_linha = 5;   /* iniciado em linha 5 para que, ao mover 5 para cima, chegue a 0 */
    int bispo_coluna = 0;
    const int passos_bispo = 5;

    printf("=== Bispo ===\n");
    printf("Posição inicial do bispo: (linha=%d, coluna=%d)\n", bispo_linha, bispo_coluna);

    /* Verifica se o salto direto é válido dentro do tabuleiro 0..7 */
    if (bispo_linha - passos_bispo < 0 || bispo_coluna + passos_bispo > 7) {
        printf("Movimento inválido: ultrapassaria a borda do tabuleiro.\n");
    } else {
        /* Aplica salto direto e imprime cada casa da diagonal. */
        for (int i = 1; i <= passos_bispo; i++) {
            bispo_linha -= 1;   /* cima */
            bispo_coluna += 1;  /* direita */
            printf("Passo %d:\n", i);
            printf("Cima\n");
            printf("Direita\n");
        }
        printf("Movimento do bispo concluído.\n");
    }

    printf("\n");
    /* Movimento do Cavalo (2 para baixo e 1 para esquerda) */

    int cavalo_linha = 0;   /* posição inicial do cavalo (linha)  - exemplo */
    int cavalo_coluna = 5;  /* posição inicial do cavalo (coluna) - exemplo */

    /* Entradas (definidas em código) */
    const int passos_para_baixo = 2;  /* duas casas para baixo */
    const int passos_para_esquerda = 1; /* uma casa para esquerda */

    printf("=== Cavalo ===\n");
    
    for (int movimentoL = 0; movimentoL < 1; movimentoL++) {
        /* mover para baixo - usando while */
        int feitos = 0;
        while (feitos < passos_para_baixo) {
            cavalo_linha += 1; /* "baixo" -> aumenta a linha */
            feitos++;
            printf("Baixo\n");
        }

        /* mover para esquerda - usando do-while) */
        int feitos_esq = 0;
        do {
            cavalo_coluna -= 1; /* "esquerda" -> diminui a coluna */
            feitos_esq++;
            printf("Esquerda\n");
        } while (feitos_esq < passos_para_esquerda);
    }

    printf("Movimento do cavalo concluído.\n");

    return 0;
}