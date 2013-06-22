//
//  Dealer.h
//  Card Game Set up
//
//  Created by Andrew Matteson on 10/28/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#ifndef __Card_Game_Set_up__Dealer__
#define __Card_Game_Set_up__Dealer__

#include <iostream>
#include <algorithm>
#include "CardDeck.h"



class Dealer{
private:
    CardDeck dealersDeck;
    int cardsDealt;
public:
    //DVC
    Dealer();

    
    //deal cards
    vector<string> dealCards(int);
    //shuffle deck
    void shuffleDeck();
    //update cards dealt
    void updateCardsDealt();
    
    //TESTER
    void numCardsInDeck();
    
    void newNumDecks(int);

};




#endif /* defined(__Card_Game_Set_up__Dealer__) */
