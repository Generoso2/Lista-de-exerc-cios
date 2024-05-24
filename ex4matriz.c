#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente uma matriz de m linhas por n colunas
int** allocate_matrix(int m, int n) {
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    return matrix;
}

// Função para liberar a memória de uma matriz de m linhas
void free_matrix(int **matrix, int m) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Função para multiplicar duas matrizes A (m x n) e B (n x p)
int** multiply_matrices(int **A, int m, int n, int **B, int p) {
    int **C = allocate_matrix(m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Função para transpor uma matriz A (m x n)
int** transpose_matrix(int **A, int m, int n) {
    int **T = allocate_matrix(n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }
    return T;
}

// Função para imprimir uma matriz de dimensão m x n
void print_matrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n, p;

    // Leitura das dimensões das matrizes
    printf("Digite as dimensões da matriz A (m e n): ");
    scanf("%d %d", &m, &n);

    printf("Digite as dimensões da matriz B (n e p): ");
    scanf("%d %d", &n, &p); // n é redefinido para ser compatível

    // Alocação das matrizes A e B
    int **A = allocate_matrix(m, n);
    int **B = allocate_matrix(n, p);

    // Leitura dos elementos da matriz A
    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Leitura dos elementos da matriz B
    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Multiplicação das matrizes
    int **C = multiply_matrices(A, m, n, B, p);

    // Impressão da matriz resultante
    printf("Matriz C (resultado da multiplicação de A e B):\n");
    print_matrix(C, m, p);

    // Transposição da matriz A
    int **T = transpose_matrix(A, m, n);

    // Impressão da matriz transposta
    printf("Matriz T (transposta de A):\n");
    print_matrix(T, n, m);

    // Liberação da memória das matrizes
    free_matrix(A, m);
    free_matrix(B, n);
    free_matrix(C, m);
    free_matrix(T, n);

    return 0;
}
