#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
#include <fstream>
#include "Category.h"

using namespace std;

/// Creating Struct for read each line from transactions.txt
struct transactionStruct
{
	int number; // Transaction category number
	double amount; // Transaction amount
	int year; // Transaction year
	int month; // Transaction month
	int day; // Transaction day
	string description; // Transaction description
};

/// Non-member function for comparing
bool compareTransDates(const transactionStruct, const transactionStruct); // compare function must be nonmember function class end struct

/// Transaction Class
class Transaction
{
	/// A friend fucntion for overloding output operator
	friend ostream &operator<<(ostream &, const Transaction&);
	
	public:
		/// Transaction constructor
		Transaction();
		/// Function for reading transactions.txt file
		void readTransactionFile();
		/// Function for getting begin of vector in terms of transactionStruct
		vector<transactionStruct>::iterator getTransactionVectorBegin();
		/// Function for getting end of vector in terms of transactionStruct
		vector<transactionStruct>::iterator getTransactionVectorEnd();
		/// Function for sorting vector in terms of transactionStruct
		void sortTransactionVector();
		/// Function for printing vector in terms of transactionStruct
		void printTransactionVector();
		/// Function for applying Transaction
		void applyTransactions();
		/// Function for adding Transactions to Category
		void addTransactionToCategory();
	private:
		/// Creating object from Categtory class for transactions
		Category currentCategory;
		/// A Structure for reading each line from file
		transactionStruct transactionInitStructure;
		/// STL Container vector in terms of transactionStruct
		vector<transactionStruct> transactionInitVector;
};

#endif
