#ifndef CATEGORY_H
#define CATEGORY_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/// Creating Struct for read each line from budget.txt
struct categoryStruct
{
	int number; // Category number
	double currentBalance; // Category balance
	string name; // Category name
};

/// Non-member function for comparing
bool compareBudget(const categoryStruct, const categoryStruct); // Compare function must be nonmember function class end struct

/// Category Class
class Category
{
	/// A friend fucntion for overloding output operator
	friend ostream &operator<<(ostream&, const Category&);
	
	public:
		/// Category constructor
		Category();
		/// Function for reading budget.txt file
		void readBudgetFile();
		/// Function for getting begin of vector in terms of categoryStruct
		vector<categoryStruct>::iterator getCategoryVectorBegin();
		/// Function for getting end of vector in terms of categoryStruct
		vector<categoryStruct>::iterator getCategoryVectorEnd();
		/// Function for sorting vector in terms of categoryStruct
		void sortCategoryVector();
		/// Function for printing vector in terms of categoryStruct
		void printCategoryVector();
	private:
		/// STL Container vector in terms of categoryStruct
		vector<categoryStruct> categoryInitVector;
		/// A Structure for reading each line from file
		categoryStruct categoryInitStructure;
};

#endif
