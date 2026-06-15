#include <stdio.h>

	int main ()
	{
		
	double raiz = 0.0;
	double x = 0.0;
	double xk = 0.0;
	
	printf("Informe o numero que deseja calcular a raiz quadrada\n");
	scanf("%lf", &x);
	
	xk = x;
	
	for(int i=0; i < 10; i++)
	{
		raiz = 0.5*(xk + (x/xk));
		xk = raiz;
		printf("O valor da raiz e: %lf\n", raiz);
	}

	return(0);
	}