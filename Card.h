#pragma once

//declarations for all the required classes
#include <string>

class Player; 

class Card 
{
public:
	Card();
	virtual ~Card();
	//two virtual member functions that must be implemented by all derived classes :
	//name()
	//effect().
	virtual std::string name() = 0;
	virtual void effect(Player* p) = 0;
};