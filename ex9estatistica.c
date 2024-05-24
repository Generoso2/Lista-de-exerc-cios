#include <stdio.h>
#include <stdlib.h>

double calcularMedia(const int* arr, int tamanho) {
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += arr[i];
    }
    return soma / tamanho;
}

int comparar(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double calcularMediana(int* arr, int tamanho) {
    qsort(arr, tamanho, sizeof(int), comparar);

    if (tamanho % 2 == 0) {
        return (arr[tamanho / 2 - 1] + arr[tamanho / 2]) / 2.0;
    } else {
        return arr[tamanho / 2];
    }
}

int calcularModa(const int* arr, int tamanho) {
    int moda = arr[0];
    int frequencia = 1;
    int max_frequencia = 1;

    for (int i = 1; i < tamanho; i++) {
        if (arr[i] == arr[i - 1]) {
            frequencia++;
        } else {
            frequencia = 1;
        }
        if (frequencia > max_frequencia) {
            moda = arr[i];
            max_frequencia = frequencia;
        }
    }

    return moda;
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int arr[tamanho];

    printf("Digite os elementos do array separados por espaço:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &arr[i]);
    }

    double media = calcularMedia(arr, tamanho);
    double mediana = calcularMediana(arr, tamanho);
    int moda = calcularModa(arr, tamanho);

    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    return 0;
}
