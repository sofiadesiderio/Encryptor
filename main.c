#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

unsigned int SIZE;
char * KEY;

FILE * INPUT_FILE;
FILE * OUTPUT_FILE;

void encrypt();
char * adress();
int keyGenerator();

int main(int argc, char ** argv) {
    INPUT_FILE = fopen(argv[1], "r");

    int user_choice;

    if (INPUT_FILE) {
        printf("-----------------------------------------------\n");
        printf("------------------ CRIPT.COM ------------------\n");
        printf("-----------------------------------------------\n");
        printf("[1] - CRIPTOGRAFAR ARQUIVO\n");
        printf("[2] - DESCRIPTOGRAFAR ARQUIVO\n");
        printf("[3] - SAIR\n");
        printf("~ Opção escolhida: ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                if (keyGenerator()) {
                    printf("! - CHAVE CRIADA COM SUCESSO.\n");

                    OUTPUT_FILE = fopen(adress(), "w");
                    if (OUTPUT_FILE) {
                        encrypt();
                    } else {
                        printf("! - NÃO FOI POSSÍVEL CRIAR O ARQUIVO DE SAÍDA.\n");
                    }
                } else {
                    printf("! - NÃO FOI POSSÍVEL CRIAR A CHAVE DE ACESSO.\n");
                }
                break;
            case 2:
                break;
            case 3:
                break;
            default:
        }
    } else {
        printf("! - ARQUIVO NÃO ENCONTRADO.\n");
    }

    return EXIT_SUCCESS;
}

int keyGenerator() {
    system("clear"); // windows: "cls"
    printf("ESCOLHA O TAMANHO DA CHAVE DE ACESSO: ");
    scanf("%d", &SIZE); 

    KEY = malloc(SIZE * sizeof(char));

    printf("INSIRA SUA CHAVE: ");
    scanf("%s", KEY);

    if (SIZE != strlen(KEY)) return FALSE;
    return TRUE;
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

void encrypt() {
    int i = 0;
    while (!feof(INPUT_FILE)) {
        int character = fgetc(INPUT_FILE);
        fprintf(OUTPUT_FILE, "%d#", character * (int) KEY[i]);
        if (i < SIZE) i = 0;
        else i++;
    }
}