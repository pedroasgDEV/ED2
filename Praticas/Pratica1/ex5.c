//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Modulos
#include "aluno.h"

int main(){
    //Abrir o arquivo
    FILE *txtIn = fopen("alunos.bin", "rb");
    FILE *txtOut = fopen("temp.bin", "wb");

    //Lê a matricula do aluno a ser excluido
    char matricula[4];
    printf("Matricula: "); scanf("%s", matricula);

    int num;
    fread(&num, sizeof(int), 1, txtIn); //Lê o numero de alunos
    fwrite(&num, sizeof(int), 1, txtOut); //Grava o numero de alunos
    TAluno aluno;


    for(int i = 0; i < num; i++){
        fread(&aluno, sizeof(TAluno), 1, txtIn); //Lê os alunos
        if(strcmp(aluno.matricula, matricula) == 0) aluno.ativo = 0; //Define estado do aluno
        else aluno.ativo = 1; //Define estado do aluno
        fwrite(&aluno, sizeof(TAluno), 1, txtOut); //Grava os alunos
    }

    //Free
    fclose(txtIn);
    fclose(txtOut);

    remove("alunos.bin");
    rename("temp.bin", "alunos.bin");

    return 0;
}