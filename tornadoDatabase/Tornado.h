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
using namespace std;

class Tornado
{
	public:

		int getYear()
		{
			return year;
		}
		void setYear(int y)
		{
			if (y<1900 || y>2500)
			{
				cout << "ERROR IN FILE:invalid year"<<endl;
				year = 1900;
			}
			else
			{
				year = y;
			}
		}
		string getCounty()
		{
			return county;
		}
		void setCounty(string c)
		{
			county = c;
		}

		string getCategory()
		{
			return category;
		}

		void setCategory(string f)
		{
			if(f=="F0" || f=="F1" || f=="F2" || f=="F3" || f=="F4" || f=="F5" )
			{
				category = f;
			}
			else
			{
				cout << "ERROR IN FILE:invalid category"<<endl;
				category = "F0";
			}
		}
		double getMaxWind()
		{
			return maxWind;
		}
		void setMaxWind(double mW)
		{
			maxWind = mW;
		}

		int getVictims()
		{
			return victims;
		}
		void setVictims(int v)
		{
			victims = v;
		}

	private:
		int year;
		string county;
		string category;
		double maxWind;
		int victims;


};
