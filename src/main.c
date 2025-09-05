#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char numero[20];
    char profissao[50];
} Cadastro;

void lerOpcao(char *opcao) {
    char entrada[10];
    fgets(entrada, sizeof(entrada), stdin);
    *opcao = entrada[0];
}

void cadastrarUsuario(Cadastro *c) {
    printf("Nome do contato: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0';

    printf("Numero (sem espacos e simbolos): ");
    fgets(c->numero, sizeof(c->numero), stdin);
    c->numero[strcspn(c->numero, "\n")] = '\0';

    printf("Profissao: ");
    fgets(c->profissao, sizeof(c->profissao), stdin);
    c->profissao[strcspn(c->profissao, "\n")] = '\0';
}

void listarContatos(Cadastro lista_telefonica[], int total_contatos) {
    if (total_contatos == 0) {
        printf("Nenhum contato registrado.\n");
    } else {
        printf("\n--- Lista de Contatos ---\n");
        for (int i = 0; i < total_contatos; i++) {
            printf("Nome: %s\n", lista_telefonica[i].nome);
            printf("Numero: %s\n", lista_telefonica[i].numero);
            printf("Profissao: %s\n\n", lista_telefonica[i].profissao);
        }
    }
}

int main() {
    Cadastro lista_telefonica[100];
    int total_contatos = 0;
    char opcao_menu;
    char continuar_cadastro;

    while (1) {
        printf("\nO que deseja fazer?\n");
        printf("1 - Acessar lista de contatos\n");
        printf("2 - Adicionar novo contato\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        lerOpcao(&opcao_menu);

        switch (opcao_menu) {
            case '1':
                listarContatos(lista_telefonica, total_contatos);
                break;

            case '2':
                do {
                    cadastrarUsuario(&lista_telefonica[total_contatos]);
                    total_contatos++;

                    printf("Deseja adicionar outro contato? (1 - Sim / 2 - Nao): ");
                    lerOpcao(&continuar_cadastro);

                } while (continuar_cadastro == '1' && total_contatos < 100);
                break;

            case '3':
                printf("Saindo\n");
                exit(0);

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}
