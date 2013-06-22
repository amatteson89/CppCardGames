//
//  CardDeck.h
//  Card Game Set up
//
//  Created by Andrew Matteson on 10/28/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#ifndef __Card_Game_Set_up__CardDeck__
#define __Card_Game_Set_up__CardDeck__

#include <iostream>
#include <vector>
#include "PlayingCard.h"

using namespace std;

class CardDeck{
public:
    vector<string> deck;

    //Default 1 deck
    CardDeck();
    
    //param: enter number of decks
    //MIGHT NOT NEED
    CardDeck(int);
    

    /*Both of these are used in conjuction with the built in 
     * sort function.
    */
    static bool compareCards(string,string);
    static bool compareFaces(string,string);

    
    static int compareFacesInt(string,string);
    
    
    //Blackjack card values,  number = numbervalue, face = 10, ace = 11 (or 1 if necessary) 
    static int returnFaceValue(string);


};


#endif /* defined(__Card_Game_Set_up__CardDeck__) */
