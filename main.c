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

//constantes classes
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
//Variáveis Globais
int atributo[6],
    modificador[6],
    teste_de_resistencia[6],
    pericias_valores[18];

int classe_jogador = 0,
    pontos_de_vida;

//Protótipos de função
int calculoDeAtributos (void);
void escolhaClasse(void);
void calculaPontosDeVida(void);
void pericias(int classe, int raca);
void initPericias();

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
   initPericias();
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

void pericias(int classe, int raca) {
    //tabelas de pericias primeiro item 
    int proficiencias[] = {};
    char *Barbaro[] = {"Lidar com Animais", "Atletismo","intimidação", };  
    /*
    Barbaro(2 entre Adestrar Animais, Atletismo, Intimidação, Natureza, Percepcao, e Sobrevivencia)
    Bardo(3 quaisquer)
    Bruxo(2 entre Arcanismo, Enganacao, historia, Investigacao, Natureza e Religiao) 
    Clérigo(2 de historia, Intuicao, medicina, persuasao, religiao)
    Druida( 2 dentre arcanismo, adestrar, animais, intuicao, medicina, percepcao, religiao, sobrevivencia)
    Feiticeiro( 2 entrea arcanismo, enganacao, intuicao, intimidacao, persuacao, religiao )
    Guerreiro(2 entre acrobacia, adestrar animais, atletismo, historia, intuicao, intimidacao, percepcao, sobrevivencia)
    Ladino (4 entre acrobacia, atletismo, atuacao, enganacao, furtividade, intimidacao, intuicao, investigacao, percepcao, persuasao, presdigitacao)
    Mago(2 arcanismo, historia, intuicao, investigacao, madicina, religiao)
    Monge(2 entre acrobacia, atletismo, furtividade, historia, intuicao, religiao)
    Paladino(2 atletismo, intuicao, intimidacao, medicina, persuasao, religiao)
    Patrulheiro(2 adestrar animais, atletismo, Furtividade, Intuicao, Investigacao, Natureza, percepcao e sobrevivencia)
    */
    /*
    Anao
    Elfo
    Halfling
    Humano( 1 pericia a escolha )
    Draconato
    Gnomo
    Meio-Elfo(2 pericia a escolha)
    Meio-Orc
    Tiefling
    */

    switch (classe) {
        
    }

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