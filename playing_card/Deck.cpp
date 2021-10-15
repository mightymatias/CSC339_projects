#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Deck.h"

/**
 * Creates a standard deck of 52 cards.
 */
Deck::Deck(){
    for (int i = Card::suit_e::Club; i <= Card::suit_e::Spade; i++){
        for (int j = Card::value_e::Two; j <= Card::value_e::Ace; j++){
            Card *card = new Card((Card::suit_e)i, (Card::value_e)j);
            this->deck.push_back(card);
        }
    }
}

/**
 * Destroys a deck of crds.
 */
Deck::~Deck(){
    for (int i = 0; i < this->deck.size(); i++){
        delete this->deck[i];
    }
}

/**
 * Prints the full deck of cards, sorted. Used for debugging.
 */
void Deck::printDeck(){
    for (int i = 0; i < this->deck.size(); i++){
        this->deck[i]->printCard();
    }
}

/**
 * Shuffles the cards in a deck by adding them to the stack in a random order. Will also reset the amount of cards back to 52.
 */
void Deck::shuffle(){
    if (!this->deckStack.empty()){
        do {deckStack.pop();} while (!deckStack.empty());
    }
    std::random_shuffle(this->deck.begin(), this->deck.end());
    for (int i = 0; i < this->deck.size(); i++){
        this->deckStack.push(this->deck[i]);
    }
}

/**
 * Draws (returns) the top card off of the shuffled stack.
 * Returns NULL if there are no cards in the deck.
 */
Card* Deck::draw(){
    Card *tempCard = NULL;
    if (this->deckStack.empty()){
        return tempCard;
    }
    tempCard = this->deckStack.top();
    this->deckStack.pop();
    return tempCard;
}