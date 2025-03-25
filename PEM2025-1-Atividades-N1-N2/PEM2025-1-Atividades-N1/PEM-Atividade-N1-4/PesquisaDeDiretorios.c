/*-------------------------------------------------------*
 * Disciplina: Programaçao Estruturada e Modular          *
 *          Prof. Veríssimo                               *
 *--------------------------------------------------------*
 * Objetivo do Programa: Calcular notas e exibir media    *
 * Data - 25/03/2025                                      *
 * Autor: Gabriel Rossi                                   *
 *--------------------------------------------------------*/
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

// Função recursiva para listar arquivos e subdiretórios
void listarDiretorios(const char *caminho, int nivel) {
    DIR *dir = opendir(caminho); // Abre o diretório
    struct dirent *entry;

    // Verifica se o diretório foi aberto corretamente
    if (dir == NULL) {
        perror("Erro ao abrir diretorio");
        return;
    }

    // Percorre todas as entradas dentro do diretório
    while ((entry = readdir(dir)) != NULL) {
        // Ignora "." e "..", que representam o diretório atual e o diretório pai
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Cria o caminho completo do arquivo ou subdiretório
        char caminhoCompleto[1024];
        snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s/%s", caminho, entry->d_name);

        // Exibe o nome do arquivo ou diretório com recuo proporcional ao nível
        for (int i = 0; i < nivel; i++) {
            printf("  "); // Recuo proporcional ao nível de profundidade
        }
        printf("%s\n", entry->d_name);

        // Se for um diretório, chama a função recursivamente
        if (entry->d_type == DT_DIR) {
            listarDiretorios(caminhoCompleto, nivel + 1); // Recurssão para subdiretório
        }
    }

    closedir(dir); // Fecha o diretório
}

int main() {
    char caminho[1024];

    // Solicita o caminho do diretório para o usuário
    printf("Digite o caminho do diretorio: ");
    scanf("%s", caminho);

    // Inicia a função recursiva para listar a árvore de diretórios
    listarDiretorios(caminho, 0);

    return 0;
}
