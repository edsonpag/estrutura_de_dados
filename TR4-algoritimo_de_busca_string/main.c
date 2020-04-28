#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int naive(char *word, char *file) {
    const int word_length = strlen(word) - 1; // -1 para tirar o caractere do enter
    const int file_length = strlen(file);

    for(int i = 0; i <= file_length - word_length; i++) {
        int auxiliar = 0;

        while(auxiliar < word_length && word[auxiliar] == file[i + auxiliar]) {

            auxiliar++;
        }

        if(auxiliar == word_length) {
            return 1;
        }
    }

    return 0;
}

char * read_file() {
    //char *str = malloc(100 * sizeof(char));
    char auxiliar[100];
    

    FILE *file;
    file = fopen("arquivo.txt", "r");
    
    while(feof(file) == 0) {
        fgets(auxiliar, 100, file) != NULL;
        //strcat(str, auxiliar);
    }

    return auxiliar;
}

int main() {
    const int word_length = 50; 
    char word[word_length];
    char *file;
    int verify;

    file = read_file();

    printf("%c", file[0]);

    printf("Digite uma frase para pesquisa:\n");
    fgets(word, word_length, stdin);
    
    verify = naive(word, file);

    if(verify == 1) {
        printf("Encontramos a palavra/frase: %s\n", word);
    } else {
        printf("Não encontramos a palavra\n");
    }
}