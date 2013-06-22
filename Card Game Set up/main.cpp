/*
    Name: Andrew Matteson
    Date:11/7/12
    IDE built using: Xcode 4.5.1
    CSCD 305 C++ Programming
    Assignment 2
 
 
 PT I:
         Program Description:
            Write the following classes.  Expect to use these classes for various card games (poker, bridge, blackjack, solitaire, hearts, pinochle, etc.)
            A playingCard class
            a dealer class
            a player class
         
            Create a main program that ends up with a dealer dealing a deck of 52 cards to two players.  Have the players sort their cards by pairs, three of a kinds, and four of a kinds - the other cards should be sorted according to suit and number (clubs, diamonds, hearts, spades, ace high).  Each player should display their hands in some manner.  Let the application loop, reshuffling and redealing and redisplaying until the user types 'q' to quit.
         
         
         Notes:
            The part where the program sorts the cards doesn't card in what order the pairs, 3 of a kinds and 4 of a kinds are in. Even though it is currently set to deal 26 cards to each player, it was built with the intent of dealing much fewer cards.
         
 PT II:
        Use your classes from last week to create two card games.  War and BlackJack.  Turn in all of your files and a makefile (which we will talk about on Monday).  tarred and with documentation about how to make and use them.  In your documentation, please also write a small design document about how to create a game where the deal of cards switches between players.
            The game can just be run, please let the user press a key to make the next turn happen.
 
 */

#include <iostream>
#include <algorithm>
#include "Dealer.h"
#include "Player.h"
#include "WarGame.h"
#include "BlackJackGame.h"

using namespace std;

//Used for testing War
// const int HANDSPLAYED = 100;


int main()
{
    
    Dealer dealer;
    int numPlayers = 0;
    string playerName;
    string gameChoice;
    
    vector<Player> players;
    //Used since my War games removes players as they are being deleted and needed a way to reset them when war was done
    vector<Player> copyPlayers;
    int copyNumPlayers;
    
    
    cout << "How many players would you like? " << endl;
    cin >> numPlayers;
    

    
    for (int i = 0; i < numPlayers; i++) {
        cout << "Enter the name of player " << i + 1 << " : " << endl;
        cin >> playerName;
        players.push_back(Player(playerName));
        copyPlayers.push_back(Player(playerName));
    }
    
    copyNumPlayers = numPlayers;
    
    cout << "Welcome ";
    
    for ( int i = 0; i < numPlayers; i++){
        if(i + 1 < numPlayers){
            cout << players[i].getPlayerName() << ", ";
        }
        else{
            cout << "and " << players[i].getPlayerName() << ".";
        }
    }
    cout << endl;
    cout << "Let the games begin!" << endl;
    
    
    
    while(true){
        //Reset players
        players.clear();
        numPlayers = copyNumPlayers;
        for(int i = 0; i < numPlayers;i++){
            players.push_back(Player(copyPlayers[i].getPlayerName()));
        }
        
        
        
        cout << endl << endl;
        cout << "What game would you like to play? " << endl;
        cout << "1) BlackJack" << endl;
        cout << "2) War (Players required: 2+ )" << endl;
        cout << "Enter 1 or 2 to choose or 'q' to quit" << endl;
        cin >> gameChoice;
        
        if(gameChoice == "1"){
            cout << "you want to play blackjack!" << endl;
            BlackJackGame::BlackJackGameInterface(dealer, players, numPlayers);
        }
        else if(gameChoice == "2"){
            if(numPlayers < 2){
                cout << "You don't have enough players" << endl;
            }
            else{
                cout << "you want to play war!" << endl;
                WarGame::WarGameInterface(dealer, players, numPlayers);
            }

        }
        else if (gameChoice == "q" || gameChoice == "Q") {
            break;
        }
        else{
            cout << "Not a valid input choice, try again" << endl;
        }
        

    }
    

    cout << endl << "Program closing..." << endl;
    
    
    
    
    
    

    
    
    
    
    
    /* START BLACKJACK SIMULATOR
    
    Dealer dealer;
    string playerOneName;
    string playerTwoName;
    
    cout << "What is the name of player 1: " << endl;
    cin >> playerOneName;
    Player player1(playerOneName);
    
    
    
    //Turned off for the time being to test blackjack game
    while(false){
        cout << "What is the name of player 2: " << endl;
        cin >> playerTwoName;
        Player player2(playerTwoName);
        WarGame::WarGameInterface(dealer, player1, player2);
    }
    
    BlackJackGame::BlackJackGameInterface(dealer, player1);
    
      END BLACKJACK SIMULATOR */
    
    
    
    
    
    
    /* BEGIN WAR SIMULATOR   
    Dealer dealer;
    string playerOneName = "one";
    string playerTwoName = "two";
    string quitter;
    int numHandsPlayed = 0;
    int gamesFinished = 0;
    int gamesTied = 0;
    
//    cout << "What is the name of player 1: " << endl;
//    cin >> playerOneName;
//    
//    cout << "What is the name of player 2: " << endl;
//    cin >> playerTwoName;
    
    Player player1(playerOneName);
    Player player2(playerTwoName);
    
    

    
    while (gamesFinished + gamesTied < 20) {

        dealer.shuffleDeck();
        player1.clearHand();
        player2.clearHand();
        player1.dealtHand(dealer, 26);
        player2.dealtHand(dealer, 26);
        numHandsPlayed = 0;
        

        while (player1.numCardsInHand() > 0 && player2.numCardsInHand() > 0 && numHandsPlayed < HANDSPLAYED) {
            cout << "before combat" << endl;
            player1.displayHand();
            player2.displayHand();
        
        
            WarGame::combat(player1, player2);
        
            cout << "after combat" << endl;
            player1.displayHand();
            player2.displayHand();
            
            numHandsPlayed++;
            cout << "Hands played: " << numHandsPlayed << endl;
            
            if (numHandsPlayed == HANDSPLAYED) {
                cout << "The game is a tie" << endl;
                gamesTied++;
            }
            else if(player1.numCardsInHand() < 1 || player2.numCardsInHand() < 1)
            {
                gamesFinished++;   
            }
        

    //        cout << endl;
    //        cout << "Enter Q to quit, enter anything else to continue." << endl;
    //        cin >> quitter;
    //        
    //        if(quitter == "Q" || quitter == "q")
    //            break;
        }
        
        cout << "Games tied: " << gamesTied << endl;
        cout << "Games finished: " << gamesFinished << endl;
    }
        
    
    */ /*END WAR GAME SIMULATOR */
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    // BEGIN ASSIGNMENT 1 TESTER
     
    Dealer dealer;
    string playerOneName;
    string playerTwoName;
    string quitter;
    
    

    
    cout << "What is the name of player 1: " << endl;
    cin >> playerOneName;
    
    cout << "What is the name of player 2: " << endl;
    cin >> playerTwoName;
    
    Player player1(playerOneName);
    Player player2(playerTwoName);
    
    while(true){
    
        player1.dealtHand(dealer, 26);
        player2.dealtHand(dealer, 26);
        
        cout << endl;
        cout << "Hands before sorting" << endl;

        player1.displayHand();
        player2.displayHand();
    
        player1.sortHand();
        player2.sortHand();

        cout << endl;
        cout << "Hands after Sorting" << endl;
      
        player1.displayHand();
        player2.displayHand();

    
        cout << endl;
        cout << "Enter Q to quit, enter anything else to continue." << endl;
        cin >> quitter;
        
        if(quitter == "Q" || quitter == "q")
            break;
        
        cout << "Quitter before clear : " << quitter << endl;
        quitter = ""; //RESET quitter;
        cout << "quitter after clear : " << quitter << endl;
        

        player1.clearHand();
        player2.clearHand();
        dealer.shuffleDeck();
        
    }
    
     */ //END ASSIGNMENT ONE TESTER

    
    return 0;
}



















