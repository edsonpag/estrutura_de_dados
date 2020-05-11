int read_integer() {
    char str[15];
    int number = 0;

    fgets(str, 15, stdin);
    number = strtol(str, NULL, 10);


    return number;
}

void verifyResponse(int response) {

    if(response == 1) {
        main();
    } else {
        printf("Saindoo...\n");
    }

}

void askToUserIfHeWantsToContinue() {
    int response = 0;

    printf("Deseja adicionar mais um elemento a lista ?\n");
    printf("Digite 1 para continuar ou 2 para sair\n");

    response = read_integer();

    verifyResponse(response);
}