#ifndef DECK_H
#define DECK_H

#include <vector>
#include <stack>
#include "Card.h"


class Deck {
    public: //CONSTRUCTORS AND DESCONSTRUCTORS
        /*the classic "it shouldn't need a parameter,
        but when I remove the parameter,
        it doesn't work" */
        Deck(int useless); 
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