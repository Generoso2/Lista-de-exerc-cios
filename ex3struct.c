#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float preco;
    int quantidade;
} Produto;

void clearbuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarProduto(Produto produtos[], int *numProdutos) {
    if (*numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    printf("Digite o nome do produto: ");
    fgets(produtos[*numProdutos].nome, MAX_NOME, stdin);
    produtos[*numProdutos].nome[strcspn(produtos[*numProdutos].nome, "\n")] = '\0';

    printf("Digite o preço do produto: ");
    scanf("%f", &produtos[*numProdutos].preco);
    clearbuffer();

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produtos[*numProdutos].quantidade);
    clearbuffer();

    (*numProdutos)++;
}

void exibirProdutos(Produto produtos[], int numProdutos) {
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
    }
}

float calcularValorTotalEstoque(Produto produtos[], int numProdutos) {
    float valorTotal = 0.0;
    for (int i = 0; i < numProdutos; i++) {
        valorTotal += produtos[i].preco * produtos[i].quantidade;
    }
    return valorTotal;
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;
    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Cadastrar produto\n");
        printf("2. Exibir produtos\n");
        printf("3. Calcular valor total em estoque\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        clearbuffer();

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &numProdutos);
                break;
            case 2:
                exibirProdutos(produtos, numProdutos);
                break;
            case 3: {
                float valorTotal = calcularValorTotalEstoque(produtos, numProdutos);
                printf("O valor total em estoque é: %.2f\n", valorTotal);
                break;
            }
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
