//declarations for all the required classes
#include "Player.h"
#include "Card.h"

// Constructor & Destructor for the Player class
Player::Player(Player* opponent) : opponent(opponent), health(20) {}
Player::~Player() {}

// Function to decrease the player's health by the specified amount
void Player::loseHealth(int i) {
    health -= i;
}

// Function to draw a card from the player's deck and add it to their hand
// Returns true if a card was drawn, false if the deck is empty
bool Player::drawCard() {

    // If the deck is empty, return false
    if (deck.empty()) 
    {
        return false;
    }

    // Otherwise, remove the top card from the deck and add it to the hand
    Card* top_card = deck.back();
    deck.pop_back();
    hand.push_back(top_card);
    return true;
}
// Function to play a card from the player's hand and apply its effect
void Player::playCard(Card* c) {
    // Find the card in the hand and remove it
    auto it = std::find(hand.begin(), hand.end(), c);
    if (it != hand.end()) 
    {
        hand.erase(it);
    }

    // Move the card to the discard pile
    discard_pile.push_back(c);
}

// Function to check if the player has lost the game
bool Player::hasLost() {

    // If the player's health is less than or equal to 0, they have lost
    if (health <= 0) 
    {
        return true;
    }

    // Otherwise, try to draw a card from the deck
    // If it is not possible to draw a card, the player has lost
    return !drawCard();
}