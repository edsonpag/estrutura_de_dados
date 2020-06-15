int read_integer() {
    char *str, *aux;
    int serializedStr;

    str = (char *) malloc(sizeof(char));
    fgets(str, sizeof str, stdin);

    serializedStr = strtol(str, &aux, 10);

    return serializedStr;
}