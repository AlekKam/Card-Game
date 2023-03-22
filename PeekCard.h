#pragma once

//declarations for all the required classes
#include "Card.h"
#include "Player.h"

class PeekCard : public Card 
{
public:

	// Constructor & Destructor for the PeekCard class
	PeekCard();
	~PeekCard();

	// Returns the name of the PeekCard
	std::string name() override;
	// Applies the PeekCard's effect to the player passed as an argument
	void effect(Player* p) override;
};

