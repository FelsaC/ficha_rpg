//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>




//Protótipos de função
int calculoDeAtributos (void);

//Função Principal
int main () {
  int forca, destreza, constituicao, inteligencia, sabedoria, carisma, raca_jogador, sub_raca, modificador;
  int modificador_forca, modificador_destreza, modificador_constituicao, modificador_inteligencia, modificador_sabedoria, modificador_carisma;
  
  
  
  //Define a "semente" para gerar um número aleatório
  srand(time(NULL));
  
//cálculo básico de habilidades 
    forca        = calculoDeAtributos();
  destreza     = calculoDeAtributos();
  constituicao = calculoDeAtributos();
  inteligencia = calculoDeAtributos();
  sabedoria    = calculoDeAtributos();
  carisma      = calculoDeAtributos();

 
  
  printf ("\n\n forca = %d \n", forca);
  printf (" destreza = %d \n", destreza);
  printf (" constituicao = %d \n", constituicao);
  printf (" intelifencia = %d \n", inteligencia);
  printf (" sabedoria = %d \n", sabedoria);
  printf (" carisma = %d \n", carisma);

// calculo do modificador
    modificador_forca = floor ((forca - 10)/2 );
    printf ("\nmodificador de forca = (%d)", modificador_forca);
    modificador_destreza = floor ((destreza - 10)/2 );
    printf ("\nmodificador de destreza = (%d)", modificador_destreza);
    modificador_constituicao = floor ((constituicao - 10)/2 );
    printf ("\nmodificador de constituicao = (%d)", modificador_constituicao);
    modificador_inteligencia = floor ((inteligencia - 10)/2 );
    printf ("\nmodificador de inteligencia = (%d)", modificador_inteligencia);
    modificador_sabedoria = floor ((sabedoria - 10)/2 );
    printf ("\nmodificador de sabedoria = (%d)", modificador_sabedoria);
    modificador_carisma = floor ((carisma - 10)/2 );
    printf ("\nmodificador de carisma = (%d)\n", modificador_carisma);



  
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
