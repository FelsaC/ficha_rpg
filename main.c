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
void escolhaRaca (void);
void escolhaClasse(void);
void calculaPontosDeVida(void);
void calculoTesteDeResistencia(void);

//Função Principal
int main () {
  srand(time(NULL)); //Define a "semente" para gerar um número aleatório
  const char *atributos_nomes[] = {"forca", "destreza", "constituicao", "inteligencia", "sabedoria", "carisma"}; 
    
  //Inicializacao dos valores de atributo e modificadores respectivos
    for(int i = 0; i < 6; i++){
        atributo[i] = calculoDeAtributos(); // Calcula cada atributo
        modificador[i] = floor ((atributo[i] - (double)10)/2 ); //Calcula cada modificador baseado nos atributos 
        teste_de_resistencia[i] = modificador[i]; //Valores iniciais do teste de resistencia baseado modificador
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

   escolhaRaca ();
   escolhaClasse();
   calculaPontosDeVida(); 
   calculoTesteDeResistencia();
   //init debug
   for(int i = 0; i < 6; i++){
        printf("Teste de resistencia atribut: %s = %d \n", atributos_nomes[i], teste_de_resistencia[i]);
    }
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
        //system("cls"); //limpa a tela. No linux system("clear");
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

//escolha de racas
void escolhaRaca () {
  int atributos, clock , raca, sub_raca, raca_jogador;
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
            scanf ("%d",&atributos);
                switch (atributos){

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
            } while (atributos > 6 || atributos < 1 && clock != 2 );    
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

void calculoTesteDeResistencia() {
  switch (classe_jogador) {
    case bruxo:
    case clerigo:
    case paladino:
      teste_de_resistencia[sabedoria] += 2;
      teste_de_resistencia[carisma] +=  2;
      break;
  
    case barbaro:
    case guerreiro:
      teste_de_resistencia[forca] += 2;
      teste_de_resistencia[constituicao] += 2; 
      break;

    case druida:
    case mago:
      teste_de_resistencia[inteligencia] += 2;
      teste_de_resistencia[sabedoria] += 2;
      break;

    case monge:
    case patrulheiro:
      teste_de_resistencia[forca] += 2;
      teste_de_resistencia[destreza] += 2;
      break;

    case bardo:
      teste_de_resistencia[destreza] += 2;
      teste_de_resistencia[carisma] += 2;
      break;

    case feiticeiro:
      teste_de_resistencia[constituicao] += 2;
      teste_de_resistencia[carisma] += 2;
      break;
    
    case ladino:
      teste_de_resistencia[destreza] += 2;
      teste_de_resistencia[inteligencia] += 2;
      break;
  }
}