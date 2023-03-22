#pragma once

//declarations for all the required classes
#include "Card.h"

class RefreshCard : public Card 
{
public:

	// Constructor & Destructor for the RefreshCard class
	RefreshCard();
	~RefreshCard();

	// Returns the name of the RefreshCard
	std::string name() override;
	// Applies the RefreshCard's effect to the player passed as an argument
	void effect(Player* p) override;
};

