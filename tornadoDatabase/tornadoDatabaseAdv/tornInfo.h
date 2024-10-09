// ---------------------------------------------------------------------------
// Name: Kethan Pilla
// Course-Section: CS255-01
// Assignment: Project #1
// Date due: 08/31/2023
// Description: Constructing an interface to a tornado database.
//				This Programs objective is to copy data from a file and
// 				store the data in structs to make it efficient and reusable.
// ---------------------------------------------------------------------------
#include <string>
using namespace std;

struct tornInfo
{
	int year;
	string county;
	string category;
	double wind;
	int victims;
};
