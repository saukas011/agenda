#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

struct contato{
    int codigo;
    char nome[50];
    char telefone[11];
    int tipo;
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

    int sensor = 0;
    int tipo;
    
    printf("\ncodigo do contato> ");
    scanf("%d", &contatos[*totalContatos].codigo);
    getchar();
    for(int i=0; i<*totalContatos; i++){
        if(contatos[*totalContatos].codigo==contatos[i].codigo){
            printf("este codigo ja esta sendo usado!\n\n");
            return;
        }
    }

    printf("nome do contato> ");
    scanf("%[^\n]", contatos[*totalContatos].nome);

    do{
        if(sensor>0){
            printf("o telefone deve ter de 10 a 11 dígitos!\n");
        }
        printf("telefone do contato> ");
        scanf("%11s", &contatos[*totalContatos].telefone);
        sensor++;
    }while(strlen(contatos[*totalContatos].telefone)>11 || strlen(contatos[*totalContatos].telefone)<10);
    
    printf("o contato é:\n");
    printf("1 - trabalho\n");
    printf("2 - pessoal\n");
    printf("> ");
    scanf("%d", &tipo);
    contatos[*totalContatos].tipo = tipo;
    
    //imprine ctt novo
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

    int opcao, codigo;
    
    if(*totalContatos==0){
    printf("você ainda não tem contatos\n\n");
    return;
    }
    
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

    for(int i=0; i<*totalContatos; i++){
        if(codigo==contatos[i].codigo){
            for(int j=i; j<*totalContatos; j++){
                contatos[i]=contatos[j];
            }
            printf("contato excluído!\n\n");
            (*totalContatos)--;
            return;
        }
    }
    printf("esse contato nao existe!\n\n");
}

void alterarNome(struct contato contatos[], int index);
void alterarCodigo(struct contato contatos[], int index);
void alterarTelefone(struct contato contatos[], int index);
void alterarTipo(struct contato contatos[], int index, int tipoAntigo);

void alterar(struct contato contatos[], int totalContatos){

    int codigo, opcao, tipoAntigo, codigoAntigo;
    int sensor = 0;
    int index = -1;
    char nomeAntigo[50], telefoneAntigo[11];

    if(totalContatos==0){
        printf("voce ainda não tem contatos\n\n");
        return;
    }

    printf("\ndigite o código do contato que deseja alterar\n");
    printf("> ");
    scanf("%d", &codigo);
    
    for(int i=0; i<totalContatos; i++){
        if(codigo == contatos[i].codigo){
            index = i;
            break;
        }
    }    
    
    if(index == -1){
        printf("contato não encontrado!\n\n");
        return;
    }
    
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
    }while(opcao<1 || opcao>4);
    
    switch(opcao){
        
        case 1: for(int i=0; i<50; i++){nomeAntigo[i]=contatos[index].nome[i];} alterarNome(contatos, index); break;
        case 2: codigoAntigo=contatos[index].codigo; alterarCodigo(contatos, index); break;
        case 3: for(int i=0; i<11; i++){telefoneAntigo[i] = contatos[index].telefone[i];} alterarTelefone(contatos, index); break;
        case 4: tipoAntigo=contatos[index].tipo; alterarTipo(contatos, index, tipoAntigo);

    }
    
    if(opcao==1){
        printf("           %s--->|%s|\n", nomeAntigo, contatos[index].nome);
    }else{
        printf("           |%s|\n", contatos[index].nome);
    }
        
    if(opcao==2){
        printf("codigo.........%d--->%d\n", codigoAntigo, contatos[index].codigo);
    }else{
        printf("codigo.........%d\n", contatos[index].codigo);
    }
        
    printf("numero:....");

    if(opcao==3){
        printf("(%c%c)", telefoneAntigo[0], telefoneAntigo[1]);
            for(int i=2; i<11; i++){
                printf("%c", telefoneAntigo[i]);
                if(i==6){
                    printf("-");
                }
            }
            printf(" -----> ");
    }

    printf("(%c%c)", contatos[index].telefone[0], contatos[index].telefone[1]);
    for(int i=2; i<11; i++){
        printf("%c", contatos[index].telefone[i]);
            if(i==6){
                printf("-");
            }
    }

    printf("\n           ");

    if(opcao==4){
        if (tipoAntigo==1){
            printf("|trabalho|");
        }else{
            printf("|pessoal|");
        }
            printf("--->");
    }

    if(contatos[index].tipo==1){
        printf("|trabalho|\n\n");
    }else{
        printf("|pessoal|\n\n");
    }
    
}

void alterarNome(struct contato contatos[], int index){
    printf("digite o novo nome\n");
    printf("> ");
    getchar();
    scanf("%[^\n]", contatos[index].nome);
    printf("\nnome alterado!\n\n");
}
void alterarCodigo(struct contato contatos[], int index){
    printf("digite o novo codigo\n");
    printf("> ");
    scanf("%d", &contatos[index].codigo);
    printf("\ncodigo alterado!\n\n");
}
void alterarTelefone(struct contato contatos[], int index){
    printf("\ndigite o novo numero de telefone\n");
    printf("> ");
    scanf("%s", contatos[index].telefone);
    printf("\ntelefone alterado!\n\n");
}
void alterarTipo(struct contato contatos[], int index, int tipoAntigo){
    if(tipoAntigo==1){
        contatos[index].tipo=2;
    }else{
        contatos[index].tipo=1;
    }
    printf("\ntipo alterado!\n\n");
}


void listar(struct contato contatos[], int totalContatos){
    if(totalContatos==0){
        printf("você ainda não tem contatos\n\n");
        return;
    }
    
    printf("listando %d contatos...\n", totalContatos);
    for(int i = 0; i<totalContatos; i++){
        printf("%d) ", i+1);
        printf("%d", contatos[i].codigo);
        printf("...");
        printf("|%s|", contatos[i].nome);
        printf("...");
        printf("(%c%c)", contatos[i].telefone[0], contatos[i].telefone[1]);
        for(int j=2; j<11; j++){
            printf("%c", contatos[i].telefone[j]);
            if(j==6){
                printf("-");
            }
        }
        
        if(contatos[i].tipo==1){
            printf(" (trabalho)\n");
        }else{
            printf(" (pessoal)\n");
        }
    }
}

void localizar(struct contato contatos[], int totalContatos){

    int codigo;

    if(totalContatos==0){
        printf("voce ainda nao tem contatos\n\n");
        return;
    }
    
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
