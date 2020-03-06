
//* Player Implementation File *//
//* Contains Member Function Definitions for the Player Class *//

#include "Player.h"
#include <iostream>

using namespace std;

// Constructor Function
Player::Player() {}

// Destructor Function
Player::~Player() {}

// Function Definitions
void Player::setPlayerNumber(int pN) {
	playerNumber = pN;
}

int Player::getPlayerNumber() {
	return playerNumber;
}

void Player::setName(string n) {
	name = n;
}

string Player::getName() {
	return name;
}

void Player::setPosition(string p) {
	position = p;
}

string Player::getPosition() {
	return position;
}

void Player::setMinsPlayed(float mP) {
	minsPlayed = mP;
}

float Player::getMinsPlayed() {
	return minsPlayed;
}

void Player::setGoalScored(int gS) {
	goalScored = gS;
}

int Player::getGoalScored() {
	return goalScored;
}

void Player::setGamesPlayed(int gP) {
	gamesPlayed = gP;
}

int Player::getGamesPlayed() {
	return gamesPlayed;
}