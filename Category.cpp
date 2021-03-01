#include "Category.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

/// Category constructor prints constructor message
Category::Category()
{
	cout << "Constructor Category running..." << endl << endl;  // consturctor message
}

/// That functions reads budget.txt file; assign each line to a struct then push them into Category vector, returns nothing& reeives nothing
void Category::readBudgetFile()
{
	fstream newFile("budget.txt"); // openin file; creating object from STL fstream class
	string Line; // creating Line string for reading Category names
	
	if(!newFile.eof()){  // runs file to end of file(eof)
		while(!newFile.eof()){ // loop for reading all line of File
			newFile >> categoryInitStructure.number >> categoryInitStructure.currentBalance;  // assign Category each category number and balance to necessary struct members
			newFile.ignore(1); // ignoring empt space between balance and name
			getline(newFile,Line); // gets all line after number and balance
			categoryInitStructure.name=Line; // assign Line string to Struct member of name
			
			categoryInitVector.push_back(categoryInitStructure); // add struct which filled with a line of File
		}
		
		newFile.close(); // closing file
	}
	else
		cout << "Unable to open file" << endl; // Exception handling
}

/// That function returns begin() of vector as iterator and receives nothing
vector<categoryStruct>::iterator Category::getCategoryVectorBegin()
{
	return categoryInitVector.begin();
}

/// That function returns end() of vector as iterator and receives nothing
vector<categoryStruct>::iterator Category::getCategoryVectorEnd()
{
	return categoryInitVector.end();
}

/// That friend function overloads output operator(<<) for vector of class in terms of categoryStruct
ostream &operator<<(ostream &output, const vector<categoryStruct> &v)
{
	for(int i=0;i<v.size();++i){
		output << v[i].number << " " << fixed << setprecision(2) << v[i].currentBalance << " " << v[i].name << endl;
	}
	
	// fixed and setprecision were used for rounding and showing 2 decimal number after point( xxx.223 = xxx.22)
	
	return output;
}
/// That function sorts vector of Category class, returns nothing& reeives nothing
void Category::sortCategoryVector()
{
	sort(getCategoryVectorBegin(),getCategoryVectorEnd(),&compareBudget);  // sort function from algorithm lib. was used for sorting vector.
	// sort function gets begin, end of the vector and sate from compareBudget function
}

/// That nonmember function compares Category numbers of struct which members of vector, receives categoryStruct type variable and returns bool type variable
bool compareBudget(const categoryStruct a, const categoryStruct b)
{
	return (a.number < b.number);	
}
/// That fucntion prints Category vector, returns nothing& reeives nothing
void Category::printCategoryVector()
{
	cout << categoryInitVector;  // uses overloaded operator when printing vector.
}

