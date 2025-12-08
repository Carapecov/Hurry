#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

Cliente bancoDados[MAX_CLIENTES];

int main() {
    inicializarSistema();

    int opcao = 0;
    int idLogado = -1;

    while (1) {
        printf("\n Sistema Bancario Hurry\n");

        if (idLogado == -1) {
            printf("1. Criar Nova Conta\n");
            printf("2. Entrar (Login)\n");
            printf("3. Sair\n");
            printf("Escolha: ");
            scanf("%d", &opcao);
            limparBuffer();

            if (opcao == 1) {
                char nome[MAX_NOME];
                char senha[MAX_SENHA];

                printf("Nome: ");
                scanf("%[^\n]s", nome);
                limparBuffer();

                printf("Senha: ");
                scanf("%s", senha);
                limparBuffer();

                if (validarSenhaForte(senha)) {
                    int id = criarConta(nome, senha);
                    if (id != -1) {
                        printf("Conta criada! ID: %d\n", id);
                    } else {
                        printf("Erro: Banco cheio.\n");
                    }
                }
            }
            else if (opcao == 2) {
                char nome[MAX_NOME];
                char senha[MAX_SENHA];

                printf("Nome: ");
                scanf("%[^\n]s", nome);
                limparBuffer();

                printf("Senha: ");
                scanf("%s", senha);
                limparBuffer();

                int id = login(nome, senha);
                if (id != -1) {
                    idLogado = id;
                    printf("Bem-vindo, ID %d!\n", id);
                } else {
                    printf("Dados incorretos.\n");
                }
            }
            else if (opcao == 3) {
                break;
            }
        } else {
            printf("Ola, %s (ID: %d)\n", bancoDados[idLogado - 1].nome, idLogado);
            printf("Saldo: R$ %.2f\n", bancoDados[idLogado - 1].saldo);
            printf("1. Depositar\n");
            printf("2. Sacar\n");
            printf("3. Transferir\n");
            printf("4. Sair da Conta\n");
            printf("Escolha: ");
            scanf("%d", &opcao);
            limparBuffer();

            if (opcao == 1) {
                float valor;
                printf("Valor: ");
                scanf("%f", &valor);
                depositar(idLogado, valor);
            }
            else if (opcao == 2) {
                float valor;
                printf("Valor: ");
                scanf("%f", &valor);
                if (sacar(idLogado, valor)) {
                    printf("Saque realizado.\n");
                } else {
                    printf("Erro no saque.\n");
                }
            }
            else if (opcao == 3) {
                int idDestino;
                float valor;
                printf("ID Destino: ");
                scanf("%d", &idDestino);
                printf("Valor: ");
                scanf("%f", &valor);
                if (transferir(idLogado, idDestino, valor)) {
                    printf("Transferencia realizada.\n");
                } else {
                    printf("Erro na transferencia.\n");
                }
            }
            else if (opcao == 4) {
                idLogado = -1;
            }
        }
    }

    return 0;
}