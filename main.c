/*
	Projeto: Ficha de Jogador para D&D
	Autores: Alisson dos Santos, Felipe de Sá Correa, Flavio Moreira e Tristan Piamolini Alves
	Data: 03/07/2022
  Versão: 1.0.0
	Atualizado em: --
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

//Macros
//constantes atributos
#define forca          0
#define destreza       1 
#define constituicao   2  
#define inteligencia   3 
#define sabedoria      4 
#define carisma        5

//constantes classes
#define barbaro         0
#define bardo           1 
#define bruxo           2
#define clerigo         3
#define druida          4
#define feiticeiro      5 
#define guerreiro       6 
#define ladino          7
#define mago            8 
#define monge           9
#define paladino        10
#define patrulheiro     11 

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
#define anao             0
#define elfo             1       
#define halfiling        2
#define humano           3
#define draconato        4
#define gnomo            5
#define meio_elfo        6
#define meio_orc         7
#define tielfing         8

//constanstes subracas
#define anao_da_colina     0
#define anao_da_montanha   1 
#define alto_elfo          2  
#define elfo_da_floresta   3 
#define elfo_negro         4
#define pes_leves          5
#define robusto            6
#define gnomo_da_floresta  7
#define gnomo_das_rochas   8

//outras constantes
#define nao_inicializada -1
#define sem_subraca      -1

//Variáveis Globais
//Favor professora nao nos julgar, trabalhar com pointers eh dificil :(
char nome[30];
int atributo[6],
    modificador[6],
    teste_de_resistencia[6],
    pericias_valores[18],
    proficiencias[] = {1, -1, -1, -1, -1, -1, -1},
    tabela_pericias[12][20] = {
        {2,atletismo, adestrar_animais, intimidacao, natureza, percepcao, sobrevivencia, -1}, //Barbaro
  
        {3,atletismo, acrobacia, furtividade, prestidigitacao, arcanismo,historia,investigacao, natureza , religiao, adestrar_animais,
intuicao, medicina, percepcao, sobrevivencia, atuacao, enganacao,intimidacao,persuasao,-1}, //Bardo
  
        {2,arcanismo, enganacao, historia, investigacao, natureza, religiao, -1}, //Bruxo
  
        {2,historia, intuicao, medicina, persuasao, religiao, -1}, //Clérigo
  
        {2,arcanismo, adestrar_animais, intuicao, medicina, percepcao, religiao,sobrevivencia, -1}, //Druida
  
        {2,arcanismo, enganacao, intuicao, intimidacao, persuasao, religiao, -1},//Feiticeiro
  
        {2,acrobacia, adestrar_animais, atletismo, historia, intuicao, intimidacao,percepcao, sobrevivencia, -1}, //Guerreiro
  
        {4,acrobacia, atletismo, atuacao, enganacao, furtividade, intimidacao,intuicao, investigacao, percepcao, persuasao, prestidigitacao, -1}, //Ladino
  
        {2,arcanismo, historia, intuicao, investigacao, medicina, religiao, -1},//Mago
  
        {2,acrobacia, atletismo, furtividade, historia, intuicao, religiao, -1},//monge
  
        {2,atletismo, intuicao, intimidacao, medicina, persuasao, religiao, -1},//Paladino
  
        {2,adestrar_animais, atletismo, furtividade, intuicao, investigacao, natureza,percepcao, sobrevivencia, -1}//Patruleiro   
};

int classe_jogador = nao_inicializada,
    raca_jogador = nao_inicializada,
    sub_raca,
    pontos_de_vida,
    dado_de_vida,
    iniciativa,
    nivel,
    bonus_proficiencia;


float deslocamento;

//vetores de strings
const char *atributos_nomes[] = {
      "forca",       //0 
      "destreza",    //1
      "constituicao",//2
      "inteligencia",//3
      "sabedoria",   //4
      "carisma"      //5    
};

const char *pericias_nomes[] = {
      "Atletismo",       //0 
      "Acrobacia",       //1
      "Furtividade",     //2
      "Prestidigitacao", //3
      "Arcanismo",       //4  
      "Historia",        //5
      "Investigacao",    //6
      "Natureza",        //7
      "Religiao",        //8
      "Adestra animais", //9
      "Intuicao",        //10
      "Medicina",        //11
      "Percepcao",       //12
      "Sobrevivencia",   //13
      "Atuacao",         //14
      "Enganacao",       //15
      "Intimidacao",     //16
      "Persuasao"        //17
};

const char *classes_nomes[] = {
  "Barbaro",           //0  
  "Bardo",             //1 
  "Bruxo",             //2  
  "Clerigo",           //3
  "Druida",            //4
  "Feiticeiro",        //5
  "Guerreiro",         //6
  "Ladino",            //7       
  "Mago",              //8
  "Monge",             //9
  "Paladino",          //10
  "Patrulheiro",       //11
};

const char *racas_nomes[] = {
    "Anao",            //0 
    "Elfo",            //1
    "Halfiling",       //2
    "Humano",          //3
    "Draconato",       //4
    "Gnomo",           //5
    "Meio-elfo",       //6  
    "Meio-or",         //7
    "Tielfing"         //8 
}; 

const char *subracas_nomes[] = {
    "Anao da colina",     //0
    "Anao da montanha",   //1 
    "Alto elfo",          //2  
    "Elfo da floresta",   //3 
    "Elfo negro",         //4
    "Pes leves",          //5
    "Robusto",            //6
    "Gnomo da floresta",  //7
    "Gnomo das rochas"    //8
};

//Protótipos de função
void limpaBuffer();

void inserirNome();

int  calculoDeAtributos();
void modificacaoAtributos();

void initValoresIniciais();
void initPericias();

bool validarProficienciaClasse(int proficiencia, int tamanho_tabela);
bool proficienciaEscolhidaClasse(int proficiencia);
bool proficienciaEscolhidaRaca(int proficiencia);
bool validarProficienciaRaca(int proficiencia);
void aplicarProficiencias();

void escolhaNivel();
void escolhaRaca();
void escolhaSubRaca();
void validaSubRaca();
void escolhaClasse();

void calculoPontosDeVida();
void calculoTesteDeResistencia();
void calculoProficiencias();
void calculoDeslocamento();
void calculoBonusProficiencia();

void printar_pericias_classe(int tabela_pericias[12][20]);
void print_proficiencias(int proficiencias[7]);
void printar_pericias_raca();
void printAtributos();
void printPericias();
void printTesteDeResistencia();
void printModificadoresAtributos();
void printTelaInicial();
void printFicha();
void printLinhaHorizontal(int numero_de_caracteres);
void printSubRacas();

void limparTela();
void congelaTela();

//Função Principal
int main () {
    srand(time(NULL));                 //Define a "semente" para gerar um número aleatório
    setlocale(LC_ALL, "Portuguese");   //Permite o uso de acentos e "ç" 
  
    printTelaInicial();                //Mostra a tela inicial do programa
    initValoresIniciais();             //Calcula os valores iniciais do programa
    inserirNome();                     //Recebe o nome do personagem
    escolhaNivel();                    //Recebe o nível do personagem
    calculoBonusProficiencia();        //Calcula o bônus de proficiência função do nivel do personagem
    escolhaRaca();                     //Recebe a Raça do personagem
    escolhaSubRaca();                  //Recebe a Sub-raça do personagem   
    calculoDeslocamento();             //Calcula o deslocamento do personagem função das raças e sub-raças 
    modificacaoAtributos();            //Modifica os valores dos atributos em função das raças e sub-raças
    escolhaClasse();                   //Recebe a classe do personagem 
    calculoProficiencias();            //Calcula as proficiencias   
    aplicarProficiencias();            //Aplica as proficiencias nas pericias escolhidas
    calculoPontosDeVida();             //Calcula pontos de vida e dados de vida em função da classe
    calculoTesteDeResistencia();       //Calcula teste de resistência em função da classe
    printFicha();               
       
  return 0;  
} //end main

//-------------- funções de calculo --------------------//
int calculoDeAtributos() {
    int habs[4];     
    int hab_t = 0; 
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

void calculoPontosDeVida() {
  switch (classe_jogador) {
       case barbaro:
            pontos_de_vida = 12 + modificador[constituicao];                    
             dado_de_vida = 12;         
            break;

       case bardo:
       case bruxo:
       case clerigo:
       case druida:
       case ladino:
       case monge:
            pontos_de_vida = 8 + modificador[constituicao];
            dado_de_vida = 8;
            break;
           
       case feiticeiro:
       case mago:
            pontos_de_vida = 6 + modificador[constituicao];
            dado_de_vida = 6;
            break;
                
       case guerreiro:
       case paladino:
       case patrulheiro:
            pontos_de_vida = 10 + modificador[constituicao];
            dado_de_vida = 10;
            break;
  }
} 

void calculoTesteDeResistencia() {
  switch (classe_jogador) {
    case bruxo:
    case clerigo:
    case paladino:
      teste_de_resistencia[sabedoria] += bonus_proficiencia;
      teste_de_resistencia[carisma] +=  bonus_proficiencia;
      break;
  
    case barbaro:
    case guerreiro:
      teste_de_resistencia[forca] += bonus_proficiencia;
      teste_de_resistencia[constituicao] += bonus_proficiencia; 
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

void calculoDeslocamento() {
    if(sub_raca == elfo_da_floresta) {
      deslocamento = 10.5;
    }
    else if((raca_jogador == gnomo || raca_jogador == halfiling) || (raca_jogador == anao)){
      deslocamento = 7.5;
    }
    else {
      deslocamento = 9.0;
    }
}

void calculoBonusProficiencia() {
    switch(nivel) {
      case 1:
      case 2:
      case 3:
      case 4:
        bonus_proficiencia = 2;
        break;
      
      case 5:
      case 6:
      case 7:
      case 8:
        bonus_proficiencia = 3;
        break;
      
      case 9:
      case 10:
      case 11:
      case 12:
        bonus_proficiencia = 4; 
        break;

      case 13:
      case 14:
      case 15:
      case 16:
        bonus_proficiencia = 5;
        break;

      case 17:
      case 18:
      case 19:
      case 20:
        bonus_proficiencia = 6;
        break;
    }
}

void modificacaoAtributos() {
    switch(raca_jogador){
        case anao:
            atributo[constituicao] += 2; //adiciona +2 de constiuicao
            break;

        case elfo:
            atributo[destreza] += 2;
            break;
          
        case  halfiling:
            atributo[destreza] += 2; 
            break;
          
        case humano:
            for(int i = 0; i < 6; i++) {
                atributo[i] += 1; //Para humano todos os atributos recebem +1
            }
            break;

        case draconato:
            atributo[forca] += 2;       
            atributo[carisma] += 1; 
            break;

        case gnomo:
            atributo[inteligencia] += 2;
            break;
            
        case meio_elfo:
            atributo[carisma] += 2; //adiciona +2 de carisma      
            //+1 em duas habilidades que o jogador escolher
            //deslocamento = 9.0;
            int atributoModificado;
            
            do {
              printf("\n\n==> PARTICULARIDADE do Meio-Elfo\n\n");
              printf("Escolha um atributo para ganhar +1\n\n");
              for(int i = 1; i < 7;i++) {
                printf("\t%i.%s\n", i, atributos_nomes[i-1]);
              }
              printf("\nEscolha: ");
              scanf("%i", &atributoModificado);
              limparTela();
            } while(atributoModificado < 1 || atributoModificado > 6);

            atributo[atributoModificado-1]++;
            
            break;

        case meio_orc:
            atributo[forca] += 2; //adiciona +2 de forca      
            atributo[constituicao] += 1; //adiciona +1 de constituicao 
            //deslocamento = 9.0;
            break;

        case tielfing:
            atributo[carisma] += 2; //adiciona +2 de carisma      
            atributo[inteligencia] += 1; //adiciona +1 de inteligencia
            //deslocamento = 9.0;
            break;
    }  

    if(sub_raca != sem_subraca) {
        switch(sub_raca) {
            case anao_da_colina:    
                atributo[sabedoria] += 1;
                break;
          
            case anao_da_montanha:
                atributo[carisma] += 2;
                break;

            case alto_elfo:
                atributo[inteligencia] += 1;
                break;

            case elfo_da_floresta:
                atributo[sabedoria] += 1;
                break;

            case elfo_negro:
                atributo[carisma] += 1;
                break;

            case pes_leves:
                atributo[carisma] += 1;
                break;
            
            case robusto:
                atributo[constituicao] += 1;
                break;

            case gnomo_da_floresta:
                atributo[destreza] += 1;
                break;

            case gnomo_das_rochas:
                atributo[constituicao] += 1;
                break;
        }        
    }  
}
//-------------- fim calculo --------------------//


//-------------- funções de inicialização --------------------//
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
//-------------- fim inicialização --------------------//


//-------------- funções de proficiencias --------------------//
void calculoProficiencias() {
  //reseta o array de proficiencias
  proficiencias[0] = 1;
  for(int i = 1; i < 8; i++){
    proficiencias[i] = -1;
  }

  //Acha o tamanho do array de pericias que podem receber proficiencia de cada classe
  int tamanho_tabela_classe = 0;

  for(int i = 1; i < 19; i ++){
    if(tabela_pericias[classe_jogador][i] == -1) {break;}
    else {tamanho_tabela_classe++;}
  }

  // Verifica escolha de pericias disponiveis para ganhar proficiencia em classes especificas
  int num_pericias_raca; 
  
  switch(raca_jogador){
    case humano:
      num_pericias_raca = 1;
      break;
    case meio_elfo:
      num_pericias_raca = 2;
      break;
    default:
      num_pericias_raca = 0;
      break;
  };

  //Menu de proficiencias para classes
  while(tabela_pericias[classe_jogador][0] > 0) {
    int escolha;
    bool proficiencia_aceita;
    do {
      printf("\n\n==> PROFICIENCIA de Classe\n\n");
      print_proficiencias(proficiencias);
      
      printf("Sua classe é %s, isso lhe da direito ha:\n", classes_nomes[classe_jogador]);
      printf("\n\t%i pericias do grupo atual\n\n", tabela_pericias[classe_jogador][0]);
      
      printar_pericias_classe(tabela_pericias);
      
      printf("Escolha uma de cada vez, por favor.\n\n");
      printf("Sua escolha: ");
      scanf("%i", &escolha);
      
      limparTela();
      proficiencia_aceita = validarProficienciaClasse(escolha, tamanho_tabela_classe);
    } while (!proficiencia_aceita);
    tabela_pericias[classe_jogador][0]--;   
  }

  // Menu de proficiencias extras para raca, somente nas duas racas que necessitam disso
  while(num_pericias_raca > 0) {
    int escolha;
    bool proficiencia_aceita_raca = false;
    do {
      printf("\n\n==> PROFICIENCIA de Raca\n\n");
      print_proficiencias(proficiencias);
      printf("Sua raca é %s, isso lhe da direito ha:\n", racas_nomes[raca_jogador]);
      printf("\n\t%i pericias do grupo atual\n\n", num_pericias_raca);
      
      printar_pericias_raca(tabela_pericias);
      
      printf("Escolha uma de cada vez, por favor.\n\n");
      printf("Sua escolha: ");
      scanf("%i", &escolha);
      printf("%i\n", escolha);
      limparTela();
      proficiencia_aceita_raca = validarProficienciaRaca(escolha);
    } while (!proficiencia_aceita_raca);
    num_pericias_raca--;   
  }
  
  print_proficiencias(proficiencias);
  
}

//Valida se a pericia escolhida esta correta ou se ja nao foi escolhida no menu de classe
bool validarProficienciaClasse(int proficiencia, int tamanho) {
  if(proficiencia < 1 || proficiencia > tamanho){
    printf("Proficiencia fora da lista!!!");
    return false;
  } else if(proficienciaEscolhidaClasse(proficiencia)){
    printf("Proficiencia ja escolhida!");
    return false;
  } else {
    proficiencias[proficiencias[0]] = tabela_pericias[classe_jogador][proficiencia];
    proficiencias[0]++;
    return true;
  }
}

//Valida se a pericia escolhida esta correta ou se ja nao foi escolhida no menu de raca
bool validarProficienciaRaca(int proficiencia) {
  if(proficiencia < 1 || proficiencia > 18){
    printf("Proficiencia fora da lista!!!");
    return false;
  } else if(proficienciaEscolhidaRaca(proficiencia)){
    printf("Proficiencia ja escolhida!");
    return false;
  } else {
    proficiencias[proficiencias[0]] = proficiencia - 1;
    proficiencias[0]++;
    return true;
  }
}

void printar_pericias_raca() {
    for(int i = 0; i < 18; i++){
     printf("%i.%s\n", i+1,pericias_nomes[i]);
    }
  printf("\n");
}

//Imprime as pericias ja escolhidas para receber proficiencia no menu de classe
bool proficienciaEscolhidaClasse(int proficiencia){
  bool ok = false;
  for(int i = 1; i < 7;i++){
    if(tabela_pericias[classe_jogador][proficiencia] == proficiencias[i]){
      ok = true;
      break;
      printf("proficiencia: %i\n", proficiencia);
      printf("proficiencias[0]: %i\n", proficiencias[0]);
    } 
  }
  return ok;
}

//Imprime as pericias ja escolhidas para receber proficiencia no menu de raca
bool proficienciaEscolhidaRaca(int proficiencia) {
  bool ok = false;
  for(int i = 1; i < 7;i++){
    if(proficiencia - 1 == proficiencias[i]){
      ok = true;
      break;
      printf("proficiencia: %i\n", proficiencia);
      printf("proficiencias[0]: %i\n", proficiencias[0]);
    } 
  }
  return ok;
}

void print_proficiencias(int proficiencias[7]) {
  printf("Proficiencias já escolhidas\n\n");
  if(proficiencias[0] == 1) printf("\t----Vazio----\n\n");
  for(int i = 1; i < 7; i++){
      if(proficiencias[i] == -1) break;
      printf("\t%s\n", pericias_nomes[proficiencias[i]]);
  }
  printf("\n");
}

void printar_pericias_classe(int tabela_pericias[12][20]) {
    for(int i = 1; i < 19; i++){
      if(tabela_pericias[classe_jogador][i] != -1) {
        printf("%i.%s\n",i, pericias_nomes[tabela_pericias[classe_jogador][i]]);
      } else {
        break;
      }
    }
  printf("\n");
}

// Aplica o bonus de proficiencia as pericias escolhidas
void aplicarProficiencias() {
  for(int i = 1; i < 7; i++){
    pericias_valores[proficiencias[i]] += bonus_proficiencia; 
  }
}
// ---------------fim das proficiencias-----------------//


//-------------- funções de escolha --------------------//
void escolhaRaca() {
  
  while (raca_jogador == nao_inicializada || (raca_jogador < 0 || raca_jogador > 8)){
      printf("\n\n==> RACAS de D&D\n");
      printf ("\n 0. anao\n 1. elfo \n 2. halfling \n 3. humano \n 4. draconato \n");
      printf (" 5. gnomo \n 6. meio-elfo \n 7. meio-orc \n 8. tiefling \n");
      printf ("\nDigite o numero referente a sua raca: ");
      scanf ("%d",&raca_jogador);
      //system("cls");
      if(raca_jogador < 0 || raca_jogador > 8) {
        printf("\nOpcao invalida! Pressione enter para tentar novamente");
        limpaBuffer();
        getchar(); //o terminal congela ate que uma tecla seja pressionda
        //system("read");
      }
        //system("cls"); //limpa a tela. No linux system("clear");
      limparTela();
   }
  
}

void escolhaSubRaca() {
    printf("\n\n==> Sub-raças para %s\n", racas_nomes[raca_jogador]);
    switch(raca_jogador){
        case anao:
            printf ("\n 0. Anão da colina \n 1. Anão da montanha\n");
            printf ("\nDigite o numero referente a uma das sub-raças: ");
            scanf ("%d", &sub_raca);
            validaSubRaca();
            break;
      
        case elfo:
            printf ("\n 2. Alto Elfo\n 3. Elfo da Floresta\n 4. Elfo Negro\n");
            printf ("\nDigite o numero referente a uma das sub-raças: ");
            scanf ("%d", &sub_raca);
            validaSubRaca();
            break;
      
        case halfiling:
            printf ("\n 5. Pés leves \n 6. Robusto\n");
            printf ("\nDigite o numero referente a uma das sub-raças: ");
            scanf ("%d", &sub_raca);
            validaSubRaca();
            break;
      
        case gnomo:
            printf ("\n 7. Gnomo da floresta\n 8. Gnomo das rochas\n");
            printf ("\nDigite o numero referente a uma das sub racas: ");
            scanf ("%d", &sub_raca);
            validaSubRaca();
            break;
      
        default:
            sub_raca = sem_subraca;  
            break;
  }
  
  limparTela();
}

//valida se o valor da sub-raca é correto 
void validaSubRaca() {
  int min,
      max;
  
  switch (raca_jogador){
    case anao:
      min = 0;
      max = 1;
      break;
    
    case elfo:
      min = 2;
      max = 4;
      break;
    
    case halfiling:
      min = 5;
      max = 6;
      break;
    
    case gnomo:
      min = 7;
      max = 8;
      break;

    default:
      return;
    }
  
  if(sub_raca < min || sub_raca > max){
    printf("\nOpção escolhida incorreta, pressione enter para tentar novamente. ");
    limpaBuffer();
    getchar();
    limparTela();
    escolhaSubRaca();
  }
  else {
        return;
  }    
}

void escolhaClasse() {
    while (classe_jogador == nao_inicializada || (classe_jogador < 0 || classe_jogador > 11)) {
        printf("\n\n==> CLASSES de D&D\n");
        printf("\n0.Barbaro \n1.Bardo \n2.Bruxo \n3.Clerigo \n4.Druida \n5.Feiticeiro");
        printf("\n6.Guerreiro \n7.Ladino \n8.Mago \n9.Monge \n10.Paladio \n11.Patrulheito");
        printf("\n\nDigite o numero referente a sua classe: ");
        scanf("%d", &classe_jogador);
        
        if(classe_jogador < 0 || classe_jogador > 11) {
          printf("\nOpcao invalida! Pressione enter para tentar novamente");
          limpaBuffer(); //limpa buffer do teclado. Necessaria para que o getchar() funcione corretamente.
          getchar(); //o terminal congela ate que uma tecla seja pressionda.
        }
        //system("cls"); //limpa a tela. No linux system("clear");
      limparTela();
      } 
    } 

void escolhaNivel() {
  do {  
    printf("Selecione o nivel do seu personagem de 1-20: ");
    scanf("%d", &nivel);

    if (nivel < 1 || nivel > 20){
        printf("\nOpcao invalida! Pressione enter para tentar novamente");
        limpaBuffer(); //limpa buffer do teclado. Necessaria para que o getchar() funcione corretamente.
        getchar(); //o terminal congela ate que uma tecla seja pressionda
        limparTela();    
    }
  } while (nivel < 1 || nivel > 20);   
}
//-------------- fim escolha --------------------//


//------------------------prints----------------------------------//
void printLinhaHorizontal(int numero_de_caracteres){
  for(int i = 0; i < numero_de_caracteres; i++){
    printf("* ");
  }
  printf("\n");
}

void printTelaInicial(){
  limparTela();
  printf(".,__  ,..----------------..,___ \n");
  printf("    \\/   FICHA SIMPLIFICADA    \\ \n");
  printf("    |   DUNGEONS & DRAGONS      \\ \n");
  printf("    |                            \\ \n");
  printf("    |           por               \\ \n");
  printf("    |           Alisson            \\ \n");
  printf("    |            Flavio             \\ \n");
  printf("    |              Felipe            \\ \n");
  printf("    |               Tristan           \\ \n");
  printf(".,\\ | /.....-----------------...._____,\\ \n");
  printf("===\\_/=================================/ \n");
  printf("===\\__/===============================/ \n");
  printf("Isso é um livro... eu juro.");
  printf("\n\n");
  printf("\nPara iniciar o programa pressione enter...");
  getchar();
  limparTela();

}

void printAtributos(){
  for(int i = 0; i < 6;i++) {
    printf("%i.  %-13s: %i\n", i+1, atributos_nomes[i], atributo[i]);
  }
}

void printModificadoresAtributos(){
   for(int i = 0; i < 6;i++) {
    printf("%i.  Modificador de %-13s: %+i\n", i+1, atributos_nomes[i], modificador[i]);
  }
} 

void printPericias() {
  for(int i = 0; i < 18;i++) {
    if(i < 9)
      printf("%i.  %-19s: %+i\n", i+1, pericias_nomes[i], pericias_valores[i]);
    
    else
      printf("%i. %-19s: %+i\n", i+1, pericias_nomes[i], pericias_valores[i]);
  }
}

void printTesteDeResistencia() {
  for(int i = 0; i < 6;i++) {
    printf("%i.  Teste de resistência para %-17s: %+i\n", i+1, atributos_nomes[i], teste_de_resistencia[i]);
  }
}

void printSubRacas(){
  if(sub_raca == sem_subraca){
    printf("Subraça: não possui\n");
  }
  else{
    printf("Subraça: %s\n", subracas_nomes[sub_raca]);
  }
}

void printFicha(){
  limparTela();
  printf("\n\n==> FICHA final\n\n");
  //----------prints da parte superior da tela------------//
  printLinhaHorizontal(38);
  printf("NOME: %s", nome);
  printf("Raça: %-14s", racas_nomes[raca_jogador]);
  printSubRacas();
  printf("Pontos de vida: %-4d", pontos_de_vida);
  printf("Deslocamento: %-10.1f", deslocamento);
  printf("Classe: %s\n", classes_nomes[classe_jogador]);
  printf("Dado de vida: d%-5d", dado_de_vida);
  printf("Iniciativa: %-12d", iniciativa);
  printf("Bônus de proficiência: %d\n", bonus_proficiencia);
  printLinhaHorizontal(38);
  printf("\n");
  //---------- fim prints da parte superior da tela------------//
  
  printf("==> Atributos\n");
  printAtributos();
  printf("\n\n");

  printf("==> Modificadores de Atributos\n");
  printModificadoresAtributos();
  printf("\n\n");

  printf("==> Teste de Resistência\n");
  printTesteDeResistencia();
  printf("\n\n");
  
  printf("==> Pericias\n");
  printPericias();
  printf("\n\n");

  //tem que printar o teste de resistência.
}
 //--------------------fim-prints---------------------------------//


//--------------------Outras funções---------------------------------//
void limparTela(){
  system("clear"); //para Linux
  //system("cls"); //para Windows
}

void limpaBuffer(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void inserirNome() {
  printf("Qual será o nome do personagem? ");
  fgets(nome,30,stdin);
  limparTela();
}
//Parabéns você chegou na linha mil!!!
