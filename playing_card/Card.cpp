
#include <stdlib.h>
#include <iostream>
#include "Card.h"

Card::Card(suit_e suit, value_e value){
    this->suit = suit;
    this->value = value;
}

Card::~Card(){}

//If equal, return 0. If not, return 1
int Card::testSuitEquality(Card card){
    if (this->suit != card.suit){
        return -1;
    }
    else {
        return 0;
    }
}

/*
* If card is equal to card passed in, returns 0
* If card is greater than passed in, returns positive
* If card is less than passed in, returns negative
*/
int Card::testValueEquality(Card card){
    if (this->value < card.value){
        return -1;
    }
    if (this->value > card.value){
        return 1;
    }
    else {
        return 0;
    }
}

const char* Card::getSuit(){
    switch (this->suit){
        case Club:
            return "Club";
        case Diamond:
            return "Diamond";
        case Heart:
            return "Heart";
        case Spade:
            return "Spade";
    }
    return "Error";
}

const char* Card::getValue(){
    switch (this->value){
        case Two:
            return "2";
        case Three:
            return "3";
        case Four:
            return "4";
        case Five:
            return "5";
        case Six:
            return "6";
        case Seven:
            return "7";
        case Eight:
            return "8";
        case Nine:
            return "9";
        case Ten:
            return "10";
        case Jack:
            return "Jack";
        case Queen:
            return "Queen";
        case King:
            return "King";
        case Ace:
            return "Ace";
    }
    return "Error";
}

void Card::printCard(){
    std::cout << getValue() << " of " << getSuit() << "s" << std::endl;
}