//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

//Macros
//constantes atributos
#define forca          0
#define destreza       1 
#define constituicao   2  
#define inteligencia   3 
#define sabedoria      4 
#define carisma        5

//constantes classes
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

//constantes pericias
#define atletismo        0 
#define acrobacia        1
#define furtividade      2
#define prestidigitacao  3
#define arcanismo        4  
#define historia         5
#define investigacao     6
#define natureza         7
#define religiao         8 
#define adestrar_animais 9
#define intuicao         10
#define medicina         11
#define percepcao        12
#define sobrevivencia    13
#define atuacao          14
#define enganacao        15
#define intimidacao      16
#define persuasao        17

//constantes racas
#define anao             1
#define elfo             2        
#define halfiling        3
#define humano           4
#define draconato        5
#define gnomo            6
#define meio_elfo        7
#define meio_orc         8
#define tielfing         9

//Variáveis Globais
int atributo[6],
    modificador[6],
    teste_de_resistencia[6],
    pericias_valores[18];

int classe_jogador = 0,
    raca_jogador = 0,
    sub_raca,
    pontos_de_vida,
    iniciativa;

//vetores de strings
const char *atributos_nomes[] = {
      "forca",           //0 
      "destreza",        //1
      "constituicao",    //2
      "inteligencia",    //3
      "sabedoria",       //4
      "carisma"          //5    
};

const char *pericias_nomes[] = {
      "atletismo",        //0 
      "acrobacia",        //1
      "furtividade",      //2
      "prestidigitacao",  //3
      "arcanismo",        //4  
      "historia",         //5
      "investigacao",     //6
      "natureza",         //7
      "religiao",         //8
      "adestrar_animais", //9
      "intuicao",         //10
      "medicina",         //11
      "percepcao",        //12
      "sobrevivencia",    //13
      "atuacao",          //14
      "enganacao",        //15
      "intimidacao",      //16
      "persuasao"         //17
};

//discutir indice
const char *classes_nomes[] = {
  "barbaro",  
  "bardo", 
  "bruxo",  
  "clerigo",  
  "druida",  
  "feiticeiro",  
  "guerreiro",  
  "ladino",  
  "mago",  
  "monge",  
  "paladino",  
  "patrulheiro",  
};

//discutir indice
const char *racas_nomes[] = {
    "anao",             
    "elfo",            
    "halfiling",       
    "humano",          
    "draconato",       
    "gnomo",           
    "meio-elfo",  
    "meio-or",
    "tielfing"
};

//Protótipos de função
int  calculoDeAtributos();
void escolhaRacas();
void escolhaSubRaca();
void escolhaClasse();
void calculaPontosDeVida();
void calculoTesteDeResistencia();
void calculoPericias();
void initValoresIniciais();
void initPericias();

//Função Principal
int main () {
    srand(time(NULL)); //Define a "semente" para gerar um número aleatório
   
    int raca_jogador, sub_raca;   
   
    initValoresIniciais();
    escolhaClasse();
    calculoPericias();
    calculaPontosDeVida(); 
    calculoTesteDeResistencia();
       
    printf("numero da classe: %d \n", classe_jogador);
    printf("pontos de vida: %d \n", pontos_de_vida);

   
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
        printf("\n\nDigite o numero referente a sua classe: ");
        scanf("%d", &classe_jogador);
        
        if(classe_jogador < 0 || classe_jogador > 12) {
          printf("\nOpcao invalida! Pressione enter para tentar novamente");
          fflush(stdin); //limpa buffer do teclado. Necessaria para que o getchar() funcione corretamente.
          getchar(); //o terminal congela ate que uma tecla seja pressionda
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

void initValoresIniciais() {
  //Inicializacao dos valores de atributo, modificadores e teste de resistência
  for(int i = 0; i < 6; i++) {
        atributo[i] = calculoDeAtributos(); // Calcula cada atributo
        modificador[i] = floor ((atributo[i] - (double)10)/2 ); //Calcula cada modificador baseado nos atributos 
        teste_de_resistencia[i] = modificador[i]; //Valores iniciais do teste de resistencia baseado modificador
  }

  //Inicialização da iniciativa
  iniciativa = modificador[destreza];

  //inicialização das pericias
    initPericias();

   //init debug
    for(int i = 0; i < 6; i++){
        printf("%s = %d \n", atributos_nomes[i] ,atributo[i]);
    }

    printf("\n");

    for(int i = 0; i < 6; i++){
        printf ("modificador de  %s = (%d)\n", atributos_nomes[i], modificador[i]);
    }
    
    printf("\n");

    for(int i = 0; i < 6; i++){
        printf("Teste de resistencia atribut: %s = %d \n", atributos_nomes[i], teste_de_resistencia[i]);
    }
  
    printf("\n");
  
    for(int i = 0; i < 18; i++){
        printf("Pericias %s = %d \n", pericias_nomes[i], pericias_valores[i]);
    }
    
    printf("\n");

    printf("Iniciativa = %d \n", iniciativa);

    //end debug
}

void calculoPericias() {
    //tabelas de pericias primeiro item 
    int proficiencias[18] = {};
    int tabela_pericias[18][18] = {
        {atletismo, adestrar_animais, intimidacao, natureza, percepcao, sobrevivencia, -1}, //Barbaro
  
        {atletismo, acrobacia, furtividade, prestidigitacao, arcanismo,historia,investigacao, natureza , religiao, adestrar_animais,
        intuicao, medicina, percepcao, sobrevivencia, atuacao, enganacao,intimidacao,persuasao}, //Bardo
  
        {arcanismo, enganacao, historia, investigacao, natureza, religiao, -1}, //Bruxo
  
        {historia, intuicao, medicina, persuasao, religiao, -1}, //Clérigo
  
        {arcanismo, adestrar_animais, intuicao, medicina, percepcao, religiao,sobrevivencia, -1}, //Druida
  
        {arcanismo, enganacao, intuicao, intimidacao, persuasao, religiao, -1},//Feiticeiro
  
        {acrobacia, adestrar_animais, atletismo, historia, intuicao, intimidacao,percepcao, sobrevivencia, -1}, //Guerreiro
  
        {acrobacia, atletismo, atuacao, enganacao, furtividade, intimidacao,intuicao, investigacao, percepcao, persuasao, prestidigitacao, -1}, //Ladino
  
        {arcanismo, historia, intuicao, investigacao, medicina, religiao, -1},//Mago
  
        {acrobacia, atletismo, furtividade, historia, intuicao, religiao, -1},//monge
  
        {atletismo, intuicao, intimidacao, medicina, persuasao, religiao, -1},//Paladino
  
        {adestrar_animais, atletismo, furtividade, intuicao, investigacao, natureza,percepcao, sobrevivencia, -1}//Patruleiro   
    };
  
  for(int i = 0;i < 12; i++) {
    printf("%s:\n",classes_nomes[i]);
    for(int j = 0; j < 18; j++){
      if(tabela_pericias[i][j] != -1){
        printf("%i",tabela_pericias[i][j]);
        printf("*%s\n",pericias_nomes[tabela_pericias[i][j]]);
      } else{
        break;
      }
    } 
    printf("\n");
  }
}

void initPericias() {
  pericias_valores[atletismo]         =   modificador[forca];
  pericias_valores[acrobacia]         =   modificador[destreza];
  pericias_valores[furtividade]       =   modificador[destreza];
  pericias_valores[prestidigitacao]   =   modificador[destreza];
  pericias_valores[arcanismo]         =   modificador[inteligencia];
  pericias_valores[historia]          =   modificador[inteligencia];
  pericias_valores[investigacao]      =   modificador[inteligencia];
  pericias_valores[natureza]          =   modificador[inteligencia];
  pericias_valores[religiao]          =   modificador[inteligencia];
  pericias_valores[adestrar_animais]  =   modificador[sabedoria];
  pericias_valores[intuicao]          =   modificador[sabedoria];
  pericias_valores[medicina]          =   modificador[sabedoria];
  pericias_valores[percepcao]         =   modificador[sabedoria];
  pericias_valores[sobrevivencia]     =   modificador[sabedoria];
  pericias_valores[atuacao]           =   modificador[carisma];
  pericias_valores[enganacao]         =   modificador[carisma];
  pericias_valores[intimidacao]       =   modificador[carisma];
  pericias_valores[persuasao]         =   modificador[carisma];
}

void escolhaRaca() {
  while (raca_jogador <= 0 || raca_jogador > 9){
      printf ("\n 1. anao\n 2. elfo \n 3. halfling \n 4. humano \n 5. draconato \n");
    printf ("6. gnomo \n 7. meio-elfo \n 8. meio-orc \n 9. tiefling \n");
      printf ("Digite o numero referente a sua raca: \n");
      scanf ("%d",&raca_jogador);
      //system("cls");
      if(classe_jogador < 0 || classe_jogador > 9) {
          printf("\nOpcao invalida! Pressione enter para tentar novamente");
          fflush(stdin); //limpa buffer do teclado. Necessaria para que o getchar() funcione corretamente.
          getchar(); //o terminal congela ate que uma tecla seja pressionda
        }
        //system("cls"); //limpa a tela. No linux system("clear");
  
   }
}

void escolhaSubRaca(){
    switch(raca_jogador){
        case anao:
            printf ("\n 1. anao da colina (+1 de sabedoria); \n 2. anao da montanha (+2 de forca)");
            printf ("\nDigite o numero referente a uma das sub racas ");
            scanf ("%d",&sub_raca);
            break;
      
        case elfo:
            printf ("\n Escolha uma sub raca \n 1.Alto Elfo: +1 de inteligencia \n 2.Elfo da Floresta: +1 de Sabedoria, deslocamento passa a ser 10,5m \n 3.Elfo Negro: +1 de Carisma \n");
            scanf ("%d",&sub_raca);
            break;

         case halfiling:
            printf ("\n 1. Pes leves: +1 de carisma; \n 2.Robusto: +1 de constituiçao");
            printf ("\nDigite o numero referente a um das sub racas ");
            scanf ("%d",&sub_raca);
            break;
      
        case gnomo:
            printf ("\n 1. Gnomo da floresta ; \n 2. (subraca2)");
            printf ("\nDigite o numero referente a um das sub racas ");
            scanf ("%d",&sub_raca);
            break;
      
      default:
      //pensar em algo para as racas que nao possuem subracas
       
  }
}

/*void escolhaRaca () {
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
           
           atributo[forca] =        atributo[forca] + 10;    
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

}*/