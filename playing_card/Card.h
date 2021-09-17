/*
//////TODO://////
* Figure out type for suit and value
    *Look into enums
*/

#ifndef CARD_H
#define CARD_H

class Card{
    public: //CONSTRUCTORS AND DECONSTRUCTORS
        Card(int suit, int value); //change types***
        ~Card();

    public: //methods
        int getSuit(); //change getsuit and getvalue type***
        int getValue();

    protected:
        int suit; //change types***
        int value;


};

#endif //CARD_H