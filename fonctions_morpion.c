//
//  main.c
//  Projet CALM
//  VERSION SANS IA
//
//  Created by Adrien MIGNEROT on 20/12/2017.
//  Copyright © 2017 Projet CALM. All rights reserved.
//

#include "header_morpion.h"

char tableau[nblignes][nbcolonnes];
int i, j, choix, nombreJoueurs, niveau = 0;

void morpion(joueur rep[], int id) {
    player repmorp[REP];
    int p=0, quit=0;
    printf("*** Bienvenue sur le jeu des morpions ! ***\n\n");
    
    while(i != 1){
        printf("*********\n");
        printf("1 - Mode classique (2 players)\n");
        printf("2 - Mode tournoi\n");
        printf("3 - Quitter\n");
        printf("*********\n");
        printf("Que souhaitez-vous faire ?\n");
        scanf("%d", &choix);
        switch(choix){
            case 1 :
                initJoueur(repmorp, rep, 2, id);
                initTab(tableau); //initialise le jeu avec des cases vides
                afficherTab(tableau); //affiche le jeu (vide)
                do
                {
                    quit=modifTab(tableau, repmorp, i);//enregistre la saisie du player (1 si i est paire, sinon 2).
                    i++;
                }
                while(!testGagnant(tableau, repmorp) && quit == 0);//test si 3 mêmes cractères sont alignés, si oui, ajoute des points au score du gagnant et le félicite.
                for(j=0; j<2; j++) {
                    rep[repmorp[j].id].score=repmorp[j].score;
                }
                break;
            case 2 :
                printf("Saisir le nombre de players (4 ou 8) :\n");
                scanf("%d", &nombreJoueurs);
                while(nombreJoueurs != 4 && nombreJoueurs != 8){
                    printf("Desole, cette configuration n est pas disponible !\nVous pouvez faire un tournoi de 4 ou 8 players.\n");
                    printf("Saisir le nombre de players :\n");
                    scanf("%d", &nombreJoueurs);
                }
                tournoi(tableau, repmorp, nombreJoueurs, rep, id);
                for(j=0; j<nombreJoueurs; j++) {
                    rep[repmorp[j].id].score=repmorp[j].score;
                }
                break;
            case 3 :
                i = 1;
                break;
            default:
                printf("Votre choix n est pas dans la liste\n");
                break;
        }
    }
}

void initJoueur(player repmorp[], joueur rep[], int part, int id) {
    int temp=0, i=0, j=0;
    printf("Choisir les participants :\n");
    printRep(rep, id);
    printf("\nSelection (entrer l'ID du joueur)\n");
    for(i=0; i<part; i++) {
        printf("Joueur %d : ", i+1);
        scanf("%d", &temp);
        repmorp[i].score=rep[temp].score;
        strcpy(repmorp[i].nom, rep[temp].nom);
        repmorp[i].pointsTournoi=0;
        repmorp[i].id=temp;
    }
}


void initTab(char tableau[nblignes][nbcolonnes])
{
    int i = 0;
    int j = 0;
    for(i=0;i<nblignes;i++)
    {
        for(j=0;j<nbcolonnes;j++)
        {
            tableau[i][j] = ' ' ;
        }
        
    }
    
}

int modifTab(char tableau[nblignes][nbcolonnes], player repmorp[], int i) {
    int quit=0;
    int colonne;
    int ligne;
    if(i%2 == 0){
    printf("Au tour de %s :\n\n", repmorp[0].nom);
        printf("Choisir une ligne :\n");
    scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
    scanf("%d",&colonne);
    system("cls");
    while(tableau [ligne -1][colonne -1] != ' '){
        afficherTab(tableau);
        printf("Cette case est deja prise !\n");
        printf("Choisir une ligne :\n");
        scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
        scanf("%d",&colonne);
        if (ligne == 0 || colonne == 0) {
            quit=1;
        }
    }
        tableau [ligne -1][colonne -1] ='X';
    afficherTab(tableau);
    } else {
    printf("Au tour de %s :\n\n", repmorp[1].nom);
        printf("Choisir une ligne :\n");
    scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
    scanf("%d",&colonne);
    if (ligne == 0 || colonne == 0) {
            quit=1;
        }
    system("cls");
    while(tableau [ligne -1][colonne -1] != ' '){
        afficherTab(tableau);
        printf("Cette case est deja prise !\n");
        printf("Choisir une ligne :\n");
        scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
        scanf("%d",&colonne);
    }
        tableau [ligne -1][colonne -1] ='O';
    afficherTab(tableau);
    }
    return quit;
}

void afficherTab(char tableau[nblignes][nbcolonnes])
{
    printf("\n\n\n");
    printf("\t+-----------+\n");
    printf("\t| %c | %c | %c |\n", tableau[0][0], tableau[0][1], tableau[0][2]);
    printf("\t+-----------+\n");
    printf("\t| %c | %c | %c |\n", tableau[1][0], tableau[1][1], tableau[1][2]);
    printf("\t+-----------+\n");
    printf("\t| %c | %c | %c |\n", tableau[2][0], tableau[2][1], tableau[2][2]);
    printf("\t+-----------+\n");
    printf("\n\n\n");
    
    
}

int testGagnant(char tableau[nblignes][nbcolonnes], player repmorp[])
{
    int i, j, somme = 0, caseVide = 0;
    for (i=0; i<nblignes; i++, somme=0)
    {
        for (j=0; j<nbcolonnes; j++){
            somme+=tableau[i][j];
        }
        if(somme==264)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repmorp[0].nom);
            repmorp[0].score+=100;
            return 1;
        }
        if(somme==237)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repmorp[1].nom);
            repmorp[1].score+=100;
            return 1;
        }
    }
    for(j=0 ; j<nbcolonnes ; j++, somme=0)
    {
        for(i=0 ; i<nblignes ; i++){
            somme+=tableau[i][j] ;
        }
        if(somme==264)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repmorp[0].nom);
            repmorp[0].score+=100;
            return 1;
        }
        if(somme==237)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repmorp[1].nom);
            repmorp[1].score+=100;
            return 1;
        }
    }
    if((tableau[0][0] + tableau[1][1] + tableau[2][2] == 264) ||
       (tableau[0][2] + tableau[1][1] + tableau[2][0] == 264))
    {
        printf("Felicitations %s, tu remporte la partie !\n", repmorp[0].nom);
        repmorp[0].score+=100;
        return 1;
    }
    if((tableau[0][0] + tableau[1][1] + tableau[2][2] == 237) ||
       (tableau[0][2] + tableau[1][1] + tableau[2][0] == 237))
    {
        printf("Felicitations %s, tu remporte la partie !\n", repmorp[1].nom);
        repmorp[1].score+=100;
        return 1;
    }
    /* Test si le tableau est plein :*/
    for(i=0; i<nblignes; i++, caseVide = 0){
        for(j=0; j<nbcolonnes; j++) {
            if(tableau[i][j] == ' '){
                return 0;
            }
        }
    }
                printf("Aucun des 2 players n'a gagne \n");
                return 2;
}

int testGagnantTournoi(char tableau[nblignes][nbcolonnes], player repmorp[], int playerA, int playerB)
{
    int i, j, somme = 0, caseVide = 0;
    char car;
    for (i=0; i<nblignes; i++, somme=0)
    {
        for (j=0; j<nbcolonnes; j++){
            somme+=tableau[i][j];
        }
        if(somme==264)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repmorp[playerA].nom);
            repmorp[playerA].pointsTournoi+=1;
            printf("\n* Saisir un caractere pour continuer. *\n");
            scanf(" %c", &car);
            system("cls");
            return 1;
        }
        if(somme==237)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repmorp[playerB].nom);
            repmorp[playerB].pointsTournoi+=1;
            printf("\n* Saisir un caractere pour continuer. *\n");
            scanf(" %c", &car);
            system("cls");
            return 1;
        }
    }
    for(j=0 ; j<nbcolonnes ; j++, somme=0)
    {
        for(i=0 ; i<nblignes ; i++){
            somme+=tableau[i][j] ;
        }
        if(somme==264)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repmorp[playerA].nom);
            repmorp[playerA].pointsTournoi+=1;
            printf("\n* Saisir un caractere pour continuer. *\n");
            scanf(" %c", &car);
            system("cls");
            return 1;
        }
        if(somme==237)
        {
            printf("Felicitations %s, tu remporte la partie !\n", repmorp[playerB].nom);
            repmorp[playerB].pointsTournoi+=1;
            printf("\n* Saisir un caractere pour continuer. *\n");
            scanf(" %c", &car);
            system("cls");
            return 1;
        }
    }
    if((tableau[0][0] + tableau[1][1] + tableau[2][2] == 264) ||
       (tableau[0][2] + tableau[1][1] + tableau[2][0] == 264))
    {
        printf("Felicitations %s, tu remporte la partie !\n", repmorp[playerA].nom);
        repmorp[playerA].pointsTournoi+=1;
        printf("\n* Saisir un caractere pour continuer. *\n");
        scanf(" %c", &car);
        system("cls");
        return 1;
    }
    if((tableau[0][0] + tableau[1][1] + tableau[2][2] == 237) ||
       (tableau[0][2] + tableau[1][1] + tableau[2][0] == 237))
    {
        printf("Felicitations %s, tu remporte la partie !\n", repmorp[playerB].nom);
        repmorp[playerB].pointsTournoi+=1;
        printf("\n* Saisir un caractere pour continuer. *\n");
        scanf(" %c", &car);
        system("cls");
        return 1;
    }
    /* Test si le tableau est plein :*/
    for(i=0; i<nblignes; i++, caseVide = 0){
        for(j=0; j<nbcolonnes; j++) {
            if(tableau[i][j] == ' '){
                return 0;
            }
        }
    }
    int chiffre = 0, tire = 0;
    srand(time(NULL));
    tire = rand()%1;
    printf("Aucun des 2 players n'a gagne \n");
    printf("Procedons a un tirage au sort ! \n");
    printf("%s doit choisir un chiffre entre 0 et 1 : \n", repmorp[playerA].nom);
    scanf(" %d", &chiffre);
    while(chiffre != 0 && chiffre != 1){
        printf("%s doit choisir un chiffre entre 0 et 1 : \n", repmorp[playerA].nom);
        scanf(" %d", &chiffre);
    }
    if(chiffre == tire){
        printf("Felicitations %s, tu remporte le tirage !\n", repmorp[playerA].nom);
        repmorp[playerA].pointsTournoi+=1;
    } else {
        printf("Felicitations %s, tu remporte le tirage !\n", repmorp[playerB].nom);
        repmorp[playerB].pointsTournoi+=1;
    }
    printf("\n* Saisir un caractere pour continuer. *\n");
    scanf(" %c", &car);
    system("cls");
    return 2;
}

void modifTabTournoi(char tableau[nblignes][nbcolonnes], player repmorp[], int i, int playerA, int playerB)
{

    int colonne;
    int ligne;
    if(i%2 == 0){
        printf("Au tour de %s :\n\n", repmorp[playerA].nom);
        printf("Choisir une ligne :\n");
        scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
        scanf("%d",&colonne);
        system("cls");
        while(tableau [ligne -1][colonne -1] != ' '){
        afficherTab(tableau);
        printf("Cette case est deja prise !\n");
        printf("Choisir une ligne :\n");
        scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
        scanf("%d",&colonne);
        }
        tableau [ligne -1][colonne -1] ='X';
        afficherTab(tableau);
    } else {
        printf("Au tour de %s :\n\n", repmorp[playerB].nom);
        printf("Choisir une ligne :\n");
        scanf("%d", &ligne);
        printf("\nChoisir une colonne :\n");
        scanf("%d",&colonne);
        system("cls");
        while(tableau [ligne -1][colonne -1] != ' '){
            afficherTab(tableau);
            printf("Cette case est deja prise !\n");
            printf("Choisir une ligne :\n");
            scanf("%d", &ligne);
            printf("\nChoisir une colonne :\n");
            scanf("%d",&colonne);
        }
        tableau [ligne -1][colonne -1] ='O';
        afficherTab(tableau);
    }
    
}

void initPointsTournoi(player repmorp[]){
    int i = 0;
    for(i=0;i<8;i++){
        repmorp[i].pointsTournoi=0;
    }
}

void tournoi(char tableau[nblignes][nbcolonnes], player repmorp[], int nombreJoueurs, joueur rep[], int id)
{
    int i = 0;
    system("cls");
    printf("*** Vous etes en mode tournoi pour %d players ***\n\n", nombreJoueurs);
    switch(nombreJoueurs){
        case 4 :
            initPointsTournoi(repmorp);
            initJoueur(repmorp, rep, 4, id);
            //Match 1
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                modifTabTournoi(tableau, repmorp, i, 0, 1);
                i++;
            }
            while(!testGagnantTournoi(tableau, repmorp, 0, 1));
            
            //Match 2
            
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                modifTabTournoi(tableau, repmorp, i, 2, 3);
                i++;
            }
            while(!testGagnantTournoi(tableau, repmorp, 2, 3));
            
            //Match Final
            
            /* On trie le tableau en fonction du nombre de points de tournoi */
            int i, j=0;
            int gagnants[10] = {0};
            for(i=0; i<4; i++){
                    if(repmorp[i].pointsTournoi == 1) {
                        gagnants[j] = i;
                        j++;
                    }
                }
            system("cls");
            printf("Finale : %s VS %s\n\n", repmorp[gagnants[0]].nom, repmorp[gagnants[1]].nom);
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                modifTabTournoi(tableau, repmorp, i, gagnants[0], gagnants[1]);
                i++;
            }
            while(!testGagnantTournoi(tableau, repmorp, gagnants[0], gagnants[1]));
            char car;
            for(i=0; i<4; i++){
                if(repmorp[i].pointsTournoi == 2){
                    repmorp[i].score += 500;
                    printf("10 points ont etes ajoutes au score de %s pour avoir remporte le tournoi !\n", repmorp[i].nom);
                    printf("\n* Saisir un caractere pour continuer. *\n");
                    scanf(" %c", &car);
                    system("cls");
                }
            }
            break;
        case 8 :
            initPointsTournoi(repmorp);
            initJoueur(repmorp, rep, 4, id);
            int k = 0;
            for(j=0,k=1;j<7;j=j+2,k=k+2){
                initTab(tableau);
                afficherTab(tableau);
                do
                {
                    modifTabTournoi(tableau, repmorp, i, j, k);
                    i++;
                }
                while(!testGagnantTournoi(tableau, repmorp, j, k));
            }
            
            /* On trie le tableau en fonction du nombre de points de tournoi */
            for(i=0, j=0; i<8; i++){
                if(repmorp[i].pointsTournoi == 1) {
                    gagnants[j] = i;
                    j++;
                }
            }
            system("cls");
            printf("Demi-Finale 1 : %s VS %s\n\n", repmorp[gagnants[0]].nom, repmorp[gagnants[1]].nom);
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                modifTabTournoi(tableau, repmorp, i, gagnants[0], gagnants[1]);
                i++;
            }
            while(!testGagnantTournoi(tableau, repmorp, gagnants[0], gagnants[1]));
            system("cls");
            printf("Demi-Finale 2 : %s VS %s\n\n", repmorp[gagnants[2]].nom, repmorp[gagnants[3]].nom);
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                modifTabTournoi(tableau, repmorp, i, gagnants[2], gagnants[3]);
                i++;
            }
            while(!testGagnantTournoi(tableau, repmorp, gagnants[2], gagnants[3]));
            
            /* On trie le tableau en fonction du nombre de points de tournoi */
            for(i=0, j=0; i<8; i++){
                if(repmorp[i].pointsTournoi == 2) {
                    gagnants[j] = i;
                    j++;
                }
            }
            
            system("cls");
            printf("Finale : %s VS %s\n\n", repmorp[gagnants[0]].nom, repmorp[gagnants[1]].nom);
            initTab(tableau);
            afficherTab(tableau);
            do
            {
                modifTabTournoi(tableau, repmorp, i, gagnants[0], gagnants[1]);
                i++;
            }
            while(!testGagnantTournoi(tableau, repmorp, gagnants[0], gagnants[1]));
            for(i=0, j=0; i<8; i++){
                if(repmorp[i].pointsTournoi == 3){
                    repmorp[i].score += 1000;
                    printf("20 points ont etes ajoutes au score de %s pour avoir remporte le tournoi !\n", repmorp[i].nom);
                    printf("\n* Saisir un caractere pour continuer. *\n");
                    scanf(" %c", &car);
                    system("cls");
                }
            }
            break;
        default:
            printf("Une erreur est survenue !\n");
            break;
    }
}