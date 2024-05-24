#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char nome[MAX_NAME_LENGTH];
    int idade;
    float salario;
} Funcionario;

void adicionar_funcionario(FILE *arquivo) {
    Funcionario func;

    printf("Digite o nome do funcionário: ");
    scanf("%s", func.nome);
    printf("Digite a idade do funcionário: ");
    scanf("%d", &func.idade);
    printf("Digite o salário do funcionário: ");
    scanf("%f", &func.salario);

    fseek(arquivo, 0, SEEK_END);
    fwrite(&func, sizeof(Funcionario), 1, arquivo);

    printf("Funcionário adicionado com sucesso.\n");
}

void listar_funcionarios(FILE *arquivo) {
    Funcionario func;
    fseek(arquivo, 0, SEEK_SET);

    printf("Lista de Funcionários:\n");
    while (fread(&func, sizeof(Funcionario), 1, arquivo)) {
        printf("Nome: %s, Idade: %d, Salário: %.2f\n", func.nome, func.idade, func.salario);
    }
}

void buscar_funcionario(FILE *arquivo) {
    char nome_busca[MAX_NAME_LENGTH];
    Funcionario func;
    int encontrado = 0;

    printf("Digite o nome do funcionário a ser buscado: ");
    scanf("%s", nome_busca);

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&func, sizeof(Funcionario), 1, arquivo)) {
        if (strcmp(func.nome, nome_busca) == 0) {
            printf("Registro encontrado: Nome: %s, Idade: %d, Salário: %.2f\n", func.nome, func.idade, func.salario);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionário com nome %s não encontrado.\n", nome_busca);
    }
}

int main() {
    FILE *arquivo;
    int opcao;

    arquivo = fopen("funcionarios.dat", "rb+");
    if (arquivo == NULL) {
        arquivo = fopen("funcionarios.dat", "wb+");
        if (arquivo == NULL) {
            perror("Erro ao abrir o arquivo");
            return 1;
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Funcionário\n");
        printf("2. Listar Funcionários\n");
        printf("3. Buscar Funcionário por Nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            adicionar_funcionario(arquivo);
        } else if (opcao == 2) {
            listar_funcionarios(arquivo);
        } else if (opcao == 3) {
            buscar_funcionario(arquivo);
        } else if (opcao == 0) {
            printf("Saindo...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    fclose(arquivo);
    return 0;
}
