#include <stdio.h>
#include "banco.h"

int contaValida(int id) {
    int index = id - 1;
    if (id > 0 && id <= MAX_CLIENTES && bancoDados[index].ativo) {
        return 1;
    }
    return 0;
}

void depositar(int idUsuario, float valor) {
    if (valor <= 0) return;

    if (contaValida(idUsuario)) {
        bancoDados[idUsuario - 1].saldo += valor;
        printf("Sucesso: Deposito de R$ %.2f realizado!\n", valor);
    } else {
        printf("Erro: Conta invalida.\n");
    }
}

int sacar(int idUsuario, float valor) {
    if (valor <= 0) return 0;

    if (contaValida(idUsuario)) {
        if (bancoDados[idUsuario - 1].saldo >= valor) {
            bancoDados[idUsuario - 1].saldo -= valor;
            return 1;
        }
    }
    return 0;
}

int transferir(int idOrigem, int idDestino, float valor) {
    if (valor <= 0) return 0;
    if (idOrigem == idDestino) return 0;
    if (contaValida(idOrigem) && contaValida(idDestino)) {
        if (bancoDados[idOrigem - 1].saldo >= valor) {
            bancoDados[idOrigem - 1].saldo -= valor;
            bancoDados[idDestino - 1].saldo += valor;
            return 1;
        }
    }
    return 0;
}