#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PESSOAS 100

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int comparar_idade(const void *a, const void *b) {
    Pessoa *pessoaA = (Pessoa *)a;
    Pessoa *pessoaB = (Pessoa *)b;
    return (pessoaA->idade - pessoaB->idade);
}

void cadastrarPessoa(Pessoa pessoas[], int *numPessoas) {
    if (*numPessoas >= MAX_PESSOAS) {
        printf("Limite de pessoas atingido.\n");
        return;
    }

    printf("Digite o nome da pessoa: ");
    fgets(pessoas[*numPessoas].nome, sizeof(pessoas[*numPessoas].nome), stdin);
    pessoas[*numPessoas].nome[strcspn(pessoas[*numPessoas].nome, "\n")] = '\0';

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoas[*numPessoas].idade);
    (*numPessoas)++;
    getchar();
}

void exibirPessoas(Pessoa pessoas[], int numPessoas) {
    for (int i = 0; i < numPessoas; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
    }
}

int main() {
    Pessoa pessoas[MAX_PESSOAS];
    int numPessoas = 0;
    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Cadastrar pessoa\n");
        printf("2. Exibir pessoas\n");
        printf("3. Ordenar pessoas por idade\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarPessoa(pessoas, &numPessoas);
                break;
            case 2:
                exibirPessoas(pessoas, numPessoas);
                break;
            case 3:
                qsort(pessoas, numPessoas, sizeof(Pessoa), comparar_idade);
                printf("Pessoas ordenadas por idade.\n");
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
