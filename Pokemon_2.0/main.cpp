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
#include <stdlib.h>
#include <time.h>

#include "Pokemon.h" // header file for class implemantation

using namespace std;

// Function declarations
void initializeTeams(Pokemon*[], Pokemon*[]); // Initializes player and computer Pokemon teams.
void menu(int&);	// Displays a menu for player choices.
void battle(int&, int&, Pokemon*[], Pokemon*[]); // Simulates a Pokemon battle.
void evolveMenu(Pokemon*[], int&);	// Allows the player to evolve a Pokemon.
int updateCompExhausted(Pokemon*[], const int);	// Updates the number of exhausted 
												// computer-controlled Pokemon.

const int SIZE = 6;  // size of the teams

// a text-based Pokemon battle simulation 
// game between a player's team and computer-controlled opponents.
int main()
{
	// Generate random numbers
	srand(time(0));

	// Arrays of pointers to Pokemon objects
	Pokemon* playerTeam[SIZE];
	Pokemon* computerTeam[SIZE];

	int compNumExhausted = 0;
	int playerCoins = 0;
	int choice;

	int currentPlayerIndex = 0;

	// Function call to initialize teams
	initializeTeams(playerTeam, computerTeam);

	while (compNumExhausted < SIZE)  // Size of the teams
	{
		cout << "STANDINGS: " << compNumExhausted << " wild Pokemon defeated so far." << endl;
		menu(choice);

		if (choice == 3)
		{
			cout << "Game OVER!  Goodbye!!" << endl;
			break;
		}
		else if (choice == 1)
		{
			battle(currentPlayerIndex, playerCoins, playerTeam, computerTeam);
			compNumExhausted = updateCompExhausted(computerTeam, SIZE);
		}
		else if (choice == 2)
		{
			evolveMenu(playerTeam, playerCoins);
		}
	}
	if (choice != 3)
	{
		cout << "You have defeated the Computer Team.  Your Team is victorious!!" << endl;
	}

	// clear the dynamically allocated memory
	for (int i = 0; i < SIZE; i++)
	{
		delete playerTeam[i];
		delete computerTeam[i];
	}

	return 0;
}
 
//---------------------------------------------------------------------------
/* initializeTeams() Function to initialize teams with pointers
* INCOMING DATA: 2 object pointers p, c
* OUTGOING DATA: none
*/
void initializeTeams(Pokemon* p[], Pokemon* c[])
{
	// Initialize Computer Team
	c[0] = new Pokemon(1, "Bulbasaur", "Ivysaur", "Venusaur", 0, false);
	c[1] = new Pokemon(2, "Charmander", "Charmeleon", "Charizard", 2, false);
	c[2] = new Pokemon(3, "Squirtle", "Wartortle", "Blastoise", 1, false);
	c[3] = new Pokemon(4, "Caterpie", "Metapod", "Butterfree", 0, false);
	c[4] = new Pokemon(5, "Weedle", "Kakuna", "Beedrill", 1, false);
	c[5] = new Pokemon(3, "Squirtle", "Wartortle", "Blastoise", 2, false);

	// Initialize Player Team
	p[0] = new Pokemon(1, "Bulbasaur", "Ivysaur", "Venusaur", 0, false);
	p[1] = new Pokemon(2, "Charmander", "Charmeleon", "Charizard", 0, false);
	p[2] = new Pokemon(3, "Squirtle", "Wartortle", "Blastoise", 0, false);
	p[3] = new Pokemon(4, "Caterpie", "Metapod", "Butterfree", 0, false);
	p[4] = new Pokemon(5, "Weedle", "Kakuna", "Beedrill", 0, false);
	p[5] = new Pokemon(1, "Bulbasaur", "Ivysaur", "Venusaur", 0, false);
}

//---------------------------------------------------------------------------
/* menu() Function to display the menu and get user choice
* INCOMING DATA: 1 int choice
* OUTGOING DATA: 1 int pass by reference: choice
*/
void menu(int& choice)
{
	cout << endl;
	cout << "Select an Option:" << endl;
	cout << "\t 1. Battle." << endl;
	cout << "\t 2. Evolve Pokemon." << endl;
	cout << "\t 3. Quit" << endl;
	cin >> choice;
}

//---------------------------------------------------------------------------
/* battle() Function for the battle logic
* INCOMING DATA: 2 int's PBR: actPok, playerCoins, 
*				2 Pokemon object type pointers: p, c
* OUTGOING DATA: no return value,2 PBR actPok and playerCoins.
*/
void battle(int& actPok, int& playerCoins, Pokemon* p[], Pokemon* c[])
{
	int randIndex, temp;
	int choice = 0;
	bool win;
	randIndex = rand() % SIZE;
	cout << endl;
	cout << "******************************" << endl;
	cout << "*** A WILD POKEMON APPEARS ***" << endl;
	cout << "******************************" << endl;

	do
	{
		cout << "   Your Active Pokemon: " << p[actPok]->getName() << " at Level " <<
		     p[actPok]->getLevel() << endl;
		cout << "   Computer Active Pokemon: " << c[randIndex]->getName() << " at Level " <<
		     c[randIndex]->getLevel() << endl;
		cout << endl << endl;

		cout << "What Would You Like to Do?:" << endl;
		cout << "\t 1. Fight!!" << endl;
		cout << "\t 2. Flee!!" << endl;
		cout << "\t 3. Swap Pokemon" << endl;
		cin >> choice;

		if (choice == 3)
		{
			cout << "Here is Your Team: " << endl;
			for (int i = 0; i < SIZE; i++)
			{
				cout << "\t" << i + 1 << ": " << p[i]->getName() << " at Level " << p[i]->getLevel() << endl;
			}
			cout << "Choose Your Pokemon" << endl;
			cin >> temp;
			actPok = temp - 1;
		}
	}
	while (choice == 3);

	if (choice == 2)
	{
		cout << endl << endl;
		cout << "Discretion is the better part of valor!  Let's see if there are any more Pokemon out here..."
		     << endl;
		cout << "." << endl;
		cout << "." << endl;
		cout << "." << endl;
		cout << "." << endl;
		cout << "." << endl;
	}
	else if (choice == 1)
	{
		if (!c[randIndex]->getExhaust())
		{
			if (*c[randIndex] > *p[actPok])  // Using overloaded > operator with pointers
			{
				cout << endl;
				cout << "\t Your opponent was TOO STRONG.  You lose." << endl << endl;
			}
			else if (*c[randIndex] < *p[actPok])  // Using overloaded < operator with pointers
			{
				cout << endl;
				cout << "\t You OVERPOWERED your opponent.  You win." << endl << endl;
				c[randIndex]->setExhaust(true);
			}
			else
			{
				switch (p[actPok]->getType())
				{
					case 1: // Grass Poison Type
						if (*c[randIndex] == 2)  // Using overloaded == operator with pointers
						{
							win = false;
						}
						else if (*c[randIndex] == 3)  // Using overloaded == operator with pointers
						{
							win = true;
						}
						else if (*c[randIndex] == 4)  // Using overloaded == operator with pointers
						{
							win = true;
						}
						else if (*c[randIndex] == 5)  // Using overloaded == operator with pointers
						{
							win = false;
						}
						break;
				}

				if (win)
				{
					cout << "\t YOU WIN... Your attack was SUPER EFFECTIVE. You earn a coin!" << endl << endl;
					playerCoins++;
					c[randIndex]->setExhaust(true);
				}
				else
				{
					cout << "\t YOU LOSE... Your attack was SUPER INEFFECTIVE." << endl << endl;
				}
			}
		}
		else
		{
			cout << "\t YOU WIN... your opponent was exhausted. You earn a coin!" << endl << endl;
			playerCoins++;
		}
	}
}

//---------------------------------------------------------------------------
/* evolveMenu() Function for evolving a Pokemon
*     INCOMING DATA: 1 Pokemon object pointer pt, 1 int numCoins
*     OUTGOING DATA: nothing returned, updated number of coins PBR*/
void evolveMenu(Pokemon* pt[], int& numCoins)
{
	// Check if the player has enough coins to evolve a Pokemon
	if (numCoins >= 3)
	{
		int choice;
		cout << "Select a Pokemon to Evolve:" << endl;

		// Display the player's Pokemon team with numbered options
		for (int i = 0; i < SIZE; i++)
		{
			cout << "\t" << i + 1 << ": " << pt[i]->getName() << " at Level " << pt[i]->getLevel() << endl;
		}

		cin >> choice;

		// Ensure the choice is within the valid range
		if (choice >= 1 && choice <= SIZE)
		{
			// Evolve the selected Pokemon if it's not already at level 2
			if (pt[choice - 1]->getLevel() < 2)
			{
				pt[choice - 1]->evolve();  // Evolve the selected Pokemon
				numCoins -= 3;           // Deduct 3 coins for evolution
				cout << "Congratulations! " << pt[choice - 1]->getName() << " has evolved to Level " <<
				     pt[choice - 1]->getLevel() << "!" << endl;
			}
			else
			{
				cout << "Sorry, this Pokemon is already at its maximum level (Level 2)." << endl;
			}
		}
		else
		{
			cout << "Invalid choice. Please select a valid Pokemon to evolve." << endl;
		}
	}
	else
	{
		cout << "You have earned " << numCoins << " Coins." << endl;
		cout << "You need 3 coins to evolve one of your Pokemon" << endl << endl;
	}
}

//---------------------------------------------------------------------------
/* updateCompExhausted() Function to update the number of exhausted wild Pokemon
*     INCOMING DATA: 1 Pokemon object pointer c, 1 const int size
*     OUTGOING DATA: int numExhausted*/
int updateCompExhausted(Pokemon* c[], const int size)
{
	int numExhausted = 0;

	// Loop through the wild Pokemon array and count the exhausted ones
	for (int i = 0; i < size; i++)
	{
		if (c[i]->getExhaust())
		{
			numExhausted++;
		}
	}

	return numExhausted;
}

