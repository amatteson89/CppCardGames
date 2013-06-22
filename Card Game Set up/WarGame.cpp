//
//  WarGame.cpp
//  Card Game Set up
//
//  Created by Andrew Matteson on 11/2/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#include "WarGame.h"



void WarGame::WarGameInterface(Dealer& dealer,vector<Player>& players,int& numPlayers){
    int numCardsPerPlayer = 52 / numPlayers;
    dealer.shuffleDeck();
    
    
    for(int i =0; i < numPlayers; i++){
        players[i].clearHand();
        players[i].dealtHand(dealer, numCardsPerPlayer);

    }
    

    string quitter;
    
    cout << "Welcome to the game of WAR!!!" << endl;

    while (true) {
        
        if(numPlayers ==1){
            cout << "The winner is " << players[0].getPlayerName() << "!!" << endl;
            return;
        }
        else if(numPlayers < 1){
            cout << "There were no winners!" << endl;
            return;
        }
        else{
            WarGame::combat(players, numPlayers);
        }
        

        cout << endl;
        cout << "Enter Q to quit, enter anything else for players to continue battling:";
        cin >> quitter;

        if(quitter == "Q" || quitter == "q")
            return;
        quitter = "";

       
        
    }

}




void WarGame::combat(vector<Player>& players, int& numPlayers){
    
    for(int i = 0; i < numPlayers; i++){
        players[i].displayHand();
    }
    
    if(numPlayers > 1){
        cardCombat(players, numPlayers);
    }
    
    
}




//NEED TO FIGURE OUT EXACTLY WHEN TO REMOVE THE TOP CARDS FROM THE PLAYERS!!!
void WarGame::cardCombat(vector<Player>& players, int &numPlayers){


    //This saves all the cards the winner of the hand will get
    vector<string> winnerCards;
    //this is used an an index store which saves which player[i] is the current leader
    int winnerNumber = 0;
    //This stores the number of players who currently are tied for the higest cards
    vector<Player> winner;
    
   

    
    
    do{
        
        
        for(int i = 0; i < numPlayers; i++ ){
            cout << players[i].getPlayerName() << "'s next card: " << players[i].displayTopCard() << endl;
            winnerCards.push_back(players[i].displayTopCard());
        }

        

        //Start by assuming the first person has the highest card
        winner.clear();
        winner.push_back(players[0]);
        players[0].removeTopCard();

        //Find the largest
        for(int i = 1; i < numPlayers; i++){
                //CARDS MATCH
            if( CardDeck::compareFacesInt(winner[0].displayTopCard(), players[i].displayTopCard()) == 0 ){
                winner.push_back(players[i]);
            }
            else if(CardDeck::compareFacesInt(winner[0].displayTopCard(), players[i].displayTopCard()) > 0){
                //Player i's card is bigger than the current highest
                winner.clear();
                winner.push_back(players[i]);
                winnerNumber = i;
            }
            else if (CardDeck::compareFacesInt(winner[0].displayTopCard(), players[i].displayTopCard()) < 0){
                //player i's card is lower than the current highest
                //do nothing
            }
            players[i].removeTopCard();
        }
        
        //if there is more than one player who wins AKA tie hand
        if(winner.size() > 1){
            cout << "There was a tie" << endl;
            cout << "Continuing combat" << endl;
        }
        else{
            cout << winner[0].getPlayerName() << " wins this hand!" << endl;
            for(int i = 0; i < winnerCards.size(); i ++){
                players[winnerNumber].addCard(winnerCards[i]);
                
            }
            winnerCards.clear();
        }
        
        for(int i = numPlayers - 1; i >= 0; i--){
            //If any player is now out of cards, they are out of the game
            if(players[i].numCardsInHand() < 1){
                cout << players[i].getPlayerName() << " loses and is ejected from the game" << endl;
                players.erase(players.begin() + i);
                numPlayers--;
            }
        }
     
    }while (winnerCards.size() > 0 && numPlayers > 1 );
    
    
    
    
   

    
    
}