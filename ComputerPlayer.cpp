//declarations for all the required classes & standard library headers
#include "ComputerPlayer.h"
#include "Player.h"
#include <algorithm>
#include <random>
#include <iostream>
#include <vector>

// Constructor & Destructor for the ComputerPlayer class
ComputerPlayer::ComputerPlayer(Player* opponent) : Player(opponent) {}
ComputerPlayer::~ComputerPlayer() {}

// Function representing the computer player's turn in the game
void ComputerPlayer::myTurn() 
{
    // Create a random device and mt19937 random number generator
    std::random_device rd;
    std::mt19937 rng(rd());

    // While the computer player's hand is not empty
    while (!hand.empty()) 
    {
        // Generate a random index
        std::uniform_int_distribution<int> dist(0, hand.size() - 1);
        int index = dist(rng);

        // Get the card at the randomly generated index
        Card* c = hand[index];

        // Play the card
        playCard(c);

        // If the computer player has lost, print a message and return
        if (hasLost()) 
        {
            std::cout << "The computer has lost the game!" << std::endl;
            return;
        }

        // If the computer player's opponent has lost, print a message and return
        if (opponent->hasLost()) 
        {
            std::cout << "You have lost the game!" << std::endl;
            return;
        }
    }
}