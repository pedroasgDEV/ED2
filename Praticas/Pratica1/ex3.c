//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Modulos
#include "aluno.h"

int main(){
    //Abrir o arquivo
    FILE *txtIn = fopen("alunos.bin", "rb");
    FILE *txtOut = fopen("conceitos.txt", "w");

    int num;
    fread(&num, sizeof(int), 1, txtIn); //Lê o numero de alunos
    fprintf(txtOut, "%d\n", num); //Grava o numero de alunos

    TAluno aluno;
    
    for(int i = 0; i < num; i++){
        fread(&aluno, sizeof(TAluno), 1, txtIn); //Lê os alunos
        aluno.conceito = conceito(aluno); //Calcula o coeficiente
        fprintf(txtOut, "%s %s %c\n", aluno.matricula, aluno.nome, aluno.conceito); //Grava o txt
    }
    
    //Free
    fclose(txtIn);
    fclose(txtOut);

    return 0;
}