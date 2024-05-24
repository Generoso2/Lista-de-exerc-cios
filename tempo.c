#include <stdio.h>
#include <time.h>

int main() {
    int tam_array;
    int i;
    int soma = 0;
    clock_t inicio, fim;
    double tempo_decorrido;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tam_array);

    int array[tam_array];

    for (i = 0; i < tam_array; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    inicio = clock();

    for (i = 0; i < tam_array; ++i) {
        soma += array[i];
    }

    fim = clock();
    tempo_decorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("A soma dos elementos do array é: %d\n", soma);
    printf("O tempo de execução para calcular a soma foi: %.6f segundos\n", tempo_decorrido);

    return 0;
}