#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int encrypt();
char * adress();

int main(int argc, char ** argv) {
    FILE * input_file = fopen(argv[1], "r");
    FILE * output_file;

    int size;
    char * key;

    if (input_file) {
        printf("ESCOLHA O TAMANHO DA SUA CHAVE: ");
        scanf("%d", &size); key = malloc(size * sizeof(char));
        printf("INSIRA SUA CHAVE: ");
        scanf("%s", key);

        if (!key) {
            output_file = fopen(adress(), "w");

        }
    } else {
        printf("ARQUIVO NÃO ENCONTRADO.\n");
    }

    return EXIT_SUCCESS;
}

char * adress() {
    int day, month, year, hours, minutes;
    time_t now; time(&now);

    struct tm * local = localtime(&now);

    day = local -> tm_mday;
    month = local -> tm_mon + 1;
    year = local -> tm_year + 1900;

    hours = local -> tm_hour;
    minutes = local -> tm_min;

    char * adress_name = malloc(54 * sizeof(char));
    sprintf(adress_name, "arquivos_gerados/%02d-%02d-%d#%02d:%02d#encrypt.txt", day, month, year, hours, minutes);

    return adress_name;
}

int encrypt() {

}