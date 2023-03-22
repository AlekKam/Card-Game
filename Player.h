#pragma once

//declarations for all the required classes
#include <vector>

using namespace std;

class Card;

class Player 
{
public:
	// Constructor which takes in a pointer to a Player object as an argument
	Player(Player* opponent);
	virtual ~Player();

	// Pointer to the player's opponent
	Player* opponent;

	// The player's current health
	int health;

	// Decreases the player's health by the specified amount
	void loseHealth(int i);

	// Draws a card from the player's deck and adds it to their hand
	// Returns true if a card was drawn, false otherwise
	bool drawCard();

	// Plays the specified card
	void playCard(Card* c);

	// Player's turn in the game
	virtual void myTurn() = 0;

	// Returns true if the player has lost, false otherwise
	bool hasLost();

	// Restores the player's health to full
	void heal();

	// Returns a reference to the player's deck
	std::vector<Card*>& getDeck();

	// Returns a pointer to the player's opponent
	Player* getOpponent();

	// Returns a reference to the player's discard pile
	std::vector<Card*>& getDiscardPile();

	// Sets the player's deck to the specified vector
	void setDeck(std::vector<Card*> newDeck);

	// Sets the player's discard pile to the specified vector
	void setDiscardPile(std::vector<Card*> newDiscardPile);

	// Vector representing the player's hand of cards
	std::vector<Card*> hand;

	// Vector representing the player's deck of cards
	std::vector<Card*> deck;

	// Sets the player's opponent to the specified player
	void setOpponent(Player* p) 
	{
		opponent = p;
	}

	// Vector representing the player's discard pile
	std::vector<Card*> discard_pile;
};

// Restores the player's health to full
void Player::heal()
{
	health = 20;
}

// Returns a reference to the player's deck
std::vector<Card*>& Player::getDeck() 
{
	return deck;
}

// Returns a pointer to the player's opponents
Player* Player::getOpponent() 
{
	return opponent;
}

// Returns a reference to the player's discard pile
std::vector<Card*>& Player::getDiscardPile() 
{
	return discard_pile;
}

// Sets the player's deck to the specified vector
void Player::setDeck(std::vector<Card*> newDeck) 
{
	deck = newDeck;
}

// Sets the player's discard pile to the specified vector
void Player::setDiscardPile(std::vector<Card*> newDiscardPile) 
{
	discard_pile = newDiscardPile;
}
