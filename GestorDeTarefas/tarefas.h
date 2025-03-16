#ifndef TAREFAS_H
#define TAREFAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRIORIDADE 5  // Prioridade m�xima

// Estrutura de uma tarefa
typedef struct Tarefa {
    char id[50];              // Identificador da tarefa
    int prioridade;           // Prioridade da tarefa (0 a 5)
    time_t data_criacao;      // Data de cria��o da tarefa
    struct Tarefa *proxima;   // Ponteiro para a pr�xima tarefa
} Tarefa;

// Estrutura de uma lista de tarefas
typedef struct {
    Tarefa *primeira;
} ListaTarefas;

// Fun��es principais
void inicializar_listas(ListaTarefas listas[]);
void adicionar_tarefa(ListaTarefas listas[], int prioridade, const char *id);
void listar_tarefas(ListaTarefas listas[], int prioridade);
void concluir_tarefa(ListaTarefas listas[], const char *id);
void liberar_memoria(ListaTarefas listas[]);

#endif // TAREFAS_H

