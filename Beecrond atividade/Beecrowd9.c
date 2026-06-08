#include<stdio.h>
 
int main() {
 
    int funcionario = 0;
    int horas = 0;
    double conta = 0.0;
    double salario = 0.0;

    scanf("%d", &funcionario);
    scanf("%d", &horas);
    scanf("%lf", &conta);
    
    salario = horas*conta;
    
    printf("NUMBER = %d\n", funcionario);
    printf("SALARY = U$ %.2lf\n", salario);
    
    return 0;
}