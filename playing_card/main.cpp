#include <iostream>
#include <stdlib.h>

#include "Deck.h"

/**
 * Draws ncards cards from the deck provided, and prints them to the console.
 */
void drawCardsFromDeck(int ncards, Deck &deck){
    for (int i = 0; i < ncards; i++){
        deck.draw()->printCard();
    }
}

int main(int argc, char **argv){
    //initialize deck
    Deck deck;

    //suffle and draw 10 cards twice
    deck.shuffle();
    drawCardsFromDeck(10, deck);

    std::cout << std::endl;
    
    deck.shuffle();
    drawCardsFromDeck(10, deck);
}