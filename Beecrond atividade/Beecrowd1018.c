#include <stdio.h>

int main() {
    int valor, atual;
    
    if (scanf("%d", &valor) != 1) return 0;
    
    printf("%d\n", valor);
    
    atual = valor;
    
    printf("%d nota(s) de R$ 100,00\n", atual / 100);
    atual %= 100;
    
    printf("%d nota(s) de R$ 50,00\n", atual / 50);
    atual %= 50;
    
    printf("%d nota(s) de R$ 20,00\n", atual / 20);
    atual %= 20;
    
    printf("%d nota(s) de R$ 10,00\n", atual / 10);
    atual %= 10;
    
    printf("%d nota(s) de R$ 5,00\n", atual / 5);
    atual %= 5;
    
    printf("%d nota(s) de R$ 2,00\n", atual / 2);
    atual %= 2;

    printf("%d nota(s) de R$ 1,00\n", atual / 1);
    
    return 0;
}