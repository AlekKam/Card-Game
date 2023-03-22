#pragma once

//declarations for all the required classes
#include "Card.h"

class SpiteCard : public Card 
{
public:

	// Constructor & Destructor for the SpiteCard class
	SpiteCard();
	~SpiteCard();

	// Returns the name of the SpiteCard
	std::string name() override;
	// Applies the SpiteCard's effect to the player passed as an argument
	void effect(Player* p) override;
};

