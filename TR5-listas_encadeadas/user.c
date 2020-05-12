void addNewdataToList();
void verifyUserResponse(int response);
void start();
void askToUserIfHeWantsToContinue();

void addNewDataToList() {
    int response = 0;

    printf("Digite o valor para ser adicionado: ");
    response = read_integer();

    addData(response);
    askToUserIfHeWantsToContinue();
}

void verifyUserResponse(int response) {
    if(response == 1) {
        addNewDataToList();
    } else {
        show();
        printf("Saindo...\n");
        exit(0);
    }
}

void start() {
    int response = 0;

    printf("Deseja criar uma lista encadeada?\nDigite 1 para continuar ou Digite 0 para sair\n");
    response = read_integer();

    verifyUserResponse(response);
    
}

void askToUserIfHeWantsToContinue() {
    int response = 0;

    printf("Deseja continuar?\nDigite 1 para continuar ou Digite 0 para sair\n");
    response = read_integer();
    
    verifyUserResponse(response);

}
