/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "headermenu.h"

int printMainMenu() {
    int ch1=0;
    system("cls");
    printf("******** Projet CALM *******\n\n1 - Lancer une partie\n2 - Repertoire des joueurs\n3 - Tableau des scores\n4 - Quitter\n\nSelection : ");
    scanf("%d", &ch1);
    return ch1;
}

int choiceMainMenu(joueur rep[], int id) {
    int ch1;
    char enter=0;
    do {
        ch1=printMainMenu();
        switch(ch1) {
            case 1:
                choiceGameMenu(rep, id);
                break;
            
            case 2:
                id=gestionRep(rep, id);
                break;
            
            case 3:
                printf("En développement");
                break;
            
            case 4:
                printf("\nMerci d'avoir joue !\n");
                break;
                
            default:
                printf("\nVeuillez selectionner l'une des options\n");
                break;
        }
    }
    while (ch1 != 4);
    return id;
}

int printGameMenu() {
    int ch2=0;
    system("cls");
    printf("******** Projet CALM *******\n\n1 - Morpion\n2 - Bataille navale\n3 - Blackjack\n4 - Liar's dice\n5 - Retour\n\n");
    printf("Selection : ");
    scanf("%d", &ch2);
    return ch2;
}

int choiceGameMenu(joueur rep[], int id) {
    int ch2=0;
    char enter=0;
    do {
        ch2=printGameMenu();
        switch(ch2) {
            case 1:
                morpion(rep);
                break;
                
            case 2:
                //bataille navale
                break;
                
            case 3:
                //blackjack
                break;
                
            case 4:
                liarDice(rep);
                break;
                
            case 5:
                printf("\nRetour au menu principal...");
                break;
                
            default:
                printf("\nVeuillez selectionner l'une des options\n");
                break;
        }
        fflush(stdin);
        while (enter != '\r' && enter != '\n') { enter = getchar(); }
        enter=0;
    }
    while(ch2 != 5);
    return id;
}