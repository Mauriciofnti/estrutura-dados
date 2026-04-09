#include <stdio.h>

#define MAX 5

int main() {

    int posInicial = 0;
    int posFinal = 0;
    int totalDePessoas = 0;
    int posFila = 1;
    int opcao = -1;

    struct lista {
        char nome[50];
        int idade;
        int renda;
    } pessoa[MAX];

    for (int i = 0; i < MAX; i++) {
        pessoa[i].nome[0] = '\0';
        printf("limpou");
    }


    void inserir(struct lista pessoa[]) {
        if(MAX == totalDePessoas){
            printf("Lista cheia!!\n");
        } else {
            if (posInicial == 5) {posInicial = 0;}
            printf("Informe o nome da pessoa: ");
            scanf("%s", pessoa[posInicial].nome);
            printf("Idade: ");
            scanf("%d", &pessoa[posInicial].idade);
            printf("Renda: ");
            scanf("%d", &pessoa[posInicial].renda);
            printf("Pessoa '%s' adicionado(a).\n", pessoa[posInicial].nome);
            posInicial++;
            totalDePessoas++;
        }
    }

    void retirar(struct lista pessoa[]) {
        if (totalDePessoas == 0) {
            printf("A lista esta vazia!\n");
        } else {
            if (posFinal == 5){posFinal = 0;}
            printf("Usuario %s saiu da fila!\n", pessoa[posFinal].nome);
            pessoa[posFinal].nome[0] = '\0';
            posFinal++;
            totalDePessoas--;
        }        
    }
    
    void listar(struct lista pessoa[]) {
        if (totalDePessoas == 0) {
            printf("Nenhum usúario cadastrado!!\n");
        } else {
            printf("Total de pessoas cadastradas: %d/%d",totalDePessoas, MAX);
            for (int i = 0; i < MAX; i++) {
                if((pessoa[i].nome[0] != '\0')){
                    printf("\n%d. Nome: %s - Idade: %d Renda: %d", i + 1, pessoa[i].nome, pessoa[i].idade, pessoa[i].renda);
                }
            }
            printf("\n");
        }
    }

    do {        
        printf("\n--Fila de pessoas (FIFO)--\n1-Inserir / 2-Listar / 3-Retirar / 0-Sair: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: inserir(pessoa); break;
            case 2: listar(pessoa); break;
            case 3: retirar(pessoa); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}