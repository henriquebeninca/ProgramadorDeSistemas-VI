#include<stdio.h>

double soma(double a, double b);
double subtracao(double a, double b);
double multiplicacao(double a, double b);
double divisao(double a, double b);
double raiz(double raiz);
double potenciacao(double a, int b);
int mmc(int a, int b);


int main () {
	int opcao = 0;
	double a = 0.0;
	int exp = 0;
	double b = 0.0;
	double resposta = 0.0;
	
	do{
	
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("|Bem vindo a Calculadora 1.0.................................................................................|\n");
	printf("|Escolha uma opcao...........................................................................................|\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("| 0 - MDC....................................................................................................|\n");
	printf("| 1 - MMC....................................................................................................|\n");
	printf("| 2 - Soma...................................................................................................|\n");
	printf("| 3 - Sair...................................................................................................|\n");
	printf("| 4 - Divisao................................................................................................|\n");
	printf("| 5 - Subtracao..............................................................................................|\n");
	printf("| 6 - Potenciacao............................................................................................|\n");
	printf("| 7 - Multiplicacao..........................................................................................|\n");
	printf("| 8 - Raiz Quadrada..........................................................................................|\n");
	printf("| 9 - Fatorial Duplo (N!!) ..................................................................................|\n");
	printf("| 10 - Fatorial Simples (N!) ................................................................................|\n");
	printf("| 11 - Equacao do Segundo Grau...............................................................................|\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	scanf("%d", &opcao);
	
	switch (opcao)
	{	
	
	case 1:
	printf("Digite dois numeros que deseja calcular\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	resposta = mmc(a,b); 
	printf("Resposta = %.5lf\n", resposta);
	break;
	
	case 2: 
	printf("Digite dois numeros que deseja calcular\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	resposta = soma(a,b); 
	printf("Resposta = %.5lf\n", resposta);
	break;
	
	case 3:
	opcao = 0;
	break;
	
	case 4:
	printf("Digite dois numeros que deseja calcular\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
if(b == 0)
	printf("Erro: divisao por zero!\n");
else {
	resposta = divisao(a,b);
	printf("Resposta = %.5lf\n", resposta);
}
	break;
	
	case 5:
	printf("Digite dois numeros que deseja calcular\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	
	resposta = subtracao(a,b);
	printf("Resposta = %.5lf\n", resposta);
	break;
	
	case 6:
	printf("Digite dois numeros, primeiro a base, depois o expoente\n");
	scanf("%lf", &a);
	scanf("%d", &exp);
	resposta = potenciacao(a,exp);
	printf("Resposta = %.5lf\n", resposta);
	break;
	
	case 7:
	printf("Digite dois numeros que deseja calcular\n");
	scanf("%lf", &a);
	scanf("%lf", &b);

	resposta = multiplicacao(a,b);
	printf("Resposta = %.5lf\n", resposta);
	break;
	
	case 8:
	printf("Digite um numero que deseja calcular a raiz quadrada\n");
	scanf("%lf", &a);
	resposta = raiz(a);
	printf("A raiz quadrada e: %.5lf\n", resposta);
	break;
	m
	default:
			printf("O numero informado nao representa uma operacao!\n");
	}
	}while (opcao !=0);

	return (0);
}

double soma(double a, double b)
{
	double c = 0.0;
	c = a+b;
	return(c);
}

double subtracao(double a, double b)
{
	double c = 0.0;
	c = a-b;
	return(c);
}
double multiplicacao(double a, double b)
{
	double c = 0.0;
	c = a*b;
	return(c);
}
double divisao(double a, double b)
{
	double c = 0.0;
	c = a/b;
	return(c);
}
double raiz(double a)
{	double raiz = 0.0, b = 0.0;
	b = a;
	
	for(int i=0; i < 100; i++)
	{
		raiz = 0.5*(b + (a/b));
		
		b = raiz;
	}		
	return(raiz);
}
double potenciacao(double a, int exp) 
{
	double resultado = 1.0;
	
	if(exp == 0.0)
	{
		return 1.0;
	}
	
	for(int i=0; i < exp; i++) {
		resultado *= a;
	}
	return(resultado);
}
int mmc(int a, int b)
{
	int c = 0; 
	a * b / mmc(a,b);
	
	return(c);
}