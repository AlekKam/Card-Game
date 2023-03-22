#pragma once
//declarations for all the required classes
#include "Card.h"

class SwitcherooCard : public Card 
{
public:

	// Constructor & Destructor for the SwitcherooCard class
	SwitcherooCard();
	~SwitcherooCard();

	// Returns the name of the SwitcherooCard
	std::string name() override;

	// Applies the SwitcherooCard's effect to the player passed as an argument
	void effect(Player* p) override;
};
