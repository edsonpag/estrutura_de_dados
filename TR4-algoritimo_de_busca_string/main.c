#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCII 256
#define NUMBER_PRIME 101

char fullText[5000];

void search(char *word, int world_hash, char *file) {
    int file_hash = 0;
    const int word_length = strlen(word);
    const int file_length = strlen(file);
    int aux = 1;

    for(int i = 0; i < word_length - 1; i++) {
        aux = (aux * ASCII) % NUMBER_PRIME;
    }

    for(int i = 0; i < word_length; i++) {
        file_hash = (ASCII * file_hash + file[i]) % NUMBER_PRIME;
    }

    for(int i = 0; i <= file_length - word_length; i++) {

        if(file_hash == world_hash) {
            int j;

            for(j = 0; j < word_length; j++) {

                if(file[i+j] != word[j]) {
                    j = word_length + 1;
                }

            }

            if(j == word_length) {
                printf("A palavra/frase \"%s\" foi encontrada\n", word);
                printf("Ela inicia no caractere %i e termina no caractere %i\n", i+1, i + word_length);
                exit(0);
            }
 
        }

        if(i < file_length - word_length) {
            file_hash = (ASCII * (file_hash - file[i] * aux) + file[i + word_length]) % NUMBER_PRIME;
        }

        if(file_hash < 0) {
            file_hash = (file_hash + NUMBER_PRIME);
        }
    }

}

int hashWorld(char *word) {
    int world_hash = 0;
    const int word_length = strlen(word);

    for(int i = 0; i <  word_length; i++) {
        world_hash = (ASCII * world_hash + word[i]) % NUMBER_PRIME;
    }

    return world_hash;
}

void rabin_karp(char *word) {
    const int world_hash = hashWorld(word);

    search(word, world_hash, fullText);
}


void naive(char *word, char *file) {
    const int word_length = strlen(word);
    const int file_length = strlen(file);

    for(int i = 0; i <= file_length - word_length; i++) {
        int auxiliar = 0;

        while(auxiliar < word_length && word[auxiliar] == file[i + auxiliar]) {

            auxiliar++;
        }

        if(auxiliar == word_length) {
            printf("A palavra/frase \"%s\" foi encontrada\n", word);
            printf("Ela inicia no caractere %i e termina no caractere %i\n", i + 1, i + auxiliar);
        }
    }
}

char * formattingTheWord(char word[]) {
    int word_length = strlen(word);
    if(word[word_length - 1] == '\n') {
        word[word_length - 1] = '\0';
    }

    return word;
}

void read_file() {
    char text_line[20];
    FILE *file = fopen("arquivo.txt", "r");

    if(file == NULL) {
        printf("Erro na leitura");
    }

    while(fgets(text_line, 20, file) != NULL) {

        for(int i = 0; i < 20 - 1; i++) {

            if(text_line[i] == '\n') {
                text_line[i] = '\0';
            }
        }

        strcat(fullText, text_line);
    }
}

int main() {
    char *word;
    char aux[50];

    read_file();

    printf("Digite uma frase para pesquisa:\n");
    fgets(aux, 50, stdin);

    word = formattingTheWord(aux);

    //naive(word, fullText);

    rabin_karp(word);
}