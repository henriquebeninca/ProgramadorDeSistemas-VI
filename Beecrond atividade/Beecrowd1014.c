#include <stdio.h>
 
int main() {
 
    int km = 0;
    double comb = 0.0;
    double conta  = 0.0;
    
    scanf("%d", &km);
    scanf("%lf", &comb);

    conta = km/comb;

    printf("%.3lf km/l\n", conta);

    return 0;
}