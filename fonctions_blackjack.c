
#include "header_blackjack.h"

/*
 1;coeur  4:pique  2:carreau  3:trefle 34->37
 * ♠♡♢♣
 */


void jack(joueur rep[]){
     bjack b;
    int i,j=0;
    int end=0;
    int max=0;
    
    int n=0;
    int tour;   // = nombre de carte tirées
    int joueur; // = numero du joueur (1 => 5)
    carte c;
    srand(time(0));
    //aleaCarte(tour,joueur);
    n=intPlayer();
    bjack tab[(PLAYER)];
    
    for(i=0;i<PLAYER;i++){
        tab[i].count = 0;
        tab[i].done = 0;
        tab[i].win = 0;
        for(j=0;j<CARTE;j++){
            tab[i].jeu.card[j].blazon=0;
            tab[i].jeu.card[j].valeur=0;
    }
    }
    
    end = Alpha(n, tab);    
    
    if (end==0){
        Beta(n, tab,0); //tour 2
        
        Beta(n, tab,1); //tour 3
        Beta(n, tab,2); //tour 4
}
    
    bank();
    max = maxCard();
    printf("\n\nLe plus gros score des joueurs est %d",max);
    compare(max);
}

int maxCard(){
    bjack tab[PLAYER];
    int maximum=0  ;
    int i=0;
    for(i=1;i<(PLAYER-1);i++){
        if(((tab[i].count)>maximum) && tab[i].count<=21){
            maximum=tab[i].count;
        }
    }
    return(maximum);
}


void compare(int max){
    bjack tab[PLAYER];
    int i=0;
    
    if(max<tab[10].count){ //la banque gagne
        printf("\nC'est la banque qui gagne");
        for(i=0;i<(PLAYER-1);i++){
         tab[i].win=2;   
        }
    }
    
    else if(max>=tab[10].count){
        for(i=0;i<(PLAYER-1);i++){
            if(tab[i].count == max){
                tab[i].win=1;
            }
            else{
                tab[i].win=2;
            }
        }
    }
    
    for(i=0;i<PLAYER-1;i++){
        if(tab[i].win == 1){
            printf("\nJoueur %d : gagnant",i);
        }
        else{
            printf("\nJoueur %d : perdant",i);
        }
    }
    if(tab[10].win == 1){
            printf("\nBanque : gagnante");
        }
        else{
            printf("\nBanque : perdante");
        }
}

int intPlayer(){
    int n=0;//nombre de joueur
    
    printf("Nombre de joueurs : ");
    scanf("%d",&n);
    
    int i,j=0;
    bjack b;
    bjack tab[PLAYER];
    int compteur[10];
    char nom[NOM]="\0";
    
    
    for(i=0;i<n;i++){
        printf("Entrez le nom du joueur %d : ",(i+1));
        scanf("%s",tab[i].nom);
        
    }
    system("cls");
    
    for(j=0;j<n;j++){
    printf("Joueur %d = %s\n",(j+1),tab[j].nom);
    }
    return(n);
    }

int aleaCarte(int t,int j){
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

 int Alpha(int n, bjack tab[(PLAYER)]){
     int i; // numéro joueur
     int c=0;
     int end=0;
     
    system("cls");
    for(i=0;i<n;i++){
    printf("Joueur %d \n",(i+1));
    c=aleaCarte(0,i);
    c=c+aleaCarte(1,i);
    tab[i].count = c;
    printf ("\n\nTotal = %d",c);
    if(c == 21){
        winBlack(i); 
        i=n;
        end=1;
    }  
    attente();
    
    system("cls");
    }
    return end ;
 }   

void Beta(int n,bjack tab[(PLAYER)],int a){
      int i; // numéro joueur
     int c=0;
     int choix=0;
    
    
    for(i=0;i<n;i++){
    system("cls");
    printf("Tour %d : \nJoueur %d \n",(a+2),(i+1));
    c = tab[i].count;
    printf ("\n\nTotal = %d",c);
    if(tab[i].done == 0){
    choix = choixCarte(i);
    if(choix ==1){
        c=c+aleaCarte(2+a,i);      
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

   void winBlack(int n){
      bjack tab[(PLAYER)];
      printf("\nBLACKJACK !\nC'est %s ,le joueur %d qui gagne",tab[(n+1)].nom,(n+1));
      tab[n].win = 1;
   }


   int choixCarte(int i){
    int choix = 0 ;
    int a=0;
    bjack tab[(PLAYER)];
    
     int c=0;
     if((tab[i].done)==0){
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

     
void bank(){ // La banque est le joueur n°10 (position 9 du tableau)
    bjack tab[(PLAYER)];
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
      tab[9].count = c;
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
        if(c2>=10){
            count=11;
        }
        else if(c2<10){
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
