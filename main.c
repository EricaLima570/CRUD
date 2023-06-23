#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include  "agenda.h"


int main(){
    system("color 0E");
    
    int opcao;

    do{
        menu();
        gotoxy(1,15);printf("Escolha uma opcao:");
        scanf("%d", &opcao);
        system("cls");
        switch(opcao){
        case 1:
            cadastrofuncionario();

        break;

        case 2:
           exibir();
           system("Pause");
        break;
        case 3:
            pesquisarContato();
        break;
        case 4:
            alterar();
        break;
        case 5:
            remover();
        break;
        case 6:
          printf("Obrigada por sua visita!\n");
          getch();
        break;

        default:
          printf("Opcao invalida!\n");
          printf("Aperte enter para continuar\n");
          getch();
        break;
       }

    }while(opcao != 6);
    return 0;
}
