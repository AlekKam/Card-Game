//declarations for all the required classes & standard library headers
#include "Player.h"
#include <iostream>
#include "PeekCard.h"

// Constructor & Destructor for the PeekCard class
PeekCard::PeekCard() : Card() {}
PeekCard::~PeekCard() {}

// Function returning the name of the PeekCard
std::string PeekCard::name() 
{
	return "Peek";
}

// Function implementing the effect of the PeekCard on the player passed as argument
void PeekCard::effect(Player* p)
{
	// Print the name of the top card in the player's deck
	std::cout << "Top card in your deck: " << p->deck.back()->name() << std::endl;
}