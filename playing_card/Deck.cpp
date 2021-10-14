#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Deck.h"

#define NUM_CARDS_IN_SUIT 13
#define NUM_SUITS 4


Deck::Deck(int useless){
    for (int i = 0; i < NUM_SUITS; i++){
        for (int j = 2; j < NUM_CARDS_IN_SUIT + 1; j++){
            Card *card = new Card((Card::suit_e)i, (Card::value_e)j);
            this->deck.push_back(card);
        }
    }
}

Deck::~Deck(){
    for (int i = 0; i < this->deck.size(); i++){
        delete this->deck[i];
    }
}

void Deck::printDeck(){
    for (int i = 0; i < this->deck.size(); i++){
        this->deck[i]->printCard();
    }
}

void Deck::shuffle(){
    if (!this->deckStack.empty()){
        std::cout << "-----I'm not empty my man-----" << std::endl;
        do {deckStack.pop();} while (!deckStack.empty());
    }
    if (this->deckStack.empty()){
        std::cout << "-----I am indeed empty-----" << std::endl;
    }
    std::random_shuffle(this->deck.begin(), this->deck.end());
    for (int i = 0; i < this->deck.size(); i++){
        this->deckStack.push(this->deck[i]);
    }
}

Card* Deck::draw(){
    Card *tempCard = this->deckStack.top();
    this->deckStack.pop();
    return tempCard;
}


