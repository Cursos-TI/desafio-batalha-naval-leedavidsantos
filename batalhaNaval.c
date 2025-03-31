#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define MAR 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Vetores para representar os navios (não são usados para armazenar posições, mas ilustram que cada navio tem 3 partes)
    int navio_horizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 4; // Começo do navio horizontal
    int linha_vertical = 5, coluna_vertical = 7;     // Começo do navio vertical

    // Validação simples para garantir que os navios não saem do tabuleiro
    if (coluna_horizontal + TAM_NAVIO > TAM_TABULEIRO || linha_vertical + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        // Verifica se a posição já está ocupada
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] != MAR) {
            printf("Erro: Sobreposição detectada ao posicionar o navio horizontal.\n");
            return 1;
        }
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_vertical + i][coluna_vertical] != MAR) {
            printf("Erro: Sobreposição detectada ao posicionar o navio vertical.\n");
            return 1;
        }
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    // Impressão do tabuleiro
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

