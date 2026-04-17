#include <stdio.h>

#define MAX

int main() {
    int pos = 0;
    int totalDePessoas = 0;

    // typedef struct elemento {
    //     char nome[30];
    //     struct elemento *proximo;        
    // }

    // elemento *lista = Null;

    struct lista {
        char nome[50];
    } pessoa[MAX];

    for (int i = 0; i < MAX; i++) {
        pessoa[i].nome[0] = '\0';
        printf("limpou");
    }

    inserir(nome[]) {
        if (totalDePessoas == MAX) {
            printf("Número MAX de pessoas atingido!!\n");
        }
        for (int i = 0; i < MAX){
            if (pessoa[i].nome[0] == '\0'){
                printf("Informe o nome a ser inserido: ");
                scanf("%s", pessoa[pos]);        
                totalDePessoas++;
            }
        }      
    }

    remover(nome[]) {
        if (totalDePessoas == 0) {
            printf("Nenhuma pessoa cadastrado!!\n");
        }
        char pessoaRemovida;  
        printf("Informe o nome a ser removido: ");
        scanf("%s", pessoa[pos]);
        for (int i = 0; i < MAX; i++) {
            if (pessoa[i].nome == pessoaRemovida) {
                possoa[i].nome[0] = '\0'
            }
        }
        printf("Pessoa %s saiu da fila!\n", pessoa[posFinal].nome);
        pessoa[posFinal].nome[0] = '\0';
        totalDePessoas--;
    }

    consultar(nome[]) {
        char pessoaConsulta;
        printf("Informe o nome a ser consultado: ");
        scanf("%s", )
    }

}