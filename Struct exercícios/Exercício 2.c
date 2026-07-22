#include <stdio.h>
#include <string.h>

struct aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    struct aluno alunos[5]; 
    int i;
	
    for (i = 0; i < 5; i++) { 
        
        printf("--- Digite os dados do aluno %d ---\n", i + 1);
            
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome); 
        
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
            
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }
    
    printf("\n=== Dados dos alunos cadastrados ===\n");
    for (i = 0; i < 5; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n\n", alunos[i].nota);
    }
    
    return 0;
}
