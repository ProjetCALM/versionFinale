/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "headerliar.h"


void liarDice(joueur rep[]) {
    int p=0;
    srand(time(0));
    system("cls");
    printf("**** LIAR'S DICE ****\n\nEntrer nombre de participants : ");
    scanf("%d", &p);
    
    player table[p]; //crée un tableau contenant toutes les données de tous les joueurs de la table
    initTable(table, rep, p);
    printf("Initialise");
    turn(table, p);
}








void turn(player table[], int p) {
    int rnd=1, end=0, i=0, j=0, k=0, l=0, ch=0; //rnd permet de suivre le nombre de tours, end permet de mettre fin à la partie lorsqu'un joueur a gagné, i et j servent pour boucle, ch permet choix
    int prec=0, liecheck=0, betcheck=0, last=0; //prec permet de faire des tests sur le joueur précédent, liecheck détermine le nombre de dés si call liar, last détermine personne commencant
    char enter=0; //utile pour certaines confirmations
    for(rnd=1; end != p-1; rnd++) {
        if(rnd == 1) { //lance les dés au premier tour
            for(j=0; j<p; j++) {
                table[j]=rollTheDice(table[j]);
            }
        }
        else 
        {
            last=0; //le perdant de la manche précédente commence la suivante, mais le tour de table commence quand même au joueur 0 si ce n'est pas un début de manche
        }
        for(i=last; i<p; i++) { //pour faire le tour de la table en fonction du nombre de participants
            end=checkEnd(table, p);
            if (i == 0) {prec=p-1;}//au cas où on commence un nouveau tour lors de la déclaration du menteur, permet de désigner le dernier joueur
            else {prec=i-1;} //permet de tester le joueur précédent même lorsque il s'agit du début de la boucle
            if (table[i].out == 0) {//permet de sauter les joueurs éliminés
                system("cls");
                printf("Joueur actuel : %s\n", table[i].nom);
                printf("Score : %d\n", table[i].score);
                printf("Nombre de joueur restants : %d\n", end);
                printf("Pari actuel : La face %d est sortie %d fois.\n\n", table[prec].betface, table[prec].betnb);
        
                if(rnd == 1) {
                    printf("ROLL THE DICE !\n");
                    fflush(stdin);
                    while (enter != '\r' && enter != '\n') { enter = getchar(); }
                    enter=0;
                    printTheDice(table[i]);
                }
        
                else {
                    printf("Des actuels :\n");
                    printTheDice(table[i]);
                }
            
                printf("1 - Parier\n2 - Call liar\n3 - Quitter la partie\nChoix : ");
                scanf("%d", &ch);
                switch(ch) {
                    case 1:
                        do {
                            betcheck=0; //pour confirmer que le pari est correct, et parce que je ne sais pas mettre trois conditions non indépendantes dans une boucle
                            printf("Choisir la face sur laquelle parier (entre 2 et 6) : ");
                            scanf("%d", &table[i].betface);
                            
                            printf("Choisir le nombre de %d sur lequel parier (entre 1 et %d): ", table[i].betface, totalDice(table, p));
                            scanf("%d", &table[i].betnb);
                            if(table[i].betnb < table[prec].betnb)
                            {
                                printf("Vous devez parier sur un nombre de faces plus grand que le joueur precedent, ou sur le meme nombre de faces mais une face superieure.\n");
                                betcheck=1;
                            }
                            else if (table[i].betnb == table[prec].betnb && table[i].betface == table[prec].betface)
                            {
                                printf("Vous devez parier sur un nombre de des plus eleves que le joueur precedent, ou sur le meme nombre de des mais une face superieure.\n");
                                betcheck=1;
                            }
                            else if (table[i].betface < 2 || table[i].betface > 6)
                            {
                                printf("Vous devez parier sur une face entre 2 et 6.\n");
                                betcheck=1;
                            }
                            else if (table[i].betnb < 1 || table[i].betnb > totalDice(table, p))
                            {
                                printf("Vous devez parier sur une face entre 2 et 6.\n");
                                betcheck=1;
                            }
                        }
                        while (betcheck != 0);
                        break;
                    
                    case 2:
                        if(table[prec].betface==0)
                        {
                            printf("Vous ne pouvez pas declarer menteur pendant le premier tour. Veuillez faire un pari.\n\n");
                            printf("Choisir la face sur laquelle parier (entre 2 et 6) : ");
                            scanf("%d", &table[i].betface);
                            printf("Choisir le nombre de %d sur lequel parier (entre 1 et %d): ", table[i].betface, p*5);
                            scanf("%d", &table[i].betnb);
                        }
                        else
                        {
                            for(k=0; k<p; k++) {
                                for(l=0; l<table[k].dicenb; l++) {
                                    if (table[prec].betface == table[k].dice[l] || table[k].dice[l] == 1) 
                                    {
                                        liecheck++;
                                    }
                                }
                            } //permet de compter le nombre de face présentes sur lesquelles le joueur précédent a parié
                            if (table[prec].betnb > liecheck) 
                            {
                                printf("Il y avait un total de %d des affichant %d. Le joueur precedent avait menti et perd un de.\nTout le monde relance les des.\n", liecheck, table[i-1].betface);
                                table[prec].dice[table[prec].dicenb]=0;
                                table[prec].dicenb--;//retire un dé
                                if (table[prec].dicenb == 0)
                                {
                                    table[prec].out=1;
                                    printf("Le joueur %d a ete elimine.\n", prec);
                                }
                                last=prec;//le perdant de la manche commence la suivante
                            }
                            else
                            {
                                printf("Il y avait un total de %d des affichant %d. Le joueur precedent disait la verite. Vous perdez un de.\nTout le monde relance les des.\n", liecheck, table[i-1].betface);
                                table[i].dice[table[i].dicenb]=0;
                                table[i].dicenb--;//retire un dé
                                if (table[i].dicenb == 0)
                                {
                                    table[i].out=1;
                                    printf("Le joueur %d a ete elimine.\n", i);
                                }
                                last=i;//le perdant de la manche commence la suivante
                                
                            }
                            liecheck=0;//réinitialise à 0 pour le test suivant
                            fflush(stdin);
                            printf("Press [Enter] to continue.");
                            while (enter != '\r' && enter != '\n') { enter = getchar(); }
                            enter=0;
                        }
                        rnd=0;
                        i=p;
                        initTable2(table, p); //réinitialise paris
                        break;
                    
                    case 3:
                        end=p-1;
                        i=p;
                        break;
                    
                }
            }
        }
    }
        
    
}

int checkEnd(player table[], int p) {
    int i=0, prog=0;
    for (i=0; i<p; i++) {
        prog+=table[i].out;
    }
    return prog;
}

void initTable(player table[], joueur rep[], int p) {
    int i=0, j=0;
    for (i=0; i<p; i++) {
        table[i].score=rep[i].score;
        strcpy(table[i].nom, rep[i].nom);
        table[i].dicenb=5;
        for(j=0; j<5; j++) {
            table[i].dice[j]=0;
        }
        table[i].betnb=0;
        table[i].betface=0;
        table[i].out=0;
    }
}

void initTable2(player table[], int p) {
    int i=0, j=0;
    for (i=0; i<p; i++) {
        for(j=0; j<table[i].dicenb; j++) {
            table[i].dice[j]=0;
        }
        table[i].betnb=0;
        table[i].betface=0;
    }
}

int totalDice(player table[], int p) {
    int i=0, tot=0;
    for(i=0; i < p; i++) {
        tot+=table[i].dicenb;
    }
    return tot;
}

player rollTheDice(player a) {
    int i=0;
    for(i=0; i<a.dicenb; i++) { 
        a.dice[i]=(rand()%6)+1; //calcule un résultat entre 1 et 6 pour le dé
    }
    return a;
} //note : pas certain que le fonctionnement des pointeurs permette de récupérer le résultat des dés. A vérifier.
 
void locate(int x,int y) { 
    //permet de replacer le curseur à l'endroit désiré, afin que votre prochain printf se fasse à l'endroit que vous souhaitez
    //fonctionne grâce à windows.h, pensez à l'inclure. Ne marchera probablement pas pour toi, Adrien.
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X=x;
    C.Y=y;
    SetConsoleCursorPosition(H,C);
}

void printTheDice(player a) { //permet de lancer et d'afficher les 6 dés
    int i=0;
    for(i=0; i<a.dicenb; i++) { 
        if(a.dice[i] == 1) { //affiche le dé qui nous intéresse en fonction du résultat
            locate(14*i, 6);
            printf("+---------+");
            locate(14*i, 7);
            printf("|         |");
            locate(14*i, 8);
            printf("|    O    |");
            locate(14*i, 9);
            printf("|         |");
            locate(14*i, 10);
            printf("+---------+\n");
        }
        else if(a.dice[i] == 2) {
            locate(14*i, 6);
            printf("+---------+");
            locate(14*i, 7);
            printf("|       O |");
            locate(14*i, 8);
            printf("|         |");
            locate(14*i, 9);
            printf("| O       |");
            locate(14*i, 10);
            printf("+---------+\n");
        }
        else if(a.dice[i] == 3) {
            locate(14*i, 6);
            printf("+---------+");
            locate(14*i, 7);
            printf("|       O |");
            locate(14*i, 8);
            printf("|    O    |");
            locate(14*i, 9);
            printf("| O       |");
            locate(14*i, 10);
            printf("+---------+\n");
        }
        else if(a.dice[i] == 4) {
            locate(14*i, 6);
            printf("+---------+");
            locate(14*i, 7);
            printf("| O     O |");
            locate(14*i, 8);
            printf("|         |");
            locate(14*i, 9);
            printf("| O     O |");
            locate(14*i, 10);
            printf("+---------+\n");
        }
        else if(a.dice[i] == 5) {
            locate(14*i, 6);
            printf("+---------+");
            locate(14*i, 7);
            printf("| O     O |");
            locate(14*i, 8);
            printf("|    O    |");
            locate(14*i, 9);
            printf("| O     O |");
            locate(14*i, 10);
            printf("+---------+\n");
        }
        else if(a.dice[i] == 6) {
            locate(14*i, 6);
            printf("+---------+");
            locate(14*i, 7);
            printf("| O     O |");
            locate(14*i, 8);
            printf("| O     O |");
            locate(14*i, 9);
            printf("| O     O |");
            locate(14*i, 10);
            printf("+---------+\n");
        }
    }
}