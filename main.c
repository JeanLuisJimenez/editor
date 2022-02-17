#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_spaces(char *cadena, int index);
void sentence_case(char *text);
void title_case(char *text);
void sustituir (char *text);

int main()
{
    printf("ICC-103 – PUCMM – Jean Luis Jimenez – 10135117 - Práctica #2\n");

    char cadena_1[100], cadena_2[100];

    printf("Introduzca una cadena de texto: \n");
    scanf("%[^\n]%*c", &cadena_1);

    printf("Introduzca otra cadena de texto: \n");
    scanf("%[^\n]%*c", &cadena_2);

    strncat(cadena_1, cadena_2, 100); // Concatenar/entrelazar cadena

    printf("Cadena entrelazada es:\n'%s'\n\n", cadena_1);

    char cadena_copy[100];

    strncpy(cadena_copy, cadena_1, 100);
    remove_spaces(cadena_copy, 0);

    printf("Cadena sin espacios al principio:\n'%s'\n\n", cadena_copy);

    strncpy(cadena_copy, cadena_1, 100);
    strrev(cadena_copy);
    remove_spaces(cadena_copy, 0);
    strrev(cadena_copy);
    printf("Cadena sin espacios al final:\n'%s'\n\n", cadena_copy);

    strncpy(cadena_copy, cadena_1, 100);
    printf("Mayusculas: %s\n", strupr(cadena_copy));

    strncpy(cadena_copy, cadena_1, 100);
    printf("Minusculas: %s\n", strlwr(cadena_copy));

    strncpy(cadena_copy, cadena_1, 100);
    sentence_case(cadena_copy);
    printf("Sentence case: %s\n", cadena_copy);

    strncpy(cadena_copy, cadena_1, 100);
    title_case(cadena_copy);
    printf("Title case: %s\n", cadena_copy);

    strncpy(cadena_copy, cadena_1, 100);
    sustituir(cadena_copy);
    printf("Sustituir: %s\n", cadena_copy);

    return 0;
}

void remove_spaces(char *cadena, int index) {
    if (cadena[index] == 32) {
        cadena[index] = '\r';

        remove_spaces(cadena, ++index);
    }

    return;
}

void sentence_case(char *text) {
    int index = 0, length = strlen(text);

    for (; index < length; index++) {
        if (index == 0 && text[index] >= 'a' && text[index] <= 'z') {
            text[index] -= 32;
            continue;
        }

        if (text[index] == '.') {
            if (text[index + 1] == ' ' && text[index + 2] >= 'a' && text[index + 2] <= 'z') text[index + 2] -= 32;
            else if (text[index + 1] >= 'a' && text[index + 1] <= 'z') text[index + 1] -= 32;
        }
    }
}

void title_case(char *text) {
    int index = 0, length = strlen(text);

    for (; index < length; index++) {
        if (index == 0 && text[index] >= 'a' && text[index] <= 'z') {
            text[index] -= 32;
            continue;
        }

        if (text[index] == ' ' && text[index + 1] >= 'a' && text[index + 1] <= 'z') {
            text[index + 1] -= 32;
        }
    }
}

void sustituir (char *text) {
    char por;
    char *ref;
    char sus[10];

    printf("Indique el caracter que desea sustituir:\n");
    scanf("%[^\n]%*c", sus);
    ref = strstr(text, sus);

    if (!ref) {
        printf("Error: la subcadena que ha introducido no se encuentra en la cadena principal\n");
        sustituir(text);
        return;
    }

    printf("Indique el caracter por el que sustituir:\n");
    scanf("%c", &por);

    int index = 0;
    while(text[index]) {
        if (text[index] == *sus) text[index] = por;
        index++;
    }
}
