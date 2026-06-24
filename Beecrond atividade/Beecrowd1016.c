#include <stdio.h>
 
int main() {
    
    int a = 0;
    int b = 0;
    
    scanf("%d", &a);
    scanf("%d", &b);
    
    b = a+a;
    
    printf("%d minutos\n",  b);
    return 0;
}