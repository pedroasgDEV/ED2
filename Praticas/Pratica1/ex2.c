//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Modulos
#include "aluno.h"

int main(){
    //Abrir o arquivo
    FILE *txtIn = fopen("alunos.txt", "r");
    FILE *txtOut = fopen("alunos.bin", "wb");

    int num;
    fscanf(txtIn, "%d", &num); //Lê o numero de alunos
    fwrite(&num, sizeof(int), 1, txtOut); //Grava o numero de alunos

    TAluno aluno;

    for(int i = 0; i < num; i++){
        aluno = read(txtIn); //Lê os alunos
        fwrite(&aluno, sizeof(TAluno), 1, txtOut); //Grava o txt
    }
    
    //Free
    fclose(txtIn);
    fclose(txtOut);

    return 0;
}