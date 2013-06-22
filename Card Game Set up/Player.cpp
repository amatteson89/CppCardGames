//
//  Player.cpp
//  Card Game Set up
//
//  Created by Andrew Matteson on 10/28/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#include "Player.h"


Player::Player(string name){
    this -> name = name;
}





void Player::displayHand(){
    cout << name << "'s hand: ";
    for(int i = 0; i < this -> cardsInHand.size(); i++ ){
        cout << cardsInHand[i] << " " ;
    }
    cout << endl;
}






string Player::getPlayerName() const{
    return this->name;
}





void Player::sortHand(){
    int counter = 0;
    
    
    /* This finds all the pairs, 3 of a kind, 4 of a kind
     * the counter is used to tell which position we have sorted to
     *      (ie. counter = 2 means position 1 and position 0 have been 'sorted'
    */
    for(int i = 0; i < cardsInHand.size() - 1 ; i ++){
        vector<string> staticDummy = cardsInHand;
        for(int j = i + 1; j < cardsInHand.size(); j++){
            
            if(staticDummy[i].substr(0,1)== staticDummy[j].substr(0,1)){        //Found pair
                
                swap(cardsInHand[i],cardsInHand[counter]);
                counter++;

                swap(cardsInHand[j], cardsInHand[counter]);
                counter++;

                //check for 3 of a kind
                for(int k = j +1; k < cardsInHand.size();k++){
                    
                    //Found 3 of a ind
                    if(staticDummy[i].substr(0,1)== staticDummy[k].substr(0,1)){
                        swap(cardsInHand[k], cardsInHand[counter]);
                        counter++;
                        j = k; //So it doesn't check the same thing twice
                        
                        //check for 4 of a kind
                        for(int m = k + 1; m < cardsInHand.size();m++){
                            
                            //found 4 of a kind
                            if(staticDummy[i].substr(0,1) == staticDummy[m].substr(0,1)){
                                swap(cardsInHand[m], cardsInHand[counter]);                     
                                m = (int) cardsInHand.size();
                            }
                        }
                    }
                }
            }
        }
        //This is the key to this working
        //Without this it will check repeated things and possibly move them as well
        if(i < counter){
            i = counter - 1;
        }
    }
    
    
    
    
    /* The remaining will sort the cards first according to suit then according to number
     *  in order C, D, H, S  then in order 2 - A, ace being high
     *
     */    
    sort(cardsInHand.begin()+counter, cardsInHand.end(),CardDeck::compareCards);
    
    

    
}




string Player::displayTopCard(){
    //MAY WANT TO CHECK TO MAKE SURE THE DECK/HAND ISN'T EMPTY
    
    return cardsInHand[0];
    
}



void Player::removeTopCard(){
    //MAY WANT TO CHECK TO SEE IF THE DECK/HAND ISN'T EMPTY
    if(cardsInHand.size()  < 1){
        cout << "There are no more cards to remove";
        return;
    }
    
    vector<string> temp;
    
    
    //Use the temp string vector which has all the cards from cardsInHand minus the first one
    for(int i = 1; i < cardsInHand.size(); i++){
        temp.push_back(cardsInHand[i]);
    }
    
    clearHand();
    
    cardsInHand = temp;
    
}





void Player::addCard(string newCard){
    cardsInHand.push_back(newCard);
}





void Player::dealtHand(Dealer & host, int numCards){
    cardsInHand = host.dealCards(numCards);
}

int Player::numCardsInHand(){
    return (int)cardsInHand.size();
}






//Added this in to test certain hand situations
void Player::cheater(){
    cardsInHand.clear();
    cardsInHand.push_back("QH");
    cardsInHand.push_back("7H");
    cardsInHand.push_back("4D");
    cardsInHand.push_back("JD");
    cardsInHand.push_back("9S");
}


void Player::clearHand(){
    cardsInHand.clear();
}