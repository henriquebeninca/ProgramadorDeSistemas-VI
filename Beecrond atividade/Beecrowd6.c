#include <stdio.h>
 
int main() {
    double nota1 = 0.0;
    double nota2 = 0.0;
    double media = 0.0;
    
    scanf("%lf", &nota1);
    scanf("%lf", &nota2);
    
    media = ((nota1*3.5)+(nota2*7.5))/11.0;
    
    printf("MEDIA = %.5lf\n", media);
    
    return 0;
    
}