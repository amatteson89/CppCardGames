//
//  BlackJackGame.h
//  Card Game Set up
//
//  Created by Andrew Matteson on 11/3/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#ifndef __Card_Game_Set_up__BlackJackGame__
#define __Card_Game_Set_up__BlackJackGame__

#include <iostream>
#include "Dealer.h"
#include "Player.h"

class BlackJackGame{
private:
    static void hit(Dealer&, Player&);

public:
    static void BlackJackGameInterface(Dealer, vector<Player>,int);
    
    static int returnTotalHandValue(Player);
    
    
};





#endif /* defined(__Card_Game_Set_up__BlackJackGame__) */
