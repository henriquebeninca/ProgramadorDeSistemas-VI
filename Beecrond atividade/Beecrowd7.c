#include<stdio.h>
 
int main() {
 
    double nota1 = 0.0;
    double nota2 = 0.0;
    double nota3 = 0.0;
    double media = 0.0;
    
    scanf("%lf", &nota1);
    scanf("%lf", &nota2);
    scanf("%lf", &nota3);
    
    media = ((nota1*2.0)+(nota2*3.0)+(nota3*5.0))/10.0;
 
    printf("MEDIA = %.1lf\n", media);
    
    return 0;
}