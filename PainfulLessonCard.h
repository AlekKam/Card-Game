#pragma once

//declarations for all the required classes
#include "Card.h"

class PainfulLessonCard : public Card 
{
public:

	// Constructor & Destructor for the PainfulLessonCard class
	PainfulLessonCard();
	~PainfulLessonCard();


	// Returns the name of the PainfulLessonCard
	std::string name() override;

	// Applies the PainfulLessonCard's effect to the player passed as an argument
	void effect(Player* p) override;
};
