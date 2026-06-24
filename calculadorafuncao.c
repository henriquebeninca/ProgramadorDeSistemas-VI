#include<stdio.h>

int soma(int a, int b);
int subtracao(int a, int b);
int multiplicacao(int a, int b);
int divisao(int a, int b);

int main () {
	int opcao = 0;
	int a = 0;
	int b = 0;
	int resposta = 0;
	
	do{
	
	printf("---------------------------------\n");
	printf("Que calculo voce deseja realizar?\n");
	printf("1 - soma\n");
	printf("2 - subtracao\n");
	printf("3 - multiplicacao\n");
	printf("4 - divisao\n");
	printf("0 - sair\n");
	printf("---------------------------------\n");
	scanf("%d", &opcao);
	
	switch (opcao)
	{
	case 0:
	opcao = 0;
	break;
	case 1: 
	printf("Digite dois numeros que deseja calcular\n");
	scanf("%d", &a);
	scanf("%d", &b);
	
	resposta = soma(a,b); 
	printf("Resposta = %d\n", resposta);
	break;
	
	case 2:
	printf("Digite dois numeros que deseja calcular\n");
	scanf("%d", &a);
	scanf("%d", &b);
	
	resposta = subtracao(a,b);
	printf("Resposta = %d\n", resposta);
	break;
	
	case 3:
	printf("Digite dois numeros que deseja calcular\n");
	scanf("%d", &a);
	scanf("%d", &b);

	resposta = multiplicacao(a,b);
	printf("Resposta = %d\n", resposta);
	break;
	
	case 4:
	printf("Digite dois numeros que deseja calcular\n");
	scanf("%d", &a);
	scanf("%d", &b);
if(b == 0)
	printf("Erro: divisao por zero!\n");
else {
	resposta = divisao(a,b);
	printf("Resposta = %d\n", resposta);
}
	
	break;
	default:
			printf("O numero informado nao representa uma operacao!\n");
	}
	}while (opcao !=0);

	return (0);
}

int soma(int a, int b)
{
	return(a+b);
}

int subtracao(int a, int b)
{
	return(a-b);
}
int multiplicacao(int a, int b)
{
	return(a*b);
}
int divisao(int a, int b)
{
	return(a/b);
}