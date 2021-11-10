#include <iostream>
#include <random>
#include <algorithm>
#include "War.h"

War::War(){
    this->deck;
}

War::~War(){

}

/**
 * @brief All game logic is contained in this function
 * 
 */
void War::play(){
    deck = new Deck;
    std::string playerName;
    std::stack<Card*> *playerHand = new std::stack<Card*>;
    std::stack<Card*> *computerHand = new std::stack<Card*>;
    std::vector<Card*> *playerDiscard = new std::vector<Card*>;
    std::vector<Card*> *computerDiscard = new std::vector<Card*>;

    std::cout << "Welcome to WAR! Please enter your name: ";
    std::cin >> playerName;

    std::cout << "Hello, " << playerName << ". Let the WAR begin!" << std::endl << std::endl;

    dealCards(deck, playerHand, computerHand);
    std::cout << "(HINT!) If you see a new round line begin with ^, that means the players hand was just refilled with their discard pile!" <<
        " And if you see a * that means the same, but for the computer!" << std::endl;

    //while 0, play game. When 1, player wins. When -1, computer wins
    int winCondition = 0;
    char continueCondition = 'c';

    do{
        
        if (playerHand->empty() && playerDiscard->size() > 0) {
            std::cout << "^";
            refillHand(playerDiscard, playerHand);
        }
        if (computerHand->empty() && computerDiscard->size() > 0){
            std::cout << "*";
            refillHand (computerDiscard, computerHand);
        }
        if (playerHand->empty() && playerDiscard->size() == 0){
            winCondition = -1;
        }
        if (computerHand->empty() && computerDiscard->size() == 0){
            winCondition = 1;
        }
        warCycle(playerHand, computerHand, playerDiscard, computerDiscard, playerName);

        std::cout << "Should we play another round? c to continue, q to quit: ";
        std::cin >> continueCondition;

        if (continueCondition == 'q'){
            //refill the hands as we quit just to get a total "score"
            refillHand(playerDiscard, playerHand);
            refillHand(computerDiscard, computerHand);
            std::cout << "Player Cards Remaining: " << playerHand->size() << std::endl;
            std::cout << "Computer Cards Remaining: " << computerHand->size() << std::endl;
        }
    } 
    while(winCondition == 0 && continueCondition == 'c');

    if(winCondition == -1){
        std::cout << "THE COMPUTER WON!!!" << std::endl;
    }
    if(winCondition == 1){
        std::cout << "CONGRATULATIONS " << playerName << " YOU WON!!!" << std::endl;
    }
}

/**
 * @brief This method deals cards from a fresh deck to two players hands
 * 
 * @param playDeck the deck from which to deal
 * @param playerHand a reference to the player's hand
 * @param computerHand a reference to the computer's hand
 */
void War::dealCards(Deck* playDeck, std::stack<Card*> *playerHand, std::stack<Card*> *computerHand){
    std::cout << "Dealing cards to both the player and computer.." << std::endl;
    playDeck->shuffle();
    while (!playDeck->deckStack.empty()){
        Card *card = playDeck->draw();
        if (card != NULL){
            playerHand->push(card);
        } else {
            std::cout << "NULL player card" << std::endl;
        }
        
        card = playDeck->draw();
        if (card != NULL){
            computerHand->push(card);
        } else {
            std::cout << "NULL computer card" << std::endl;
        }
    }
    std::cout << "The cards have been dealt" << std::endl << std::endl;
}
/**
 * @brief The main game loop
 * 
 * @param playerHand a reference to the players hand which contains cards
 * @param computerHand a reference to the computers hand which contains cards
 * @param playerDiscard a reference to the players discard pile
 * @param computerDiscard a reference to the computers discard pile
 * @param playerName the players name
 */
void War::warCycle(std::stack<Card*> *playerHand, std::stack<Card*> *computerHand, std::vector<Card*> *playerDiscard, std::vector <Card*> *computerDiscard, std::string playerName){
    std::cout << "-----------------" << std::endl;
    std::cout << "The player draws: ";
    Card* playerCard = playerHand->top();
    playerHand->pop();
    playerCard->printCard();
    std::cout << std::endl;

    std::cout << "The computer draws: ";
    Card* computerCard = computerHand->top();
    computerHand->pop();
    computerCard->printCard();
    std::cout << std::endl;

    int result = playerCard->testValueEquality(computerCard);
    if (result > 0){
        std::cout << playerName << " wins the round!" << std::endl;
        playerDiscard->push_back(playerCard);
        playerDiscard->push_back(computerCard);
    } else if (result < 0){
        std::cout << "Computer wins the round!" << std::endl;
        computerDiscard->push_back(playerCard);
        computerDiscard->push_back(computerCard);
    } else {
        int warResult = warTime(playerHand, computerHand, playerDiscard, computerDiscard, playerName);
        if (warResult == 1){
            std::cout << playerName << " wins the war!" << std::endl;
            playerDiscard->push_back(playerCard);
            playerDiscard->push_back(computerCard);
        }
        if (warResult == -1){
            std::cout << "Computer wins the war!" << std::endl;
            computerDiscard->push_back(playerCard);
            computerDiscard->push_back(computerCard);
        }
    }
}

void War::refillHand(std::vector<Card*> *discardPile, std::stack<Card*> *hand){
    std::random_device  rd;
    std::mt19937 rng(rd());
    std::shuffle(discardPile->begin(), discardPile->end(), rng);
    int numCard = discardPile->size();

    for (int i = 0; i < numCard; i++){
        Card* testCard = discardPile->at(0);
        hand->push(testCard);
        discardPile->erase(discardPile->begin());
    }
}

int War::warTime(std::stack<Card*> *playerHand, std::stack<Card*> *computerHand, std::vector<Card*> *playerDiscard, std::vector <Card*> *computerDiscard, std::string playerName){
    int warResult;
    //If the player or computer don't have enough cards, but there are cards in their discard, shuffle discard into hand
    if (playerHand->size() < 2 && playerDiscard->size() > 0){
        refillHand(playerDiscard, playerHand);
    }
    else if (computerHand->size() < 2 && computerDiscard->size() > 0){
        refillHand(computerDiscard, computerHand);
    }
    //if player or computer don't have enough cards, and no cards in their discard, that person loses the war
    else if (playerHand->size() < 2){
        return -1;
    }
    else if (computerHand->size() < 2){
        return 1;
    }
    //if they both have the cards, we war!
    else {
        std::cout << ">>>>LET THERE BE WAR!<<<<<" << std::endl;
        //grabbing the cards that are in escrow during the war
        std::vector<Card*> escrowCards;
        Card* cardA = playerHand->top();
        playerHand->pop();
        Card* cardB = computerHand->top();
        computerHand->pop();

        std::cout << "The additional cards you are fighting for:" << std::endl;
        cardA->printCard();
        cardB->printCard();
        std::cout << std::endl;

        //getting the cards we are going to actually compare to see who wins the war
        Card* playerWarCard = playerHand->top();
        playerHand->pop();
        std::cout << playerName << "'s Champion for this war is: ";
        playerWarCard->printCard();
        std::cout << std::endl;
        Card* computerWarCard = computerHand->top();
        computerHand->pop();
        std::cout <<"The computer's Champion for this war is: ";
        computerWarCard->printCard();
        std::cout << std::endl;

        //compare the cards to see who wins, or if we are recursively warring
        int result = playerWarCard->testValueEquality(computerWarCard);
        if (result > 0){
            playerDiscard->push_back(playerWarCard);
            playerDiscard->push_back(computerWarCard);
            playerDiscard->push_back(cardA);
            playerDiscard->push_back(cardB);
            warResult = 1;
        } 
        else if (result < 0){
            computerDiscard->push_back(playerWarCard);
            computerDiscard->push_back(computerWarCard);
            playerDiscard->push_back(cardA);
            playerDiscard->push_back(cardB);
            warResult = -1;
        } 
        else {
            std::cout << "!>!>!>LET THERE BE more WAR<!<!<!" << std::endl;
            warResult = warTime(playerHand, computerHand, playerDiscard, computerDiscard, playerName);
        }
    } 
    return warResult;
}