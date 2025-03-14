/*-------------------------------------------------------*
 * Disciplina: Programação Estruturada e Modular         *
 *          Prof. Veríssimo                              *
 *--------------------------------------------------------*
 * Objetivo do Programa: Gestão de Estoque               *
 * Data: 05/03/2025                                      *
 * Autor: Gabriel Rossi                                  *
 *--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define NUM_RUAS 3
#define NUM_GONDOLAS 10

char estoque[NUM_RUAS][NUM_GONDOLAS][20];

void inicializarEstoque()
{
    for (int i = 0; i < NUM_RUAS; i++)
    {
        for (int j = 0; j < NUM_GONDOLAS; j++)
        {
            strcpy(estoque[i][j], "Vazio");
        }
    }
}

int getRuaIndex(char rua)
{
    switch (rua)
    {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    default:
        return -1;
    }
}

int estocarProduto(char rua, int gondola, char *produto)
{
    int ruaIndex = getRuaIndex(rua);

    if (ruaIndex == -1 || gondola < 1 || gondola > NUM_GONDOLAS)
    {
        printf("Erro: Rua ou Gôndola inválida!\n");
        return 0;
    }

    if (strcmp(estoque[ruaIndex][gondola - 1], "Vazio") != 0)
    {
        printf("Erro: Gôndola já ocupada!\n");
        return 0;
    }

    strcpy(estoque[ruaIndex][gondola - 1], produto);
    printf("Produto %s estocado na Rua %c, Gôndola %d.\n", produto, rua, gondola);
    return 1;
}

int retirarProduto(char rua, int gondola, char *produto)
{
    int ruaIndex = getRuaIndex(rua);

    if (ruaIndex == -1 || gondola < 1 || gondola > NUM_GONDOLAS)
    {
        printf("Erro: Rua ou Gôndola inválida!\n");
        return 0;
    }

    if (strcmp(estoque[ruaIndex][gondola - 1], produto) != 0)
    {
        printf("Erro: Produto não encontrado ou gôndola errada!\n");
        return 0;
    }

    strcpy(estoque[ruaIndex][gondola - 1], "Vazio");
    printf("Produto %s retirado da Rua %c, Gôndola %d.\n", produto, rua, gondola);
    return 1;
}

int main()
{
    inicializarEstoque();

    char operacao;
    char rua;
    int gondola;
    char produto[20];

    while (1)
    {
        printf("\nEscolha uma operacao: (E)stocar / (R)etirar / (S)air: ");
        scanf(" %c", &operacao);

        if (operacao == 'S' || operacao == 's')
        {
            break;
        }

        printf("Digite o codigo do produto (ex: S123): ");
        scanf("%s", produto);

        printf("Digite a Rua (A, B, C): ");
        scanf(" %c", &rua);

        printf("Digite a Gôndola (1-10): ");
        scanf("%d", &gondola);

        if (operacao == 'E' || operacao == 'e')
        {
            estocarProduto(rua, gondola, produto);
        }
        else if (operacao == 'R' || operacao == 'r')
        {
            retirarProduto(rua, gondola, produto);
        }
        else
        {
            printf("Operação inválida! Tente novamente.\n");
        }
    }

    return 0;
}