#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define tam 50

typedef struct contato CONTATO;
void gotoxy(int x, int y);
void bordasuperior();
void bordainferior();
void limpartela();
void itemmenu(int i,char str[]);
void menu();
void inserir();
void listar();

struct contato{
    char nome[20];
    char fone[15];
};
void gotoxy(int x, int y){
    HANDLE hCon;
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);

}
void bordasuperior(){
    system("cls");
    printf("%c",201);
    for(int i=0;i<=tam;i++){
    printf("%c",205);
    }
    printf("%c\n",187);
}
void bordainferior(){

    printf("%c",200);
    for(int i=0;i<=tam;i++){
    printf("%c",205);
    }
    printf("%c\n",188);
}
void itemmenu(int i,char str[]){

    printf("%c",186);
    printf("%s",str);
    gotoxy(tam+2,i);
    printf("%c\n",186);
}
void limpartela(){
    getchar();//poderia substituir por um printf: aperte enter
    system("cls"); // limpo o terminal}
}

void menu(){
    bordasuperior();
    gotoxy(20,1);printf("Cadastro de Dados");
    gotoxy(0,1);printf("%c\n",186);
    gotoxy(52,1);printf("%c\n",186);
    itemmenu(2,"\n");
    itemmenu(3,"\n");
    itemmenu(4,"1-Inserir nome e contato");
    itemmenu(5,"\n");
    itemmenu(6,"2-Listar cadastros");
    itemmenu(7,"\n");
    itemmenu(8,"3-Sair");
    itemmenu(9,"\n");
    itemmenu(10,"\n");
    itemmenu(11,"\n");
    itemmenu(12,"\n");
    itemmenu(13,"\n");
    bordainferior();

}
void inserir(){
    FILE* arquivo;
    CONTATO ctt;
    arquivo = fopen("agenda.txt","ab");
    if(arquivo == NULL){
        printf("Problem ao abrir o arquivo\n");
    }
    else{
        do{
            limpartela();
            bordasuperior();
            gotoxy(0,1);printf("%c\n",186);
            gotoxy(52,1);printf("%c\n",186);
            fflush(stdin);
            itemmenu(2,"Digite o nome: ");
            fflush(stdin);
            itemmenu(3,"Digite o fone: ");
            itemmenu(4,"\n");
            itemmenu(5,"\n");
            itemmenu(6,"\n");
            itemmenu(7,"\n");
            itemmenu(8,"\n");

            itemmenu(9,"Voce quer continuar(s/n)?");
            bordainferior();

            gotoxy(15,2);gets(ctt.nome);
            gotoxy(15,3);gets(ctt.fone);
            gotoxy(28,9);

            fwrite(&ctt,sizeof(CONTATO),1,arquivo);



        }while(getche()=='s');
        fclose(arquivo);
        getchar();
    }
}
void listar(){
    FILE* arquivo;
    CONTATO ctt;
    arquivo = fopen("agenda.txt","rb");


    if(arquivo == NULL){
        printf("Problem ao abrir o arquivo\n");
    }
    else{
        while(fread(&ctt,sizeof(CONTATO),1,arquivo)==1){
            printf("Nome %s\n",ctt.nome);
            printf("Fone: %s\n\n\n",ctt.fone);
        }

    }
    fclose(arquivo);
    getch();
}
int main(){
    //setlocale(LC_ALL,"Portuguese");
    int opcao;

    do{
        menu();
        gotoxy(1,13);printf("Escolha uma opcao:");
        scanf("%d", &opcao);
        system("cls");
        switch(opcao){
        case 1:
            inserir();
        break;

        case 2:
           listar();
        break;
        case 3:
          printf("Obrigada por sua visita!\n");
          getch();
        break;

        default:
          printf("Opcao invalida!\n");
          printf("Aperte enter para continuar\n");
          getch();
        break;
       }

    }while(opcao != 3);
    return 0;
}

