//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Modulos
#include "aluno.h"

int main(){
    //Abrir o arquivo
    FILE *txtIn = fopen("alunos.txt", "r");
    FILE *txtOut = fopen("conceitos.txt", "w");

    int num;
    fscanf(txtIn, "%d", &num); //Lê o numero de alunos
    fprintf(txtOut, "%d\n", num); //Grava o numero de alunos
    
    TAluno aluno;

    for(int i = 0; i < num; i++){
        aluno = read(txtIn); //Lê os alunos
        aluno.conceito = conceito(aluno); //Calcula o coeficiente
        fprintf(txtOut, "%s %s %c\n", aluno.matricula, aluno.nome, aluno.conceito); //Grava o txt
    }
    
    //Free
    fclose(txtIn);
    fclose(txtOut);

    return 0;
}
