//declarations for all the required classes
#include "Player.h"
#include "PainfulLessonCard.h"

// Constructor & Destructor for the PainfulLessonCard class
PainfulLessonCard::PainfulLessonCard() : Card() {}
PainfulLessonCard::~PainfulLessonCard() {}

// Function returning the name of the PainfulLessonCard
std::string PainfulLessonCard::name() 
{
	return "Painful Lesson";
}

// Function implementing the effect of the PainfulLessonCard on the player passed as argument
void PainfulLessonCard::effect(Player* p) 
{
	// Decrease the player's health by 2
	p->loseHealth(2);

	// Make the player draw a card
	p->drawCard();
}