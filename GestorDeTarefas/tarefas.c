#include "tarefas.h"

// Inicializa as listas de tarefas
void inicializar_listas(ListaTarefas listas[]) {
	int i;
    for ( i = 0; i <= MAX_PRIORIDADE; i++) {
        listas[i].primeira = NULL;
    }
}

// Adiciona uma nova tarefa
void adicionar_tarefa(ListaTarefas listas[], int prioridade, const char *id) {
    if (prioridade < 0 || prioridade > MAX_PRIORIDADE) {
        printf("Erro: Prioridade inválida!\n");
        return;
    }

    // Criar nova tarefa
    Tarefa *nova = (Tarefa *)malloc(sizeof(Tarefa));
    if (!nova) {
        printf("Erro: Falha ao alocar memória!\n");
        return;
    }

    strcpy(nova->id, id);
    nova->prioridade = prioridade;
    nova->data_criacao = time(NULL);
    nova->proxima = NULL;

    // Inserir ordenado por data de criação
    Tarefa **atual = &(listas[prioridade].primeira);
    while (*atual && (*atual)->data_criacao > nova->data_criacao) {
        atual = &((*atual)->proxima);
    }
    nova->proxima = *atual;
    *atual = nova;

    printf("Tarefa adicionada: %s (Prioridade %d)\n", id, prioridade);
}

// Lista as tarefas com a prioridade indicada ou superior
void listar_tarefas(ListaTarefas listas[], int prioridade) {
    if (prioridade < 0 || prioridade > MAX_PRIORIDADE) {
        printf("Erro: Prioridade inválida!\n");
        return;
    }

    printf("\nTarefas com prioridade >= %d:\n", prioridade);
    int encontrou = 0;
    int j;
    for (j = MAX_PRIORIDADE; j >= prioridade; j--) {
        Tarefa *atual = listas[j].primeira;
        while (atual) {
            printf("ID: %s | Prioridade: %d | Criada em: %s", 
                   atual->id, atual->prioridade, ctime(&(atual->data_criacao)));
            atual = atual->proxima;
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma tarefa encontrada.\n");
    }
}

// Remove uma tarefa pelo ID
void concluir_tarefa(ListaTarefas listas[], const char *id) {
	int z;
    for (z = 0; z <= MAX_PRIORIDADE; z++) {
        Tarefa **atual = &(listas[z].primeira);
        while (*atual) {
            if (strcmp((*atual)->id, id) == 0) {
                Tarefa *remover = *atual;
                *atual = remover->proxima;
                free(remover);
                printf("Tarefa concluída: %s\n", id);
                return;
            }
            atual = &((*atual)->proxima);
        }
    }
    printf("TAREFA INEXISTENTE\n");
}

// Libera a memória alocada
void liberar_memoria(ListaTarefas listas[]) {
	int k;
    for ( k = 0; k <= MAX_PRIORIDADE; k++) {
        Tarefa *atual = listas[k].primeira;
        while (atual) {
            Tarefa *remover = atual;
            atual = atual->proxima;
            free(remover);
        }
    }
}

