//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

//Macros
#define forca          0
#define destreza       1 
#define constituicao   2  
#define inteligencia   3 
#define sabedoria      4 
#define carisma        5
#define deslocamento   0

//Variáveis Globais
int atributo[6],
    modificador[6];

//Protótipos de função
int calculoDeAtributos (void);
void escolhaRaca (void);

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
  printf (" inteligencia = %d \n", atributo[inteligencia]);
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
  
  escolhaRaca ();
 
    
  
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

//escolha de racas
void escolha_raca () {
  int atributo, clock , raca, sub_raca, raca_jogador;
 do{ 
    printf ("\n 1. anao\n 2. elfo \n 3. halfling \n 4. humano \n 5. draconato \n");
    printf ("6. gnomo \n 7. meio-elfo \n 8. meio-orc \n 9. tiefling \n");
    printf ("Digite o numero referente a sua raca: \n");
    scanf ("%d",&raca_jogador);
    system("cls");
    switch (raca_jogador){
      case 1: //anao
            atributo[constituicao] = atributo[constituicao] + 2;
            //deslocamento = 7.5;
       do{
            printf ("\n 1. anao da colina (+1 de sabedoria); \n 2. anao da montanha (+2 de forca)");
            printf ("\nDigite o numero referente a uma das sub racas ");
            scanf ("%d",&sub_raca);
            if (sub_raca == 1){
               atributo[sabedoria] = atributo[sabedoria] + 1;
            } else
              if  (sub_raca == 2) {
                atributo[forca] = atributo[forca] + 2;
              } else {
                printf ("/n digite novamente");
              }
          }while (sub_raca > 2 || sub_raca < 1);  
            break;
      case 2: //elfo
            atributo[destreza] + 2;
            //deslocamento == 9;
           do {
            printf ("\n Escolha uma sub raca \n 1.Alto Elfo: +1 de inteligencia \n 2.Elfo da Floresta: +1 de Sabedoria, deslocamento passa a ser 10,5m \n 3.Elfo Negro: +1 de Carisma \n");
            scanf ("%d", &sub_raca);
              switch (sub_raca){
                  case 1:
                  atributo[inteligencia] = atributo[inteligencia] + 1;
                  break;

                  case 2:
                  atributo[sabedoria] = atributo[sabedoria] + 1;
                  //deslocamento == 10.5;
                  break;

                  case 3:
                  atributo[carisma] = atributo[carisma] + 1;
                  break;

                  default:
                  printf ("digite novamente");
                  break;
            };
             }while (sub_raca > 3 || sub_raca < 1);

            break;
      case 3: //halfling
            atributo[destreza] + 2;
            //deslocamento 7.5

             do{
            printf ("\n 1. Pes leves: +1 de carisma; \n 2.Robusto: +1 de constituiçao");
            printf ("\nDigite o numero referente a um das sub racas ");
            scanf ("%d",&sub_raca);
            if (sub_raca == 1){
               atributo[carisma] = atributo[carisma] + 1;
            } else
              if  (sub_raca == 2) {
                atributo[constituicao] = atributo[constituicao]  + 1;
              } else {
                printf ("/n digite novamente");
              }
          }while (sub_raca > 2 || sub_raca < 1);  
            
            break;
      case 4: //humano
           
           atributo[forca] =        atributo[forca] + 1;    
           atributo[destreza] =     atributo[destreza] + 1;    
           atributo[constituicao] = atributo[constituicao] + 1; 
           atributo[inteligencia] = atributo[inteligencia] + 1;
           atributo[sabedoria] =    atributo[sabedoria] + 1; 
           atributo[carisma] =      atributo[carisma] + 1;
          //deslocamento 9;

           break;
      case 5: //draconato
           atributo[forca] = atributo[forca]  + 2;
           atributo[carisma] = atributo[carisma] + 1;
           //deslocamento == 9;

            break;
      case 6: //gnomo 
            atributo[inteligencia] = atributo[inteligencia] + 2;
            //deslocamento == 7.5
            
          do{
            printf ("\n 1. Gnomo da floresta ; \n 2. (subraca2)");
            printf ("\nDigite o numero referente a um das sub racas ");
            scanf ("%d",&sub_raca);
            if (sub_raca == 1){
               atributo[destreza] = atributo[destreza] + 1;
            } else
              if  (sub_raca == 2) {
                atributo[constituicao] = atributo[constituicao] + 1;
              } else {
                printf ("/n digite novamente");
              }
          }while (sub_raca > 2 || sub_raca < 1);
            break;
      case 7: //meio-elfo
            atributo[carisma] = atributo[carisma] + 2;
            //deslocamento 9m; 
           do{
            printf ("\n Escolha duas habilidades para adcionar mais 1 ponto: \n");
                switch (atributo){

                  case 1:
                    atributo[forca] =                atributo[forca] + 1;
                  break;
                  case 2:
                    atributo[destreza] =          atributo[destreza] + 1;
                  break;
                  case 3:
                    atributo[constituicao] =  atributo[constituicao] + 1;
                  break;
                  case 4:
                    atributo[inteligencia] = atributo[inteligencia]  + 1;
                  break;
                  case 5:
                    atributo[sabedoria] =        atributo[sabedoria] + 1;
                  break;
                  case 6:
                    atributo[carisma] =            atributo[carisma] + 1;
                  break;
                  default:
                  printf ("\n Digite novamente \n");
                }
              clock++;
            } while (atributo > 6 || atributo < 1 && clock != 2 );    
            break;
      case 8: //meio-orc 
            atributo[forca] = atributo[forca] + 2;
            atributo[constituicao] = atributo[constituicao] + 1;
            //deslocamento 9;
            break;
      case 9: //tiefling
            atributo[inteligencia] = atributo[inteligencia] + 1;
            atributo[carisma] = atributo[carisma] + 2;
            break;
      default:
            printf ("\nDigite o numero correto.");
            break;
  }
   } while (raca_jogador > 9 || raca_jogador < 1);

}