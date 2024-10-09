// ---------------------------------------------------------------------------
// Name: Kethan Pilla
// Course-Section: CS255- 01
// Assignment: HW #4
// Date due: 09/03/2023
// Description: Constructing an interface to a tornado database.
//				This Programs objective is to copy data from a file and
// 				store the data in a object of a class to make it
//				efficient and reusable.
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Tornado.h"

using namespace std;

// Function prototypes
int loadTornados(Tornado[], string);
//The below functions require you to implement them
int menu();
void displayAll(Tornado[], const int);
void numByYear(Tornado[], const int, int&);
int vicByYear(Tornado[], const int);
void tornByCounty(Tornado[], const int, int&);

int main()
{
	// Roundoff upto two decimal values.
	cout<<fixed<<setprecision(2);
	const int maxSize = 100;
	// Struct object
	Tornado tornados[maxSize];  //Tornado tn1;
	// Declare variables
	int numTorn=0;
	int choice;

	string filename;
	cout<<"Enter the filename of your tornado database."<<endl;
	// Use getline to capture all the all with spaces.
	getline(cin, filename);
	numTorn = loadTornados(tornados, filename);

	int result;
	/* Function call to display menu, user should select a choice and
	*  the choice calls the following function returning the output. */
	choice = menu();
	while(choice != 6)
	{
		if(choice == 1)
		{
			result = numTorn;
		}
		else if(choice == 2)
		{
			displayAll(tornados, numTorn);
			result = numTorn;
		}
		else if(choice == 3)
		{
			numByYear(tornados, numTorn, result);
		}
		else if(choice == 4)
		{
			result = vicByYear(tornados, numTorn);
		}
		else if(choice == 5)
		{
			tornByCounty(tornados, numTorn, result);
		}

		cout<<"Result: "<<result<<endl;
		choice = menu();
	}
	cout<<"Goodbye.  Have a nice day!"<<endl;
}


//---------------------------------------------------------------------------
/* loadTornados() loads the information from the file to the object
*		tornados.
*     INCOMING DATA: object Tornado tornados, and a filename string
*     OUTGOING DATA: integer count number of tornadoes */
int loadTornados(Tornado t[], string fN)
{
	ifstream file(fN);
	string line;
	int count = 0;
	int next_year, next_victims;
	string next_county, next_category, temp;
	double next_maxwind;
	while(getline(file,line))
	{
		int pos = 0;
		//parse the next line
		pos = line.find(", ");
		temp = line.substr(0, pos);
		next_year = stoi(temp);
		//cout<<next_year;

		line.erase(0, pos+2);
		pos = line.find(", ");
		next_county = line.substr(0, pos);
		//cout<<" "<<next_county;

		line.erase(0, pos+2);
		pos = line.find(", ");
		next_category = line.substr(0, pos);
		//cout<<" "<<next_category;

		line.erase(0, pos+2);
		pos = line.find(", ");
		temp = line.substr(0, pos);
		next_maxwind = stod(temp);
		//cout<<" "<<next_maxwind;

		line.erase(0, pos+2);
		next_victims = stoi(line);
		//cout<<" "<<next_victims<<endl;

//        year[count] = next_year;
		t[count].setYear(next_year);
//        county[count] = next_county;
		t[count].setCounty(next_county);
//        category[count] = next_category;
		t[count].setCategory(next_category);
//        maxwind[count] = next_maxwind;
		t[count].setMaxWind(next_maxwind);
//        victims[count] = next_victims;
		t[count].setVictims(next_victims);

		count++;
	}
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
	cout<<"\t 6. Quit"<<endl;

	cin>>choice;
	return choice;
}

//---------------------------------------------------------------------------
/* displayAll() Function displays the data in an appropriately formatted
*	 manner for all the tornado data, one tornado per numbered line.
*     INCOMING DATA: Tornado tornados object, const int numTorn
*     OUTGOING DATA: none*/
void displayAll(Tornado t[], const int numTorn)
{
	// setw() is used for line spacing, used to set the width.
	cout << setw(4) << "SNo." << setw(8) << "Year" << setw(15) << "County" <<
	     setw(25) << "Category" << setw(30) << "Maxwind" << setw(10) << "Victims" << endl;
	cout <<"---" << endl;

	for (int i = 0; i < numTorn; i++)
	{
		cout << setw(4) << i + 1 << setw(8) << fixed << t[i].getYear();
		cout << setw(15) << fixed << t[i].getCounty();
		cout << setw(25) << fixed << t[i].getCategory();
		cout << setw(30) << fixed << t[i].getMaxWind();
		cout << setw(10) << fixed << t[i].getVictims() << endl;
	}
}

//---------------------------------------------------------------------------
/* numByYear() Function prompts the input of year from user and
*		displays us the number of tornados in that year.
*     INCOMING DATA: Tornado tornados object, PBR result
*     OUTGOING DATA: PBR result*/
void numByYear(Tornado t[], const int numTorn, int& result)
{
	int searchYear;
	result = 0;

	cout << "Enter the Year: ";
	cin >> searchYear;

	for(int i = 0; i < numTorn; i++)
	{
		if(t[i].getYear() == searchYear)
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
*     INCOMING DATA: Tornado tornados object, numTorn const int
*     OUTGOING DATA: int result*/
int vicByYear(Tornado t[], const int numTorn)
{
	int victimByYear;
	int result = 0;

	cout << "Enter the Year to know the total victims for the year: ";
	cin >> victimByYear;
	cout << endl;

	for(int i = 0; i < numTorn; i++)
	{
		if(t[i].getYear() == victimByYear)
		{
			result = t[i].getVictims() + result;
		}
	}
	return result;
}

//---------------------------------------------------------------------------
/* tornByCounty() function asks the user for a specific county, and accepts that
*	 input from the user.  Function uses that input to process the database
*	 and display ALL tornado data for that specific county in a numbered list.
*     INCOMING DATA: Tornado tornados object, one int constant numTorn, 1 int result PBR
*     OUTGOING DATA: int result PBR*/
void tornByCounty(Tornado t[], const int numTorn, int& result)
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
		if (countyName == t[i].getCounty())
		{
			cout << setw(4) << result + 1 << setw(8) << fixed << t[i].getYear();
			cout << setw(15) << fixed << t[i].getCounty();
			cout << setw(25) << fixed << t[i].getCategory();
			cout << setw(30) << fixed << t[i].getMaxWind();
			cout << setw(10) << fixed << t[i].getVictims() << endl;

			result++;
		}
	}
}