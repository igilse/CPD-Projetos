#include "tarefas.h"

int main() {
    ListaTarefas listas[MAX_PRIORIDADE + 1];
    inicializar_listas(listas);

    char comando[20], id[50];
    int prioridade;

    while (1) {
        printf("\nComandos disponíveis: new <prioridade> <id>, list <prioridade>, complete <id>, exit\n");
        printf("Digite um comando: ");
        scanf("%s", comando);

        if (strcmp(comando, "new") == 0) {
            scanf("%d %s", &prioridade, id);
            adicionar_tarefa(listas, prioridade, id);
        } 
        else if (strcmp(comando, "list") == 0) {
            scanf("%d", &prioridade);
            listar_tarefas(listas, prioridade);
        } 
        else if (strcmp(comando, "complete") == 0) {
            scanf("%s", id);
            concluir_tarefa(listas, id);
        } 
        else if (strcmp(comando, "exit") == 0) {
            break;
        } 
        else {
            printf("Comando inválido!\n");
        }
    }

    liberar_memoria(listas);
    return 0;
}

