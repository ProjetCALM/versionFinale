/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   headermenu.h
 * Author: prico
 *
 * Created on 22 décembre 2017, 23:19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headerrep.h"

#define NOM ((int)100) //taille max du nom de joueur
#define REP ((int)50) //taille max du répertoire de joueurs

int printMainMenu();
int choiceMainMenu(joueur rep[], int);
int printGameMenu();
int choiceGameMenu(joueur rep[], int);

void morpion(joueur rep[]);
void liarDice(joueur rep[]);

