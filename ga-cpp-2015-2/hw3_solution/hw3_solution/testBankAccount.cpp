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
#include <string>

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
        
        int * samplePastBalances = new int [instance.numOfPastBalances + 1];
        for(int i ; i < instance.numOfPastBalances ; i++) {
            samplePastBalances[i] = i;
        }
        
        WHEN( "Apply past balances to instance" ) {
            instance.setPastBalances(samplePastBalances);
            int * pastBalances = new int [instance.numOfPastBalances + 1];
            pastBalances = instance.getPastBalances();
            THEN( "instance's past balances should be equal to samplePastBalances")
            {
                /* It's needed to refactor code, Use function (No Hard coding) */
                for(int i=0 ; i < instance.numOfPastBalances ; i++) {
                    REQUIRE( pastBalances[i] == samplePastBalances[i] );
                }
            }
        }
    }
}

/* operator<< has some problems ( catch? or implementation? ) */
/*
SCENARIO( "Test print PastBalances using operator<<", "[set]" ) {
    GIVEN( "Apply sample past balances to instance" ) {
        CBankAccount instance;
        
        int * samplePastBalances = new int [instance.numOfPastBalances + 1];
        for(int i ; i < instance.numOfPastBalances ; i++) {
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

SCENARIO( "Test CBankAccount operator=", "[operator]" ) {
    GIVEN( "1. Initialze one bank data, 2. Set sample past balances to originalAccount" ) {
        
        /* a Bank data */
        string firstAccountBankName = "foo Bank";
        int firstAccountBalances = 123;
        double firstAccountInterestRate = 1.23;
        
        /* Bank */
        CBankAccount originalAccount(
                                  firstAccountBankName,
                                  firstAccountBalances,
                                  firstAccountInterestRate);
        CBankAccount copyAccount;
        
        /* Set sample past balances to originalAccount */
        int * samplePastBalances = new int [copyAccount.numOfPastBalances + 1];
        for(int i ; i < copyAccount.numOfPastBalances ; i++) {
            samplePastBalances[i] = i;
        }
        originalAccount.setPastBalances(samplePastBalances);

        
        WHEN( "Copy account using operator=" ) {
            copyAccount = originalAccount;
            
            THEN( "Sum account should be equal to the each sum of the partial value")
            {
                REQUIRE( copyAccount.getBankName() == originalAccount.getBankName() );
                REQUIRE( copyAccount.getBalances() == originalAccount.getBalances() );
                REQUIRE( copyAccount.getInterestRate() == originalAccount.getInterestRate() );
                REQUIRE( copyAccount.getPastBalances() == originalAccount.getPastBalances() );
            }
        }
    }
}

SCENARIO( "Test string replace,\
         ( This replace implementation just parse starts with bank name to before ','\
         If more exact parsing, it's needed to use vector objects, and NLP skills )",
         "[string]" ) {
    GIVEN( "1. Original bank name, New bank name, and Sample sentence exist" ) {
        
        string originalBankName = "Bank of America";
        string newBankName = "Korean ExFchange Bank";
        string sampleSentence =
            "Welcome to Bank of America, the nation's leading financial institution and home for all of your personal financial needs";
        
        WHEN(
             " In the sample sentence, \
             1. Find bank name position, \
             2. Change original bank name to new name in the sample sentence" ) {
            
            size_t bankNameStartPos = sampleSentence.find(originalBankName);
            size_t origninalBankNameLength = (
                                              sampleSentence.substr(bankNameStartPos)
                                              ).find_last_of(",") - 1;
            size_t bankNameEndPos = bankNameStartPos + origninalBankNameLength;
            
            string modifiedSampleSentence = sampleSentence;
            modifiedSampleSentence =
                modifiedSampleSentence.erase(
                                             bankNameStartPos,
                                             bankNameEndPos).insert(
                                                                    bankNameStartPos,
                                                                    newBankName);

            THEN( "Bank name should starts with 11, ends with 25 in the sample.")
            {
                /* string's find method starts with 0 */
                REQUIRE( bankNameStartPos == 12 - 1 );
                REQUIRE( bankNameEndPos ==  26 - 1 );
            }
            AND_THEN("Original bank name should be changed to new bank name in the sentence")
            {
                REQUIRE( modifiedSampleSentence != sampleSentence );
                REQUIRE( modifiedSampleSentence.find(newBankName) );
            }
        }
    }
}

SCENARIO( "Test string replace using class methods", "[string], [method]" ) {
    GIVEN( "1. Original bank name, New bank name, 2. Class instance exists" ) {
        
        string originalBankName = "Bank of America";
        string newBankName = "Korean ExFchange Bank";
        string sampleSentence =
        "Welcome to Bank of America, the nation's leading financial institution and home for all of your personal financial needs";

        CBankAccount instance;
        
        WHEN(
             " In the sample sentence, \
             1. Find bank name position, \
             2. Change original bank name to new name in the sample sentence\
             USING METHODS" ) {
            
            tuple<size_t, size_t> bankNamePos = instance.FindBankInSentence(sampleSentence);
            
            string modifiedSentence =
                instance.SubstituteBankName(sampleSentence, newBankName);
                        
            THEN( "Bank name should starts with 11, ends with 25 in the sample.")
            {
                /* string's find method starts with 0 */
                REQUIRE( get<0>(bankNamePos) == 12 - 1 );
                REQUIRE( get<1>(bankNamePos) ==  26 - 1 );
            }
            AND_THEN("Original bank name should be changed to new bank name in the sentence")
            {
                REQUIRE( modifiedSentence != sampleSentence );
                REQUIRE( modifiedSentence.find(newBankName) );
            }
        }
    }
}

/* This has some problem, maybe cin causes a crash with catch */
/*
SCENARIO( "Set bank name from user input", "[user input]" ) {
    GIVEN( "expected Bank Name and CBankAccount instance exists" ) {
        string expectedBankName = "bank";
        string inputBankName;
        
        CBankAccount instance;
        
        WHEN( "Call setBankNameFromUserInput" ) {
            instance.setBankNameFromUserInput(instance);
            
            THEN( "Return value should be equal to the expectedBankName")
            {
                REQUIRE( instance.getBankName() == expectedBankName );
            }
        }
    }
}
*/

int nTimeSize =(nMaxShowTime -720)/60 +1;// 상영시간의 개수 계산
int **pTheatherSchedule =new int*[nTheater];//2차원 할당
for(int nRow =0 ; nRow <nTheater ; nRow++)
pTheatherSchedule[nRow] =new int[nTimeSize];//1차원 할당

for(int nRow =0 ; nRow <nTheater ;nRow++)
{
    for(int nColumn =0 ; 720 +nColumn*60 <= nMaxShowTime ; nColumn++)
    {
        pTheatherSchedule[nRow][nColumn] = 720 +nColumn*60;
        //	*(*(pTheatherSchedule) +nColumn) = 720 +nColumn*60;// 포인터연산은 포인터의 차원을 보기는 좋지만 가독성이 적어서 수정.
        //	cout << *(*(pTheatherSchedule) +nColumn) << endl;
    }
}

SCENARIO( "Test compound interest", "[compound interest]" ) {
    GIVEN( "Three CBankAccount instance exists, each instances have different interest rate" ) {
        double firstInterestRate = 0.1;
        double secondInterestRate = 0.2;
        double thirdInterestRate = 0.4;
        
        CBankAccount firstInstance;
        CBankAccount secondInstance;
        CBankAccount thirdInstance;
        
        firstInstance.setInterestRate(firstInterestRate);
        secondInstance.setInterestRate(secondInterestRate);
        thirdInstance.setInterestRate(thirdInterestRate);
        
        WHEN( "Call setBankNameFromUserInput" ) {
            instance.setBankNameFromUserInput(instance);
            
            THEN( "Return value should be equal to the expectedBankName")
            {
                REQUIRE( instance.getBankName() == expectedBankName );
            }
        }
    }
}

