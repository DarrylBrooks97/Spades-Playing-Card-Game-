#include "Test2.h"

int main(){
	Moves moveObj;
	string temp;
	int playerScore;
	int computerScore;
	int i=0;
	bool t=true;
	bool f=false;
	
	moveObj.deckObj.setDeck();
	moveObj.deckObj.shuffleDeck();
	moveObj.setHands();
	cout<<string(60,'-')<<endl;
	cout<<string(15, ' ');
	cout<<"Welcome to the game of Spades"<<endl;
	cout<<string(60,'-')<<endl;
	cout<<"What is your name?"<<endl;
	cout<<"= ";
	getline(cin,temp);
	moveObj.setPlayerName(temp);
	cout<<"\nWhat would you like the computer name to be?"<<endl;
	cout<<"= ";
	getline(cin,temp);
	moveObj.setComputerName(temp);
	do 
    {
	 cout<<string(15,' ');
	 cout <<"Press Enter to begin the game"<<endl;
	} while (cin.get() != '\n');
	
	cin.ignore(100,'\n');

	while(i<27){
		cout<<moveObj<<endl;
		cin>>moveObj;
		moveObj.playerMove();
		++i;
	}

	playerScore = moveObj.getPlayerScore();         //Gets final score of player
	computerScore = moveObj.getComputerScore();     //Gets final score of computer
	 
	if(playerScore>computerScore){
		moveObj.setVictory(t);
	}else if(moveObj==moveObj){                     //Uses overload comparison operator 
		cout<<"TIE"<<endl;
	}else{
		moveObj.setVictory(f);
	}
	
	moveObj.printFinalResults();                    //Prints out who won

	
	return 0;
}
