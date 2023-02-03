#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define ENCRYPT 3
#define DECRYPT 2

unsigned int SIZE;
char * KEY;

FILE * INPUT_FILE;
FILE * OUTPUT_FILE;

char * adress(int type);
int keyGenerator();
void encrypt();
void decrypt();

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
                    OUTPUT_FILE = fopen(adress(ENCRYPT), "w");
                    if (OUTPUT_FILE) {
                        encrypt();
                    } else {
                        printf("! - NÃO FOI POSSÍVEL CRIAR O ARQUIVO DE SAÍDA.\n");
                    }
                } else {
                    printf("! - NÃO FOI POSSÍVEL CRIAR A CHAVE DE ACESSO.\n");
                } break;
            case 2:
                if (keyGenerator()) {
                    printf("! - CHAVE ACEITA.\n");
                    OUTPUT_FILE = fopen(adress(DECRYPT), "w");
                    if (OUTPUT_FILE) {
                        decrypt();
                    } else {
                        printf("! - NÃO FOI POSSÍVEL CRIAR O ARQUIVO DE SAÍDA.\n");
                    }
                } else {
                    printf("! - CHAVE DE ACESSO INVÁLIDA.\n");
                }
                break;
            case 3:
                break;
            default:
                printf("! - OPÇÃO INVÁLIDA.\n");
        }
    } else {
        printf("! - ARQUIVO NÃO ENCONTRADO.\n");
    }
    fclose(INPUT_FILE);
    fclose(OUTPUT_FILE);
    return EXIT_SUCCESS;
}

int keyGenerator() {
    system("clear"); // windows: "cls"
    printf("-----------------------------------------------\n");
    printf("------------------ CRIPT.COM ------------------\n");
    printf("-----------------------------------------------\n");
    printf("TAMANHO DA CHAVE DE ACESSO: ");
    scanf("%d", &SIZE); 
    KEY = malloc(SIZE * sizeof(char));
    printf("INSIRA SUA CHAVE: ");
    scanf("%s", KEY);
    if (SIZE != strlen(KEY)) return FALSE;
    return TRUE;
}

char * adress(int type) {
    char * adress_name = malloc(100 * sizeof(char));
    int day, month, year, hours, minutes;
    time_t now; time(&now);
    struct tm * local = localtime(&now);
    day = local -> tm_mday;
    month = local -> tm_mon + 1;
    year = local -> tm_year + 1900;
    hours = local -> tm_hour;
    minutes = local -> tm_min;
    sprintf (
        adress_name, 
        (type == ENCRYPT) ? "arquivos_criptografados/%02d-%02d-%d#%02d:%02d#encrypt.txt" : "arquivos_descriptografados/%02d-%02d-%d#%02d:%02d#decrypt.txt",
        day, month, year, hours, minutes
    );
    return adress_name;
}

void encrypt() {
    int i = 0;
    while (!feof(INPUT_FILE)) {
        int character = fgetc(INPUT_FILE);
        fprintf(OUTPUT_FILE, "%d#", character * (int) KEY[i]);
        if (i == SIZE - 1) i = 0;
        else i++;
    }
}

void decrypt() {
    int i = 0;
    int cript_value;
    while (!feof(INPUT_FILE)) {
        fscanf(INPUT_FILE, "%d#", &cript_value);
        fprintf(OUTPUT_FILE, "%c", cript_value / KEY[i]);
        if (i == SIZE - 1) i = 0;
        else i++;
    }
}