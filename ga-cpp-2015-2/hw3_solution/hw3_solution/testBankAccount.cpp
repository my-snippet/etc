//
//  testBankAccount.cpp
//  hw3_solution
//
//  Created by wikibootup on 11/18/15.
//  Copyright © 2015 wikibootup. All rights reserved.
//

/* Project libraries */
#include "BankAccount.hpp"

/* External libraries */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

/* Built-in libraries */
#include <array>

using namespace std;


SCENARIO( "Test sample (array object test example)", "[array]" ) {
    GIVEN( "This stuff exists" ) {
        array<string, 2> input = {"abc", "def"};

        WHEN( "I do this" ) {
            THEN( "it should do this")
            {
                REQUIRE( input[0] == "abc" );
                AND_THEN( "do that")
                REQUIRE( input[1] == "def" );
            }
        }
    }
}

SCENARIO( "initial pastBalances return NULL", "[initial value]" ) {
    GIVEN( "This stuff exists" ) {
        CBankAccount instance;
        
        WHEN( "I do this" ) {
            THEN( "it should do this")
            {
                REQUIRE( instance.getPastBalances() == NULL );
            }
        }
    }
}

SCENARIO( "Test set, get methods", "[set], [get]" ) {
    GIVEN( "The CBankAccount instance exists" ) {
        CBankAccount instance;
        WHEN( "Set instance variables as a some value" ) {
            
            string bankName;
            int balances;
            double interestRate;
            
            /* Sample data */
            string bank1 = "bank1";
            int balances1 = 123;
            double interestRate1 = 1.17;
            
            /* Set sample data */
            instance.setBankName(bank1);
            instance.setBalances(balances1);
            instance.setInterestRate(interestRate1);
            
            THEN( "Instance variables should be equal to set values")
            {
                REQUIRE( instance.getBankName() == bank1);
                REQUIRE( instance.getBalances() == balances1);
                REQUIRE( instance.getInterestRate() == interestRate1);
            }
        }
    }
}

SCENARIO( "Test set 3 values using just the one method", "[set]" ) {
    GIVEN( "The CBankAccount init using constructor" ) {
        WHEN( "Set instance variables as a some value" ) {
            /* Sample data */
            string bank1 = "bank1";
            int balances1 = 123;
            double interestRate1 = 1.17;
            
            CBankAccount instance(bank1, balances1, interestRate1);
            THEN( "Instance variables should be equal to set values")
            {
                REQUIRE( instance.getBankName() == bank1);
                REQUIRE( instance.getBalances() == balances1);
                REQUIRE( instance.getInterestRate() == interestRate1);
            }
        }
    }
}