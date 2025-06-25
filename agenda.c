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
    if(*totalContatos==0){
    printf("você ainda não tem contatos\n\n");
    return;
    }

    int opcao, codigo;
    printf("qual contato deseja excluir?\n");
    printf("1 - escolher por código\n");
    printf("2 - não sei o código (listar contatos)\n");
    printf("> ");
    scanf("%d", &opcao);

    if(opcao==2){
        listar(contatos, *totalContatos);
    }
    printf("\ninsira o código do contato a ser excluído\n");
    printf("> "); scanf("%d", codigo);

    for(int i = 0; i<*totalContatos; i++){
        if(codigo==contatos[i].codigo){
            for(int j = i+1; j<*totalContatos; j++){
                contatos[i]=contatos[j];
            }
        }
    }
    (*totalContatos)--;
}

void alterar(struct contato contatos[], int totalContatos){
    int codigo, opcao;
    printf("digite o código do contato que deseja alterar\n");
    printf("> ");
    scanf("%d", codigo);

    printf("o que deseja alterar?\n");
    printf("1 - telefone\n");
    printf("2 - nome\n");
    printf("3 - código\n");
    printf("4 - tipo (trabalho/pessoal)");
    printf("> ");
    scanf("%d", opcao);

    if(opcao)
    }

void listar(struct contato contatos[], int totalContatos){
    if(totalContatos==0){
        printf("você ainda não tem contatos\n\n");
        return;
    }
    
    printf("listando %d contatos...\n", totalContatos);
    for(int i = 0; i<totalContatos; i++){
        printf("%d", contatos[i].codigo);
        printf("...");
        printf("%s", contatos[i].nome);
        printf("...");
        printf("(%c%c)", contatos[i].telefone[0], contatos[i].telefone[1]);
        for(int j=2; j<11; j++){
            printf("%c", contatos[i].telefone[j]);
            if(j==6){
                printf("-");
            }
            if(j==10){
                printf("\n");
            }
        }
    }
}
void localizar(struct contato contatos[], int totalContatos){
    int codigo;
    printf("1 - insira o código do contato\n");
    printf("> ");
    scanf("%d", codigo);
    
    for(int i = 0; i<totalContatos; i++){
        if(codigo==contatos[i].codigo){
            printf("           |%s|\n", contatos[i].nome);
            printf("código.........%d \n", contatos[i].codigo);
            printf("numero:....(%c%c)", contatos[i].telefone[0], contatos[i].telefone[1]);
            for(int j = 2; j<=11; j++){
                printf("%c", contatos[i].telefone[j]);
                if(j==6){
                    printf("-");
                }
            }
        if(tipo==1){
        printf("\n           |trabalho|\n\n");
        }else{
        printf("\n           |pessoal|\n\n");
        }
        }
    }
}
