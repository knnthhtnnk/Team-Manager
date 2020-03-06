
//* Player Header File *//
//* Contains Player Class Definitions & Functions *//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
	private:
		int playerNumber;
		string name;
		string position;
		float minsPlayed;
		int goalScored;
		int gamesPlayed;

	public:
		// Constructor
		Player();
		
		// Destructor
		~Player();

		// Functions
		void setPlayerNumber(int);
		int getPlayerNumber();

		void setName(string);
		string getName();

		void setPosition(string);
		string getPosition();

		void setMinsPlayed(float);
		float getMinsPlayed();

		void setGoalScored(int);
		int getGoalScored();

		void setGamesPlayed(int);
		int getGamesPlayed();
};

#endif