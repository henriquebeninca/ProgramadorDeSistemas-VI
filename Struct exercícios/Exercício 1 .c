#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[100];
    char autor[100];
    float preco;
};

int main() {

    struct Livro meuLivro;

    strcpy(meuLivro.titulo, "Dom Casmurro");
    strcpy(meuLivro.autor, "Machado de Assis");
    meuLivro.preco = 39.90;

    printf("=== Dados do Livro ===\n");
    printf("Título: %s\n", meuLivro.titulo);
    printf("Autor:  %s\n", meuLivro.autor);
    printf("Preço:  R$ %.2f\n", meuLivro.preco);

    return 0;
}