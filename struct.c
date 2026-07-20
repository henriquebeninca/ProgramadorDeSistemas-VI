#include<stdio.h>
#include<string.h>

struct aluno
{
	char nome[50];
	int idade;
	float nota;
};

int main ()
{
	struct aluno a1;
	
	strcpy(a1.nome, "joao");
	a1.idade = 20;
	a1.nota = 8.9;
	
	printf("Nome: %s\n", a1.nome);
	printf("Idade: %d\n", a1.idade);
	printf("Nota: %.2f\n", a1.nota);
	
	return(0);
}