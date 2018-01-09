#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "header_rep.h"


#define LIN ((int)10)
#define COL ((int)10)
#define NOM ((int)100)
/*joueurs*/

typedef struct Player{
    char nom1[NOM];
    char nom2[NOM];
    int score1;
    int score2;
    int compteurj1;
    int compteurj2;
    int id1;
    int id2;
}player;

/*initialisation*/
player initPlayer(player, joueur rep[], int);
/*placement des bateaux de j1*/
void affiche1(int tab1[LIN][COL]);
void placement1(int tab1[LIN][COL], player J);
void bateaux1(int tab1[LIN][COL]);
/*placement des bateaux de j2*/
void affiche2(int tab2[LIN][COL]);
void placement2(int tab2[LIN][COL], player J);
void bateaux2(int tab2[LIN][COL]);
/*début de partie*/
/*attaque de j1*/
void afgrille2(int grille2[LIN][COL], player J);
player attaque1(int grille1[LIN][COL], int tab1[LIN][COL], player J);
void attgrille2(int grille2[LIN][COL], player J);
/*attaque de j2*/
void afgrille1(int grille1[LIN][COL], player J);
player attaque2(int grille1[LIN][COL], int tab1[LIN][COL], player J);
void attgrille1(int grille2[LIN][COL], player J);
/*attaques générales*/
void boucleatt(int grille1[LIN][COL], int tab1[LIN][COL], int grille2[LIN][COL], int tab2[LIN][COL], int, player J, joueur rep[]);
/*en plus*/
int continuer(int);
void rappel();