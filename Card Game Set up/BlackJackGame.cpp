//
//  BlackJackGame.cpp
//  Card Game Set up
//
//  Created by Andrew Matteson on 11/3/12.
//  Copyright (c) 2012 Andrew Matteson. All rights reserved.
//

#include "BlackJackGame.h"


//GIVE THE DEALER 5 DECKS
void BlackJackGame::BlackJackGameInterface(Dealer dealer, vector<Player> players, int numPlayers){
    
    Player playerDealer("Dealer");
    
    //Change the amount of decks the dealer has to 5
    dealer.newNumDecks(5);


    string quitter;
    
    cout << endl << endl;
    cout << "Welcome to Blackjack!!" << endl;
    cout << endl;
    
    
    while (true) {
        dealer.shuffleDeck();

        playerDealer.clearHand();
        playerDealer.dealtHand(dealer, 2);

        for(int i = 0; i < numPlayers; i++){
            players[i].clearHand();
            players[i].dealtHand(dealer, 2);
        }

        
        
        for(int i = 0; i < numPlayers; i++){
            //Display the persons name, declaring their turn
            if(i == 0){
                cout << players[i].getPlayerName() << " goes first" << endl;
                cout << endl;
            }
            else{
                cout << players[i].getPlayerName() << " goes next" << endl;
                cout << endl;

            }
            
            //Show the dealers hand
            cout << playerDealer.getPlayerName()<< "'s hand: " << playerDealer.displayTopCard() << " **" << endl;

            //Show the current players hand
            players[i].displayHand();
            
            //Check the current player for a blackjack
            if( BlackJackGame::returnTotalHandValue(players[i]) == 21){
                cout << "You have a blackjack!" << endl;
            }
            
            //Options for player to hit or stay
            //quits when players hand value is too large
            while(BlackJackGame::returnTotalHandValue(players[i]) < 21){
                string option;
                
                
                cout << players[i].getPlayerName() << "'s hand value: " <<  BlackJackGame::returnTotalHandValue(players[i]) << endl;
                cout << "What would you like to do: hit or stay?" << endl;
                cin >> option;
                cout << endl;
                
                if(option == "hit"){
                    cout << "You chose hit!" << endl;
                    BlackJackGame::hit(dealer, players[i]);
                    players[i].displayHand();
                }
                else if(option == "stay"){
                    cout << "You chose stay" << endl;
                    //do nothing
                    break;
                }
                else{
                    cout << "Not an option, try again" << endl;
                }
                
            }
            
            
            if (BlackJackGame::returnTotalHandValue(players[i]) > 21) {
                cout << "You bust!" << endl;
            }
            if( i == numPlayers - 1){
                while (BlackJackGame::returnTotalHandValue(playerDealer) < 17) {
                    playerDealer.displayHand();
                    cout << playerDealer.getPlayerName() << "'s hand value:" <<  BlackJackGame::returnTotalHandValue(playerDealer) << endl;
                    cout << endl;
                    cout << playerDealer.getPlayerName() << " hits" << endl;
                    cout << endl;
                    BlackJackGame::hit(dealer, playerDealer);
                }
                
                //Show dealers hand
                playerDealer.displayHand();
                
                //Show dealers hand value
                cout << playerDealer.getPlayerName() << "'s hand value:" <<  BlackJackGame::returnTotalHandValue(playerDealer) << endl;
                
                
                if (BlackJackGame::returnTotalHandValue(playerDealer) > 21) {
                    cout << "Dealer busts, " << players[i].getPlayerName() << " wins!" << endl;
                    for(int i = 0; i < numPlayers; i++){
                        if(BlackJackGame::returnTotalHandValue(players[i]) < 22){
                            cout << players[i].getPlayerName() << " wins" << endl;
                        }
                        else{
                            cout << players[i].getPlayerName() << " loses" << endl;
                        }
                    }
                }
                else{
                    for(int i = 0; i < numPlayers; i++){
                        if( BlackJackGame::returnTotalHandValue(players[i]) == BlackJackGame::returnTotalHandValue(playerDealer)){
                            cout << players[i].getPlayerName() << " tie with " << playerDealer.getPlayerName() << endl;
                        }
                        else if (BlackJackGame::returnTotalHandValue(players[i]) > BlackJackGame::returnTotalHandValue(playerDealer)){
                            cout << players[i].getPlayerName() << " wins." << endl;
                        }
                        else{
                            cout << players[i].getPlayerName() << " loses." << endl;
                        }
                    }
                }
            }
        }
  
        
        
        
        
        cout << endl;
        cout << "Enter Q to quit, enter anything else to play again:";
        cin >> quitter;
        
        if(quitter == "Q" || quitter == "q")
            break;

        quitter = "";
        
    }
    
    cout << "Thanks for playing BlackJack!!" << endl;
}





int BlackJackGame::returnTotalHandValue(Player player1){
    int result = 0;
    int numCards = player1.numCardsInHand();
    int numAces = 0;
    
    for(int i = 0; i < numCards; i++){
        
        int temp = CardDeck::returnFaceValue(player1.displayTopCard());
     
        if( temp == 11 ){
            numAces++;
        }
        
        result += temp;
        player1.removeTopCard();
    }
    
    while(result > 22 && numAces > 0){
        for(int i = 0; i < numAces; i++){
            result -= 10;
            numAces--;
        }
    }
    
    return result;
}


void BlackJackGame::hit(Dealer& dealer, Player& player){
    vector<string> temp;
    
    temp = dealer.dealCards(1);
    
    player.addCard(temp[0]);
    
    
    
}

















