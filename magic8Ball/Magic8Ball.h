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
#include<fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Class declaration
class Magic8Ball
{
	// Access specifier
	private:
		// Constant vairable
		const static int SIZE = 10;
		string positive[SIZE];
		string negative[SIZE];
		int fate;
		
	// Access specifier	
	public:
		// Constructor
		Magic8Ball()
		{
			string posFileName;
			string negFileName;
			string file1;
			string file2;
			int count1 = 0;
			int count2 = 0;
			// Generate random number
			srand(time(0));
			// initialize fate value
			fate = 5;
			
			cout << "Enter the positive answer file name: " << endl;
			cin >> posFileName;
			cout << "Enter the negative answer file name: " << endl;
			cin >> negFileName;
			
			// read files
			ifstream infile1(posFileName);
			ifstream infile2(negFileName);
			
			while(getline(infile1,file1))
			{
				positive[count1] = file1;
				count1++;
			}
			while(getline(infile2,file2))
			{
				negative[count2] = file2;
				count2++;
			}
			
/*			void printAll();
			{
				cout << "Positive statements" << endl;
				for(int i = 0; i < SIZE; i++)
				{
					cout << positive[i] << endl;
				}
				cout << "Negative statements" << endl;
				for(int j = 0; j < SIZE; j++)
				{
					cout << negative[j] << endl;
				}
			}*/
		} 
			//---------------------------------------------------------------------------
			/* fateValue() This function is called to set the fate value from 
			*		1-10(1 being the worst luck and 10 being the best luck.)
			*     INCOMING DATA: no paramaters
			*     OUTGOING DATA: nothing returned*/
			void fateValue()
			{
				cout << "Choose a fate between 1 and 10 (1 being the worst luck, 10 being the best luck.)" << endl;
				cin >> fate;
			} 
			
			//---------------------------------------------------------------------------
			/* shakingBall() When we call this function it should display our fortune 
			*		based on the fate value.
			*     INCOMING DATA: no parameters.
			*     OUTGOING DATA: nothing returned */
			string shakingBall()
		    {
		    	cout << "Your fate is at level: " << fate << endl;
		        int index = rand() % 10; // Generate a number between 0 and 9
		        if (index < fate)
		        {
		            int randomIndex = rand() % SIZE;
		            return positive[randomIndex];
		        }
		        else
		        {
		            int randomIndex = rand() % SIZE;
		            return negative[randomIndex];
		        }
		    }
};