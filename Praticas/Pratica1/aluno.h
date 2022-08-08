#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno{
    char matricula[4];
    char nome [6];
    int nota1;
    int nota2;
    int nota3;
    int falta;
    int ativo;  //1 - sim, 0 - não
    char conceito;
}TAluno;

//Prototipos

//Lê e grava os alunos
TAluno read(FILE *txt);

//Calcula o coeficiente
char conceito(TAluno aluno);


#endif
