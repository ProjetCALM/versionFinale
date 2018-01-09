/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "header_liar.h"


void liarDice(joueur rep[], int id) {
    int p=0, hu=0, ai=0, ch=0, i=0;
    srand(time(0));
    system("cls");
    printf("**** LIAR'S DICE ****\n\n1 - Lancer une partie\n2 - Retour\n\nChoix : ");
    scanf("%d", &ch);
    if(ch == 2)
    {
        printf("Retour au menu principal...");
    }
    else 
    {
        printf("\nEntrer nombre de participants : ");
        scanf("%d", &p);
        printf("Entrer le nombre de joueurs (les places restantes seront remplies par des AIs) : ");
        scanf("%d", &hu);
        ai=p-hu;
    
        player table[p]; //crée un tableau contenant toutes les données de tous les joueurs de la table
        initTable(table, rep, hu, id);
        initAI(table, ai, hu);
        printf("Initialise");
        turn(table, p);
        for(i=0; i<p; i++) {
            if(table[i].out=0) {
                table[i].score+=p*300;
            }
        }
    }
}








void turn(player table[], int p) {
    int rnd=1, end=0, i=0, j=0, k=0, ch=0, chAI=0; //rnd permet de suivre le nombre de tours, end permet de mettre fin à la partie lorsqu'un joueur a gagné, i et j servent pour boucle, ch permet choix
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
            if (i == 0) {prec=p-1;}//au cas où on commence un nouveau tour lors de la déclaration du menteur, permet de désigner le dernier joueur
            else {prec=i-1;} //permet de tester le joueur précédent même lorsque il s'agit du début de la boucle
            if (table[i].out == 0) {//permet de sauter les joueurs éliminés
                system("cls");
                printf("Joueur actuel : %s\n", table[i].nom);
                printf("Score : %d\n", table[i].score);
                printf("Nombre de joueur restants : %d\n", end);
                printf("Pari actuel : La face %d est sortie %d fois.\n\n", table[prec].betface, table[prec].betnb);
        
                if (table[i].human == 1) //si le joueur est un ordi
                {
                    chAI=turnAI(table, prec, p, i);
                    if (chAI == 1) 
                    {
                        printf("%s parie sur %d faces affichant %d.\n\n", table[i].nom, table[i].betnb, table[i].betface);
                        fflush(stdin);
                        printf("Press [Enter] to continue.");
                        while (enter != '\r' && enter != '\n') { enter = getchar(); }
                        if(entery)
                        enter=0;
                    }
                    else
                    {
                        printf("%s declare menteur !\n\n", table[i].nom);//quelque chose foire par ici
                        for(k=0; k < p; k++) {
                            liecheck+=countFace(table, k, table[prec].betface);
                        } //permet de compter le nombre de face présentes sur lesquelles le joueur précédent a parié
                        if (table[prec].betnb > liecheck) 
                        {
                            printf("Il y avait un total de %d des affichant %d. Le joueur precedent avait menti et perd un de.\nTout le monde relance les des.\n", liecheck, table[prec].betface);
                            table[prec].dice[table[prec].dicenb]=0;
                            table[prec].dicenb--;//retire un dé
                            if (table[prec].dicenb == 0)
                            {
                                table[prec].out=1;
                                printf("Le joueur %d a ete elimine.\n", prec);
                            }
                            last=prec;//le perdant de la manche commence la suivante
                        }
                        else if (table[prec].dicenb <= liecheck)
                        {
                            printf("Il y avait un total de %d des affichant %d. Le joueur precedent disait la verite. %s perd un de.\nTout le monde relance les des.\n", liecheck, table[i].betface, table[i].nom);
                            table[i].dice[table[i].dicenb]=0;
                            table[i].dicenb--;//retire un dé
                            if (table[i].dicenb == 0)
                            {
                                table[i].out=1;
                                printf("Le joueur %d a ete elimine.\n", i);
                            }
                            last=i;//le perdant de la manche commence la suivante
                              
                        }
                        chAI=0;
                        fflush(stdin);
                        printf("Press [Enter] to continue.");
                        while (enter != '\r' && enter != '\n') { enter = getchar(); }
                        enter=0;
                        rnd=0;
                        i=p;
                        liecheck=0;//réinitialise à 0 pour le test suivant
                        initTable2(table, p); //réinitialise paris
                    }
                }
                
                else 
                {
                    if(rnd == 1) 
                    {
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
                            end=checkEnd(table, p);
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
                                printf("%s declare menteur !\n\n", table[i].nom);//quelque chose foire par ici
                                for(k=0; k<p; k++) {
                                    liecheck+=countFace(table, k, table[prec].betface);
                                } //permet de compter le nombre de face présentes sur lesquelles le joueur précédent a parié
                                if (table[prec].betnb > liecheck) 
                                {
                                    printf("Il y avait un total de %d des affichant %d. %s avait menti et perd un de.\nTout le monde relance les des.\n", liecheck, table[prec].betface, table[prec].nom);
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
                                    printf("Il y avait un total de %d des affichant %d. Le joueur precedent disait la verite. %s perd un de.\nTout le monde relance les des.\n", liecheck, table[i].betface, table[i].nom);
                                    table[i].dice[table[i].dicenb]=0;
                                    table[i].dicenb--;//retire un dé
                                    if (table[i].dicenb == 0)
                                    {
                                        table[i].out=1;
                                        printf("Le joueur %d a ete elimine.\n", i);
                                    }
                                    last=i;//le perdant de la manche commence la suivante
                                    
                                }
                                fflush(stdin);
                                printf("Press [Enter] to continue.");
                                while (enter != '\r' && enter != '\n') { enter = getchar(); }
                                enter=0;
                            }
                            liecheck=0;//réinitialise à 0 pour le test suivant
                            rnd=0;
                            i=p;
                            ch=0;
                            initTable2(table, p); //réinitialise paris
                            end=checkEnd(table, p);
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
}

int checkEnd(player table[], int p) {//calcule le nombre de joueurs ayant été éliminés à chaque tour
    int i=0, prog=0;
    for (i=0; i<p; i++) {
        prog+=table[i].out;
    }
    return prog;
}

void initTable(player table[], joueur rep[], int hu, int id) {
    int temp=0, i=0, j=0;
    printf("Choisir les participants :\n");
    printRep(rep, id);
    printf("\nSelection\n");
    for(i=0; i<hu; i++) {
        printf("Joueur %d : ", i+1);
        scanf("%d", &temp);
        table[i].score=rep[temp-1].score;
        strcpy(table[i].nom, rep[temp-1].nom);
        table[i].dicenb=5;
        for(j=0; j<5; j++) {
            table[i].dice[j]=0;
        }
        table[i].betnb=0;
        table[i].betface=0;
        table[i].out=0;
        table[i].human=0;
    }
}

void initAI(player table[], int ai, int hu) {
    int i=0, j=0;
    for(i=0; i<ai; i++) {
        table[hu+i].score=0;
        sprintf(table[hu+i].nom, "Ordi %d", i+1);
        table[hu+i].dicenb=5;
        for(j=0; j<5; j++) {
            table[hu+i].dice[j]=0;
        }
        table[hu+i].betnb=0;
        table[hu+i].betface=0;
        table[hu+i].out=0;
        table[hu+i].human=1;
    }
}

int turnAI(player table[], int prec, int p, int cur) {//prec=joueur précédent, cur=joueur actuel, p=participants
    int choice=0, temp=0, max=0, face=2, i=0, j=0; //max permet de trouver
    for(j=0; j<6; j++) {//permet à l'AI de compter le nombre de faces pour déterminer ses chances
        temp=countFace(table, cur, j);
        }
        if(temp > max) {max=temp; face=j;}
    if(table[prec].betnb > (totalDice(table, p)/3) + countFace(table, cur, table[prec].betface) + rand()%2) //fait une estimation pour deviner si le joueur précédent ment ou pas 
    {
        choice=2;
    }
    else if (rand()%10 < rand()%12 || face < table[prec].betface) //donne à l'AI une chance aléatoire de bluffer
    {
        choice=1;
        if(table[prec].betface != 6) {table[cur].betface = table[prec].betface+rand()%2;}
        if(table[cur].betface > 6) {table[cur].betface = 6;}
        else {table[cur].betface=6;}
        table[cur].betnb=table[prec].betnb+rand()%3+1;
    }
    else if(face > table[prec].betface) {
        choice=1;
        table[cur].betface=face;
        table[cur].betnb=totalDice(table, p)/3 + max - rand()%3;
        while (table[cur].betnb <= table[prec].betnb) 
        {
            table[cur].betnb+=rand()%3;
        }
    }
    return choice;
}

int countFace(player table[], int player, int face) {//permet de compter la quantité d'une face donnée dans la main d'un joueur
    int i=0, count=0;
    for(i=0; i<table[player].dicenb; i++) {
        if(table[player].dice[i] == face || table[player].dice[i] == 1) {count++;}
    }
    return count;
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
