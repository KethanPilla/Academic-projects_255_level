// ---------------------------------------------------------------------------
// Name: Kethan Pilla
// Course-Section: CS 255- 01
// Assignment: Project 4
// Date due: 10/08/2023
// Description: The program is a text-based Pokemon battle simulation
// game where the player's team of Pokemon competes against a
// computer-controlled team using dynamic memory allocation
// and operator overloading.
// ---------------------------------------------------------------------------
#include "Pokemon.h"
#include <string>
#include <iostream>

using namespace std;

// Constructor
Pokemon::Pokemon()
{
	type = 0;
	level = 0;
	exhausted = false;
}

// Overloaded constructor definition
Pokemon::Pokemon(int t, string n1, string n2, string n3, int l, bool e)
{
	type = t;
	names[0] = n1;
	names[1] = n2;
	names[2] = n3;
	level = l;
	exhausted = e;
}

// Getter and Setter methods
int Pokemon::getType() const
{
	return type;
}

void Pokemon::setType(int t)
{
	type = t;
}

string Pokemon::getName(int index) const
{
	if (index >= 0 && index < 3)
	{
		return names[index];
	}
	return ""; // Return an empty string if the index is out of bounds.
}

void Pokemon::setNames(string n1, string n2, string n3)
{
	names[0] = n1;
	names[1] = n2;
	names[2] = n3;
}

int Pokemon::getLevel() const
{
	return level;
}

void Pokemon::setLevel(int l)
{
	level = l;
}

bool Pokemon::getExhaust() const
{
	return exhausted;
}

void Pokemon::setExhaust(bool e)
{
	exhausted = e;
}

// Evolve method
void Pokemon::evolve()
{
	if (level < 2)
	{
		level++;
	}
}

// This operator is used to compare the levels of two Pokemon objects.
bool Pokemon::operator>(const Pokemon& other) const
{
	return level > other.level;
}

// This operator is used to compare the levels of two Pokemon objects.
bool Pokemon::operator<(const Pokemon& other) const
{
	return level < other.level;
}

// This operator is used to compare the type of a Pokemon object with an integer value.
bool Pokemon::operator==(int t) const
{
	return type == t;
}

// defines how a Pokemon object should be formatted and displayed 
// when sent to the standard output 
ostream& operator<<(ostream& os, const Pokemon& pokemon)
{
	os << pokemon.getName() << " at Level " << pokemon.getLevel();
	return os;
}
