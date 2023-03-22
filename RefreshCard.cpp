//declarations for all the required classes & standard library headers
#include "RefreshCard.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include <random>

using namespace std;

// Constructor &  Destructor for RefreshCard
RefreshCard::RefreshCard() : Card() {}
RefreshCard::~RefreshCard() {}

// Returns the name of the card
std::string RefreshCard::name() 
{
	return "Refresh";
}

// Applies the effect of the card on the given player
// then shuffles their discard pile and adds it to their deck,
// then clears the discard pile
void RefreshCard::effect(Player* p) 
{
	// The player loses 3 health points
	p->loseHealth(3);

	// Get the player's discard pile
	std::vector<Card*> discard_pile = p->getDiscardPile();

	// Shuffle the discard pile
	std::random_shuffle(discard_pile.begin(), discard_pile.end());

	// Add the discard pile to the player's deck
	p->setDeck(discard_pile);

	// Clear the discard pile
	p->setDiscardPile({});
}