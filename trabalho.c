#include<stdio.h>

double soma(double a, double b);
double subtracao(double a, double b);
double multiplicacao(double a, double b);
double divisao(double a, double b);
double raiz(double raiz);
double potenciacao(double a, int b);
int mdc(int a, int b);
int mmc(int a, int b);
int fatorialsimples(int a);
int fatorialduplo(int a);
void segundograu(double a, double b, double c);

int main () {
	int opcao = 0;
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	int exp = 0;
	double resposta = 0.0;
	int aint = 0, bint = 0;
	int resp = 0;
	
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
	
	case 0:
	printf("Digite dois numeros que deseja calcular o MDC.\n");
	scanf("%d", &aint);
	scanf("%d", &bint);
	resp = mdc(aint,bint);
	printf("Resposta = %d\n", resp);
	break;
	
	case 1:
	printf("Digite dois numeros que deseja calcular o MMC.\n");
	scanf("%d", &aint);
	scanf("%d", &bint);
	resposta = mmc(aint,bint); 
	printf("Resposta = %.5lf\n", resposta);
	break;
	
	case 2: 
	printf("Digite dois numeros que deseja calcular.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	resposta = soma(a,b); 
	printf("Resposta = %.5lf\n", resposta);
	break;
	
	case 3:
	opcao = 3;
	break;
	
	case 4:
	printf("Digite dois numeros que deseja calcular.\n");
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
	printf("Digite dois numeros que deseja calcular.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	resposta = subtracao(a,b);
	printf("Resposta = %.5lf\n", resposta);
	break;
	
	case 6:
	printf("Digite dois numeros, primeiro a base, depois o expoente.\n");
	scanf("%lf", &a);
	scanf("%d", &exp);
	resposta = potenciacao(a,exp);
	printf("Resposta = %.5lf\n", resposta);
	break;
	
	case 7:
	printf("Digite dois numeros que deseja calcular.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	resposta = multiplicacao(a,b);
	printf("Resposta = %.5lf\n", resposta);
	break;
	
	case 8:
	printf("Digite um numero que deseja calcular a raiz quadrada.\n");
	scanf("%lf", &a);
	resposta = raiz(a);
	if (a < 0) {
	printf("Nao existe raiz quadrada para numeros negativos.\n");
	} 
	else {
	   printf("A raiz quadrada e: %.5lf\n", resposta);}
	break;

	case 9:
	printf("Digite um numero.\n");
	scanf("%d", &aint);
	resp = fatorialduplo(aint);
	if (aint < 0) {
        printf("Nao existe fatorial para numeros negativos.\n");
    } else
		{
        printf("O fatorial e: %d\n", fatorialduplo(aint));
    }
	break;
	
	case 10: 
	printf("Digite um numero.\n");
	scanf("%d", &aint);
	resp = fatorialsimples(aint);
	if (aint < 0) {
        printf("Nao existe fatorial para numeros negativos.\n");
    } else if (aint > 12) {
        printf("Valores acima de 12 estouram o limite.\n");
    } else {
        printf("O fatorial e: %d\n", fatorialsimples(aint));
    }
	break;
	
	case 11:
	printf("Digite os coeficientes a, b, c.\n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	segundograu(a,b,c);
	break;
	
	default:
			printf("O numero informado nao representa uma operacao!\n");
	}
	}while (opcao !=3);

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
	
	if (a == 0)
		return (0);
	
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
int mdc(int a, int b) 
{	
    int resto;
	
    while (b != 0) {
        resto = a % b; 
        a = b;         
        b = resto;     
    }
    
    return (a); 
}
int mmc(int a, int b)
{
	int c = 0;
	
    if (a == 0 || b == 0) return 0;
	return (a / mdc(a, b)) * b; 
	return(c);
}
int fatorialsimples(int a)
{
    int fatorial = 1;
    for (int i = 1; i <= a; i++) {
        fatorial *= i;
    }
    return (fatorial);
}
int fatorialduplo(int a)
{
	int fatorial = 1;
	for (int i = a; i >= 1; i -= 2) {
        fatorial *= i;
	}
	return (fatorial);
}
void segundograu(double a, double b, double c)
{
    double delta, x1, x2;

    if (a == 0)
    {
        printf("Nao e uma equacao do segundo grau.\n");
        return;
    }

    delta = b * b - 4 * a * c;

    if (delta < 0)
    {
        printf("A equacao nao possui raizes reais.\n");
    }
    else if (delta == 0)
    {
        x1 = -b / (2 * a);

        printf("A equacao possui apenas uma raiz.\n");
        printf("x = %.5lf\n", x1);
    }
    else
    {
        x1 = (-b + raiz(delta)) / (2 * a);
        x2 = (-b - raiz(delta)) / (2 * a);

        printf("x1 = %.5lf\n", x1);
        printf("x2 = %.5lf\n", x2);
    }
}