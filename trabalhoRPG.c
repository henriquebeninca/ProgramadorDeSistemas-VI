#include <stdio.h>
#include <stdlib.h>

#define POCAO_P 1
#define POCAO_G 2
#define ESPADA 3
#define ARMADURA 4
#define ESCUDO 5


typedef struct {

    char nome[50];

    int vida;
    int vidaMaxima;

    int ataque;
    int defesa;

    int nivel;
    int experiencia;

    int ouro;

    int inventario[20];

} Personagem;


typedef struct {

    char nome[30];

    int vida;
    int ataque;

    int xp;
    int ouro;

} Monstro;



void criarPersonagem(Personagem *p);
void mostrarStatus(Personagem p);
void explorarMapa(Personagem *p);
void combate(Personagem *p, Monstro m);
void subirNivel(Personagem *p);
void loja(Personagem *p);
void inventario(Personagem *p);
void descansar(Personagem *p);
void chefeFinal(Personagem *p, int *menu);

int adicionarItem(Personagem *p, int item);
void nomeItem(int item);
void BossSecreto(Personagem *p, int *menu);


int main(){

    Personagem jogador;

    int i;

    jogador.nome[0] = '\0';


    for(i = 0; i < 20; i++)
        jogador.inventario[i] = 0;


    srand(1);


    int opcao;


    do{


        printf("\n=================================================\n");
        printf("          RPG DE TEXTO - A JORNADA DO HEROI\n");
        printf("=================================================\n");

        printf("\n1 - Criar Personagem");
        printf("\n2 - Ver Status");
        printf("\n3 - Explorar Mapa");
        printf("\n4 - Loja");
        printf("\n5 - Inventario");
        printf("\n6 - Descansar");
        printf("\n7 - Enfrentar Chefe Final");
        printf("\n0 - Sair");

        printf("\n\nEscolha: ");
        scanf("%d",&opcao);
        getchar();



        if(opcao != 1 && opcao != 0 && jogador.nome[0] == '\0'){

            printf("\nCrie um personagem primeiro!\n");

            continue;
        }



        switch(opcao){

            case 1:
                criarPersonagem(&jogador);
                break;

            case 2:
                mostrarStatus(jogador);
                break;

            case 3:
                explorarMapa(&jogador);
                break;

            case 4:
                loja(&jogador);
                break;

            case 5:
                inventario(&jogador);
                break;

            case 6:
                descansar(&jogador);
                break;

            case 7:
                chefeFinal(&jogador,&opcao);
                break;

			case 999:
                BossSecreto(&jogador,&opcao);
                break;
				
            case 0:
			
                printf("\nFim da aventura!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");

        }


    }while(opcao != 0);



    return 0;
}



// CRIAR PERSONAGEM

void criarPersonagem(Personagem *p){


    if(p->nome[0] != '\0'){

        printf("\nPersonagem ja criado!\n");

        return;
    }



    printf("\nDigite o nome do heroi: ");

    fgets(p->nome,50,stdin);



    int i = 0;

    while(p->nome[i] != '\n' && p->nome[i] != '\0')
        i++;


    p->nome[i] = '\0';



    p->vida = 100;
    p->vidaMaxima = 100;

    p->ataque = 10;
    p->defesa = 5;

    p->nivel = 1;
    p->experiencia = 0;

    p->ouro = 50;


    printf("\nPersonagem criado com sucesso!\n");

    printf("Boa sorte na jornada, %s!\n",p->nome);

}

void mostrarStatus(Personagem p){
    printf("\n===== STATUS =====\n");
    printf("Nome: %s\n",p.nome);
    printf("Vida: %d/%d\n",p.vida,p.vidaMaxima);
    printf("Ataque: %d\n",p.ataque);
    printf("Defesa: %d\n",p.defesa);
    printf("Nivel: %d\n",p.nivel);
    printf("Experiencia: %d/100\n",p.experiencia);
    printf("Ouro: %d\n",p.ouro);
}

void explorarMapa(Personagem *p){

    if(p->vida <= 0){
        printf("\nVoce esta sem vida. Descanse primeiro!\n");
        return;
    }

    int evento = rand()%5+1;

    printf("\nVoce explorou uma nova regiao do reino...\n");

    if(evento == 1){

        Monstro m;
        int tipo = rand()%4+1;

        if(tipo == 1){
            m.nome[0]='G';m.nome[1]='o';m.nome[2]='b';m.nome[3]='l';m.nome[4]='i';m.nome[5]='n';m.nome[6]='\0';
            m.vida=30;
            m.ataque=5;
            m.xp=20;
            m.ouro=15;
        }
        else if(tipo == 2){
            m.nome[0]='E';m.nome[1]='s';m.nome[2]='q';m.nome[3]='u';m.nome[4]='e';m.nome[5]='l';m.nome[6]='e';m.nome[7]='t';m.nome[8]='o';m.nome[9]='\0';
            m.vida=50;
            m.ataque=8;
            m.xp=35;
            m.ouro=25;
        }
        else if(tipo == 3){
            m.nome[0]='O';m.nome[1]='r';m.nome[2]='c';m.nome[3]='\0';
            m.vida=80;
            m.ataque=12;
            m.xp=50;
            m.ouro=40;
        }
        else{
            m.nome[0]='L';m.nome[1]='o';m.nome[2]='b';m.nome[3]='i';m.nome[4]='s';m.nome[5]='o';m.nome[6]='m';m.nome[7]='e';m.nome[8]='m';m.nome[9]='\0';
            m.vida=120;
            m.ataque=15;
            m.xp=70;
            m.ouro=60;
        }

        printf("\nUm %s apareceu!\n",m.nome);
        combate(p,m);
    }

    else if(evento == 2){

        int ouro = rand()%21+20;

        printf("\nVoce encontrou um bau!\n");
        printf("+%d moedas de ouro\n",ouro);

        p->ouro += ouro;
    }

    else if(evento == 3){

        int item = rand()%2+1;

        printf("\nVoce encontrou uma ");
        nomeItem(item);
        printf("!\n");

        if(adicionarItem(p,item))
            printf("Item adicionado ao inventario.\n");
        else
            printf("Inventario cheio.\n");
    }

    else if(evento == 4){

        printf("\nVoce caiu em uma armadilha!\n");
        printf("Perdeu 15 pontos de vida.\n");

        p->vida -= 15;

        if(p->vida < 0)
            p->vida = 0;
    }

    else{
        printf("\nNada aconteceu nesta area.\n");
    }
}

void combate(Personagem *p, Monstro m){

    int acao;
    int defendendo;

    while(p->vida > 0 && m.vida > 0){

        printf("\n===== COMBATE =====\n");
        printf("%s VS %s\n",p->nome,m.nome);
        printf("Sua vida: %d/%d\n",p->vida,p->vidaMaxima);
        printf("Vida do inimigo: %d\n",m.vida);

        printf("\n1 - Atacar\n");
        printf("2 - Defender\n");
        printf("3 - Fugir\n");
        printf("Escolha: ");
        scanf("%d",&acao);

        defendendo = 0;

        if(acao == 1){

            int dano = p->ataque;

            m.vida -= dano;

            printf("\nVoce atacou e causou %d de dano!\n",dano);

        }

        else if(acao == 2){

            defendendo = 1;

            printf("\nVoce levantou sua defesa!\n");

        }

        else if(acao == 3){

            printf("\nTentando fugir...\n");

            if(rand()%100 < 50){

                printf("Voce conseguiu fugir, covarde!\n");
                return;

            }
            else{

                printf("A fuga falhou!\n");

            }
        }

        else{

            printf("Opcao invalida!\n");

        }


        if(m.vida > 0){

            int dano = m.ataque - p->defesa;

            if(dano < 1)
                dano = 1;

            if(defendendo)
                dano = m.ataque/2;

            p->vida -= dano;

            printf("%s atacou e causou %d de dano!\n",m.nome,dano);

            if(p->vida < 0)
                p->vida = 0;
        }
    }


    if(m.vida <= 0){

        printf("\n%s derrotado!\n",m.nome);
        printf("+%d XP\n",m.xp);
        printf("+%d Ouro\n",m.ouro);

        p->experiencia += m.xp;
        p->ouro += m.ouro;

        subirNivel(p);

    }
    else{

        printf("\nVoce foi derrotado!\n");

    }
}


void subirNivel(Personagem *p){

    if(p->experiencia >= 100){

        p->nivel++;

        p->ataque += 5;
        p->defesa += 3;

        p->vidaMaxima += 20;

        p->vida = p->vidaMaxima;

        p->experiencia -= 100;

        printf("\nParabens!\n");
        printf("Voce subiu para o nivel %d!\n",p->nivel);

    }
}


void loja(Personagem *p){

    int item;
    int preco = 0;

    printf("\n===== LOJA =====\n");
    printf("Ouro: %d\n",p->ouro);

    printf("\n1 - Pocao Pequena 20 ouro");
    printf("\n2 - Pocao Grande 40 ouro");
    printf("\n3 - Espada 100 ouro");
    printf("\n4 - Armadura 120 ouro");
    printf("\n5 - Escudo 80 ouro");
    printf("\n0 - Voltar");

    printf("\nEscolha: ");
    scanf("%d",&item);


    if(item == 0)
        return;

    if(item == POCAO_P)
        preco = 20;
    else if(item == POCAO_G)
        preco = 40;
    else if(item == ESPADA)
        preco = 100;
    else if(item == ARMADURA)
        preco = 120;
    else if(item == ESCUDO)
        preco = 80;
    else{
        printf("Item invalido!\n");
        return;
    }


    if(p->ouro >= preco){

        if(adicionarItem(p,item)){

            p->ouro -= preco;

            printf("\nCompra realizada!\n");
            printf("Voce comprou ");
            nomeItem(item);
            printf(".\n");

        }
        else{

            printf("Inventario cheio!\n");

        }

    }
    else{

        printf("Ouro insuficiente!\n");

    }
}

void inventario(Personagem *p){

    int opcao;

    do{

        printf("\n===== INVENTARIO =====\n");
        printf("1 - Visualizar Itens\n");
        printf("2 - Usar Item\n");
        printf("3 - Descartar Item\n");
        printf("0 - Voltar\n");

        printf("Escolha: ");
        scanf("%d",&opcao);


        if(opcao == 1){

            int vazio = 1;

            printf("\nItens:\n");

            for(int i = 0; i < 20; i++){

                if(p->inventario[i] != 0){

                    printf("[%d] ",i+1);
                    nomeItem(p->inventario[i]);
                    printf("\n");

                    vazio = 0;
                }
            }

            if(vazio)
                printf("Inventario vazio.\n");

        }


        else if(opcao == 2){

            int pos;

            printf("Digite o numero do item: ");
            scanf("%d",&pos);

            pos--;


            if(pos < 0 || pos >= 20 || p->inventario[pos] == 0){

                printf("Item invalido!\n");

            }

            else{

                int item = p->inventario[pos];


                if(item == POCAO_P){

                    p->vida += 20;

                    if(p->vida > p->vidaMaxima)
                        p->vida = p->vidaMaxima;

                    printf("\nVoce usou Pocao Pequena.\n");
                    printf("Recuperou 20 de vida.\n");

                }


                else if(item == POCAO_G){

                    p->vida += 50;

                    if(p->vida > p->vidaMaxima)
                        p->vida = p->vidaMaxima;

                    printf("\nVoce usou Pocao Grande.\n");
                    printf("Recuperou 50 de vida.\n");

                }


                else if(item == ESPADA){

                    p->ataque += 5;

                    printf("\nVoce equipou uma Espada.\n");
                    printf("Ataque +5!\n");

                }


                else if(item == ARMADURA){

                    p->defesa += 5;

                    printf("\nVoce equipou uma Armadura.\n");
                    printf("Defesa +5!\n");

                }


                else if(item == ESCUDO){

                    p->defesa += 3;

                    printf("\nVoce equipou um Escudo.\n");
                    printf("Defesa +3!\n");

                }


                p->inventario[pos] = 0;

            }

        }


        else if(opcao == 3){

            int pos;

            printf("Digite o numero do item: ");
            scanf("%d",&pos);

            pos--;


            if(pos >= 0 && pos < 20 && p->inventario[pos] != 0){

                p->inventario[pos] = 0;

                printf("Item descartado.\n");

            }

            else{

                printf("Item invalido!\n");

            }

        }


    }while(opcao != 0);

}



void descansar(Personagem *p){

    printf("\nVoce parou para descansar depois de uma longa jornada...\n");


    if(p->vida <= 0){

        p->vida = 30;

        printf("Voce voltou a batalha!\n");

    }

    else{

        p->vida += 30;

        if(p->vida > p->vidaMaxima)
            p->vida = p->vidaMaxima;

        printf("Voce recuperou 30 pontos de vida.\n");

    }


    printf("Vida atual: %d/%d\n",p->vida,p->vidaMaxima);

}



void chefeFinal(Personagem *p,int *menu){

    Monstro dragao;


    if(p->nivel < 5){

        printf("\nVoce ainda nao esta preparado para enfrentar o Dragao.\n");
        printf("Necessario: Nivel 5\n");
        printf("Seu nivel: %d\n",p->nivel);

        return;
    }


    dragao.nome[0]='D';
    dragao.nome[1]='r';
    dragao.nome[2]='a';
    dragao.nome[3]='g';
    dragao.nome[4]='a';
    dragao.nome[5]='o';
    dragao.nome[6]='\0';

    dragao.vida = 300;
    dragao.ataque = 25;
    dragao.xp = 999;
    dragao.ouro = 999;


    printf("\nO Dragao das Sombras apareceu!\n");
    printf("A batalha final comecou!\n");


    combate(p,dragao);


    if(p->vida > 0){

        printf("\n=================================\n");
        printf("Parabens, Heroi!\n");
        printf("Voce derrotou o Dragao das Sombras!\n");
        printf("O Reino de C-Nai foi salvo!\n");
		printf("\nMas tenha calma aventureiro\n");
		printf("Sua jornada ainda nao acabou!\n");
        printf("=================================\n");

        *menu = 1;

    }

}



int adicionarItem(Personagem *p,int item){

    for(int i = 0; i < 20; i++){

        if(p->inventario[i] == 0){

            p->inventario[i] = item;

            return 1;

        }

    }

    return 0;

}


void nomeItem(int item){

    if(item == POCAO_P)
        printf("Pocao Pequena");

    else if(item == POCAO_G)
        printf("Pocao Grande");

    else if(item == ESPADA)
        printf("Espada");

    else if(item == ARMADURA)
        printf("Armadura");

    else if(item == ESCUDO)
        printf("Escudo");

}

void BossSecreto(Personagem *p,int *menu){

    Monstro secret;


    if(p->nivel < 10){

        printf("\nComo voce descobriu isso??\n");
		printf("\nVoce nao esta preparado!\n");
        printf("Necessario: Nivel 10\n");
        printf("Seu nivel: %d\n",p->nivel);

        return;
    }
	
	secret.nome[0]='A';
    secret.nome[1]='D';
    secret.nome[2]='M';
    secret.nome[3]='\0';

    secret.vida = 1000;
    secret.ataque = 100;
    secret.xp = 0;
    secret.ouro = 1000;


    printf("\nO ADM apareceu!\n");
    printf("\nVoce sera julgado!\n");


    combate(p,secret);
	
	if(p->vida > 0){

        printf("\n=================================\n");
        printf("Parabens, Heroi!\n");
        printf("Voce derrotou o ADM!\n");
        printf("Voce e uma lenda incompreendida!\n");
        printf("=================================\n");

        *menu = 0;

    }
	
}