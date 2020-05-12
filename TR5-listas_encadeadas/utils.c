int read_integer() {
    char str[15];
    int number = 0;

    fgets(str, 15, stdin);
    number = strtol(str, NULL, 10);


    return number;
}
