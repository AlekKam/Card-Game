//declarations for all the required classes & standard library headers
#include "HumanPlayer.h"
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

// Constructor & Destructor for the HumanPlayer class
HumanPlayer::HumanPlayer(Player* opponent) : Player(opponent) {}
HumanPlayer::~HumanPlayer() {}

// Function representing the human player's turn in the game
void HumanPlayer::myTurn() 
{
    // Print a message indicating the start of the human player's turn
    std::cout << "It's your turn! You have the following cards in your hand:" << std::endl;

    // Iterate over the human player's hand and print the name of each card
    for (Card* c : hand) 
    {
        std::cout << c->name() << std::endl;
    }

    // Prompt the user to enter the name of the card they want to play or 'end' to end their turn
    std::cout << "Enter the name of the card you want to play, or enter 'end' to end your turn:" << std::endl;

    // Read the user's input
    std::string input;
    std::getline(std::cin, input);

    // While the user has not entered 'end'
    while (input != "end") 
    {

        // Set a flag indicating whether the user has played a card this iteration
        bool card_played = false;

        // Iterate over the human player's hand
        for (Card* c : hand) 
        {
            // If the user's input matches the name of the current card in the iteration
            if (c->name() == input) 
            {
                playCard(c);
                card_played = true;
                break;
            }
        }
        if (!card_played) 
        {
            // If the user's input did not match the name of any card in their hand, print an error message
            std::cout << "Invalid card name. Please try again:" << std::endl;

            // Read the user's input again
            std::getline(std::cin, input);
            continue;
        }

        // Check if the human player or their opponent has lost the game
        if (hasLost()) 
        {
            std::cout << "You have lost the game!" << std::endl;
            return;
        }
        if (opponent->hasLost()) 
        {
            std::cout << "Your opponent has lost the game!" << std::endl;
            return;
        }

        // If the game is still ongoing, prompt the user to enter the name of the next card they want to play or 'end' to end their turn
        std::cout << "Enter the name of the next card you want to play, or enter 'end' to end your turn:" << std::endl;
    }
}