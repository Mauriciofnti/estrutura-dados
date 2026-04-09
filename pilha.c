#include <stdio.h>
#include <string.h>

#define MAX 5

int main() {

    int topo = -1; 
    int opcao = -1;

    struct pessoa {
        char nome[50];
        int idade;
        int renda;
    } pilha[MAX];
    
    void inserir(struct pessoa pilha[]) {
        if (topo == MAX - 1) {
            printf("Pilha cheia!!\n");
        } else {
            topo++;
            printf("Informe o nome da pessoa: ");
            scanf("%s", pilha[topo].nome);
            printf("Idade: ");
            scanf("%d", &pilha[topo].idade);
            printf("Renda: ");
            scanf("%d", &pilha[topo].renda);
            printf("Pessoa '%s' adicionada (topo = %d).\n", pilha[topo].nome, topo);
        }
    }
    
    void retirar(struct pessoa pilha[]) {
        if (topo == -1) {
            printf("Pilha vazia!\n");
        } else {
            printf("Usuario %s retirado!\n", pilha[topo].nome);
            topo--;
        }
    }
    
    void listar(struct pessoa pilha[]) {
        if (topo == -1) {
            printf("Nenhum usuário cadastrado!!\n");
        } else {
            printf("Total de pessoas na pilha: %d/%d\n", topo + 1, MAX);
            printf("--- Topo da pilha ---\n");
            for (int i = topo; i >= 0; i--) {
                printf("%d. Nome: %s - Idade: %d - Renda: %d\n", topo - i + 1, pilha[i].nome, pilha[i].idade, pilha[i].renda);
            }
            printf("--- Base da pilha ---\n");
        }
    }
    
    do {
        printf("\n--Pilha de pessoas (LIFO)--\n1-Inserir / 2-Listar / 3-Retirar / 0-Sair:");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1: inserir(pilha); break;
            case 2: listar(pilha); break;
            case 3: retirar(pilha); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}