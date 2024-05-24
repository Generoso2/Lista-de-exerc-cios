#include <stdio.h>

int main(){
    int tam_array;
    int i;
    int soma = 0;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tam_array);

    int array[tam_array];

    for (i = 0; i < tam_array; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (i = 0; i < tam_array; ++i){
        soma += array[i];
    }

    printf("A soma dos elementos do array é: %d\n", soma);

    return 0;
}