//
//  PlayingCard.h
//  Card Game Set up
//
//  Created by Andrew Matteson on 10/28/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#ifndef __Card_Game_Set_up__PlayingCard__
#define __Card_Game_Set_up__PlayingCard__

#include <iostream>
#include <vector>

using namespace std;


class PlayingCard{
private:
    vector<string> suits;
    vector<string> number;
public:
    PlayingCard();
    
    //Returns a deck of cards using every combination of numbers,suits
    vector<string> produceDeck();

    
};



#endif /* defined(__Card_Game_Set_up__PlayingCard__) */
