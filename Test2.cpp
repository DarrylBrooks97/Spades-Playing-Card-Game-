#include "Test2.h"

string Deck::suit[4]= {"♠","♦","♣","♥"};           //Sets the static member 

void Moves::setPlayerPosition(){   //Player= 0  Computer= 1
	playerPosition =0;
}

string Moves::motivationPrompts[]={"Clever!","Smart Move!","You're Awesome","Good Job!"};      //Static Member 

string Moves::pickPrompt(){                                                        //Static member function 
	int k=0;
	srand(time(0));
	k = rand() % 4;
	return motivationPrompts[k];
}

void Players::setComputerName(){
	this->computerName= "Darryl";
}

void Moves::setComputerName(string name){
	this->computerName=name;
}

void Players::setPlayerName(string pName){
	playerName=pName;
}

void Players::setPlayerName(){
	playerName="Darryl";
}

string Players::getPlayerName() const{
	return playerName;
}

string Players::getComputerName() const{
	return computerName;
}


void Deck::setDeck(){                                                       //Placing Cards inside the deck
	for(int i=0;i<4;i++){
		
		for(int k=0;k<14;k++){
		   switch(k){
			   case 0:
				   deck.push_back(make_pair(suit[i],"1"));
				   break;
			   case 1:
				   deck.push_back(make_pair(suit[i],"2"));
				   break;
			   case 2:
				   deck.push_back(make_pair(suit[i],"3"));
				   break;
			   case 3:
				   deck.push_back(make_pair(suit[i],"4"));
				   break;
			   case 4:
				   deck.push_back(make_pair(suit[i],"5"));
				   break;
			   case 5:
				   deck.push_back(make_pair(suit[i],"6"));
				   break;
			   case 6:
				   deck.push_back(make_pair(suit[i],"7"));
				   break;
			   case 7:
				   deck.push_back(make_pair(suit[i],"8"));
				   break;
		       case 8:
				   deck.push_back(make_pair(suit[i],"9"));
				   break;
			   case 9:
				   deck.push_back(make_pair(suit[i],"10"));
				   break;
			   case 10:
				   deck.push_back(make_pair(suit[i],"J"));
				   break;
			   case 11:
				   deck.push_back(make_pair(suit[i],"Q"));
				   break;
			   case 12:
				   deck.push_back(make_pair(suit[i],"K"));
				   break;
			   default:
				   deck.push_back(make_pair(suit[i],"A"));
				   break;
		   }
		}
	}
}

vector<pair<string,string> > Deck::getDeck() const{
	return this->deck;
}

void Deck::shuffleDeck(){                                  //Shuffles Deck
	int randomIndex;
	vector<pair<string,string> > temp;
	temp.push_back(make_pair("",""));

	srand(time(0));
	for(int k=0;k<56;k++){
		randomIndex= rand() % deck.size();
		temp[0] = deck[k];
		deck[k] = deck[randomIndex];
		deck[randomIndex] = temp[0];
	}
}

string Deck::getSuit(int x) const{
	return suit[x];                               //Gets the suit from the static member 
}

int Moves::getPlayerPostion() const {
	return playerPosition;                        //Gets the playerPosition
}

void Moves::setVictory(){                         //Gets the victory status 
	this->victory=false;
}

void Moves::setVictory(bool temp){                //Sets the victory status 
	this->victory=temp;
}
bool Moves::getVictory() const{
	return this->victory;
}

void Moves::setHands(){                            //Deals the cards to the player and computer 
	
	string suit,value;
	vector< pair<string,string> > tempDeck;
	int minIndex,minVal;
	
	tempDeck = deckObj.getDeck();                             //Passes the true deck to a temp deck that will be deleted as cards are passed out 
	
	for(int i=tempDeck.size()-1;i>=0;i--){                    //First half to the user (28 cards) Second half to the computer 
		if(i>28){
			suit = tempDeck[i].first;
			value = tempDeck[i].second;
			userHand.push_back(make_pair(suit,value));
			tempDeck.pop_back();
		} else{
			suit = tempDeck[i].first;
			value = tempDeck[i].second;
			computerHand.push_back(make_pair(suit,value));
			tempDeck.pop_back();
		}
	}
	tempDeck.push_back(make_pair("",""));

	for(int k=0;k<5;k++){                    //Sorts players hand by suits 
		
		minIndex = k;
		tempDeck[0] = userHand[k];


		for(int j=k+1;j<userHand.size();j++){
			
			if(tempDeck[0]>userHand[j]){
				minIndex=j;
				tempDeck[0]=userHand[j];
			}
		}
		
		userHand[minIndex] = userHand[k];
		userHand[k] = tempDeck[0];
	}
	setPlayerScore();                      //Once haads are dealt the scores start off at 0
	setComputerScore();                    //Once haads are dealt the scores start off at 0
}

vector< pair<string,string> > Moves::getPlayerHand() const{
	return userHand;
}
vector< pair<string,string> > Moves::getComputerHand() const{
    return computerHand;
} 

vector<string> Moves::parse(string line, char delimiter){
    
    vector<string> parsedLine;
    istringstream stringStream(line); //create string stream from the line
   
    while (stringStream)//iterate through the stream
    { 
        string s;
        //uses getline to get the values from the stream before the delimiting character
        if (getline(stringStream, s, delimiter))
          parsedLine.push_back(s);
    }
    return parsedLine;
}             //Parses the user input for the suit they played 

ostream &operator<< (ostream & outF, Moves & moveObj){                   //Outputs the players hand and randomizes the computer's card's played 
	
	vector< pair<string,string> > playerHand;
	vector< pair<string,string> > computerHand;
	int randomIndex;

	playerHand = moveObj.getPlayerHand();
	srand(time(0));
	computerHand = moveObj.getComputerHand();
	moveObj.computerCardPos = rand() % computerHand.size(); 
	
	outF<<"Computer played card: "<<computerHand[moveObj.computerCardPos].first<<computerHand[moveObj.computerCardPos].second<<endl<<endl;
	moveObj.suitPlayed = computerHand[moveObj.computerCardPos].first;
	outF<<"Hand: ";
	 for(int k=0;k<playerHand.size();k++){
		 outF<<playerHand[k].first<<playerHand[k].second<<" ";
	 }
	outF<<"\n*******Copy and paste a card into the field below*******";
	outF<<"\n\nSelect a card to play: ";
	return outF;
}
bool Moves::operator==(Moves moveObj){
	return playerScore==moveObj.computerScore;                           //Compares scores 
}

istream &operator >>(istream & inF, Moves & moveObj){
	string wantedCard,userCard;
	moveObj.userCardPos=-1;
	vector<string> suitPlayed;
	int temp=0;
	int k=0;
	bool hasSuit = false;                                                    //Used to tell the program if the user has the suit or not
	
	while(moveObj.userCardPos==-1){
		
		inF>>moveObj.playerSelection;
		wantedCard = moveObj.playerSelection;
			for(int k=0;k<13;k++){                                                  //This is used to pause the user input by the suit played 
		   switch(k){
			   case 0:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'A');
				   break;
			   case 1:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'K');
				   break;
			   case 2:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'Q');
				   break;
			   case 3:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'J');
				   break;
			   case 4:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'1');  // For 10 and 1 
				   break;
			   case 5:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'9');
				   break;
			   case 6:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'8');
				   break;
			   case 7:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'7');
				   break;
		       case 8:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'6');
				   break;
			   case 9:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'5');
				   break;
			   case 10:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'4');
				   break;
			   case 11:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'3');
				   break;
			   default:
				   suitPlayed=moveObj.parse(moveObj.playerSelection,'2');
				   break;
		}
				if((suitPlayed[0]=="♠") || (suitPlayed[0]=="♣") || (suitPlayed[0]=="♦") || (suitPlayed[0]=="♦")){
					break;
				}
					
			}
		
		for(int j=0;j<moveObj.userHand.size();j++){                                    //Checks to see if the user has the computer's played suit
			if(moveObj.userHand[j].first==moveObj.computerHand[moveObj.computerCardPos].first){
				 hasSuit=true;
				 break;
			}
		}

		for(int k=0;k<moveObj.userHand.size();k++){                                  //Checks to see if used has the card being played 
				userCard = moveObj.userHand[k].first + moveObj.userHand[k].second;
				if(wantedCard==userCard) temp = k;
				else moveObj.userCardPos=-1;
		}

			if((moveObj.userHand[temp].first!=moveObj.computerHand[moveObj.computerCardPos].first) && (hasSuit==true)){          //If the player's suit is different but they have the computer's suit then loop until they play the right card 
				cout<<"\n";
				cout<<"Computer played card: "<<moveObj.computerHand[moveObj.computerCardPos].first<<moveObj.computerHand[moveObj.computerCardPos].second<<endl<<endl;
				cout<<"****You can only play the suit**"<<endl;
				cout<<"Hand: ";
				for(int k=0;k<moveObj.userHand.size();k++){
					 cout<<moveObj.userHand[k].first<<moveObj.userHand[k].second<<" ";
				}
				cout<<"\n*******Copy and paste a card into the field below*******"<<endl;
				cout<<"\nSelect a card to play: ";
				moveObj.userCardPos=-1;
			}else{
				moveObj.userCardPos=temp;
			} 

		}
	
	return inF;
}

void Moves::operator=(Moves&moveObj){
	victory=moveObj.getVictory();
}

void Moves::playerMove(){                                      //Logic of the game 
	vector< pair<string,string> > temp;
	temp.push_back(make_pair("",""));
	int k=0;
	
	if(((userHand[userCardPos].second=="A") && (computerHand[computerCardPos].second=="K")) || ((userHand[userCardPos].second=="A") && (computerHand[computerCardPos].second=="Q")) || ((userHand[userCardPos].second=="A") && (computerHand[computerCardPos].second=="J"))){ // A is bigger than K Q J
		cout<<"You won the book!"<<endl<<endl; ++playerScore;
	}else if(((userHand[userCardPos].second=="K") && (computerHand[computerCardPos].second=="A")) || ((userHand[userCardPos].second=="Q") && (computerHand[computerCardPos].second=="A")) || ((userHand[userCardPos].second=="J") && (computerHand[computerCardPos].second=="A"))){ //A is bigger than K Q J
		cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
	}else if(((userHand[userCardPos].second=="K") && (computerHand[computerCardPos].second=="Q")) || ((userHand[userCardPos].second=="K") && (computerHand[computerCardPos].second=="J"))){  //K is bigger than Q J
		cout<<"You won the book!"<<endl<<endl; ++playerScore;
	}else if(((userHand[userCardPos].second=="Q") && (computerHand[computerCardPos].second=="K")) || (((userHand[userCardPos].second=="J") && (computerHand[computerCardPos].second=="K")))){  //K is bigger than Q J
		cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
	}else if((userHand[userCardPos].first==constDeckObj.getSuit(0)) && (userHand[userCardPos].first!=computerHand[computerCardPos].first)){ //Spade is the better card *****Uses constant Data member "constDeckObj"
		srand(time(0));
		cout<<"You won the book!"<<endl<<endl; 
		cout<<pickPrompt()<<endl;
		++playerScore;
	}else if((computerHand[computerCardPos].first==constDeckObj.getSuit(0)) && (userHand[userCardPos].first!=computerHand[computerCardPos].first)){ //Spade is the better card ******Uses constant Data member "constDeckObj"
		cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
	}else if((computerHand[computerCardPos].first!=constDeckObj.getSuit(0)) && (userHand[userCardPos].first!=computerHand[computerCardPos].first)){ //An off suit is void 
		cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
	}else if(userHand[userCardPos].second>computerHand[computerCardPos].second){ 
		if((computerHand[computerCardPos].second=="10") && (userHand[userCardPos].second=="9")) {
			cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
		}else if((computerHand[computerCardPos].second=="10") && (userHand[userCardPos].second=="8")) {
			cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
		}else if((computerHand[computerCardPos].second=="10") && (userHand[userCardPos].second=="7")) {
			cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
		}else if((computerHand[computerCardPos].second=="10") && (userHand[userCardPos].second=="6")) {
			cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
		}else if((computerHand[computerCardPos].second=="10") && (userHand[userCardPos].second=="5")) {
			cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
		}else if((computerHand[computerCardPos].second=="10") && (userHand[userCardPos].second=="4")) {
			cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
		}else if((computerHand[computerCardPos].second=="10") && (userHand[userCardPos].second=="3")) {
			cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
		}else if((computerHand[computerCardPos].second=="10") && (userHand[userCardPos].second=="2")) {
			cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
		}else {
			cout<<"You won the book!"<<endl<<endl; ++playerScore;
	}
	}else if(userHand[userCardPos].second<computerHand[computerCardPos].second){
		if((userHand[userCardPos].second=="10") && (computerHand[computerCardPos].second=="9")) {
			cout<<"You won the book!"<<endl<<endl; ++playerScore;
		}else if((userHand[userCardPos].second=="10") && (computerHand[computerCardPos].second=="8")) {
			cout<<"You won the book!"<<endl<<endl; ++playerScore;
		}else if((userHand[userCardPos].second=="10") && (computerHand[computerCardPos].second=="7")) {
			cout<<"You won the book!"<<endl<<endl; ++playerScore;
		}else if((userHand[userCardPos].second=="10") && (computerHand[computerCardPos].second=="6")) {
			cout<<"You won the book!"<<endl<<endl;  ++playerScore;
		}else if((userHand[userCardPos].second=="10") && (computerHand[computerCardPos].second=="5")) {
			cout<<"You won the book!"<<endl<<endl; ++playerScore;
		}else if((userHand[userCardPos].second=="10") && (computerHand[computerCardPos].second=="4")) {
			cout<<"You won the book!"<<endl<<endl; ++playerScore;
		}else if((userHand[userCardPos].second=="10") && (computerHand[computerCardPos].second=="3")) {
			cout<<"You won the book!"<<endl<<endl;  ++playerScore;
		}else if((userHand[userCardPos].second=="10") && (computerHand[computerCardPos].second=="2")) {
			cout<<"You won the book!"<<endl<<endl; ++playerScore;
		}else {
			cout<<"Computer won the book..."<<endl<<endl; ++computerScore;
		}
	}
	
	temp[0]=userHand[userHand.size()-1];                                     //Erases the card as if it was played
	userHand[userHand.size()-1] = userHand[userCardPos];
	userHand[userCardPos] = temp[0];
	userHand.pop_back();
	
	temp[0] = computerHand[computerHand.size()-1];
	computerHand[computerHand.size()-1] = computerHand[computerCardPos];     //Erases the card as if it was played 
	computerHand[computerCardPos] = temp[0];
	computerHand.pop_back();
	
}

void Moves::setPlayerScore(){
	this->playerScore=0;
}

int Moves::getPlayerScore() const {
	return playerScore;
}

void Moves::setComputerScore(){
	this->computerScore=0;
}

int Moves::getComputerScore() const{
	return computerScore;
}

void Moves::printFinalResults(){
	
	if(getVictory()==true){
		cout<<string(26,'-')<<endl;
		cout<<string(10, ' ');
		cout<<motivationPrompts[3]<<" "<<getPlayerName()<<endl;                    //Uses static member in non static function
		cout<<"YOU WON"<<string(10,' ')<<endl;
		cout<<"YOUR SCORE: "<<getPlayerScore()<<endl;
		cout<<getComputerName()<<" SCORE: "<<getComputerScore()<<endl;
		cout<<string(26,'-')<<endl;
	}else {
		cout<<string(26,'-')<<endl;
		cout<<string(10, ' ');
		cout<<"YOU LOST"<<string(10,' ')<<endl;
		cout<<"YOUR SCORE: "<<getPlayerScore()<<endl;
		cout<<getComputerName()<<" SCORE: "<<getComputerScore()<<endl;
		cout<<string(26,'-')<<endl;
	}
}

