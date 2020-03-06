#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>

#include "Player.h"

#define SIZE 19 // macros

using namespace std;

// declaring arrays to store the details of the players from the .txt file
int playerNumber[SIZE];
string name[SIZE];
string position[SIZE];
float minsPlayed[SIZE];
int goalScored[SIZE];
int gamesPlayed[SIZE];

// declaring an array of objects (players) of type Player
Player player[SIZE];

// function declarations
int menu(void);		// to access main menu
int search(void);	// to search for a particular player
int posit(void);	// to edit the position of a player
void mins(void);	// to edit the mins played by a player
void goals(void);	// to edit the number of goals scored by a player
void games(void);	// to edit the number of games played by a player
int update(void);	// to update the database (text file) with the user-edited values
void alert(void);	// to check if a player has played >= 20 minutes

int main() {
	string infileName, myString;
	string pN, n, p, mP, gS, gP;
	int h = 1, i = 1, j = 1, k = 1, l = 1, m = 1;

	ifstream inFile;
	infileName = "D:\\data.txt";
	inFile.open(infileName.c_str()); // open the file specified in the path

	if (!inFile) {
		cout << "Error opening file " << infileName << endl;
		return -1;
	}

	// reading the input file to get data on the players
	while (getline(inFile, myString)) {		// reading each line from input file and storing it in the string myString
		stringstream ss(myString);			// declaring a stringstream variable named ss

		getline(ss, pN, ',');				// read the ss string until it encounters a comma (delimiter) and then store it into the pN string variable
		playerNumber[h] = stoi(pN); ++h;	// store the pN string as an int, using stoi(), in (int)playerNumber array & increment i

		getline(ss, n, ',');				// read the ss string until it encounters a comma (delimiter) and then store it into the n string variable
		name[i] = n; ++i;					// store the n string in (string)name array & increment j

		getline(ss, p, ',');				// read the ss string until it encounters a comma (delimiter) and then store it into the p string variable
		position[j] = p; ++j;				// store the p string in (string)position array & increment k

		getline(ss, mP, ',');				// read the ss string until it encounters a comma (delimiter) and then store it into the mP string variable
		minsPlayed[k] = stof(mP); ++k;		// store the mP string as a float, using stof(), in (float)minsPlayed array & increment l

		getline(ss, gS, ',');				// read the ss string until it encounters a comma (delimiter) and then store it into the gS string variable
		goalScored[l] = stoi(gS); ++l;		// store the gS string as an int, using stoi(), in (int)goalScored array & increment m

		getline(ss, gP, ',');				// read the ss string until it encounters a comma (delimiter) and then store it into the gP string variable
		gamesPlayed[m] = stoi(gP); ++m;		// store the gP string as an int, using stoi(), in (int)gamesPlayed array & increment m
	}

	// Uncomment the line below for debugging, should print out all the player details, checking if the arrays have the correct values
	/*for (int i = 0 ; i < SIZE ; i++) {
		cout << playerNumber[i] << ',' << name[i] << ',' << position[i] << ',' << minsPlayed[i] << ',' << goalScored[i] << ',' << gamesPlayed[i] << endl;
	}*/

	// allocating the values in the arrays into the various player objects
	for (int i = 1 ; i < SIZE ; i++) {
		player[i].setPlayerNumber(playerNumber[i]);
		player[i].setName(name[i]);
		player[i].setPosition(position[i]);
		player[i].setMinsPlayed(minsPlayed[i]);
		player[i].setGoalScored(goalScored[i]);
		player[i].setGamesPlayed(gamesPlayed[i]);

		// Uncomment the line below for debugging, should print out all the players details, checking if the player objects have the correct values
		//cout << player[i].getPlayerNumber() << ',' << player[i].getName() << ',' << player[i].getPosition() << ',' << player[i].getMinsPlayed() << ',' << player[i].getGoalScored() << ',' << player[i].getGamesPlayed() << endl;
	}

	char choice;
	do {
		menu();		// call the main menu
		alert();	// check if a player has played for >= 20 mins
		update();
		cout << "---------------------------------------------------------------------------------------------" << endl;
		cout << "\n	To go Back to Menu	:	Enter 'm'" << endl;
		cout << "	To Exit Application	:	Enter Any Key" << endl;
		cout << "---------------------------------------------------------------------------------------------" << endl;
		cout << "	Answer: ";
		cin >> choice;
	} while (choice == 'm');

	inFile.close();
}

int menu(void) {
	char answer;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "\n	Welcome to the Football Coach Assistant" << endl;
	cout << "\n	Menu	1: Search for a Player's Details" << endl;
	cout << "		2: Edit the Position Played by a Player" << endl;
	cout << "		3: Input Minutes Played by a Player" << endl;
	cout << "		4: Input Goals Scored by a Player" << endl;
	cout << "		5: Input Games Played by a Player" << endl;
	cout << "		6: Exit Application" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "	Answer: ";
	cin >> answer;
	cin.ignore(); // clear the cin buffer to allow user input in the following functions
	
	switch (answer) {
	case '1':
		search();
		break;
	case '2':
		posit();
		break;
	case '3':
		mins();
		break;
	case '4':
		goals();
		break;
	case '5':
		games();
		break;
	case '6':
		return 0;
		break;
	default:
		cout << "\n	Invalid Answer! Please try again!" << endl;
		break;
	}
}

int search(void) {
	string Name;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "\n	Search Player Details" << endl;
	cout << "	Enter Player Name: ";
	getline(cin, Name);
	//cout <<"\nRecorded Name is: " << Name << endl;

	for (int i = 1 ; i < SIZE ; i++) {
		if (player[i].getName() == Name) {
			cout << "---------------------------------------------------------------------------------------------" << endl;
			cout << "\n	Player Number	: " << player[i].getPlayerNumber() << endl;
			cout << "	Player Name	: " << player[i].getName() << endl;
			cout << "	Position	: " << player[i].getPosition() << endl;
			cout << "	Mins Played	: " << player[i].getMinsPlayed() << endl;
			cout << "	Goal Scored	: " << player[i].getGoalScored() << endl;
			cout << "	Games Played	: " << player[i].getGamesPlayed() << endl;
			return 0;
		}
	}
	cout << "	You have entered an invalid name, please try again!" << endl;
}

int posit(void) {
	string Name;
	string old_p, new_p;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "\n	Inputting Position Played by a Player" << endl;
	cout << "	Enter the name of the player: ";
	getline(cin, Name);

	for (int i = 1; i < SIZE; i++) {
		if (player[i].getName() == Name) {
			old_p = player[i].getPosition();
			cout << "---------------------------------------------------------------------------------------------" << endl;
			cout << "\n	Please input the position played by this player: ";
			getline(cin, new_p); // using getline() instead of cin in order to handle whitespaces (spacebar) present in the position names
			if (new_p == "Goalkeeper" || new_p == "Centre Defender" || new_p == "Right Back" || new_p == "Left Back" || new_p == "Midfielder" || new_p == "Striker") {
				player[i].setPosition(new_p);
				cout << "---------------------------------------------------------------------------------------------" << endl;
				cout << "	Player " << player[i].getName() << "'s Position has been Changed from " << old_p << " to " << player[i].getPosition() << endl;
				return 0;
			}
			else {
				cout << "	You have entered an invalid position, please try again!" << endl;
				cout << "---------------------------------------------------------------------------------------------" << endl;
				cout << "	Options: Goalkeeper, Centre Defender, Right Back, Left Back, Midfielder, Striker" << endl;
				return 0;
			}
		}
	}
}
 
void mins(void) {
	string Name, temp_mP;
	float old_mP, new_mP;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "\n	Inputting Minutes Played by a Player" << endl;
	cout << "	Enter the name of the player: ";
	getline(cin, Name);

	for (int i = 1 ; i < SIZE ; i++) {
		if (player[i].getName() == Name) {
			old_mP = player[i].getMinsPlayed();
			cout << "---------------------------------------------------------------------------------------------" << endl;
			cout << "\n	Please input the minutes played by this player: ";
			cin >> new_mP;
			// getline(cin, temp_mP);
			// new_mP = stof(temp_mP);
			if (!cin.fail()) {
				player[i].setMinsPlayed(new_mP);
				cout << "---------------------------------------------------------------------------------------------" << endl;
				cout << "	Player " << player[i].getName() << "'s Minutes Played has been Changed from " << old_mP << " to " << player[i].getMinsPlayed() << endl;
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "	You have entered an invalid entry, please try again!" << endl;
				cout << "---------------------------------------------------------------------------------------------" << endl;
				cout << "	Please Only Enter Numbers with a Maximum of Only 2 Decimal Places" << endl;
			}
		}
	}
}

void goals(void) {
	string Name;
	int old_gS, new_gS;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "\n	Inputting Goals Scored by a Player" << endl;
	cout << "	Enter the name of the player: ";
	getline(cin, Name);

	for (int i = 1; i < SIZE; i++) {
		if (player[i].getName() == Name) {
			old_gS = player[i].getGoalScored();
			cout << "---------------------------------------------------------------------------------------------" << endl;
			cout << "\n	Please input the goals scored by this player: ";
			cin >> new_gS;
			if (!cin.fail()) {
				player[i].setGoalScored(new_gS);
				cout << "	Player " << player[i].getName() << "'s Goals Scored has been Changed from " << old_gS << " to " << player[i].getGoalScored() << endl;
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "	You have entered an invalid entry, please try again!" << endl;
				cout << "---------------------------------------------------------------------------------------------" << endl;
				cout << "	Please Only Enter Integers" << endl;
			}
		}
	}
}

void games(void) {
	string Name;
	int old_gP, new_gP;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "\n	Inputting Number of Games Played by a Player" << endl;
	cout << "	Enter the name of the player: ";
	getline(cin, Name);

	for (int i = 1; i < SIZE; i++) {
		if (player[i].getName() == Name) {
			old_gP = player[i].getGamesPlayed();
			cout << "---------------------------------------------------------------------------------------------" << endl;
			cout << "\n	Please input the number of games played by this player: ";
			cin >> new_gP;
			if (!cin.fail()) {
				player[i].setGamesPlayed(new_gP);
				cout << "	Player " << player[i].getName() << "'s Games Played has been Changed from " << old_gP << " to " << player[i].getGamesPlayed() << endl;
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "	You have entered an invalid entry, please try again!" << endl;
				cout << "---------------------------------------------------------------------------------------------" << endl;
				cout << "	Please Only Enter Integers" << endl;
			}
		}
	}
}

int update(void) {
	string outfileName;
	ofstream outFile;
	outfileName = "D:\\data.txt";
	outFile.open(outfileName.c_str());

	if (!outFile) {
		cout << "Error opening file " << outfileName << endl;
		return -1;
	}

	// outFile << "Player Number, Name, Position, Minutes Played, Goals Scored, Games Played" << endl;

	for (int i = 1; i <= SIZE-1; i++) {
		outFile << player[i].getPlayerNumber() << ',' << player[i].getName() << ',' << player[i].getPosition() << ',' << player[i].getMinsPlayed() << ',' << player[i].getGoalScored() << ',' << player[i].getGamesPlayed() << endl;
	}
	outFile.close();
}

void alert(void) {
	for (int i = 1; i <= SIZE-1; i++) {
		if (player[i].getMinsPlayed() >= 20) {
			// cout << i << endl;
			cout << "---------------------------------------------------------------------------------------------" << endl;
			cout << "	Player " << player[i].getName() << " has played " << player[i].getMinsPlayed() << " minutes!" << endl;
			cout << "	Time for a Substitution!" << endl;
		}
	}
}