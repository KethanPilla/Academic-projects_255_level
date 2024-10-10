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
#include <iostream>
#include <string>
using namespace std;

// Class declaration
class Pokemon
{
	private:
		int type;
		string names[3];
		int level;
		bool exhausted;

	public:
		// initializes a Pokemon object with default values.
		Pokemon();
		// overloaded constructor that allows you to create a Pokemon 
		// object with specific values for its attributes.
		Pokemon(int t, string n1, string n2, string n3, int l, bool e);
		
		// Getter and setter methods
		int getType() const;
		void setType(int t);
		string getName(int index = 0) const;
		void setNames(string n1, string n2, string n3);
		int getLevel() const;
		void setLevel(int l);
		bool getExhaust() const;
		void setExhaust(bool e);
		
		void evolve();
		
		// Overloaded operators
		bool operator>(const Pokemon& other) const;
		bool operator<(const Pokemon& other) const;
		bool operator==(int t) const;

		friend ostream& operator<<(ostream& os,
		                           const Pokemon& pokemon); // Overloaded << operator declaration
};


