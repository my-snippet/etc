//
//  main.cpp
//  hw3_solution
//
//  Created by wikibootup on 11/18/15.
//  Copyright ? 2015 wikibootup. All rights reserved.
//

/* Project libraries */
#include "BankAccount/BankAccount.hpp"

/* Built-in libraries */
#include <iostream>
#include <cassert>

using namespace std;
using namespace customNameSpace;


int main() {
	/*  Notice :
	This function does not work in the normal way.
	It is called when unit testing.
	*/
	CBankAccount instance1;
	CBankAccount instance2;
	CBankAccount instance3;
	instance3 = instance1 + instance2;
	instance3.setBankName("bank3");

	int * samplePastBalances = new int[instance3.numOfPastBalances + 1];
	for (int i = 0 ; i < instance3.numOfPastBalances; i++) {
		samplePastBalances[i] = i;
	}
	instance3.setPastBalances(samplePastBalances);

	cout << instance3;

	return 0;
}