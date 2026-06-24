#include <stdio.h>
 
int main() {

    char nome[25];
    double salario = 0.0;
    double vendas = 0.0;
    double valorfinal = 0.0;
	
    scanf("%s", &nome);
    scanf("%lf", &salario); 
    scanf("%lf", &vendas);
 
    valorfinal = salario +(0.15*vendas);
    printf("TOTAL = R$ %.2lf\n", valorfinal);
    
    return 0;
}