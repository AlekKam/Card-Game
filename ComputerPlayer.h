#pragma once

//declarations for all the required classes
#include "Player.h"
#include "HumanPlayer.h"
#include <vector>

class ComputerPlayer : public Player 
{
public:
	// Constructor which takes in a pointer to a Player object as an argument
	ComputerPlayer(Player* opponent);
	// Virtual destructor
	virtual ~ComputerPlayer();

	// Overridden version of the myTurn function from the base Player class
	void myTurn() override;
};