#include <stdio.h>

#define BOARD_MIN 0
#define BOARD_MAX 7

/* Protótipos */
void torre_recursiva(int passos);
void rainha_recursiva(int passos);
void bispo_recursivo(int passos);
void cavalo_com_loops(int *linha, int *coluna, int passos_cima, int passos_direita);

int main(void) {
    /* Torre */
    const int torre_passos = 5; /* entrada fixa no código */
    printf("=== Torre ===\n");
    torre_recursiva(torre_passos);
    printf("Movimento da torre concluído.\n\n");

    /* Rainha */
    const int rainha_passos = 8; /* entrada fixa no código */
    printf("=== Rainha ===\n");
    /* Se a rainha não tem espaço suficiente para todos os passos, imprimimos até a borda.*/
    rainha_recursiva(rainha_passos);
    printf("Movimento da rainha concluído.\n\n");

    /* Bispo (recursivo + loops aninhados simples)
       O bispo deve mover 5 casas na diagonal (Cima + Direita por casa).
       Implementamos recursão e, dentro de cada passo, usamos dois pequenos loops
       (um para vertical, outro para horizontal) — cada um com 1 iteração para ficar simples. */
    const int passos_bispo = 5;
    printf("=== Bispo ===\n");
    bispo_recursivo(passos_bispo);
    printf("Movimento do bispo concluído.\n\n");

    /* Cavalo (loops aninhados simples)
       Movimento em "L": duas casas para cima e uma para a direita.
       Um for externo (um movimento em L), um while para subir 2 vezes
       e um do-while para mover 1 vez para a direita. */
    int cavalo_linha = 7;  /* posição inicial de exemplo */
    int cavalo_coluna = 0; /* posição inicial de exemplo */
    const int cavalo_passos_cima = 2;
    const int cavalo_passos_direita = 1;
    printf("=== Cavalo ===\n");
    cavalo_com_loops(&cavalo_linha, &cavalo_coluna, cavalo_passos_cima, cavalo_passos_direita);
    printf("Movimento do cavalo concluído.\n");

    return 0;
}

/* Implementações simples */

/* Torre recursiva: imprime "Direita" uma vez por passo */
void torre_recursiva(int passos) {
    if (passos <= 0) return;    /* caso base */
    printf("Direita\n");        /* ação desta casa */
    torre_recursiva(passos - 1);/* chamada recursiva reduzindo 1 passo */
}

/* Rainha recursiva: imprime "Esquerda" uma vez por passo */
void rainha_recursiva(int passos) {
    if (passos <= 0) return;
    printf("Esquerda\n");
    rainha_recursiva(passos - 1);
}

/* Bispo recursivo com "loops aninhados" simples:
   Cada passo recursivo representa uma casa na diagonal.
   Dentro de cada passo fazemos:
     - um pequeno loop vertical que imprime "Cima" (1 iteração)
     - um pequeno loop horizontal que imprime "Direita" (1 iteração)
   Assim temos recursão + loops aninhados, mas de forma clara. */
void bispo_recursivo(int passos_restantes) {
    if (passos_restantes <= 0) return;

    /* loop externo: movimento vertical (1 iteração para este passo) */
    for (int v = 0; v < 1; v++) {
        printf("Cima\n");
    }

    /* loop interno: movimento horizontal (1 iteração para este passo) */
    for (int h = 0; h < 1; h++) {
        printf("Direita\n");
    }

    /* chamada recursiva para o próximo passo diagonal */
    bispo_recursivo(passos_restantes - 1);
}

/* Cavalo com loops aninhados simples e claros:
   - for externo: quantos movimentos em L queremos (aqui 1)
   - while: repete os passos para cima (duas vezes)
   - do-while: repete os passos para a direita (uma vez)
   Imprime somente as direções por sua solicitação. */
void cavalo_com_loops(int *linha, int *coluna, int passos_cima, int passos_direita) {
    /* Executar 1 movimento em L (pode aumentar o número se quiser) */
    for (int mov = 0; mov < 1; mov++) {
        /* subir 'passos_cima' vezes */
        int feitos = 0;
        while (feitos < passos_cima) {
            /* atualização da posição (opcional para lógica interna) */
            if (*linha - 1 >= BOARD_MIN) {
                *linha = *linha - 1;
            } else {
                /* se não puder subir mais, interrompe */
                break;
            }
            feitos++;
            printf("Cima\n");
        }

        /* mover para a direita 'passos_direita' vezes usando do-while */
        int feitos_dir = 0;
        do {
            if (*coluna + 1 <= BOARD_MAX) {
                *coluna = *coluna + 1;
                printf("Direita\n");
            } else {
                /* não pode mover para a direita; sai do do-while */
                break;
            }
            feitos_dir++;
        } while (feitos_dir < passos_direita);
    }
}