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
    getchar();

    printf("nome do contato> ");
    scanf("%[^\n]", contatos[*totalContatos].nome);

    printf("telefone do contato> ");
    scanf("%11s", &contatos[*totalContatos].telefone);

    int tipo;
    printf("o contato é:\n");
    printf("1 - trabalho\n");
    printf("2 - pessoal\n");
    printf("> ");
    scanf("%d", &tipo);
    contatos[*totalContatos].tipo = tipo;
    

    printf("\ncontato adicionado!\n\n");
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
    printf("> "); scanf("%d", &codigo);

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
    if(totalContatos==0){
        printf("voce ainda não tem contatos\n\n");
        return;
    }
    int codigo, opcao;
    int sensor = 0;
    printf("\ndigite o código do contato que deseja alterar\n");
    printf("> ");
    scanf("%d", &codigo);

    do{
        if(sensor>0){
            printf("opcao inválida!\n");
        }
        printf("\no que deseja alterar?\n");
        printf("1 - nome\n");
        printf("2 - codigo\n");
        printf("3 - telefone\n");
        printf("4 - tipo (trabalho/pessoal)\n");
        printf("> ");
        scanf("%d", &opcao);
        sensor++;
    }while(opcao<=0 || opcao>4);
    
    int encontrado = 0;

    for(int i = 0; i<totalContatos; i++){
        
        if(codigo==contatos[i].codigo){
            
            if(opcao==1){

                //copiando nome antigo para que seja imprimido mais tarde
                char nomeAntigo[sizeof(contatos[i].nome)];
                for(int j = 0; j<sizeof(contatos[i].nome); j++){
                    nomeAntigo[j]=contatos[i].nome[j];
                }
                
                printf("digite o novo nome\n");
                printf("> ");
                getchar();
                scanf("%[^\n]", contatos[i].nome);
                printf("\nnome alterado!\n\n");
                encontrado++;
                break;
                
            }else if(opcao==2){
                
                //copiando codigo antigo para que seja impresso mais tarde
                int codigoAntigo=contatos[i].codigo;
                
                printf("digite o novo codigo\n");
                printf("> ");
                scanf("%d", &contatos[i].codigo);
                printf("\ncodigo alterado!\n\n");
                encontrado++;
                break;
                
            }else if(opcao==3){
            
                //copiando telefone antigo para que seja imprimido mais tarde
                char telefoneAntigo[11];
                for(int j = 0; j<11; j++){
                    telefoneAntigo[j] = contatos[i].telefone[j];
                }

                printf("\ndigite o novo numero de telefone\n");
                printf("> ");
                scanf("%s", contatos[i].telefone);
                printf("\ntelefone alterado!\n\n");
                encontrado++;
                break;
                
            }else{

                //copiando tipo antigo para que seja imprimido mais tarde
                int tipoAntigo=contatos[i].tipo;

                if(tipoAntigo==1){
                    contatos[i].tipo=2;
                }else{
                    contatos[i].tipo=1;
                }
                printf("\ntipo alterado!\n\n");
                break;
                encontrado++;
            }
        }
    }

    if(encontrado==0){
        printf("contato não encontrado\n");
        return;
    }
    
    //imprimir contato alterado
    if(opcao==1){
        printf("           %s--->|%s|\n", nomeAntigo, contatos[i].nome);
    }else{
        printf("           |%s|\n", contatos[i].nome);
    }
        
    if(opcao==2){
        printf("codigo.........%d--->%d\n", codigoAntigo, contatos[i].codigo);
    }else{
        printf("codigo.........%d\n", contatos[i].codigo);
    }
        
    //imprimir numero
    printf("numero:....");
    //nr antigo
    if(opcao==3){
        printf("(%c%c)", telefoneAntigo[0], telefoneAntigo[1]);
            for(int j = 2; j<11; j++){
                printf("%c", telefoneAntigo[j]);
                if(j==6){
                    printf("-");
                }
            }
            printf(" -----> ");
    }
    //nr novo
    printf("(%c%c)", contatos[i].telefone[0], contatos[i].telefone[1]);
    for(int j = 2; j<11; j++){
        printf("%c", contatos[i].telefone[j]);
            if(j==6){
                printf("-");
            }
        }
        
    //tipo antigo    
    if(opcao==4){
        if (tipoAntigo==1){
            printf("\n           |trabalho|");
        }else{
            printf("\n           |pessoal|");
        }
            printf("--->");
    }
    //tipo novo
    if(contatos[i].tipo==1){
        printf("|trabalho|\n\n");
    }else{
        printf("|pessoal|\n\n");
    }
    
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
    if(totalContatos==0){
        printf("voce ainda nao tem contatos\n\n");
        return;
    }
    int codigo;
    printf("1 - insira o código do contato\n");
    printf("> ");
    scanf("%d", &codigo);
    
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
        if(contatos[i].tipo==1){
        printf("\n           |trabalho|\n\n");
        }else{
        printf("\n           |pessoal|\n\n");
        }
        }
    }
}
