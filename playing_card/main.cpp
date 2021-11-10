#include <iostream>
#include <stdlib.h>

#include "Deck.h"
#include "War.h"

void doWar(){
    War war;
    war.play();

}

void doDeck(){
    Deck deck;
    deck.shuffle();
    Card* test1 = deck.draw();
    test1->printCard();
}

int main(int argc, char **argv){
    doWar();
    
}