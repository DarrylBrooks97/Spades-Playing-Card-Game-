#ifndef TEST2_H
#define TEST2_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

class Players {
	protected:
		vector<pair<string,string> > userHand;           //Users hand
	    vector<pair<string,string> > computerHand;           //Computer hand
		string playerName;
		string computerName;
		string playerSelection;                          //Player's requested card
		string suitPlayed;
	public:
		void setPlayerName(string);                     //Sets Player's name
		void setPlayerName();
		void setComputerName();                          
		string getPlayerName() const;                   //Gets Player's name 
		string getComputerName() const;                 // Gets computer player name 
		
};

class Deck{
	private:
		 vector<pair<string,string> > deck;
		 static string suit[4];
	public:
		 void setDeck(); 
		 vector<pair<string,string> > getDeck() const;
		 void shuffleDeck();                       //Will shuffle the Deck
		 string getSuit(int) const;                //Gets the suit 
};

class Moves: public Players {
	
	private:
		int playerPosition;                      //Shows which player is next
		bool victory;                            //Returns whether the player wins 
		int userCardPos;                         //Position of card in playerHand
		int computerCardPos;                     //Position of card in computerHand
		int playerScore;                         //Used to keep track of player's score
		int computerScore;                       //Used to keep track of computer's score
		static string motivationPrompts[];       //Used when the player plays a Spade and the computer has a different suit
	public:
		Moves();                                 //Default Constructor
		Moves(bool);                             //Constructor
		Deck deckObj;                            //Compostion Variable 
		const Deck constDeckObj;                 //Used to keep suits the same ****Constant composition variable
		friend ostream &operator<< (ostream &, Moves &);
		friend istream &operator >>(istream &, Moves &);
		void operator=(Moves&);                 // Assigns 
		bool operator==(Moves);                 //If scores are equal 
		static string pickPrompt();             //Static member function 
		vector<string> parse(string, char);     //Used to get the suit of user's played card
		string getSuit() const;                 //Will get the suit
		void setHands();                        //Deals both players cards (28 Each)
		void setComputerName(string);           //Overloads Parent constructor  
		void playerMove();                      //Checks to see if player card weights more than computer card   
		void setPlayerPosition();               //Sets the position 
		int getPlayerPostion() const;           //Gets the player's position
		
		void setVictory();                      
		void setVictory(bool);                   
		bool getVictory() const;                                      //Gets the victory private variable 
		vector<pair<string,string> > getPlayerHand() const;           //Retrieves hands from player
		vector<pair<string,string> > getComputerHand() const;         //Retrieves hand from computer
		void setPlayerScore();                                        //Sets score to 0
		int getPlayerScore() const;                                   //Gets the player's score
		void setComputerScore();                                      //Sets score to 0
		int getComputerScore() const ;                                //Gets the computer's score
		void printFinalResults();                                     //Prints the results of the game 
};




#endif
