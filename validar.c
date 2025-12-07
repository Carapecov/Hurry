#include <stdio.h>
#include <string.h>
#include "banco.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removerNovaLinha(char string[]) {
    size_t tamanho = strlen(string);
    if (tamanho > 0 && string[tamanho - 1] == '\n') {
        string[tamanho - 1] = '\0';
    }
}

int validarSenhaForte(char senha[]) {
    if (strlen(senha) < 4) {
        printf("Erro: Senha muito curta! Minimo 4 caracteres.\n");
        return 0;
    }
    return 1;
}