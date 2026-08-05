#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 8

typedef struct
{
	char nome[50];
	int tentativas;
	
} Jogador;

void inicializarTabuleiro(char tabuleiro[8][8]);
void mostrarTabuleiro(char tabuleiro[8][8]);
void posicionarNavios(char tabuleiro[8][8]);
int realizarAtaqueTabuleiro(char tabuleiro[8][8], int *destruidos);
void salvarResultado(Jogador jogador);
void lerResultados();

int main()
{
	char tabuleiro[8][8];
    int destruidos = 0;
    Jogador jogador;
    jogador.tentativas = 0;

	srand(time(NULL));
	
	printf("----------------------------------\n");
	printf("   BEM VINDO A BATALHA NAVAL\n");
	printf("----------------------------------\n");
	
	printf("Digite seu nome:");
	scanf("%s", jogador.nome);
	
	inicializarTabuleiro(tabuleiro);
	posicionarNavios(tabuleiro);
	
	while (destruidos < 3) {
        mostrarTabuleiro(tabuleiro);
        realizarAtaqueTabuleiro(tabuleiro, &destruidos);
        jogador.tentativas++;
    }
	
	printf("\n=================================\n");
	printf("Parabens: %s!\n", jogador.nome);
	printf("Todos os navios foram destruidos\n");
	printf("Tentativas: %d\n", jogador.tentativas);
	printf("=================================\n");
	
	salvarResultado(jogador);
	lerResultados();
	
	return(0);
	
}
	
void inicializarTabuleiro(char tabuleiro[8][8])
{
	int i, j;
	
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			tabuleiro[i][j] = '~';
		}
	}
}

void mostrarTabuleiro(char tabuleiro[8][8])
{
	int i, j;
	
	printf("\n      ");
	
	for(j=0;j<8;j++)
	printf("%d ", j);
	
	printf("\n");
	
	for(i=0;i<8;i++)
	{
		printf("%d  |  ", i);
		
		for(j=0;j<8;j++)
		{
			if(tabuleiro[i][j]=='N')
				printf("~ ");
		
			else 
				printf("%c ", tabuleiro[i][j]);
		}
		printf("\n");
	}
	
}

void posicionarNavios(char tabuleiro[8][8])
{ 
int coluna, linha;
int naviosposicionados = 0;

while(naviosposicionados < 3) {
	
	linha = rand() % 8;
	coluna = rand() % 8;
	
	 if (tabuleiro[linha][coluna] != 'N') {
        (tabuleiro[linha][coluna] = 'N');
            naviosposicionados++;
		}
	}
}

int realizarAtaqueTabuleiro(char tabuleiro[8][8], int *destruidos)
{
	int linha, coluna;

	printf("\nLinha:");
	scanf("%d", &linha);
	printf("\nColuna: ");
	scanf("%d", &coluna);

	if (tabuleiro[linha][coluna] == 'N')
	{
		printf("ACERTOU!\n");
	
		tabuleiro[linha][coluna] = 'N';
		(*destruidos)++;
		return(1);
	}
	printf("AGUA!\n");
		tabuleiro[linha][coluna] = 'O';
		return(1);
}

void salvarResultado(Jogador jogador)
{
	FILE *arquivo = fopen("historico.txt", "a");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo para salvar.\n");
		return;
	}
	fprintf(arquivo, "%s | %d tentativas\n", jogador.nome, jogador.tentativas);
	fclose(arquivo);
}

void lerResultados() 
{
	char linha[100];
	FILE *arquivo = fopen("historico.txt", "r");

	if (arquivo == NULL) {
		printf("Nenhum historico encontrado.\n");
		return;
	}

	printf("\n--- HISTORICO DE JOGADORES ---\n");
	while(fgets(linha, sizeof(linha), arquivo) != NULL) {
		printf("%s", linha);
	}
	printf("------------------------------\n");
	fclose(arquivo);
}