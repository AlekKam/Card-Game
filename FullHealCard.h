#pragma once

//declarations for all the required classes
#include "Card.h"

class FullHealCard : public Card 
{
public:
	// Constructor & Destructor for the FullHealCard class
	FullHealCard();
	~FullHealCard();

   // Returns the name of the FullHealCard
	std::string name() override;

	// Applies the FullHealCard's effect to the player passed as an argument
	void effect(Player* p) override;
};

