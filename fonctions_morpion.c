//
//  main.c
//  Projet CALM
//  VERSION SANS IA
//
//  Created by Adrien MIGNEROT on 20/12/2017.
//  Copyright © 2017 Projet CALM. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> //permet d'utiliser la fonction locate
#include <time.h>
#include "header_rep.h"

#define NOM ((int)100)
#define REP ((int)50)
#define nblignes 3
#define nbcolonnes 3

typedef struct //Joueur
{
    char nom[NOM];
    int score;
    int pointsTournoi;
    int id;
}player;


void initJoueur(player repmorp[], joueur rep[], int, int);
void initTab(char tableau[nblignes][nbcolonnes]);
int modifTab(char tableau[nblignes][nbcolonnes], player repmorp[], int);
void afficherTab(char tableau[nblignes][nbcolonnes]);
int testGagnant(char tableau[nblignes][nbcolonnes], player repmorp[]);
void tournoi(char tableau[nblignes][nbcolonnes], player repmorp[], int, joueur rep[], int id);
void initPointsTournoi(player repmorp[]);
int testGagnantTournoi(char tableau[nblignes][nbcolonnes], player repmorp[], int, int);
void modifTabTournoi(char tableau[nblignes][nbcolonnes], player repmorp[], int, int, int);
