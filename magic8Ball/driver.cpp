// ---------------------------------------------------------------------------
// Name: Kethan Pilla
// Course-Section: CS255-01
// Assignment: HW #6
// Date due: 09/10/2023
// Description: Write a code to magic 8 ball, to test your fate.Tap the ball 
//				to know your fortune.There are two files containing 10 positive 
//				statements and 10 negative statements. 
// ---------------------------------------------------------------------------
#include<iostream>
#include "Magic8Ball.h"

using namespace std;

int main()
{
	// Object declaration
	Magic8Ball start;
	int selection = 0;
	string fortune;
	
	while(selection != 3)
	{
		cout << "Select from the following menu:" << endl;
		cout << "		1. Change your fate settings." << endl;
		cout << "		2. Shake the Magic 8 Ball." << endl;
		cout << "		3. Quit" << endl;
		cin >> selection;
		
		switch(selection)
		{
			case 1:
				start.fateValue();
				break;
			case 2:
				fortune = start.shakingBall();
				cout << fortune << endl;
				break;
		}
	}
	return 0;
}