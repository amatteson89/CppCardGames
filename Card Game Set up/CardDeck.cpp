//
//  CardDeck.cpp
//  Card Game Set up
//
//  Created by Andrew Matteson on 10/28/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#include "CardDeck.h"


CardDeck::CardDeck(){
    PlayingCard cards;
    
    this->deck = cards.produceDeck();
    
}



//MIGHT NOT NEED
CardDeck::CardDeck(int numDecks){
    PlayingCard cards;
    vector<string> temp;
    
    
    for(int i = 0 ; i < numDecks; i ++) {
        temp = cards.produceDeck();
        for(int j = 0; j < temp.size(); j++){
            this->deck.push_back(temp[j]);
        }
        
    }

    
}


//First tries to compare the suits, if the suits are the same it sends the comparison off to CardDeck::compareFaces(string,string)
bool CardDeck::compareCards(string a,string b){
    int tempA = 0;
    int tempB = 0;

    /*DEBUG*/
    if(a == "" || b == ""){
        cout << "ERROR(cardDeck): a string is empty " << endl;
        return 0;
    }
    /******/
    
    
    if(a.substr(1,1) == "C")
        tempA = 0;
    else if (a.substr(1,1) == "D")
        tempA = 1;
    else if (a.substr(1,1) == "H")
        tempA = 2;
    else // == "S"
        tempA = 3;
    
    if(b.substr(1,1) == "C")
        tempB = 0;
    else if (b.substr(1,1) == "D")
        tempB = 1;
    else if (b.substr(1,1) == "H")
        tempB = 2;
    else    // == "S"
        tempB = 3;
    
    
    if(tempA == tempB)
        return CardDeck::compareFaces(a, b);
    return (tempA < tempB);
}



//The purpose of this is to convert strings which are representations of cards numbers/faces
//  into a numeric representation which allows us to compare them effectively
bool CardDeck::compareFaces(string a, string b){
    int tempA = 0;
    int tempB = 0;
    
    if( atoi(a.substr(0,1).c_str()) < 10 && atoi(a.substr(0,1).c_str()) > 0){
        tempA = atoi(a.substr(0,1).c_str());
    }
    else if (a.substr(0,1) == "T"){
        tempA = 10;
    }
    else if (a.substr(0,1) == "J"){
        tempA = 11;
    }
    else if (a.substr(0,1) == "Q"){
        tempA = 12;
    }
    else if(a.substr(0,1) == "K"){
        tempA = 13;
    }
    else{ // == "A"
        tempA = 14;
    }
 
    if( atoi(b.substr(0,1).c_str()) < 10 && atoi(b.substr(0,1).c_str()) > 0){
        tempB = atoi(b.substr(0,1).c_str());
    }
    else if (b.substr(0,1) == "T"){
        tempB = 10;
    }
    else if (b.substr(0,1) == "J"){
        tempB = 11;
    }
    else if (b.substr(0,1) == "Q"){
        tempB = 12;
    }
    else if(b.substr(0,1) == "K"){
        tempB = 13;
    }
    else{ // == "A"
        tempB = 14;
    }
    
    
    
    return (tempA <= tempB);
}






//ADD COMMENT
int CardDeck::compareFacesInt(string a, string b){
    int tempA = 0;
    int tempB = 0;
    
    if( atoi(a.substr(0,1).c_str()) < 10 && atoi(a.substr(0,1).c_str()) > 0){
        tempA = atoi(a.substr(0,1).c_str());
    }
    else if (a.substr(0,1) == "T"){
        tempA = 10;
    }
    else if (a.substr(0,1) == "J"){
        tempA = 11;
    }
    else if (a.substr(0,1) == "Q"){
        tempA = 12;
    }
    else if(a.substr(0,1) == "K"){
        tempA = 13;
    }
    else{ // == "A"
        tempA = 14;
    }
    
    if( atoi(b.substr(0,1).c_str()) < 10 && atoi(b.substr(0,1).c_str()) > 0){
        tempB = atoi(b.substr(0,1).c_str());
    }
    else if (b.substr(0,1) == "T"){
        tempB = 10;
    }
    else if (b.substr(0,1) == "J"){
        tempB = 11;
    }
    else if (b.substr(0,1) == "Q"){
        tempB = 12;
    }
    else if(b.substr(0,1) == "K"){
        tempB = 13;
    }
    else{ // == "A"
        tempB = 14;
    }
    
    
    
    return (tempB - tempA);
}






int CardDeck::returnFaceValue(string a){

    
    if( atoi(a.substr(0,1).c_str()) < 10 && atoi(a.substr(0,1).c_str()) > 0){
        return atoi(a.substr(0,1).c_str());
    }
    else if (a.substr(0,1) == "T"){
        return 10;
    }
    else if (a.substr(0,1) == "J"){
        return 10;
    }
    else if (a.substr(0,1) == "Q"){
        return 10;
    }
    else if(a.substr(0,1) == "K"){
        return 10;
    }
    else{ // == "A"
        return 11;
    }
    
    
}







