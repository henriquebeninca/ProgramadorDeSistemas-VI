#include <stdio.h>

int main () {
	
int matriz[4][4];
int i = 0, j = 0;
int macaco = 0;
printf("digite numeros para a matriz.\n");

for ( i=0; i<4; i++ ){
  for ( j=0; j<4; j++ ){
	printf ("\nElemento[%d][%d] = ", i, j);
    scanf ("%d", &matriz[i][j]);
	macaco += matriz[i][j];
  }  
}
for ( i=0; i<4; i++ ){
    for ( j=0; j<4; j++ ){
     printf("%d ", matriz[i][j]);
    }
	printf("\n");
}
	printf("soma da matriz igual a:%d\n", macaco);
return (0);
} 
