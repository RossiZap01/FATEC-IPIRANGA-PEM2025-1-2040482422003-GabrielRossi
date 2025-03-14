/*-------------------------------------------------------*
 * Disciplina: Programaçao Estruturada e Modular          *
 *          Prof. Veríssimo                               *
 *--------------------------------------------------------*
 * Objetivo do Programa: Calcular notas e exibir media    *
 * Data - 21/02/2025                                      *
 * Autor: Gabriel Rossi                                   *
 *--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

int main()
{
    int arrayCandidatos;
    printf("A tabela sera realizada com quantos candidatos??(Numero maximo de Candidatos eh 50!!)\n");
    while (1)
    {
        scanf("%d", &arrayCandidatos);
        if (arrayCandidatos > 0 && arrayCandidatos <= 50)
        {
            break;
        }
        else
        {
            printf("Digite um numero valido (entre 1 a 50)\n");
            continue;
        }
    }

    float NF[arrayCandidatos];
    char NomeCandidato[arrayCandidatos][15];

    for (int i = 0; i < arrayCandidatos; i++)
    {
        int PE[4], AC[5], PP[10], EB[3];
        int TotalPE = 0, TotalAC = 0, TotalPP = 0, TotalEB = 0;
        int MaiorNotaPE = 0, MenorNotaPE = 0, MaiorNotaAC = 0, MenorNotaAC = 0;
        int MaiorNotaPP = 0, MenorNotaPP = 0, MaiorNotaEB = 0, MenorNotaEB = 0;

        char nome[15];
        printf("Digite o nome do candidato\n");
        scanf(" %14s", nome);
        strcpy(NomeCandidato[i], nome);
        printf("Candidato %s Reconhecido\n", nome);

        printf("Digite a Primeira nota PE.\n");
        scanf("%d", &PE[0]);
        MaiorNotaPE = MenorNotaPE = PE[0];

        for (int j = 1; j < 4; j++)
        {
            printf("Digite a Proxima nota PE.\n");
            scanf("%d", &PE[j]);
            TotalPE += PE[j];
            if (PE[j] > MaiorNotaPE)
            {
                MaiorNotaPE = PE[j];
            }
            if (PE[j] < MenorNotaPE)
            {
                MenorNotaPE = PE[j];
            }
        }

        printf("Digite a Primeira nota AC.\n");
        scanf("%d", &AC[0]);
        MaiorNotaAC = MenorNotaAC = AC[0];
        for (int j = 1; j < 5; j++)
        {
            printf("Digite a Proxima nota AC.\n");
            scanf("%d", &AC[j]);
            TotalAC += AC[j];
            if (AC[j] > MaiorNotaAC)
            {
                MaiorNotaAC = AC[j];
            }
            if (AC[j] < MenorNotaAC)
            {
                MenorNotaAC = AC[j];
            }
        }

        printf("Digite a Primeira nota PP.\n");
        scanf("%d", &PP[0]);
        MaiorNotaPP = MenorNotaPP = PP[0];
        for (int j = 1; j < 10; j++)
        {
            printf("Digite a Proxima nota PP.\n");
            scanf("%d", &PP[j]);
            TotalPP += PP[j];
            if (PP[j] > MaiorNotaPP)
            {
                MaiorNotaPP = PP[j];
            }
            if (PP[j] < MenorNotaPP)
            {
                MenorNotaPP = PP[j];
            }
        }

        printf("Digite a Primeira nota EB.\n");
        scanf("%d", &EB[0]);
        MaiorNotaEB = MenorNotaEB = EB[0];
        for (int j = 1; j < 3; j++)
        {
            printf("Digite a Proxima nota EB.\n");
            scanf("%d", &EB[j]);
            TotalEB += EB[j];
            if (EB[j] > MaiorNotaEB)
            {
                MaiorNotaEB = EB[j];
            }
            if (EB[j] < MenorNotaEB)
            {
                MenorNotaEB = EB[j];
            }
        }

        NF[i] = (((TotalPE - MaiorNotaPE - MenorNotaPE) * 0.3) +
                 ((TotalAC - MaiorNotaAC - MenorNotaAC) * 0.1) +
                 ((TotalPP - MaiorNotaPP - MenorNotaPP) * 0.4) +
                 ((TotalEB - MaiorNotaEB - MenorNotaEB) * 0.2));
        printf("A nota final do candidato foi: %.2f\n", NF[i]);
    }

    for (int i = 0; i < arrayCandidatos - 1; i++)
    {
        for (int j = 0; j < arrayCandidatos - i - 1; j++)
        {
            if (NF[j] < NF[j + 1])
            {
                float tempNota = NF[j];
                NF[j] = NF[j + 1];
                NF[j + 1] = tempNota;

                char tempNome[15];
                strcpy(tempNome, NomeCandidato[j]);
                strcpy(NomeCandidato[j], NomeCandidato[j + 1]);
                strcpy(NomeCandidato[j + 1], tempNome);
            }
        }
    }

    printf("Candidatos Aprovados:\n");
    for (int i = 0; i < arrayCandidatos && i < 15; i++)
    {
        printf("%d. %s - Nota: %.2f\n", i + 1, NomeCandidato[i], NF[i]);
    }

    return 0;
}