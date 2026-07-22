#include<stdio.h>
#include<string.h>

struct Endereco {
	char rua [50];
	int numero;
};

struct Pessoa {
	char nome [50];
	struct Endereco end;
};

int main () {
	struct Pessoa p1;
	
	struct Pessoa *ptr = &p1;
	
	printf("--- Cadastro de Pessoa ---\n");
    printf("Nome: ");
    scanf(" %49[^\n]", p1.nome);
    
    printf("Rua: ");
    scanf(" %49[^\n]", p1.end.rua);
    
    printf("Numero: ");
    scanf("%d", &p1.end.numero);

    printf("\n=== Dados Cadastrados ===\n");
    printf("Nome: %s\n", ptr->nome);
    printf("Rua: %s\n", ptr->end.rua);
    printf("Numero: %d\n", ptr->end.numero);

    return 0;
}