/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header_menu.h"

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
                tabScores(rep, id);
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
                morpion(rep, id);
                break;
                
            case 2:
                bataillenavale(rep, id);
                break;
                
            case 3:
                jack(rep);
                break;
                
            case 4:
                liarDice(rep, id);
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

void tabScores(joueur rep[], int id) {
    joueur classement[REP];
    int i=0, j=0, k=0, l=0, temp=0, enter=0;
    char tempo[NOM];
    memset(tempo, 0, NOM);
    for(l=0; l < REP; l++) {
        classement[l]=rep[l];
    }
    for (j=0 ; j < REP ; j++) {
        for(i=j+1 ; i < REP ; i++) {
            if (classement[i].score > classement[j].score) 
            {
                temp=classement[i].score;
                strcpy(tempo, classement[i].nom);
                classement[i].score=classement[j].score;
                strcpy(classement[i].nom, classement[j].nom);
                classement[j].score=temp;
                strcpy(classement[j].nom, tempo);
            }
        }
    }
    system("cls");
    locate(40, 0);
    printf("**** Tableau des scores ****");
    for (k=0 ; k < id ; k++) {
        locate(32, 2*k+3);
        printf("#%d %s", k+1, classement[k].nom);
        locate(71, 2*k+3);
        printf("%d", classement[k].score);
    }
    locate(38, 2*id+5);
    printf("Appuyer sur [Enter] pour continuer.");
    fflush(stdin);
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    enter=0;
}