#include <stdio.h>

int main () {
	
int matriz[3][3];
int i = 0, j = 0;

printf("digite numeros para a matriz.\n");

for ( i=0; i<3; i++ ){
  for ( j=0; j<3; j++ ){
	printf ("\nElemento[%d][%d] = ", i, j);
    scanf ("%d", &matriz[i][j]);
  }  
}
for ( i=0; i<3; i++ ){
    for ( j=0; j<3; j++ ){
     printf("%d ", matriz[i][j]);
    }
	printf("\n");
}
return (0);
} 
