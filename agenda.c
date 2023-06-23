#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "agenda.h"

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

void linhainicial(){
    system("cls");
    printf("%c",201);
    for(int i=0;i<=50;i++){
    printf("%c",205);
    }
    printf("%c\n",187);
}

void linhafinal(){
    printf("%c",200);
    for(int i=0;i<=50;i++){
    printf("%c",205);
    }
    printf("%c\n",188);
}

void itemmenu(int i,char str[]){
    printf("%c",186);
    printf("%s",str);
    gotoxy(50+2,i);
    printf("%c\n",186);
}

void menu(){
    linhainicial();
    gotoxy(20,1);printf("Cadastro de Pessoas");
    gotoxy(0,1);printf("%c\n",186);
    gotoxy(52,1);printf("%c\n",186);
    itemmenu(2,"\n");
    itemmenu(3,"\n");
    itemmenu(4,"1-Inserir dados do contato.");
    itemmenu(5,"\n");
    itemmenu(6,"2-Exibir contatos.");
    itemmenu(7,"\n");
    itemmenu(8,"3-Pesquisar contato.");
    itemmenu(9,"\n");
    itemmenu(10,"4-Alterar");
    itemmenu(11,"\n");
    itemmenu(12,"5-Remover");
    itemmenu(13,"\n");
    itemmenu(14,"6-Sair");
    itemmenu(15,"\n");
    linhafinal();
}

void cadastrofuncionario(){
    FILE* arquivo;
    CONTATO ctt;
    arquivo = fopen("agenda.txt","ab");
    if(arquivo == NULL){
        printf("Problema ao abrir o arquivo\n");
    }
    else{
        do{
            system("cls");
            linhainicial();
            gotoxy(0,1);printf("%c\n",186);
            gotoxy(52,1);printf("%c\n",186);
            fflush(stdin);
            itemmenu(2,"Nome: ");
            fflush(stdin);
            itemmenu(3,"Fone: ");
            itemmenu(4,"\n");
            itemmenu(5,"\n");
            itemmenu(6,"\n");
            itemmenu(7,"\n");
            itemmenu(8,"\n");

            itemmenu(9,"Deseja continuar(s/n)?");
            linhafinal();

            gotoxy(15,2);gets(ctt.nome);
            gotoxy(15,3);gets(ctt.fone);
            gotoxy(28,9);

            fwrite(&ctt,sizeof(CONTATO),1,arquivo);

        }while(getche()=='s');
        fclose(arquivo);
        getchar();
    }
}

void exibir(){
    FILE* arquivo;
    CONTATO ctt;
    arquivo = fopen("agenda.txt","rb");

    if(arquivo == NULL){
        printf("Problema ao abrir o arquivo\n");
    }
    else{
        while(fread(&ctt,sizeof(CONTATO),1,arquivo)==1){
            printf("Nome: %s\n",ctt.nome);
            printf("Fone: %s\n\n\n",ctt.fone);
        }
    }
}
void remover() {
    FILE* arquivo;
    FILE* novoArquivo;
    CONTATO ctt;
    char nome[30];
    int encontrado = 0;

    arquivo = fopen("agenda.txt", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    novoArquivo = fopen("temp.txt", "wb");
    if (novoArquivo == NULL) {
        printf("Erro ao abrir o arquivo temporário\n");
        fclose(arquivo);
        return;
    }

    fflush(stdin);
    printf("Digite o nome do contato a ser removido: ");
    gets(nome);

    while (fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1) {
        if (strcmp(nome, ctt.nome) != 0) {
            fwrite(&ctt, sizeof(CONTATO), 1, novoArquivo);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(novoArquivo);

    if (encontrado) {
        remove("agenda.txt");
        rename("temp.txt", "agenda.txt");
        printf("Contato removido com sucesso!\n");
    } else {
        remove("temp.txt");
        printf("Contato não encontrado!\n");
    }

    getchar();
}
void pesquisarContato() {
    FILE* arquivo;
    CONTATO ctt;
    char nome[30];
    int encontrado = 0;

    arquivo = fopen("agenda.txt", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    fflush(stdin);
    printf("Digite o nome a ser pesquisado: ");
    gets(nome);

    while (fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1) {
        if (strcmp(nome, ctt.nome) == 0) {
            printf("Nome: %s\n", ctt.nome);
            printf("Fone: %s\n\n", ctt.fone);
            encontrado = 1;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Contato não encontrado!\n");
    }

    getch();
}
void alterar() {
    FILE* arquivo;
    FILE* novoArquivo;
    CONTATO ctt;
    char nome[30];
    int encontrado = 0;

    arquivo = fopen("agenda.txt", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    novoArquivo = fopen("temp.txt", "wb");
    if (novoArquivo == NULL) {
        printf("Erro ao abrir o arquivo temporário\n");
        fclose(arquivo);
        return;
    }

    fflush(stdin);
    printf("Digite o nome do contato a ser alterado: ");
    gets(nome);

    while (fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1) {
        if (strcmp(nome, ctt.nome) == 0) {
            encontrado = 1;

            printf("Digite o novo nome: ");
            gets(ctt.nome);
            printf("Digite o novo telefone: ");
            gets(ctt.fone);
        }

        fwrite(&ctt, sizeof(CONTATO), 1, novoArquivo);
    }

    fclose(arquivo);
    fclose(novoArquivo);

    if (encontrado) {
        remove("agenda.txt");
        rename("temp.txt", "agenda.txt");
        printf("Contato alterado com sucesso!\n");
    } else {
        remove("temp.txt");
        printf("Contato não encontrado!\n");
    }

    getchar();
}
