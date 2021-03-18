#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int args, char const *argv[]) {
    char PATH[100] = "files/users.csv";

    if (args > 1) { // Otimizar com perror!
        if (strlen(argv[1]) >= 100) { // String too big
            printf("Path string too big");
            exit(-1);
        }
        strcpy(PATH, argv[1]);
    }

    FILE *f = fopen(PATH, "r");
    if (!f) {
        printf("Could not open such file.");
        exit(-1);
    }

    int bufferSize = 1024; // Assume-se que não haverá linhas que tenham mais caracteres do que esta variavel
    char buffer[bufferSize]; //= (char *) malloc(sizeof(char) * bufferSize);
    int linhas = 0;
    int linhasBuffer = 4;
    char **file = (char **) malloc(linhasBuffer * sizeof(char *));

    while (fgets(buffer, bufferSize, f)) {
        if (linhas == linhasBuffer - 2) {
            linhasBuffer *= 2;
            file = (char **) realloc(file, linhasBuffer * sizeof (char *));
        }
        // Passar o '\n' para '\0'
        ssize_t len = strlen((const char *) &buffer);
        buffer[len - 1] = '\0';
        // Escrita no file
        file[linhas] = strndup((const char *) &buffer, len - 1);

        linhas++;
    }

    // Impressão das linhas guardadas
    for (int j = 0; j < linhas; j++) {
        printf("%s", file[j]);
    }
    return 0;
}
