#ifndef CARD_H
#define CARD_H

class Card{
    public: //eums
        enum suit_e{Club, Diamond, Heart, Spade};
        enum value_e{
            Two = 2, 
            Three, Four, Five, Six, Seven, Eight, 
            Nine, Ten, Jack, Queen, King, Ace
        };
    
    public: //CONSTRUCTORS AND DECONSTRUCTORS
        Card(suit_e suit, value_e value);
        ~Card();

    public: //methods
        const char* getSuit();
        const char* getValue();
        int testValueEquality(Card card);
        int testSuitEquality(Card card);
        void printCard();

    protected: //class variables
        suit_e suit;
        value_e value;
};
#endif //CARD_H