#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>

void abre_arq();
void grava();

struct Aluno
{
    char nome[10];
    char matricula[5];
};

using namespace std;

int main()
{
    // Declaracoes
    char opcao;
    // Instrucoes

    do
    {
        system("cls");
        system("color 0f");
        printf(" C - CADASTRA UM ALUNO \n");
        printf(" L - APRESENTA TODOS OS ALUNOS CADASTRADOS\n");
        printf(" S - SAIR\n");
        opcao = toupper(_getch());
        switch (opcao)
        {
        case 'C':
            grava();
            break;
        case 'L':
            abre_arq();
            break;

        }
    } while (opcao != 'S');
    fflush(stdin);
    _getch();
    return 0;
}

void abre_arq()
{
    FILE* arquivo = fopen("aluno.txt", "rb");
    struct Aluno dados_al;

    if (arquivo == NULL)
    {
        system("cls");
        system("color 4f");
        printf("ERRO AO ABRIR ARQUIVO. TALVEZ NÃO EXISTA...");
    }
    else
    {
        while (!feof(arquivo))
        {
            if (fread(&dados_al, sizeof(dados_al), 1, arquivo) == 1)
            {
                fprintf(stdout, "%s\n", dados_al.nome);
                fprintf(stdout, "%s\n\n", dados_al.matricula);
            }
        }
        if (fclose(arquivo) != 0)
        {
            system("color 4f");
            printf("ERRO AO FECHAR ARQUIVO");
        }
    }
    _getch();
}

void grava()
{
    struct Aluno dados_al;
    FILE* arquivo = fopen("aluno.txt", "ab");

    printf("INFORME O NOME DO ALUNO:\n");
    fflush(stdin);
    scanf("%s", dados_al.nome);
    printf("MATRICULA DO ALUNO:\n");
    fflush(stdin);
    scanf("%s", dados_al.matricula);

    if (fwrite(&dados_al, sizeof(struct Aluno), 1, arquivo) == 1)
    {
        system("color 0a");
        system("cls");
        printf("ARQUIVO GRAVADO COM SUCESSO!\n\n");
    }
    else
    {
        system("color 4f");
        printf("ERRO NA GRAVACAO DO ARQUIVO");
    }
    fclose(arquivo);
    _getch();
}