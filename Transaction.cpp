#include "Transaction.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

using namespace std;

/// Transaction constructor prints constructor message
Transaction::Transaction()
{
	cout << "Constructor Transaction running..." << endl << endl; // consturctor message
}

/// That functions reads transactions.txt file; assign each line to a struct then push them into Transaction vector, returns nothing& reeives nothing
void Transaction::readTransactionFile()
{	
	fstream newFile("transactions.txt"); // openin file; creating object from STL fstream class
	string Line; // creating Line string for reading Transaction names
	
	if(!newFile.eof()) // runs file to end of file(eof)
	{
		while(!newFile.eof()){ // loop for reading all line of File
			newFile >> transactionInitStructure.number >> transactionInitStructure.year;  // assign category number and year to necesarry struct members
			newFile.ignore(1); // ignoring '/'
			newFile >> transactionInitStructure.month; // assign month to necesarry struct members
			newFile.ignore(1); // ignoring '/'
			newFile>> transactionInitStructure.day >> transactionInitStructure.amount; // assign day and amount to necesarry struct members
			getline(newFile,Line); // gets all line after number and dates
			transactionInitStructure.description=Line; // assign Line string to Struct member of description
			
			transactionInitVector.push_back(transactionInitStructure); // add struct which filled with a line of File
		}
		
		newFile.close(); // closing file
	}
	else
		cout << "Unable to open file" << endl;	// exception handling
}

/// That function returns begin() of vector as iterator and receives nothing
vector<transactionStruct>::iterator Transaction::getTransactionVectorBegin()
{
	return transactionInitVector.begin();
}

/// That function returns end() of vector as iterator and receives nothing
vector<transactionStruct>::iterator Transaction::getTransactionVectorEnd()
{
	return transactionInitVector.end();
}

/// That friend function overloads output operator(<<) for vector of class in terms of transactionStruct
ostream &operator<<(ostream &output, const vector<transactionStruct> &v)
{
	for(int i=0;i<v.size();++i){
		output << v[i].number << " " 
			<< v[i].year << "/" 
			<< setfill('0') << setw(2) << v[i].month << "/" 
			<< setfill('0') << setw(2) << v[i].day << " "
			<< fixed << setprecision(2) << v[i].amount << " " 
			<< v[i].description << endl;
	}
	
	// setfill and setw functions were used for fillinf '0' to months and days which form of one decimal.
	
	return output;
}

/// That function sorts vector of Transaction class, returns nothing& reeives nothing
void Transaction::sortTransactionVector()
{
	sort(getTransactionVectorBegin(),getTransactionVectorEnd(),&compareTransDates); // sort function from algorithm lib. was used for sorting vector.
	// sort function gets begin, end of the vector and sate from compareTransDates function
}

/// That nonmember function compares dates and numbers, receives transactionStruct type variable and returns bool type variable
bool compareTransDates(const transactionStruct a, const transactionStruct b)
{
	if(a.number<b.number)
		return true;
	if(a.number==b.number && a.year<b.year)
		return true;
	if(a.number==b.number && a.year==b.year && a.month<b.month)
		return true;
	if(a.number==b.number && a.year==b.year && a.month==b.month && a.day<b.day)
		return true;
	else
		return false;
}

/// That fucntion prints Transaction vector, returns nothing& reeives nothing
void Transaction::printTransactionVector()
{
	cout << transactionInitVector; // uses overloaded operator when printing vector.
}

/// That function apply Transactions; creates object from Category class, accesses onject of Transaction class, reads budget.txt and transaction.txt files
/// sorts Category and Transaction vectors, uses addTransactionToCategory function.
void Transaction::applyTransactions()
{
	cout << "Categories are reading..." << endl;
	currentCategory.readBudgetFile();
	
	cout << "Categories are sorting..." << endl;
	currentCategory.sortCategoryVector();
	
	cout << "Transactions are reading..." << endl;
	this->readTransactionFile();
	
	cout << "Transactions are sorting..." << endl;
	this->sortTransactionVector();
	
	/*cout << "Budget File: " << endl;			// There are some codes for testing read and sort ind comment blocks
	currentCategory.printCategoryVector();
	cout << endl <<"Transactions File: " << endl;
	this->printTransactionVector();*/
	
	cout << "Transactions are applying..." << endl;
	cout << "Sampling Report is generating.." << endl << endl;
	addTransactionToCategory();
	
}

/// That function adds Transaction amounts to Category balances and creates sampling report for each transaction and budgets
void Transaction::addTransactionToCategory()
{
	vector<transactionStruct>::iterator itT=this->getTransactionVectorBegin(); // creating vector iterator and assignin current Transaction object vector begin to the iterator
	// for loop for accessing each member of Category vector
	for(vector<categoryStruct>::iterator itC=currentCategory.getCategoryVectorBegin();itC!=currentCategory.getCategoryVectorEnd();itC++){
			cout << itC->name << endl; // printing Category name
			cout << "Category:\t\t" << itC->number << "\t" << "Balance:\t" << itC->currentBalance << endl;  // printing category number and initial balance
			
			while(itC->number==itT->number){  // checking, are numbers of Category and Transaction same..
				itC->currentBalance=itC->currentBalance+itT->amount; // addind amount to balance
				cout << "\t" << itT->year << "/" 	// printing year
					<< setfill('0') << setw(2) << itT->month << "/" // printing month
					<< setfill('0') << setw(2) << itT->day << "\t" // printing day
					<< itT->amount << "\t\t\t" // printing amount
					<< itC->currentBalance << " " << itT->description << endl; // printing updated balance and description of Transaction
				
				if(itT==this->getTransactionVectorEnd()) // controlling transaction finish
					break; // breaking loop if is true
					
				itT++; // incrementing Transaction vector
			}
			
			cout << "Category:\t\t" << itC->number << "\t" << "Balance:\t" << itC->currentBalance << endl << endl; // printing Category number, updated balance and Category name
	}
}

