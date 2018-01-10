

#define NOM ((int)100)
#define REP ((int)50)
#define CARTE ((int)10)
#define PLAYER ((int)10)

#include "header_rep.h"
#include <direct.h>


    typedef struct Carte{   
        int valeur;
        int blazon;
    }carte;
    
    typedef struct Main{   
        carte card[CARTE];
    }Main;
    
    typedef struct BlackJack{
        char nom[NOM];
        int id;
        int score;
        Main jeu; 
        int count;
        int done; //done = 0 : Continue
                  //done = 1 : Stop
        int win;  // 0 = init
                  // 1 = gagné
                  // 2 = perdu
       
    }bjack;
    
int intPlayer(bjack tab[], joueur rep[], int);
int aleaCarte(int, int, bjack tab[]);
int aleaCarteBanque(int,int,int);//(tour,joueur,total) 
void affichage(carte);
    
void attente();
void winBlack(int,bjack tab[]); 
 
void jack();
int choixAs();
int Alpha(int, bjack tab[]);  
void Beta(int, bjack tab[],int);
void winBlack(int,bjack tab[]); 
int choixCarte(int, bjack tab[]);
void bank(bjack tab[]);
 
int maxCard(int,bjack tab[]);
void compare(int, int ,bjack tab[]);








