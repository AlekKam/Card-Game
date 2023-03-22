//declarations for all the required classes
#include "SpiteCard.h"
#include "Player.h"

// Constructor & Destructor for SpiteCard
SpiteCard::SpiteCard() : Card() {}
SpiteCard::~SpiteCard() {}

// Returns the name of the card
std::string SpiteCard::name() 
{
	return "Spite";
}

// Applies the effect of the card on the given player
void SpiteCard::effect(Player* p) 
{
	p->loseHealth(1);
	p->getOpponent()->loseHealth(1);
}