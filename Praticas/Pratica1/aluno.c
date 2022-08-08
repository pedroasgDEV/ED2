//Bibliotecas
#include <stdio.h>

//Modulos
#include "aluno.h"

//Funções
//Lê e grava os alunos
TAluno read(FILE *txt){
    TAluno aluno;

    fscanf(txt, "%s %s %d %d %d %d", aluno.matricula, aluno.nome, &aluno.nota1, &aluno.nota2, &aluno.nota3, &aluno.falta);

    return aluno;
}

//Calcula o coeficiente
char conceito(TAluno aluno){

    float media = (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;

    if(aluno.falta > 18) return 'F';
    else if(media < 6) return 'R';
    else if(media < 7.5) return 'C';
    else if(media < 9) return 'B';
    else return 'A';
}