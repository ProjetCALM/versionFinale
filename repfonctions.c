/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header_rep.h"

int gestionRep(joueur rep[], int id) {
    int choix=0;
    char enter=0;
    do {
        choix=printMenu();
        switch(choix) {
            case 1:
                addJoueur(rep, id);
                id++;
                break;
                
            case 2:
                delJoueur(rep, id);
                id--;
                break;
                
            case 3:
                searchJoueur(rep);
                break;
                
            case 4:
                system("cls");
                printf("*** Liste des profils ***");
                printRep(rep, id);
                break;
                
            case 5:
                printf("\nRetour au menu principal...");
                break;
                
            default:
                printf("Veuillez selectionner l'une des options.\n");
        }
        fflush(stdin);
        while (enter != '\r' && enter != '\n') { enter = getchar(); }
        enter=0;
    }
    while(choix != 5);
    return (id);
}

int printMenu() {
    int choix;
    system("cls");
    printf("*** Repertoire ***\n\n1 - Ajouter un joueur\n2 - Supprimer un joueur\n3 - Rechercher un joueur\n4 - Afficher liste complete\n5 - Retour\n\n");
    printf("Choix : ");
    scanf("%d", &choix);
    return choix;
}

void initRep(joueur rep[]) {
    int i=0;
    for(i=0; i<REP; i++) {
        memset(rep[i].nom, 0, NOM);
        rep[i].score=0;
    }
    //profils prédéfinis pour les tests
    strcpy(rep[0].nom, "Test");
    strcpy(rep[1].nom, "Corentin");
    strcpy(rep[2].nom, "Maxime");
    strcpy(rep[3].nom, "Leandre");
    strcpy(rep[4].nom, "Adrien");
    rep[0].score=178;
    rep[1].score=31;
    rep[2].score=666;
    rep[3].score=11037;
    rep[4].score=31415;
}

void addJoueur(joueur rep[], int id) {
    char temp[NOM];
    memset(temp, 0, NOM);
    system("cls");
    printf("*** Ajout d'un nouveau joueur ***\n\nNom du joueur : ");
    scanf("%s", temp);
    strcpy(rep[id].nom, temp);
    rep[id].score=0;
    printf("Profil cree.\nVotre score initial est de 0.");
}

void delJoueur(joueur rep[], int id) {
    system("cls");
    printf("*** Suppression d'un joueur ***");
    printRep(rep, id);
    int temp;
    printf("Selectionner le profil a supprimer : ");
    scanf("%d", &temp);
    memset(rep[temp-1].nom, 0, NOM);
    rep[temp-1].score=0;
    printf("Profil supprimé.");
}

void searchJoueur(joueur rep[]) {
    int i=0, res=0;
    char sear[NOM];
    memset(sear, 0, NOM);
    system("cls");
    printf("*** Recherche d'un profil ***\n\nEntrer nom du joueur a rechercher : ");
    scanf("%s", sear);
    for(i=0; i<REP; i++) {
        res=strcmp(sear, rep[i].nom);
        if(res == 0)
        {
            printf("*** Joueur %d ***\nNom : %s\nScore : %d\n", i, rep[i].nom, rep[i].score);
            printf("\n\n");
        }
        else
        {
            printf("Aucun resultat trouve.\n");
        }
    }
}

void printRep(joueur rep[], int id) {
    int i=0;
    if(id == 0)
    {
        printf("\nRepertoire vide.\n");
    }
    else 
    {
        for(i=0; i<id; i++) {
            printf("\n\n*** Joueur %d ***\nNom : %s\nID : %d\nScore : %d\n", i+1, rep[i].nom, i+1, rep[i].score);
        }
    }
}

