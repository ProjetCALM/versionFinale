/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   header.h
 * Author: prico
 *
 * Created on 22 décembre 2017, 15:03
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM ((int)100) //taille max du nom de joueur
#define REP ((int)50) //taille max du répertoire de joueurs

typedef struct Joueur
{
    char nom[NOM];
    int score;
}joueur;

int printMenu();
int gestionRep(joueur rep[], int);
void initRep(joueur rep[]);
void addJoueur(joueur rep[], int);
void delJoueur(joueur rep[], int);
void printRep(joueur rep[], int);
void searchJoueur(joueur rep[]);
