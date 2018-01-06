/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: prico
 *
 * Created on 22 décembre 2017, 23:18
 */

#include "headermenu.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int id=1; //id fonction du nombre de joueurs, p du nombre de participants
    joueur rep[REP];
    initRep(rep);
    id=5;
    //liarDice(rep);
    id=choiceMainMenu(rep, id);

    return (EXIT_SUCCESS);
}