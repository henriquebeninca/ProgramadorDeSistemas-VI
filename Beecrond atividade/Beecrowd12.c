#include <stdio.h>
 
int main() {

    double raio = 0.0;
    double pi = 3.14159; 
    double volume = 0.0;
    
    scanf("%lf", &raio);

    volume = (4.0/3.0)*pi*raio*raio*raio;
    
    printf("VOLUME = %.3lf\n", volume);

    return 0;
}