//declarations for all the required classes
#include "FullHealCard.h"
#include "Player.h"

// Constructor & Destructor for the FullHealCard class
FullHealCard::FullHealCard() : Card() {}
FullHealCard::~FullHealCard() {}

// Returns the name of the Full Heal card
std::string FullHealCard::name() 
{
	return "Full Heal";
}

// Applies the effect of the Full Heal card to the specified player
void FullHealCard::effect(Player* p) 
{
	// Restore the player's health to full
	p->heal();
}
