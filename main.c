//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

//Macros
//macros para atributos
#define forca          0
#define destreza       1 
#define constituicao   2  
#define inteligencia   3 
#define sabedoria      4 
#define carisma        5

//macros para classes
#define barbaro      1
#define bardo        2
#define bruxo        3
#define clerigo      4
#define druida       5
#define feiticeiro   6
#define guerreiro    7
#define ladino       8
#define mago         9
#define monge        10
#define paladino     11
#define patrulheiro  12

//Variáveis Globais
int atributo[6],
    modificador[6],
    teste_de_resistencia[6];

int classe_jogador = 0,
    pontos_de_vida;
//Protótipos de função
int calculoDeAtributos (void);
void escolhaClasse(void);
void calculaPontosDeVida(void);

//Função Principal
int main () {
  srand(time(NULL)); //Define a "semente" para gerar um número aleatório
 
  int raca_jogador, sub_raca;
  const char *atributos_nomes[] = {"forca", "destreza", "constituicao", "inteligencia", "sabedoria", "carisma"}; 
    
  //Inicializacao dos valores de atributo e modificadores respectivos
    for(int i = 0; i < 6; i++){
        atributo[i] = calculoDeAtributos(); // Calcula cada atributo
        modificador[i] = floor ((atributo[i] - (double)10)/2 ); //Calcula cada modificador baseado nos atributos 
        teste_de_resistencia[i] = modificador[i];
    }
    
    //init debug
    printf("\n");
    
    for(int i = 0; i < 6; i++){
        printf("%s = %d \n", atributos_nomes[i] ,atributo[i]);
    }

    printf("\n");

    for(int i = 0; i < 6; i++){
        printf ("modificador de  %s = (%d)\n", atributos_nomes[i], modificador[i]);
    }
    
    for(int i = 0; i < 6; i++){
        printf("Teste de resistencia atribut: %s = %d \n", atributos_nomes[i], teste_de_resistencia[i]);
    }
    //end debug

  do{ 
    printf ("\n 1. anao\n 2. elfo \n 3. halfling \n 4. humano \n 5. draconato \n 6. gnomo \n 7. meio-elfo \n 8. meio-orc \n 9. tiefling\n");
    printf ("Digite o numero referente a sua raca: \n");
    scanf ("%d",&raca_jogador);
 
    switch (raca_jogador){
      case 1: 
            printf ("voce e um anao agora");
            break;
      case 2: 
            printf ("voce e um elfo agora");
            break;
      case 3: 
            printf ("voce e um halfling agora");
            break;
      case 4: 
           printf ("voce e um humano agora");
           break;
      case 5: 
            printf ("voce e um draconato agora");
            break;
      case 6: 
            printf ("voce e um gnomo agora");
            break;
      case 7: 
            printf ("voce e um meio-elfo agora");
            break;
      case 8: 
            printf ("voce e um meio-orc agora");
            break;
      case 9: 
            printf ("voce e um tiefling agora");
            break;
      default:
            printf ("\nDigite o numero correto.");
            break;
  }
   } while (raca_jogador > 9 || raca_jogador < 1);

  if (raca_jogador == 1){
    do {
    printf ("\n 1. anao da colina (+1 de sabedoria); \n 2. anao da montanha (+2 de forca)");
    printf ("\nDigite o numero referente a uma das sub racas ");
      scanf ("%d",&sub_raca);
      switch (sub_raca){
        case 1: 
        printf ("voce e um anao da colina ");
        break;
        case 2: 
        printf ("voce e um anao da montanha");
        break;
        default:
        printf("\nDigite o numero correto");
      }
      }while (sub_raca > 2 || sub_raca < 1);
  }

    
  
   escolhaClasse();
   calculaPontosDeVida(); 
   //init debug
   printf("numero da classe: %d \n", classe_jogador);
   printf("pontos de vida: %d \n", pontos_de_vida);
   //end debug

  return 0;  
  } //end main

// Simula um dado de 6 lados
int calculoDeAtributos() {
    int habs[4]; //salva em cada índice 4 resultados de jogadas do dado
    int hab_t = 0; //salva a soma dos 3 resultados mais altos do dado 
    int min = 7;
    
    for (int i = 0; i < 4; i++) {
        habs[i] = rand() % 6 + 1;
    }
    
    //init debug
    for(int i = 0; i < 4; i++) {
        printf("%i ", habs[i]);
    }
    
    printf("\n");
    //end debug
    
    for (int i = 0; i < 4; i++) {
        hab_t += habs[i];        
        if( habs[i] < min) {
            min = habs[i];
        }
    }
    
    hab_t -= min;

    return hab_t;
}

void escolhaClasse() {
    while (classe_jogador <= 0 || classe_jogador > 12) {
        printf("\n\nCLASSES de D&D\n");
        printf("\n1.Barbaro \n2.Bardo \n3.Bruxo \n4.Clerigo \n5.Druida \n6.Feiticeiro");
        printf("\n7.Guerreiro \n8.Ladino \n9.Mago \n10.Monge \n11.Paladio \n12.Patrulheito");
        printf("\n\nEscolha a sua classe de acordo com numero respectivo: ");
        scanf("%d", &classe_jogador);
        
        if(classe_jogador < 0 || classe_jogador > 12) {
          printf("\nOpcao invalida! Pressione enter para tentar novamente");
          fflush(stdin); //limpa buffer do teclado. Necessaria para que o getchar() funcione corretamente.
          getchar(); 
        }
        system("cls"); //limpa a tela. No linux system("clear");
      } 
    } 

void calculaPontosDeVida() {
  switch (classe_jogador) {
       case barbaro:
            pontos_de_vida = 12 + modificador[constituicao];                 
            break;

       case bardo:
       case bruxo:
       case clerigo:
       case druida:
       case ladino:
       case monge:
            pontos_de_vida = 8 + modificador[constituicao];
            break;
           
       case feiticeiro:
       case mago:
            pontos_de_vida = 6 + modificador[constituicao];
            break;
                
       case guerreiro:
       case paladino:
       case patrulheiro:
            pontos_de_vida = 10 + modificador[constituicao];
            break;
  }
} 
