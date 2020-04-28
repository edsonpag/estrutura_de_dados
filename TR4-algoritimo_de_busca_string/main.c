#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCII 256
#define NUMBER_PRIME 3

char str[1000000];

void hash(char *word, char *file, int hash_word) {

    int hash_file;
    int i = 0;

    for(hash_file = 0; hash_file < hash_word; i++) {
        hash_file += file[i];
        if(hash_file == hash_word) {
            printf("Ok");
        }
    }
}

void rabin_karp(char *word, char *file) {
    const int word_length = strlen(word) - 1;
    //const int file_length = strlen(file);

    int hash_word = 0;

    for(int i = 0; i < word_length; i++) {
        hash_word += word[i];
    }

    hash(word, file, hash_word);
}


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

void read_file() {
    char auxiliar[100];
    
    FILE *file;
    file = fopen("arquivo.txt", "r");
    
    while(fgets(auxiliar, 100, file) != NULL) {
        strcat(str, auxiliar);
    }
}

int main() {
    const int word_length = 50; 
    char word[word_length];
    int verify;

    read_file();


    printf("Digite uma frase para pesquisa:\n");
    fgets(word, word_length, stdin);
    
    /*
    verify = naive(word, str);

    if(verify == 1) {
        printf("Encontramos a palavra/frase: %s\n", word);
    } else {
        printf("Não encontramos a palavra\n");
    }
    */

    rabin_karp(word, str);
}