#include <stdio.h>
 
int main() {
 
   int n = 0; 
   int horas;
   int minutos;
   int segundos;
   
   scanf("%d", &n);
   
   horas = n/3600;
   minutos = (n % 3600)/60;
   segundos = n % 60;
   
   printf("%d:%d:%d\n", horas, minutos, segundos);
   
    return 0;
}