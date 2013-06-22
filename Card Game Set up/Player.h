//
//  Player.h
//  Card Game Set up
//
//  Created by Andrew Matteson on 10/28/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#ifndef __Card_Game_Set_up__Player__
#define __Card_Game_Set_up__Player__

#include <iostream>
#include <algorithm>
#include <vector>
#include "Dealer.h"

using namespace std;

class Player{
private:
    string name;
    vector<string> cardsInHand;
    
public:
    
    Player(string playerName);  //Constructor
    void sortHand();            //sort hand
    void displayHand();         //displays the complete hand/deck of the player
    string getPlayerName() const;      //returns name
    
    //Parameters ( dealer object, number of cards you want dealt)
    void dealtHand(Dealer &,int numCards);
    
    
    //THINGS ADDED FOR WAR
    //Displays the top card in the players  (WAR)
    string displayTopCard();
    //Remove top card in the players deck (WAR)
    void removeTopCard();
    void addCard(string);
    int numCardsInHand();
    
    

    void clearHand();
    
    //Changes the players cards to defined values
    //Used for testing various possible hands
    void cheater();
    

    
    
};



#endif /* defined(__Card_Game_Set_up__Player__) */
