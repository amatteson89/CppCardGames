//
//  PlayingCard.cpp
//  Card Game Set up
//
//  Created by Andrew Matteson on 10/28/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#include "PlayingCard.h"


PlayingCard::PlayingCard(){
    //set up the suits for your game
    suits.push_back("D");
    suits.push_back("H");
    suits.push_back("C");
    suits.push_back("S");
    
    
    //set up the numbers you wish to use
    number.push_back("2");
    number.push_back("3");
    number.push_back("4");
    number.push_back("5");
    number.push_back("6");
    number.push_back("7");
    number.push_back("8");
    number.push_back("9");
    number.push_back("T");
    number.push_back("J");
    number.push_back("Q");
    number.push_back("K");
    number.push_back("A");
    
}



vector<string> PlayingCard::produceDeck(){
    vector<string> result;
    
    for(int i = 0; i < suits.size();i++){
        for(int j = 0; j < number.size();j++){
            result.push_back( number[j] + suits[i]);
        }
    }
    return result;
}