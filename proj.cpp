//*****************************************************//
/*! \mainpage BugetTracking
 *
 * Eskisehir Osmangazi University
 *
 * Berktug Akca
 * 
 * \image html UML_Project3.png
 *
 * 
 *This Project Includes Budget Tracking
 * 
 * Category class.
 * Transaction class.
 */ 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Transaction.h"

using namespace std;

int main(int argc, char** argv) {
	
	// Creating object in terms of Transaction
	Transaction doTransaction;
	
	// Call apply transaction member function from Transaction
	doTransaction.applyTransactions();
	
	return 0;
}
