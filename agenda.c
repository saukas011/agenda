#include <stdio.h>

#define MAX_CONTATOS 100

struct contato{
    int codigo;
    char nome[30];
    char telefone[11];
    int tipo; //pessoal ou trabalho
};

void incluir(struct contato contatos[], int *totalContatos);
void excluir(struct contato contatos[], int *totalContatos);
void alterar(struct contato contatos[], int totalContatos);
void listar(struct contato contatos[], int totalContatos);
void localizar(struct contato contatos[], int totalContatos);

struct contato contatos[MAX_CONTATOS];

int main(){
    int opcao;
    int totalContatos = 0;

    printf("bem-vindo à sua agenda! o que gostaria de fazer?\n");
    do{    
        printf("| 1 - incluir um novo contato              |\n");
        printf("| 2 - excluir um contato existente         |\n");
        printf("| 3 - alterar um contato existente         |\n");
        printf("| 4 - listar todos os contatos cadastrados |\n");
        printf("| 5 - localizar um contato                 |\n");
        printf("| 0 - fechar programa :(                   |\n");
        printf("> ");

        scanf("%d", &opcao);
    
        switch(opcao){
            case 1: incluir(contatos, &totalContatos); break;
            case 2: excluir(contatos, &totalContatos); break;
            case 3: alterar(contatos, totalContatos); break;
            case 4: listar(contatos, totalContatos); break;
            case 5: localizar(contatos, totalContatos);
        }

    }while(opcao!=0);
}

void incluir(struct contato contatos[], int *totalContatos){

    printf("codigo do contato> ");
    scanf("%d", &contatos[*totalContatos].codigo);

    printf("nome do contato> ");
    scanf("%s", &contatos[*totalContatos].nome);

    printf("telefone do contato> ");
    scanf("%11s", &contatos[*totalContatos].telefone);

    int tipo;
    printf("o contato é:\n");
    printf("1 - trabalho\n");
    printf("2 - pessoal\n");
    printf("> ");
    scanf("%d", &tipo);
    contatos[*totalContatos].tipo = tipo;
    

    printf("\ncontato adicionado!\n");
    printf("           |%s|\n", &contatos[*totalContatos].nome);
    printf("código.........%d \n", contatos[*totalContatos].codigo);
    printf("numero:....(%c%c)", contatos[*totalContatos].telefone[0], contatos[*totalContatos].telefone[1]);
    for(int i = 2; i<=11; i++){
        printf("%c", contatos[*totalContatos].telefone[i]);
        if(i==6){
            printf("-");
        }
    }
    if(tipo==1){
        printf("\n           |trabalho|\n\n");
    }else{
        printf("\n           |pessoal|\n\n");
    }

    (*totalContatos)++;
}

void excluir(struct contato contatos[], int *totalContatos){
    int opcao;
    printf("qual contato deseja excluir?\n");
    printf("1 - escolher por código");
    printf("2 - não sei o código (listar contatos)");
    scanf("%d", opcao);

    if(opcao==2){
        listar;
    }
}

void alterar(struct contato contatos[], int totalContatos){
}

void listar(struct contato contatos[], int totalContatos){
    for(int i = 0; i<totalContatos; i++){
        printf("%s", contatos[totalContatos].codigo);
        printf("...");
        printf("%s", contatos[totalContatos].nome);
        printf("...");
        printf("(%s%s)", contatos[totalContatos].telefone[0], contatos[totalContatos].telefone[1]);
        for(i=2; i<11; i++){
            printf("%c", contatos[totalContatos].telefone[i]);
            if(i==6){
                printf("-");
            }
        }
    }
}
void localizar(struct contato contatos[], int totalContatos){
}
