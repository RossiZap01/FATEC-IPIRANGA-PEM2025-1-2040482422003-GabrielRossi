/*-------------------------------------------------------*
 * Disciplina: Programaçao Estruturada e Modular          *
 *          Prof. Veríssimo                               *
 *--------------------------------------------------------*
 * Objetivo do Programa: Calcular notas e exibir media    *
 * Data - 24/03/2025                                      *
 * Autor: Gabriel Rossi                                   *
 *--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define NUM_RUAS 3    
#define NUM_GONDOLAS 10 
#define TAM_NOME 20

typedef struct {
    char produto[TAM_NOME];
} Gondola;

typedef struct {
    Gondola gondolas[NUM_GONDOLAS];
} Rua;

Rua estoque[NUM_RUAS];

void inicializarEstoque() {
    for (int i = 0; i < NUM_RUAS; i++) {
        for (int j = 0; j < NUM_GONDOLAS; j++) {
            strcpy(estoque[i].gondolas[j].produto, "Vazio");
        }
    }
}

int getRuaIndex(char rua) {
    switch (rua) {
        case 'A': return 0;
        case 'B': return 1;
        case 'C': return 2;
        default: return -1;
    }
}

void estocarProduto(char rua, int gondola, const char* produto) {
    int ruaIndex = getRuaIndex(rua);
    if (ruaIndex == -1 || gondola < 1 || gondola > NUM_GONDOLAS) {
        printf("Erro: Rua ou Gondola invalida!\n");
        return;
    }
    
    Gondola *g = &estoque[ruaIndex].gondolas[gondola - 1];
    if (strcmp(g->produto, "Vazio") != 0) {
        printf("Erro: Gondola já ocupada!\n");
        return;
    }
    
    strcpy(g->produto, produto);
    printf("Produto %s estocado na Rua %c, Gondola %d.\n", produto, rua, gondola);
}

void retirarProduto(char rua, int gondola, const char* produto) {
    int ruaIndex = getRuaIndex(rua);
    if (ruaIndex == -1 || gondola < 1 || gondola > NUM_GONDOLAS) {
        printf("Erro: Rua ou Gondola inválida!\n");
        return;
    }
    
    Gondola *g = &estoque[ruaIndex].gondolas[gondola - 1];
    if (strcmp(g->produto, produto) != 0) {
        printf("Erro: Produto nao encontrado ou gondola errada!\n");
        return;
    }
    
    strcpy(g->produto, "Vazio");
    printf("Produto %s retirado da Rua %c, Gondola %d.\n", produto, rua, gondola);
}

void executarOperacao(char operacao) {
    char rua, produto[TAM_NOME];
    int gondola;
    
    printf("Digite o codigo do produto (ex: S123): ");
    scanf("%s", produto);
    
    printf("Digite a Rua (A, B, C): ");
    scanf(" %c", &rua);
    
    printf("Digite a Gondola (1-10): ");
    scanf("%d", &gondola);
    
    if (operacao == 'E' || operacao == 'e') {
        estocarProduto(rua, gondola, produto);
    } else if (operacao == 'R' || operacao == 'r') {
        retirarProduto(rua, gondola, produto);
    } else {
        printf("Operacao invalida! Tente novamente.\n");
    }
}

int main() {
    inicializarEstoque();
    
    char operacao;
    while (1) {
        printf("\nEscolha uma operacao: (E)stocar / (R)etirar / (S)air: ");
        scanf(" %c", &operacao);
        
        if (operacao == 'S' || operacao == 's') {
            break;
        }
        
        executarOperacao(operacao);
    }
    
    return 0;
}
