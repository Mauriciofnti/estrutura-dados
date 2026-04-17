// Lista encadeada com alocação dinâmica
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da lista
typedef struct Node {
    char nome[31];
    struct Node *proximo;
} Node;

// Função para criar um novo nó
Node* criarNo(char *nome) {
    Node *novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo) {
        strncpy(novoNo->nome, nome, 30);
        novoNo->nome[30] = '\0'; // Garante o caractere nulo
        novoNo->proximo = NULL;
    }
    return novoNo;
}

// Inserção em ordem alfabética
void inserir(Node **cabeca, char *nome) {
    Node *novo = criarNo(nome);
    if (!novo) return;

    // Caso 1: Lista vazia ou nome deve vir antes do primeiro elemento
    if (*cabeca == NULL || strcmp(nome, (*cabeca)->nome) < 0) {
        novo->proximo = *cabeca;
        *cabeca = novo;
    } else {
        // Caso 2: Procurar a posição correta no meio ou fim
        Node *atual = *cabeca;
        while (atual->proximo != NULL && strcmp(nome, atual->proximo->nome) > 0) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
    printf("Nome '%s' inserido com sucesso!\n", nome);
}

// Excluir um nome específico
void excluir(Node **cabeca, char *nome) {
    Node *atual = *cabeca;
    Node *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Nome '%s' nao encontrado.\n", nome);
        return;
    }

    if (anterior == NULL) {
        *cabeca = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Nome '%s' removido.\n", nome);
}

// Listar todos os elementos
void listar(Node *cabeca) {
    if (cabeca == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    printf("\n--- Lista de Nomes ---\n");
    while (cabeca != NULL) {
        printf("- %s\n", cabeca->nome);
        cabeca = cabeca->proximo;
    }
}

int main() {
    Node *lista = NULL;
    int opcao;
    char buffer[31];

    do {
        printf("\n1. Inserir Nome\n2. Excluir Nome\n3. Listar Nomes\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch(opcao) {
            case 1:
                printf("Digite o nome: ");
                fgets(buffer, 31, stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; // Remove o \n do fgets
                inserir(&lista, buffer);
                break;
            case 2:
                printf("Digite o nome para excluir: ");
                fgets(buffer, 31, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                excluir(&lista, buffer);
                break;
            case 3:
                listar(lista);
                break;
        }
    } while (opcao != 0);

    return 0;
}
