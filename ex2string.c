#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char string[100];
    int i;
    int contagem = 0;

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }

    for (i = 0; string[i] != '\0'; ++i){
        char vogais = tolower(string[i]);
        if (vogais == 'a' || vogais == 'e' || vogais == 'i' || vogais == 'o' || vogais == 'u') {
            contagem++;
        }    
    }
    printf("A string possui %d vogais\n", contagem);
}