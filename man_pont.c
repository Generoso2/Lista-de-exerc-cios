#include <stdio.h>

void inverterArray(const int* arr_original, int* arr_invertido, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr_invertido[i] = arr_original[tamanho - 1 - i];
    }
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int arr_original[tamanho];
    int arr_invertido[tamanho];

    printf("Digite os elementos do array separados por espaço:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &arr_original[i]);
    }

    inverterArray(arr_original, arr_invertido, tamanho);

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr_original[i]);
    }
    printf("\n");

    printf("Array invertido: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr_invertido[i]);
    }
    printf("\n");

    return 0;
}
