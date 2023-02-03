#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

int main(int argc, char ** argv) {
    FILE * input_file = fopen(argv[1], "r");

    int size;
    char * key;

    if (input_file) {
        printf("ESCOLHA O TAMANHO DA SUA CHAVE: ");
        scanf("%d", &size); key = malloc(size * sizeof(char));
        printf("INSIRA SUA CHAVE: ");
        scanf("%s", key);
    } else {
        printf("ARQUIVO NÃO ENCONTRADO.\n");
    }

    return EXIT_SUCCESS;
}