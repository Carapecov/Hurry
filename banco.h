#ifndef BANCO_H
#define BANCO_H

#define MAX_CLIENTES 10
#define MAX_NOME 100
#define MAX_SENHA 20

typedef struct {
    int id;                 
    char nome[MAX_NOME];
    char senha[MAX_SENHA];
    float saldo;            
    int ativo;              
} Cliente;

extern Cliente bancoDados[MAX_CLIENTES];


void inicializarSistema();

int criarConta(char nome[], char senha[]);

int login(char nome[], char senha[]);

void depositar(int idUsuario, float valor);
int sacar(int idUsuario, float valor);
int transferir(int idOrigem, int idDestino, float valor);

#endif