//
//  WarGame.h
//  Card Game Set up
//
//  Created by Andrew Matteson on 11/2/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#ifndef __Card_Game_Set_up__WarGame__
#define __Card_Game_Set_up__WarGame__

#include <iostream>
#include "Player.h"
#include "Dealer.h"


class WarGame{

public:
    static void WarGameInterface(Dealer&, vector<Player>&, int&);
    static void combat(vector<Player>&, int&);
    
private:
    static void cardCombat(vector<Player> &, int&);
    
    
};



#endif /* defined(__Card_Game_Set_up__WarGame__) */
