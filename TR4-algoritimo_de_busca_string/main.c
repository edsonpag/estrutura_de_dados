#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file() {
    char *str = malloc(30 * sizeof(char));
    char auxiliar[100];

    FILE *file;
    file = fopen("arquivo.txt", "r");
    
    while(feof(file) == 0) {
        fgets(auxiliar, 100, file);
        strcat(str, auxiliar);
    }

    printf("%s\n", str);
}

int main() {
    char string_search[50];

    read_file();

    printf("Digite uma frase para pesquisa:\n");
    fgets(string_search, 50, stdin);
    printf("%s\n", string_search);

}