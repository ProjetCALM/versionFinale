

#include <stdio.h>
#include <stdlib.h>
#include "header_blackjack.h"
#include <time.h>
#define PLAYER ((int)10)


void jack(joueur rep[], int id){
   
    bjack b;
    int i,j=0;
    int end=0;
    int max=0;
    
    int n=0;
    int tour;   // = nombre de carte tirées
    int joueur; // = numero du joueur 
    carte c;
    srand(time(0));
    //aleaCarte(tour,joueur);
    
    
    
    bjack tab[(PLAYER)];
    tab[10].count = 0;
    for(i=0;i<PLAYER;i++){
        tab[i].count = 0;
        tab[i].done = 0;
        tab[i].win = 0 ;
        for(j=0;j<CARTE;j++){
            tab[i].jeu.card[j].blazon=0;
            tab[i].jeu.card[j].valeur=0;
    }
    } 
   
    n=intPlayer(tab, rep, id);
    
    end = Alpha(n, tab);    
    
    if (end==0){
        Beta(n, tab,0); //tour 2
        Beta(n, tab,1); //tour 3
        Beta(n, tab,2); //tour 4
}
    
    bank(tab);
    max = maxCard(n,tab);
    printf("\n\nLe plus gros score des joueurs est %d",max);
    compare(max,n,tab);
    for(i=0; i<n; i++) {
        rep[tab[i].id].score=tab[i].score;
    }
}


int intPlayer(bjack tab[], joueur rep[], int id){
    int n=0;//nombre de joueur
    
    printf("Nombre de joueurs : ");
    scanf("%d",&n);
    
    int compteur[10];
    
    
    int temp=0, i=0;
    printf("Choisir les participants :\n");
    printRep(rep, id);
    printf("\nSelection (entrer l'ID du joueur)\n");
    for(i=0; i<n; i++) {
        printf("Joueur %d : ", i+1);
        scanf("%d", &temp);
        tab[i].score=rep[temp-1].score;
        strcpy(tab[i].nom, rep[temp-1].nom);
        tab[i].id=temp-1;
    }
    
    system("cls");
    
//    
//    printf("Voulez-vous rajouter des IAs ?\n1 : Non\n2 : Oui\n0 : Quitter\n");
//    scanf("%d",&ia);
//    if(ia == 2){
//        ia = 3;
//    printf("1 : Ajouter une IA\n2 : Ajouter deux IA\n0 : Annuler l'ajout d'IA\n");    
//    while(ia != 0 && ia != 1 && ia != 2) {
//    scanf("%d",&ia);   
//    }
//    }
//    tab[0].stop = ia; // case inutilisée avant ça qui sert désormais a stocker le nombre d'ia
//    
    return(n);
    }

int aleaCarte(int t,int j,bjack tab[]){
    int blazon=0;
    int v=0;
    int n=0;
    bjack b;
    carte c;
    int count=0;
    
    blazon=rand()%4;
    v=rand()%13;
    printf("\n");
    if(v==0){
        printf("As");
        count = choixAs();
     
 
    }
    else if(v<=9){
        printf("%d",(v+1));
        count=(v+1);
    }
    else if(v==10){
        printf("Valet");
        count=10;
    }
    if(v==11){
        printf("Dame");
        count=10;
    }
    if(v==12){
        printf("Roi");
        count=10;
    }
    
    switch(blazon){
        case 1:
            printf(" de Coeur");
            break;
        case 2:
            printf(" de Pique");
            break;
        case 3:
            printf(" de Carreau");
            break;
        case 0:
            printf(" de Trefle");
            break;
        default:
            break;
    }
    tab[j].jeu.card[t].blazon=blazon;
    tab[j].jeu.card[t].valeur=v;
    
    return(count);
}

 int choixAs(){
     int choix=0;
     int c=0;
     printf("\nVous avez obtenu un as, choisissez la valeur qu'il prendra :\n1 ou 11\n");
     
     while(choix != 1 && choix != 11){
         scanf("%d",&choix);
         if(choix == 1){
             c = 1;
         }
         else if(choix == 11){
             c = 11;
         }
     }
     return c;
 }
 void attente(){
     char var;
     printf("\nEnter");
     fflush(stdin);
     while(var != '\n'&& var !='\r'){ var = getchar();}
     var=0;
     
 }

 int Alpha(int n, bjack tab[]){
     int i; // numéro joueur
     int c=0;
     int end=0;
     
    system("cls");
    for(i=0;i<n;i++){
    printf("Joueur %d : %s\n", i+1, tab[i].nom);
    c=aleaCarte(0,i,tab);
    c=c+aleaCarte(1,i,tab);
    tab[i].count = c;
    printf ("\n\nTotal = %d",c);
    if(c == 21){
        winBlack(i,tab); 
        i=n;
        end=1;
    }  
    attente();
    
    system("cls");
    }
    return end ;
 }   

void Beta(int n,bjack tab[],int a){
      int i; // numéro joueur
     int c=0;
     int choix=0;
    
    
    for(i=0;i<n;i++){
    system("cls");
    printf("Tour %d : \nJoueur %d : %s\n",(a+2),(i+1),tab[i].nom);
    c = tab[i].count;
    printf ("\n\nTotal = %d",c);
    if(tab[i].done == 0){
    choix = choixCarte(i,tab);
    if(choix ==1){
        c=c+aleaCarte(2+a,i,tab);      
        tab[i].count = c;
    }
    
    printf ("\n\nTotal = %d",c);
    if(c>21){
        printf("\nLe total est superieur a 21");
        tab[i].done = 1;
    }
    attente();
}
    }
}

   void winBlack(int n,bjack tab[]){
      printf("\nBLACKJACK !\nC'est %s ,le joueur %d qui gagne",tab[n].nom,(n+1));
      tab[n].win = 1;
   }


   int choixCarte(int i,bjack tab[]){
    int choix = 0 ;
    int a=0;

     if((tab[i].done) == 0){
     printf("\n1: Tirer une carte\n2:Conserver le jeu actuel");
     
     while(choix != 1 && choix != 2){
         scanf("%d",&choix);
         if(choix == 1){
            a=1;
         }
         else if(choix == 2){
        (tab[i].done)=1;
         }
     }
     }
     return a;
   }

     
void bank(bjack tab[]){ // La banque est le joueur n°10 
    int c=0;
    system("cls");
     c=c+aleaCarteBanque(0,9,c);
     c=c+aleaCarteBanque(1,9,c);
     if(c<17){
         c=c+aleaCarteBanque(2,9,c);
     }
     if(c<17){
         c=c+aleaCarteBanque(3,9,c);
     }
     if(c<17){
         c=c+aleaCarteBanque(4,9,c);
     }
      tab[10].count = c;
     printf("\nLa valeur des cartes de la banque est de %d",c);
}   


int aleaCarteBanque(int t,int j, int c2){
    int blazon=0;
    int v=0;
    int n=0;
    bjack b;
    carte c;
    bjack tab[PLAYER];
    int count=0;
    
    blazon=rand()%4;
    v=rand()%13;
    printf("\n");
    if(v==0){
        printf("As");
        if(c2<=10){
            count=11;
        }
        else if(c2>10){
            count=1;
        }
     
 
    }
    else if(v<=9){
        printf("%d",(v+1));
        count=(v+1);
    }
    else if(v==10){
        printf("Valet");
        count=10;
    }
    if(v==11){
        printf("Dame");
        count=10;
    }
    if(v==12){
        printf("Roi");
        count=10;
    }
    
    switch(blazon){
        case 1:
            printf(" de Coeur");
            break;
        case 2:
            printf(" de Pique");
            break;
        case 3:
            printf(" de Carreau");
            break;
        case 0:
            printf(" de Trefle");
            break;
        default:
            break;
    }
    tab[j].jeu.card[t].blazon=blazon;
    tab[j].jeu.card[t].valeur=v;
    
    return(count);
}
   


int maxCard(int n,bjack tab[]){
    
    int maximum=0  ;
    int i=0;
    for(i=0;i<n;i++){
        if(tab[i].count<=21){
        if(((tab[i].count)>maximum)){
            maximum = (tab[i].count);
        }
    }
    }
    return(maximum);
}


void compare(int max, int n, bjack tab[]){
    int i=0;
    int bank=0;
    bank = tab[10].count;
    
    if(bank>21){
        bank=0;
    }
    
    if(max<=bank){ //la banque gagne
        printf("\nC'est la banque qui gagne");
        tab[10].win = 1;
        for(i=0;i<n;i++){
         tab[i].win = 2;   
        }
    }
   
    if(max>bank){ //un ou plusieurs joueurs sont plus proche de 21 que la banque
        tab[10].win =2 ;
        for(i=0;i<n;i++){
            if(tab[i].count == max){
                tab[i].win=1;
            }
            else{
                tab[i].win=2;
            }
        }
         for(i=0;i<n;i++){
        if(tab[i].win == 1){
            printf("\nJoueur %d : gagnant",i+1);
            tab[i].score+=500;
        }
        else if(tab[i].win == 2){
            printf("\nJoueur %d : perdant",i+1);
        }
    }
    if(tab[10].win == 1){
            printf("\nBanque : gagnante");
        }
        else if(tab[10].win == 2){
            printf("\nBanque : perdante");
        }
        else{
            printf("Error");
        }
    }
}