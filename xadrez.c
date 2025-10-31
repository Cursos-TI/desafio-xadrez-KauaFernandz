#include <stdio.h>


int main(void) {
    int torre = 0;      // posição atual da peça (coluna)
    const int movimento = 5; // queremos mover 5 casas para a direita

    // printf("Posição inicial da torre: %d\n", torre);

    // mover a peça exatamente 5 casas para a direita uma vez
    while (torre < movimento) {
        // mostra posição antes do movimento
        printf("=== Torre ===\n");
        printf("Posição atual da torre: %d\n", torre);

        // realiza o movimento (adiciona 5)
        torre += movimento;

        // mostra resultado do movimento
        printf("Peça movimentada %d casas para a direita!\n", movimento);
    }

    printf("Movimento concluído. Posição final da torre: %d\n", torre);


//Movimento da Rainha usando do-while

int rainha = 8; // posição inicial da rainha (coluna)
const int movimento_rainha = 8; // queremos mover 8 casas para a esquerda
int destino;
 printf("=== Rainha ===\n");
    printf("Posição atual da rainha: %d\n", rainha);
do {
        destino = rainha - movimento_rainha;
        if (destino < 0) {
            rainha = 0;
            printf("Movimento ultrapassaria a borda. A rainha vai para a posição 0.\n");
        } else {
            rainha = destino;
            printf("Peça movimentada %d casas para a esquerda!\n", movimento_rainha);
        }
} while (0);

printf("Movimento concluído. Posição final da rainha: %d\n", rainha);
 
return 0;
}
