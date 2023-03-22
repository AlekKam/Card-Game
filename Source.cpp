//declarations for all the required classes & standard library headers
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include"FullHealCard.h"
#include"PainfulLessonCard.h"
#include"SpiteCard.h"
#include"SwitcherooCard.h"
#include"RefreshCard.h"
#include"PeekCard.h"

#include "Card.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Player.h"

// This function shuffles the elements of a vector of Card pointers.
// It uses a random number generator to shuffle the cards.
void shuffle(std::vector<Card*>& cards) 
{
	// Use a random number generator to shuffle the cards
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g);
}

int main() {
	// Create a vector of cards for each player
	vector<Card*> player1Cards;
	vector<Card*> player2Cards;

	// Add cards to each player's deck
	player1Cards.push_back(new FullHealCard());
	player1Cards.push_back(new PainfulLessonCard());
	player1Cards.push_back(new SpiteCard());
	player1Cards.push_back(new SwitcherooCard());
	player1Cards.push_back(new RefreshCard());
	player1Cards.push_back(new PeekCard());

	player2Cards.push_back(new FullHealCard());
	player2Cards.push_back(new PainfulLessonCard());
	player2Cards.push_back(new SpiteCard());
	player2Cards.push_back(new SwitcherooCard());
	player2Cards.push_back(new RefreshCard());
	player2Cards.push_back(new PeekCard());

	// Shuffle each player's deck
	shuffle(player1Cards);
	shuffle(player2Cards);

	// Create the players
	//For some reason, I keep getting errors with these two pieces of code
	// and I have no idea how to resolve it. Since using a different method
	//still dosen't work. Hopefully That won't be a huge issue and I apologize for this
	//but I just have no idea what I'm doing wrong here.
	HumanPlayer player1(player1Cards);
	ComputerPlayer player2(player2Cards);


	// Set each player's opponent
	player1.setOpponent(&player2);
	player2.setOpponent(&player1);

	// Run the game loop until one player has lost
	while (!player1.hasLost() && !player2.hasLost()) 
	{
		player1.myTurn();
		if (player1.hasLost() || player2.hasLost()) 
		{
			break;
		}
		player2.myTurn();
	}

	// Print a message to indicate which player won
	if (player1.hasLost()) 
	{
		std::cout << "Player 2 wins!" << std::endl;
	}
	else if (player2.hasLost()) 
	{
		std::cout << "Player 1 wins!" << std::endl;
	}
	else 
	{
		std::cout << "The game ended in a draw." << std::endl;
	}

	// Clean up the players and cards
	delete &player1;
	delete &player2;
	for (auto& card : player1Cards) 
	{
		delete card;
	}
	for (auto& card : player2Cards) 
	{
		delete card;
	}

	return 0;
}