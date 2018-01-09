/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   header.h
 * Author: prico
 *
 * Created on 20 décembre 2017, 16:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header_rep.h"

#define NOM ((int)100) //taille max du nom de joueur
#define REP ((int)50) //taille max du répertoire de joueurs

typedef struct Player
{   //crée une structure similaire à Joueur, en ajoutant un tableau prenant en compte les 5 dés, ainsi qu'une valeur pour le pari
    char nom[NOM];
    int score;
    int dicenb;
    int dice[5];
    int betnb; //utilisé pendant la partie, pari sur le nombre de dés
    int betface; //utilisé pendant la partie, pari sur la face
    int out; //utilisé pendant la partie, si un joueur est éliminé
    int human; //si =0, joueur humain. Si =1, AI.
}player;



void letTheGameBegin(player table[]);
void turn(player table[], int);
void initTable(player table[], joueur rep[], int, int);
void initAI(player table[], int, int);
int turnAI(player table[], int, int, int);
void initTable2(player table[], int);
int countFace(player table[], int, int);
int totalDice(player table[], int);
int checkEnd(player table[], int);
player rollTheDice(player);
void printTheDice(player);