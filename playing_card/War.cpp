#include <iostream>
#include "War.h"

War::War(){
    this->deck;

}

War::~War(){

}

void War::play(){
    std::string playerName;

    Deck* playDeck;
    std::stack<Card*> playerHand;
    std::stack<Card*> computerHand;
    std::vector<Card*> playerDiscard;
    std::vector<Card*> computerDiscard;

    std::cout << "Welcome to WAR! Please enter your name: ";
    std::cin >> playerName;

    std::cout << "Hello, " << playerName << ". Let the WAR begin!" << std::endl << std::endl;

    std::cout << "about to deal cards" << std::endl;
    dealCards(playDeck, playerHand, computerHand);
    warCycle(playerHand, computerHand, playerDiscard, computerDiscard, playerName);


}

void War::dealCards(Deck* playDeck, std::stack<Card*> playerHand, std::stack<Card*> computerHand){
    std::cout << "Just got into dealing cards" << std::endl;
    playDeck->shuffle();
    std::cout << "shuffle good";
    while (!playDeck->deckStack.empty()){
        std::cout << "while top" << std::endl;
        Card *card = playDeck->draw();
        if (card != NULL){
            playerHand.push(card);
        } else {
            std::cout << "NULL player card" << std::endl;
        }
        
        card = playDeck->draw();
        if (card != NULL){
            computerHand.push(card);
        } else {
            std::cout << "NULL computer card" << std::endl;
        }
    }
    std::cout << "The cards have been dealt" << std::endl;
}

void War::warCycle(std::stack<Card*> playerHand, std::stack<Card*> computerHand, std::vector<Card*> playerDiscard, std::vector <Card*> computerDiscard, std::string playerName){
    std::cout << "The player draws: " << std::endl;
    Card* playerCard = playerHand.top();
    playerHand.pop();
    playerCard->printCard();

    std::cout << "The computer draws: " << std::endl;
    Card* computerCard = computerHand.top();
    computerHand.pop();
    computerCard->printCard();

    int result = playerCard->testValueEquality(computerCard);
    if (result > 0){
        std::cout << playerName << " wins the round!" << std::endl;
    } else if (result < 0){
        std::cout << "Computer wins the round!" << std::endl;
    } else if (result = 0){
        std::cout << "LET THERE BE WAR!" << std::endl;
    }
}