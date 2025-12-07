#include <stdio.h>
#include <string.h>
#include "banco.h"

void inicializarSistema() {
    for (int i = 0; i < MAX_CLIENTES; i++) {
        bancoDados[i].ativo = 0;
    }
}

int criarConta(char nome[], char senha[]) {
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (!bancoDados[i].ativo) {
            bancoDados[i].id = i + 1;
            strcpy(bancoDados[i].nome, nome);
            strcpy(bancoDados[i].senha, senha);
            bancoDados[i].saldo = 0.0;
            bancoDados[i].ativo = 1;
            return i + 1;
        }
    }
    return -1; 
}

int login(char nome[], char senha[]) {
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (bancoDados[i].ativo &&
            strcmp(bancoDados[i].nome, nome) == 0 &&
            strcmp(bancoDados[i].senha, senha) == 0) {
            return i + 1;
        }
    }
    return -1;
}

