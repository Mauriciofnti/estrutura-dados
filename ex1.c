#include <stdio.h>
#include <string.h>

int main() {
    struct lista {
        char nome[100];
        int dia, mes, ano;
    };

    int qtdPessoa;
    printf("Capacidade maxima da lista: ");
    scanf("%d", &qtdPessoa);
    struct lista pessoa[qtdPessoa];
    int qtd = 0;
    int opcao;

    for (int i = 0; i < qtdPessoa; i++) {
        pessoa[i].nome[0] = '\0';
        printf("limpou");
    }

    void inclusao(struct lista p[], int n, int nPessoa) {
        if(n >= nPessoa) {
            printf("Lista cheia");        
        } else {
            
            int feito = 0;
            for(int i = 0; i <= n; i++){
                if (feito == 0){
                    if (p[i].nome[0] == '\0'){
                        printf("Nome: ");
                        scanf("%s", p[i].nome); 
                        printf("Data (dia mes ano): ");
                        scanf("%d %d %d", &p[i].dia, &p[i].mes, &p[i].ano);
                        printf("\n%s Cadastrado!\n", p[i].nome);
                        feito = 1;     
                        qtd++;
                        break;
                    }           
                } else {
                    printf("Nome: ");
                    scanf("%s", p[n].nome); 
                    printf("Data (dia mes ano): ");
                    scanf("%d %d %d", &p[n].dia, &p[n].mes, &p[n].ano);
                    printf("\n%s Cadastrado!\n", p[n].nome);
                    qtd++;
                    break;
                }                      
            }
        }
        return;

    }

    void listar(struct lista p[], int n) {
        if (n == 0) {
            printf("Nenhum usúario cadastrado!!");
        } else {
            for (int i = 0; i < n; i++) {
                if((p[i].nome[0] != '\0')){
                    printf("\n%d. %s - %d/%d/%d", i + 1, p[i].nome, p[i].dia, p[i].mes, p[i].ano);
                }
            }
            printf("\n");
        }
    }

    void alterar(struct lista p[], int n){
        char nAlterar[100];
        printf("Digite o nome a ser alterado: ");
        scanf("%s", nAlterar);
        for (int i = 0; i < n; i++) {
            if(strcmp(p[i].nome, nAlterar) == 0) {
                printf("Digite o novo nome para %s: ", p[i].nome);
                scanf("%s", p[i].nome);
                printf("Digite a data (dia mes ano) para %s: ", p[i].nome);
                scanf("%d %d %d",  &p[i].dia, &p[i].mes, &p[i].ano);
                printf("\nAlterado!!\n");
                return;
            }
        }
        printf("Pessoa nao encontrada.\n");
    }

    void excluir(struct lista p[], int n) {
        char nExcluir[100];
        int achou = 0;

        if (n == 0) {
            printf("A lista esta vazia!\n");
            return;
        }

        printf("Digite o nome para excluir: ");
        scanf("%s", nExcluir);

        for (int i = 0; i < n; i++) {
            if (strcmp(p[i].nome, nExcluir) == 0) {
                p[i].nome[0] = '\0';
                
                qtd--;
                printf("Usuario %s excluido com sucesso!\n", nExcluir);
                achou = 1;
                break; 
            }
        }

        if (!achou) {
            printf("\nPessoa nao encontrada.\n");
        }
    }

    do {
        printf("\n1-Incluir / 2-Listar / 3-Alterar / 4-Excluir / 0-Sair: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: inclusao(pessoa, qtd, qtdPessoa); break;
            case 2: listar(pessoa, qtdPessoa); break;
            case 3: alterar(pessoa, qtd); break;
            case 4: excluir(pessoa, qtd); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}