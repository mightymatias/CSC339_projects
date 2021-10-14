#include <iostream>
#include <stdlib.h>

#include "Card.h"
#include "Deck.h"

/**
 * Helps to test the equality of the suit of two cards.
 * Full documentation of the comparison function can be found in Card.cpp
 */
void suitEqualityTestHelper(Card card, Card compareCard){
    std::cout << "The cards: " << std::endl; 
    card.printCard();
    std::cout << "and" << std::endl;
    compareCard.printCard();
    if (card.testSuitEquality(compareCard) == 0){
        std::cout << "HAVE the same suit" << std::endl;
    }
    else if (card.testSuitEquality(compareCard) < 0){
        std::cout << "DO NOT HAVE the same suit" << std::endl;
    }
    else {
        std::cout << "Some error has occured in Suit Equality" << std::endl;
    }
}

/**
 * Helps to test the equality of the value of two cards.
 * Full documentation of the comparison function can be found in Card.cpp
 */
void valueEqualityTestHelper(Card card, Card compareCard){
    std::cout << "The cards: " << std::endl; 
    card.printCard();
    std::cout << "and" << std::endl;
    compareCard.printCard();
    if (card.testValueEquality(compareCard) == 0){
        std::cout << "have the SAME VALUE" << std::endl;
    }
    else if (card.testValueEquality(compareCard) < 0){
        std::cout << "the 1st card is SMALLER THAN the 2nd card" << std::endl;
    }
    else if (card.testValueEquality(compareCard) > 0){
        std::cout << "the 1st card is LARGER THAN the 2nd card" << std::endl;
    }
    else {
        std::cout << "Some error has occured in Value Equality" << std::endl;
    }
}

/**
 * Draws ncards cards from the deck provided, and prints them to the console.
 */
void drawCardsFromDeck(int ncards, Deck &deck){
    for (int i = 0; i < ncards; i++){
        deck.draw()->printCard();
    }
}

/**
 * Main method code from the first assignment. Keeping it for memory's sake
 */
void assignmentOne(){
    //create 5 cards
    Card card1(Card::Diamond, Card::Five);
    Card card2(Card::Diamond, Card::Two);
    Card card3(Card::Heart, Card::Five);
    Card card4(Card::Spade, Card::Ace);
    Card card5(Card::Club, Card::Jack);
    
    //print each to std out
    card1.printCard();
    card2.printCard();
    card3.printCard();
    card4.printCard();
    card5.printCard();
    std::cout << std::endl << std::endl;

    //suit equality demo
    suitEqualityTestHelper(card1, card2);
    std::cout << std::endl;
    suitEqualityTestHelper(card1, card3);
    std::cout << std::endl << std::endl;

    //value equality demo
    valueEqualityTestHelper(card1, card2);
    std::cout << std::endl;
    valueEqualityTestHelper(card1, card3);
    std::cout << std::endl;
    valueEqualityTestHelper(card1, card4);
}

int main(int argc, char **argv){
    //initialize deck
    Deck deckUno(1);

    //suffle and draw 10 cards twice
    deckUno.shuffle();
    drawCardsFromDeck(10, deckUno);

    std::cout << std::endl;
    
    deckUno.shuffle();
    drawCardsFromDeck(10, deckUno);
    
    
    
}