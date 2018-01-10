#include "header_bataillenavale.h"


void bataillenavale(joueur rep[], int id) {
    /*variables*/
    player J;
    int choix;
    int tab1[LIN][COL]; /*grille du player 1*/
    int tab2[LIN][COL]; /*grille du player 2*/
    int grille1[LIN][COL]; /*grille d'attaque de j2*/
    int grille2[LIN][COL]; /*grille d'attaque de j1*/
    J.compteurj1 = 0;
    J.compteurj2 = 0;
    /*debut du jeu*/
    printf("\t\t\t\tBATAILLE NAVALE\n\n");
    J=initPlayer(J, rep, id);
    /*initialisation de la grille 1*/
    affiche1(tab1); 
    placement1(tab1, J);
    bateaux1(tab1);
    continuer(choix);
    if(choix != 1){
        return;
    }
    /*initialisation de la grille 2*/
    printf("\t\t\t\tBATAILLE NAVALE\n\n");
    affiche2(tab2);
    placement2(tab2, J);
    bateaux2(tab2);
    continuer(choix);
    if(choix != 1){
        return;
    }
    /*fin du placement des bateaux*/
    /*début de la partie*/
    boucleatt(grille1, tab1, grille2, tab2, choix, J, rep);
}


/*fonctions pour initialiser*/
player initPlayer(player J, joueur rep[], int id) {
    int temp=0;
    printf("Choisir les participants :\n");
    printRep(rep, id);
    printf("\nSelection (entrer l'ID du joueur)\n");
    printf("Joueur 1 : ");
    scanf("%d", &temp);
    J.score1=rep[temp-1].score;
    strcpy(J.nom1, rep[temp-1].nom);
    J.compteurj1=0;
    J.id1=temp-1;
    printf("Joueur 2 : ");
    scanf("%d", &temp-1);
    J.score2=rep[temp-1].score;
    strcpy(J.nom2, rep[temp-1].nom);
    J.compteurj2=0;
    J.id2=temp-1;
    return J;
}

/*placement des bateaux de j1*/
void affiche1(int tab1[LIN][COL]){
    int i, j, lin;
    for(i = 0; i < LIN; i++){
        lin = i + 1;
        printf("%d\t", lin);
        for(j = 0; j < COL; j++){
            tab1[i][j] = 0;
            printf("%d\t", tab1[i][j]);
        }
        printf("\n");
    }
}

void placement1(int tab1[LIN][COL], player J){
    int a, b, c, nombre;
    printf("%s, placez vos 5 bateaux :\n", J.nom1);
    for(nombre = 0; nombre < 5; nombre++){
        c = nombre + 1;
        printf("Bateau %d :\n", c);
        printf("Ligne : ");
        scanf("%d", &a);
        printf("Colonne : ");
        scanf("%d", &b);
        a = a - 1;
        b = b - 1;
        tab1[a][b] = 1;
    }
}

void bateaux1(int tab1[LIN][COL]){
    system("cls");
    printf("\t\t\t\tBATAILLE NAVALE\n\n");
    int i, j, lin;
    printf("Vos bateaux :\n");
    for(i = 0; i < LIN; i++){
        lin = i + 1;
        printf("%d\t", lin);
        for(j = 0; j < COL; j++){
            printf("%d\t", tab1[i][j]);
        }
        printf("\n");
    }
}

/*placement des bateaux de j2*/
void affiche2(int tab2[LIN][COL]){
    int i, j, lin;
    for(i = 0; i < LIN; i++){
        lin = i + 1;
        printf("%d\t", lin);
        for(j = 0; j < COL; j++){
            tab2[i][j] = 0;
            printf("%d\t", tab2[i][j]);
        }
        printf("\n");
    }
}

void placement2(int tab2[LIN][COL], player J){
    int a, b, c, nombre;
    printf("%s, placez vos 5 bateaux :\n", J.nom2);
    for(nombre = 0; nombre < 5; nombre++){
        c = nombre + 1;
        printf("Bateau %d :\n", c);
        printf("Ligne : ");
        scanf("%d", &a);
        printf("Colonne : ");
        scanf("%d", &b);
        a = a - 1;
        b = b - 1;
        tab2[a][b] = 1;
    }
}

void bateaux2(int tab2[LIN][COL]){
    system("cls");
    printf("\t\t\t\tBATAILLE NAVALE\n\n");
    int i, j, lin;
    printf("Vos bateaux :\n");
    for(i = 0; i < LIN; i++){
        lin = i + 1;
        printf("%d\t", lin);
        for(j = 0; j < COL; j++){
            printf("%d\t", tab2[i][j]);
        }
        printf("\n");
    }
}


/*fonctions pour la partie*/
/*attaque de j1*/
void afgrille2(int grille2[LIN][COL], player J){
    int i, j, lin;
    printf("\nGrille de %s :\n", J.nom2);
    for(i = 0; i < LIN; i++){
        lin = i + 1;
        printf("%d\t", lin);
        for(j = 0; j < COL; j++){
            grille2[i][j] = 0;
            printf("%d\t", grille2[i][j]);
        }
        printf("\n");
    }
}

player attaque1(int grille2[LIN][COL], int tab2[LIN][COL], player J){
    int lin, col;
    printf("Ou voulez vous attaquer ?\n");
    printf("Ligne : ");
    scanf("%d", &lin);
    printf("Colonne : ");
    scanf("%d", &col);
    lin = lin - 1;
    col = col - 1;
    grille2[lin][col] = 0;
    if(grille2[lin][col] != tab2[lin][col]){
        printf("touche!\n");
        grille2[lin][col] = 1;
        J.compteurj1 = J.compteurj1 + 1;
    }
    else{
        printf("manque!\n");
        grille2[lin][col] = 2;
    }
    printf("Nombre de bateaux adverse touches : %d", J.compteurj1);
    return J;
}

void attgrille2(int grille2[LIN][COL], player J){
    int i, j, lin;
    printf("\nGrille de %s :\n", J.nom2);
    for(i = 0; i < LIN; i++){
        lin = i + 1;
        printf("%d\t", lin);
        for(j = 0; j < COL; j++){
            printf("%d\t", grille2[i][j]);
        }
        printf("\n");
    }
}


/*attaque de j2*/
void afgrille1(int grille1[LIN][COL], player J){
    int i, j, lin;
    printf("\nGrille de %s :\n", J.nom1);
    for(i = 0; i < LIN; i++){
        lin = i + 1;
        printf("%d\t", lin);
        for(j = 0; j < COL; j++){
            grille1[i][j] = 0;
            printf("%d\t", grille1[i][j]);
        }
        printf("\n");
    }
}

player attaque2(int grille1[LIN][COL], int tab1[LIN][COL], player J){
    int lin, col;
    printf("Ou voulez vous attaquer ?\n");
    printf("Ligne : ");
    scanf("%d", &lin);
    printf("Colonne : ");
    scanf("%d", &col);
    lin = lin - 1;
    col = col - 1;
    grille1[lin][col] = 0;
    if(grille1[lin][col] != tab1[lin][col]){
        printf("touche!\n");
        grille1[lin][col] = 1;
        J.compteurj2  = J.compteurj2 + 1;
    }
    else{
        printf("manque!\n");
        grille1[lin][col] = 2;
    }
    printf("Nombre de bateaux adverse touches : %d\n", J.compteurj2);
    return J;
}

void attgrille1(int grille1[LIN][COL], player J){
    int i, j, lin;
    printf("\nGrille de %s :\n", J.nom1);
    for(i = 0; i < LIN; i++){
        lin = i + 1;
        printf("%d\t", lin);
        for(j = 0; j < COL; j++){
            printf("%d\t", grille1[i][j]);
        }
        printf("\n");
    }
}

/*attaques générales*/
void boucleatt(int grille1[LIN][COL], int tab1[LIN][COL], int grille2[LIN][COL], int tab2[LIN][COL], int choix, player J, joueur rep[]){
    /*1ère attaque de j1*/
    bateaux1(tab1); 
    afgrille2(grille2, J);
    rappel();
    J = attaque1(grille2, tab2, J);
    choix = continuer(choix);
    if(choix != 1){
        return;
    }
        /*1ère attaque de j2*/
        bateaux2(tab2);
        afgrille1(grille1, J);
        rappel();
        J = attaque2(grille1, tab1, J);
        choix = continuer(choix);
        if(choix != 1){
            return;
        }
            /*boucle d'attaque*/
            while(J.compteurj1 < 5 && J.compteurj2 < 5){
                bateaux1(tab1); 
                attgrille2(grille2, J);
                J = attaque1(grille2, tab2, J);
                continuer(choix);
                if(choix != 1){
                    return;
                }
                /*attaque de j2*/
                bateaux2(tab2);
                attgrille1(grille1, J);
                J = attaque2(grille1, tab1, J);
                continuer(choix);
                if(choix != 1){
                    return;
                }
            }
            /*fin de partie*/
            if(J.compteurj1 == 5){
                printf("%s a gagné\n", J.nom1);
                J.score1 = J.score1 + 1;
                rep[J.id1].score+=500;
            }
            else if(J.compteurj2 == 5){
                printf("%s a gagné\n", J.nom2);
                J.score2 = J.score2 + 1;
                rep[J.id2].score+=500;
            }
            else{
                printf("Egalité!\n");
            }
}


/*fonctions en plus*/
int continuer(int a){
    printf("\nContinuer ?\n");
    printf("1 - Oui\n");
    printf("0 - Non\n");
    scanf("%d", &a);
    switch(a){
        case 1:
            system("cls");
            return a;
        break;
        default :
            return a;
        break;
    }
}

void rappel(){
    printf("**********************************************\n");
    printf("Rappels :\n");
    printf("0 signifie que tu n'as pas encore attaque ici\n");
    printf("1 signifie que tu as touche un bateau adverse\n");
    printf("2 signifie qu'il n'y a pas de bateau adverse ici\n");
    printf("**********************************************\n");
}