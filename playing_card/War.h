#ifndef WAR_H
#define WAR_H

#include <string>
#include <vector>
#include "Deck.h"

class War {
    public:
        War();
        ~War();

    public:
        void play();

    protected:
        Deck deck;
        void dealCards(Deck *playDeck, std::stack<Card*> playerHand, std::stack<Card*> computerHand);
        void refillHand(std::vector<Card*> discardPile, std::stack<Card*> hand);
        void warCycle(std::stack<Card*> playerHand, std::stack<Card*> computerHand, std::vector<Card*> playerDiscard, std::vector <Card*> computerDiscard, std::string playerName);

};

#endif //WAR_H