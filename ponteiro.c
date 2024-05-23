#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_uppercase(char *str) {
    if (str == NULL) return;

    char *ptr = str;
    while (*ptr != '\0') {
        *ptr = toupper((unsigned char)*ptr);
        ptr++;
    }
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }

        printf("Original: %s\n", str);
        to_uppercase(str);
        printf("Maiúsculas: %s\n", str);
    } else {
        printf("Erro ao ler a string.\n");
    }

    return 0;
}
