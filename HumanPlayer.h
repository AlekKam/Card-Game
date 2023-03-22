#pragma once

//declarations for all the required classes
#include "Player.h"
#include <vector>

class HumanPlayer : public Player 
{
public:

	// Constructor which takes in a pointer to a Player object as an argument
	HumanPlayer(Player* opponent);
	virtual ~HumanPlayer();

	// Overridden version of the myTurn function from the base Player class
	void myTurn() override;

};