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
    modificador[6];

int option,
    classe_jogador,
    pontos_de_vida;
//Protótipos de função
int calculoDeAtributos (void);
void escolhaClasse(void);

//Função Principal
int main () {
  int raca_jogador, sub_raca;
  
//Define a "semente" para gerar um número aleatório
  srand(time(NULL));
  
//cálculo básico de atributos 
  atributo[forca]        = calculoDeAtributos();
  atributo[destreza]     = calculoDeAtributos();
  atributo[constituicao] = calculoDeAtributos();
  atributo[inteligencia] = calculoDeAtributos();
  atributo[sabedoria]    = calculoDeAtributos();
  atributo[carisma]      = calculoDeAtributos();


  printf ("\n\n forca = %d \n",    atributo[forca]);
  printf (" destreza = %d \n",     atributo[destreza]);
  printf (" constituicao = %d \n", atributo[constituicao]);
  printf (" intelifencia = %d \n", atributo[inteligencia]);
  printf (" sabedoria = %d \n",    atributo[sabedoria]);
  printf (" carisma = %d \n",      atributo[carisma]);

// calculo do modificador
  modificador[forca]        = floor ((atributo[forca]        - (double)10)/2 );
  modificador[destreza]     = floor ((atributo[destreza]     - (double)10)/2 );
  modificador[constituicao] = floor ((atributo[constituicao] - (double)10)/2 );
  modificador[inteligencia] = floor ((atributo[inteligencia] - (double)10)/2 );
  modificador[sabedoria]    = floor ((atributo[sabedoria]    - (double)10)/2 );
  modificador[carisma]      = floor ((atributo[carisma]      - (double)10)/2 );
  
  printf ("\nmodificador de forca = (%d)",        modificador[forca]);
  printf ("\nmodificador de destreza = (%d)",     modificador[destreza]);
  printf ("\nmodificador de constituicao = (%d)", modificador[constituicao]);
  printf ("\nmodificador de inteligencia = (%d)", modificador[inteligencia]);
  printf ("\nmodificador de sabedoria = (%d)",    modificador[sabedoria]);
  printf ("\nmodificador de carisma = (%d)\n",    modificador[carisma]);
  
  //escolha de classe
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
   //init debug
   printf("numero da classe: %d \n", classe_jogador);
   printf("pontos de vida: %d \n", pontos_de_vida);
   //end debug

  return 0;  
  } //end main

//Funções Auxiliares
/*int calculoDeAtributos () {
  int hab1, hab2, hab3, hab4, hab_t, tmp;
  
  hab1 = (rand() % 6 + 1);
  hab2 = (rand() % 6 + 1);
  hab3 = (rand() % 6 + 1);
  hab4 = (rand() % 6 + 1);
   
    if (hab1 < hab4) {
        tmp = hab4;
        hab4 = hab1;
        hab1 = tmp;
    }
  
    if (hab1 < hab3) {
        tmp = hab3;
        hab3 = hab1;
        hab1 = tmp;
    }
  
    if (hab1 < hab2) {
        tmp = hab2;
        hab2 = hab1;
        hab1 = tmp;
    }
    if (hab2 < hab4) {
        tmp = hab4;
        hab4 = hab2;
        hab2 = tmp;
    }
  
    if (hab2 < hab3) {
        tmp = hab3;
        hab3 = hab2;
        hab2 = tmp;
    }
      

    if (hab3 < hab4) {
        tmp = hab4;
        hab4 = hab3;
        hab3 = tmp;
    }

  
  printf("\n%d %d %d %d\n", hab1, hab2, hab3, hab4);  

  
  hab_t = hab1 + hab2 + hab3;
  return hab_t;
  
} */

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
    do {
        printf("\n\nCLASSES de D&D\n");
        printf("\n1.Barbaro \n2.Bardo \n3.Bruxo \n4.Clerigo \n5.Druida \n6.Feiticeiro");
        printf("\n7.Guerreiro \n8.Ladino \n9.Mago \n10.Monge \n11.Paladio \n12.Patrulheito");
        printf("\n\nEscolha a sua classe de acordo com numero respectivo: ");
        scanf("%d", &option);
        system("cls"); //limpa a tela. No linux system("clear");

        switch (option) {
            case barbaro:
                pontos_de_vida = 12 + modificador[constituicao];                 
                break;

            case bardo:
                pontos_de_vida = 8 + modificador[constituicao];
                break;
            
            case bruxo:
                pontos_de_vida = 8 + modificador[constituicao]; 
                break;

            case clerigo:
                pontos_de_vida = 8 + modificador[constituicao];
                break;
            
            case druida:
                pontos_de_vida = 8 + modificador[constituicao];
                break;
            
            case feiticeiro:
                pontos_de_vida = 6 + modificador[constituicao];
                break;
                
            case guerreiro:
                pontos_de_vida = 10 + modificador[constituicao];
                break;
            
            case ladino:
                pontos_de_vida = 8 + modificador[constituicao];
                break;

            case mago:
                pontos_de_vida = 6 + modificador[constituicao];
                break;

            case monge:
                pontos_de_vida = 8 + modificador[constituicao];
                break;

            case paladino: 
                pontos_de_vida = 10 + modificador[constituicao];
                break;

            case patrulheiro:
                pontos_de_vida = 10 + modificador[constituicao];
                break;

            default:
                printf("\nOpcao invalida! Pressione enter para tentar novamente");
                fflush(stdin);
                getchar();
            break;
        }
    } while (option < 0 || option > 13);

    classe_jogador = option;  
}