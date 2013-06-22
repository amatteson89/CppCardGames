//
//  Dealer.cpp
//  Card Game Set up
//
//  Created by Andrew Matteson on 10/28/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#include "Dealer.h"



Dealer::Dealer(){
    
    shuffleDeck();
    cardsDealt = 0;
}




vector<string> Dealer::dealCards(int numCards){
    vector<string> result;
    int cardsDealtPrior = cardsDealt;
    
    for(int i = 0; i < numCards; i++){
        if(cardsDealt == dealersDeck.deck.size()){
            cout << "Error: too many cards distributed" << endl;
            return result;
        }
        
        
        result.push_back(dealersDeck.deck[cardsDealtPrior + i]);
        cardsDealt++;
        
    }

    
    return result;
}





//Note: Don't shuffle if the user has cards
void Dealer::shuffleDeck(){

    
    srand( (unsigned)time(NULL));
    
    //Fisher-Yates Shuffle
    //http://en.wikipedia.org/wiki/Fisher–Yates_shuffle
    for(int i = (int)dealersDeck.deck.size() - 1; i > 0; i--){
        int j = rand() % i;
        string temp = dealersDeck.deck[i];
        dealersDeck.deck[i] = dealersDeck.deck[j];
        dealersDeck.deck[j] = temp;
        
    }
    
    //Reset the number of cards dealt
    cardsDealt = 0;
}





void Dealer::numCardsInDeck(){
    cout << "number of cards in deck:" << dealersDeck.deck.size() << endl;
}



void Dealer::newNumDecks(int numDecks){

    CardDeck newCards(5);
    
    this->dealersDeck = newCards;
}