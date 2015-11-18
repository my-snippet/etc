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
            AND_THEN( "Also, pastBalances should be set NULL" ) {
                REQUIRE( instance.getPastBalances() == NULL );
            }
        }
    }
}

SCENARIO( "instance ", "[constructor]" ) {
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
            AND_THEN( "Also, pastBalances should be set NULL" ) {
                REQUIRE( instance.getPastBalances() == NULL );
            }
        }
    }
}

SCENARIO( "Test CBankAccount operator+", "[operator]" ) {
    GIVEN( "Initialze third bank data" ) {
        
        /* First bank data */
        string firstAccountBankName = "foo Bank";
        int firstAccountBalances = 123;
        double firstAccountInterestRate = 1.23;
        
        /* Second bank data */
        string secondAccountName = firstAccountBankName;
        int secondAccountBalances = 321;
        double secondAccountInterestRate = 3.21;
        
        /* Add two bank data */
        int sumAccountBalances =
            firstAccountBalances + secondAccountBalances;
        double sumBankInterestRate =
            firstAccountInterestRate + secondAccountInterestRate;
        
        /* Bank */
        CBankAccount firstAccount(
                                  firstAccountBankName,
                                  firstAccountBalances,
                                  firstAccountInterestRate);
        CBankAccount secondAccount(
                                   secondAccountName,
                                   secondAccountBalances,
                                   secondAccountInterestRate);
        CBankAccount thirdAccount;
        
        WHEN( "Add two instance using operator+" ) {
            thirdAccount = firstAccount + secondAccount;
            THEN( "Sum account should be equal to the each sum of the partial value")
            {
                REQUIRE( thirdAccount.getBankName() == firstAccountBankName);
                REQUIRE( thirdAccount.getBalances() == sumAccountBalances);
                REQUIRE( thirdAccount.getInterestRate() == sumBankInterestRate);
            }
        }
    }
}

SCENARIO( "Test setPastBalances", "[set]" ) {
    GIVEN( "Sample past balances exist" ) {
        CBankAccount instance;
        
        int * samplePastBalances = new int [instance.getnumOfPastBalances() + 1];
        for(int i ; i < instance.getnumOfPastBalances() ; i++) {
            samplePastBalances[i] = i;
        }
        
        WHEN( "Apply past balances to instance" ) {
            instance.setPastBalances(samplePastBalances);
            int * pastBalances = new int [instance.getnumOfPastBalances() + 1];
            pastBalances = instance.getPastBalances();
            THEN( "instance's past balances should be equal to samplePastBalances")
            {
                /* It's needed to refactor code, Use function (No Hard coding) */
                for(int i=0 ; i < instance.getnumOfPastBalances() ; i++) {
                    REQUIRE( pastBalances[i] == samplePastBalances[i] );
                }
            }
        }
    }
}

/* operator<< have some problems ( catch? or implementation? ) */
/*
SCENARIO( "Test print PastBalances using operator<<", "[set]" ) {
    GIVEN( "Apply sample past balances to instance" ) {
        CBankAccount instance;
        
        int * samplePastBalances = new int [instance.getnumOfPastBalances() + 1];
        for(int i ; i < instance.getnumOfPastBalances() ; i++) {
            samplePastBalances[i] = i;
        }
        instance.setPastBalances(samplePastBalances);
        
        WHEN( "Apply past balances to instance" ) {
            cout << instance << endl;
            THEN( "instance's past balances should be equal to samplePastBalances")
            {
            }
        }
    }
}
*/