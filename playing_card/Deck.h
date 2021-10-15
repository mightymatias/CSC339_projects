#ifndef DECK_H
#define DECK_H

#include <vector>
#include <stack>
#include "Card.h"


class Deck {
    public: //CONSTRUCTORS AND DESCONSTRUCTORS
        Deck(); 
        ~Deck();

    public: //METHODS
        void shuffle();
        Card* draw();
        void printDeck();

    protected:
        std::vector<Card*> deck;
        std::stack<Card*> deckStack;
};

#endif //DECK_H