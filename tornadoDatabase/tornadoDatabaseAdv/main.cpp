// ---------------------------------------------------------------------------
// Name: Kethan Pilla
// Course-Section: CS255-01
// Assignment: Project #1
// Date due: 08/31/2023
// Description: Constructing an interface to a tornado database.
//				This Programs objective is to copy data from a file and
// 				store the data in structs to make it efficient and reusable.
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "tornInfo.h"

using namespace std;

// FUNCTIONS I HAVE ALREADY UPDATED FOR YOU
void initializeArray(tornInfo[], const int);
int loadProducts(tornInfo[], string);

// FUNCTIONS WHICH DON'T NEED TO BE UPDATED
int menu();

// OLD FUNCTION DEFINITIONS WHICH NEED TO BE UPDATED
void displayAll(tornInfo[], const int);
void numByYear(tornInfo[], const int, int&);
int vicByYear(tornInfo[], const int);
void tornByCounty(tornInfo[], const int, int&);
double avgWindSpeed(tornInfo[], const int, int&);

int main()
{
	// Roundoff upto two decimal values.
	cout<<fixed<<setprecision(2);
	const int maxSize = 100;

	// Struct object
	tornInfo tnds[maxSize];

	// Declare variables
	int numTorn=0;
	int choice;
	double avg = 0;

	// Function call.
	initializeArray(tnds, maxSize);

	string filename;
	cout<<"Enter the filename of your tornado database."<<endl;
	// Use getline to capture all the all with spaces.
	getline(cin, filename);
	numTorn = loadProducts(tnds, filename);

	/* Function call to display menu, user should select a choice and
	*  the choice calls the following function returning the output. */
	int result;
	choice = menu();
	while(choice != 7)
	{
		if(choice == 1)
		{
			result = numTorn;
		}
		else if(choice == 2)
		{
			displayAll(tnds, numTorn);
			result = numTorn;
		}
		else if(choice == 3)
		{
			numByYear(tnds, numTorn, result);
		}
		else if(choice == 4)
		{
			result = vicByYear(tnds, numTorn);
		}
		else if(choice == 5)
		{
			tornByCounty(tnds, numTorn, result);
		}
		else if(choice == 6)
		{
			avg = avgWindSpeed(tnds, numTorn, result);
			cout << "Average wind speed: "<< avg << endl;
		}

		cout<<"Result: "<<result<<endl;
		choice = menu();
	}
	cout<<"Goodbye.  Have a nice day!"<<endl;
}

//---------------------------------------------------------------------------
/* initializeArray() initializes the year array to all default values, -1.
*     Because we have arrays that have a maxSize and we don't expect to actually
*     have as many items as maxSize, most of our arrays will be empty.  Having
*     a sentinal value for empty slots COULD help us when processing data.
*     INCOMING DATA: an int array, a const int representing maxSize
*     OUTGOING DATA: nothing returned, updated array to default values*/
void initializeArray(tornInfo tnds[], const int mS)
{
	for(int i=0; i<mS; i++)
	{
		tnds[i].year = -1;
	}
}

//---------------------------------------------------------------------------
/* loadProducts() loads the information about our products into an array of
*	 struct type.
*     INCOMING DATA: array of tornInfo, and a filename string
*     OUTGOING DATA: integer value number of tornadoes */
int loadProducts(tornInfo tnds[], string fN)
{
	// Accessing the file to input data
	ifstream file(fN);
	string line;
	int count = 0;
	int next_year, next_victims;
	string next_county, next_category, temp;
	double next_maxwind;
	
	/* Use find() to return the index of ",".
	* Using substr() we can move from "," to "," and 
	* divide the characters and store them in specific arrays.
	* stoi converts a string to an integer(because the line as a whole
	* is considered as a string)
	* stod is string to double
	*erase()` function can also be used to erase a specific character from a string
	 */
	while(getline(file,line))
	{
		int pos = 0;
		//parse the next line
		pos = line.find(", ");
		temp = line.substr(0, pos);
		next_year = stoi(temp);

		line.erase(0, pos+2);
		pos = line.find(", ");
		next_county = line.substr(0, pos);

		line.erase(0, pos+2);
		pos = line.find(", ");
		next_category = line.substr(0, pos);

		line.erase(0, pos+2);
		pos = line.find(", ");
		temp = line.substr(0, pos);
		next_maxwind = stod(temp);

		line.erase(0, pos+2);
		next_victims = stoi(line);

		// Store the data in tnds struct object.
		tnds[count].year = next_year;
		tnds[count].county = next_county;
		tnds[count].category = next_category;
		tnds[count].wind = next_maxwind;
		tnds[count].victims = next_victims;

		count++;
	}
	// Close the file.
	file.close();
	return count;
}

//---------------------------------------------------------------------------
/* menu() Prints menu option information to the user and returns selection.
*     Displays a numbered menu options 1 - 6: calc ttl number of tornadoes,
*	 display all tornadoes in db, calculate num for a year, calculate num
*	 victims for a year, display all tornado information for a specific county,
*	 and quit, respectively.
*     INCOMING DATA: none
*     OUTGOING DATA: integer choice selected*/
int menu()
{
	int choice;
	cout<<endl;
	cout<<"Select an Option:"<<endl;
	cout<<"\t 1. Calculate number of tornadoes in the database."<<endl;
	cout<<"\t 2. Display all tornado data."<<endl;
	cout<<"\t 3. Calculate the number of tornadoes for a certain year."<<endl;
	cout<<"\t 4. Calculate the number of victims of tornadoes for a year."<<endl;
	cout<<"\t 5. Display all tornado information for a specific county."<<endl;
	cout<<"\t 6. Display average wind speed of tornadoes in a year."<<endl;
	cout<<"\t 7. Quit"<<endl;

	cin>>choice;
	return choice;
}

/*
    **PLACE OTHER FUNCTION IMPLEMENTATIONS BELOW
    **There are four (4) functions which need to be updated.
    **Follow the example of the provided functions and code given in class.
    **YOUR FUNCTION IMPLEMENTATIONS GO BELOW
*/


/**WRITE (Implement) THE NECESSARY NEW FUNCTION HERE**/

//---------------------------------------------------------------------------
/* displayAll() Function displays the data in an appropriately formatted
*	 manner for all the tornado data, one tornado per numbered line.
*     INCOMING DATA: tnds struct, const int numTorn
*     OUTGOING DATA: none*/
void displayAll(tornInfo tnds[], const int numTorn)
{
	// setw() is used for line spacing, used to set the width.
	cout << setw(4) << "SNo." << setw(8) << "Year" << setw(15) << "County" <<
	     setw(25) << "Category" << setw(30) << "Maxwind" << setw(10) << "Victims" << endl;
	cout <<"---" << endl;

	for (int i = 0; i < numTorn; i++)
	{
		cout << setw(4) << i + 1 << setw(8) << fixed << tnds[i].year;
		cout << setw(15) << fixed << tnds[i].county;
		cout << setw(25) << fixed << tnds[i].category;
		cout << setw(30) << fixed << tnds[i].wind;
		cout << setw(10) << fixed << tnds[i].victims << endl;
	}
}

void numByYear(tornInfo tnds[], const int numTorn, int& result)
{
	int searchYear;
	result = 0;

	cout << "Enter the Year: ";
	cin >> searchYear;

	for(int i = 0; i < numTorn; i++)
	{
		if(tnds[i].year == searchYear)
		{
			result++;
		}
	}
}
//---------------------------------------------------------------------------
/* vicByYear() function asks the user for a specific year, and accepts that
*	 input from the user.  Function uses that input to process that database
*	 and calculate the total number of victims across all tornadoes
*	 for the given year.
*     INCOMING DATA: tnds struct, numTorn const int
*     OUTGOING DATA: int result*/
int vicByYear(tornInfo tnds[], const int numTorn)
{
	int victimByYear;
	int result = 0;

	cout << "Enter the Year to know the total victims for the year: ";
	cin >> victimByYear;
	cout << endl;

	for(int i = 0; i < numTorn; i++)
	{
		if(tnds[i].year == victimByYear)
		{
			result = tnds[i].victims + result;
		}
	}
	return result;
}

//---------------------------------------------------------------------------
/* tornByCounty() function asks the user for a specific county, and accepts that
*	 input from the user.  Function uses that input to process the database
*	 and display ALL tornado data for that specific county in a numbered list.
*     INCOMING DATA: 1 struct tnds, one int constant numTorn, 1 int result PBR
*     OUTGOING DATA: int result*/
void tornByCounty(tornInfo tnds[], const int numTorn, int& result)
{
	string countyName;
	result = 0;

	cout << "Enter the county name: ";
	cin >> countyName;
	cout << endl;
	cout << setw(4) << "SNo." << setw(8) << "Year" << setw(15) << "County" <<
	     setw(25) << "Category" << setw(30) << "Maxwind" << setw(10) << "Victims" << endl;
	cout << "---" << endl;

	for (int i = 0; i < numTorn; i++)
	{
		if (countyName == tnds[i].county)
		{
			cout << setw(4) << result + 1 << setw(8) << fixed << tnds[i].year;
			cout << setw(15) << fixed << tnds[i].county;
			cout << setw(25) << fixed << tnds[i].category;
			cout << setw(30) << fixed << tnds[i].wind;
			cout << setw(10) << fixed << tnds[i].victims << endl;

			result++;
		}
	}
}
//---------------------------------------------------------------------------
/* avgWindSpeed() Function calculates the average of total number 
*	of tornados in a year, and returns the number of tornados and passes 
*	Average.
*     INCOMING DATA: tnds struct, const int numTorn, PBR avg
*     OUTGOING DATA: result and PBR avg*/
double avgWindSpeed(tornInfo tnds[], const int numTorn, int& result)
{
	int year;
	double avg = 0;
	int count = 0;
	cout << "Enter a year: ";
	cin >> year;

	for(int i=0; i < numTorn; i++)
	{
		if(tnds[i].year == year)
		{
			avg = tnds[i].wind + avg;
			count++;
		}
	}
	result = count;
	avg = avg/count;

	return avg;
}
