//declarations for all the required classes & standard library headers
#include "SwitcherooCard.h"
#include "Player.h"
#include <vector>

// Constructor & Destructor for SwitcherooCard
SwitcherooCard::SwitcherooCard() : Card() {}
SwitcherooCard::~SwitcherooCard() {}

// Returns the name of the card
std::string SwitcherooCard::name() 
{
	return "Switcheroo";
}

// Applies the effect of the card on the given player
void SwitcherooCard::effect(Player* player) 
{
	// Create a temporary vector to store the player's hand
	std::vector<Card*> tempHand = player->hand;

	// Swap the player's hand with their opponent's hand
	player->hand = player->getOpponent()->hand;
	player->getOpponent()->hand = tempHand;
}