#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica_digito(char k, char n[], int ultima_posicao, int quantidade_digitos) {
    if(k == n[ultima_posicao]) {
        quantidade_digitos++;
    }

    if(ultima_posicao == 0) {
        return quantidade_digitos;
    } else {
        ultima_posicao--;
        verifica_digito(k, n, ultima_posicao, quantidade_digitos);
    }
}

int main() {
    char k = '2';
    char n[] = "245";
    int ultima_posicao = strlen(n) - 1;
    int quantidade_digitos = 0;

    quantidade_digitos = verifica_digito(k, n, ultima_posicao, quantidade_digitos);
    printf("%i\n", quantidade_digitos);
}