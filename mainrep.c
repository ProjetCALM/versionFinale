/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: prico
 *
 * Created on 22 décembre 2017, 15:02
 */

#include <stdio.h>
#include <stdlib.h>
#include "headerrep.h"

/*
 * 
 */
int gestionRep(joueur rep[REP], int id) {
    int id=1; //tracks le nombre de joueurs
    int p=0; //tracks le nombre de participants
    int choix=0;
    int check=0;
    joueur rep[REP];
    initRep(rep);
    do {
        choix=printMenu();
        system("clr");
        switch(choix) {
            case 1:
                addJoueur(rep, id);
                id++;
                printf("\n\n");
                break;
                
            case 2:
                delJoueur(rep, id);
                id--;
                printf("\n\n");
                break;
                
            case 3:
                searchJoueur(rep);
                printf("\n\n");
                break;
                
            case 4:
                printRep(rep, id);
                printf("\n\n");
                break;
                
            case 5:
                check=1;
                printf("Fermeture en cours...");
                system("cls");
                break;
        }
    }
    while(check == 0);
    return (EXIT_SUCCESS);
}

