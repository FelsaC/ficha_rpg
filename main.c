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
    teste_de_resistencia[6],
    pericias_valores[16];

int classe_jogador = 0,
    pontos_de_vida;

//Protótipos de função
int calculoDeAtributos (void);
void escolhaClasse(void);
void calculaPontosDeVida(void);
void pericias(int classe, int raca);


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

    char *pericias_nomes[] = {
        "Acrobacia",         //0
        "Arcanismo",         //1
        "Atletismo",         //2
        "Atuacao",           //3
        "Engancao",          //4
        "Furtividade",       //5
        "Historia",          //6
        "intimidação",       //7
        "Lidar com Animais", //8
        "Medicina",          //9
        "Natureza",          //10
        "Percepcao",         //11
        "Persuasao",         //12
        "Presdigitacao",     //13
        "Religiao",          //14
        "Sobrevivencia"      //15
    };
    //"forca", "destreza", "constituicao", "inteligencia", "sabedoria", "carisma"

       pericias_valores[0]  = modificador[1]; //"Acrobacia"        
       pericias_valores[1]  = modificador[3]; //"Arcanismo"                  
       pericias_valores[2]  = modificador[0]; //"Atletismo"              
       pericias_valores[3]  = modificador[5]; //"Atuacao"               
       pericias_valores[4]  = modificador[5]; //"Engancao"           
       pericias_valores[5]  = modificador[1]; //"Furtividade"      
       pericias_valores[6]  = modificador[3]; //"Historia"         
       pericias_valores[7]  = modificador[5]; //"intimidação"      
       pericias_valores[8]  = modificador[4]; //"Lidar com Animais"
       pericias_valores[9]  = modificador[4]; //"Medicina"         
       pericias_valores[10] = modificador[3]; //"Natureza"         
       pericias_valores[11] = modificador[4]; //"Percepcao"        
       pericias_valores[12] = modificador[5]; //"Persuasao"        
       pericias_valores[13] = modificador[1]; //"Presdigitacao"    
       pericias_valores[14] = modificador[3]; //"Religiao"         
       pericias_valores[15] = modificador[4]; //"Sobrevivencia"     
}
