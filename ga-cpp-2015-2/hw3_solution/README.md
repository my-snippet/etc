
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
hw3_solution is a Catch v1.2.1 host application.
Run with -? for options

-------------------------------------------------------------------------------
Scenario: Test sample (array object test example)
     Given: This stuff exists
      When: I do this
      Then: it should do this
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:24
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:31: 
PASSED:
  REQUIRE( input[0] == "abc" )
with expansion:
  "abc" == "abc"

-------------------------------------------------------------------------------
Scenario: Test sample (array object test example)
     Given: This stuff exists
      When: I do this
      Then: it should do this
       And: do that
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:24
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:33: 
PASSED:
  REQUIRE( input[1] == "def" )
with expansion:
  "def" == "def"

-------------------------------------------------------------------------------
Scenario: initial pastBalances return NULL
     Given: This stuff exists
      When: I do this
      Then: it should do this
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:39
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:46: 
PASSED:
  REQUIRE( instance.getPastBalances() == __null )
with expansion:
  __null == 0

-------------------------------------------------------------------------------
Scenario: Test set, get methods
     Given: The CBankAccount instance exists
      When: Set instance variables as a some value
      Then: Instance variables should be equal to set values
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:52
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:73: 
PASSED:
  REQUIRE( instance.getBankName() == bank1 )
with expansion:
  "bank1" == "bank1"

/hw3_solution/hw3_solution/testBankAccount.cpp:74: 
PASSED:
  REQUIRE( instance.getBalances() == balances1 )
with expansion:
  123 == 123

/hw3_solution/hw3_solution/testBankAccount.cpp:75: 
PASSED:
  REQUIRE( instance.getInterestRate() == interestRate1 )
with expansion:
  1.17 == 1.17

-------------------------------------------------------------------------------
Scenario: Test set 3 values using just the one method
     Given: The CBankAccount init using constructor
      When: Set instance variables as a some value
      Then: Instance variables should be equal to set values
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:81
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:92: 
PASSED:
  REQUIRE( instance.getBankName() == bank1 )
with expansion:
  "bank1" == "bank1"

/hw3_solution/hw3_solution/testBankAccount.cpp:93: 
PASSED:
  REQUIRE( instance.getBalances() == balances1 )
with expansion:
  123 == 123

/hw3_solution/hw3_solution/testBankAccount.cpp:94: 
PASSED:
  REQUIRE( instance.getInterestRate() == interestRate1 )
with expansion:
  1.17 == 1.17

-------------------------------------------------------------------------------
Scenario: Test set 3 values using just the one method
     Given: The CBankAccount init using constructor
      When: Set instance variables as a some value
       And: Also, pastBalances should be set NULL
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:81
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:97: 
PASSED:
  REQUIRE( instance.getPastBalances() == __null )
with expansion:
  __null == 0

-------------------------------------------------------------------------------
Scenario: instance 
     Given: The CBankAccount init using constructor
      When: Set instance variables as a some value
      Then: Instance variables should be equal to set values
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:103
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:114: 
PASSED:
  REQUIRE( instance.getBankName() == bank1 )
with expansion:
  "bank1" == "bank1"

/hw3_solution/hw3_solution/testBankAccount.cpp:115: 
PASSED:
  REQUIRE( instance.getBalances() == balances1 )
with expansion:
  123 == 123

/hw3_solution/hw3_solution/testBankAccount.cpp:116: 
PASSED:
  REQUIRE( instance.getInterestRate() == interestRate1 )
with expansion:
  1.17 == 1.17

-------------------------------------------------------------------------------
Scenario: instance 
     Given: The CBankAccount init using constructor
      When: Set instance variables as a some value
       And: Also, pastBalances should be set NULL
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:103
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:119: 
PASSED:
  REQUIRE( instance.getPastBalances() == __null )
with expansion:
  __null == 0

-------------------------------------------------------------------------------
Scenario: Test CBankAccount operator+
     Given: Initialze third bank data
      When: Add two instance using operator+
      Then: Sum account should be equal to the each sum of the partial value
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:125
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:159: 
PASSED:
  REQUIRE( thirdAccount.getBankName() == firstAccountBankName )
with expansion:
  "foo Bank" == "foo Bank"

/hw3_solution/hw3_solution/testBankAccount.cpp:160: 
PASSED:
  REQUIRE( thirdAccount.getBalances() == sumAccountBalances )
with expansion:
  444 (0x1bc) == 444 (0x1bc)

/hw3_solution/hw3_solution/testBankAccount.cpp:161: 
PASSED:
  REQUIRE( thirdAccount.getInterestRate() == sumBankInterestRate )
with expansion:
  4.44 == 4.44

-------------------------------------------------------------------------------
Scenario: Test setPastBalances
     Given: Sample past balances exist
      When: Apply past balances to instance
      Then: instance's past balances should be equal to samplePastBalances
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:167
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  0 == 0

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  1 == 1

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  2 == 2

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  3 == 3

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  4 == 4

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  5 == 5

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  6 == 6

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  7 == 7

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  8 == 8

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  9 == 9

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  10 == 10

/hw3_solution/hw3_solution/testBankAccount.cpp:184: 
PASSED:
  REQUIRE( pastBalances[i] == samplePastBalances[i] )
with expansion:
  11 == 11

Bank name :
Balances :0
InterestRate :0
PastBalanced #0 : 0
PastBalanced #1 : 1
PastBalanced #2 : 2
PastBalanced #3 : 3
PastBalanced #4 : 4
PastBalanced #5 : 5
PastBalanced #6 : 6
PastBalanced #7 : 7
PastBalanced #8 : 8
PastBalanced #9 : 9
PastBalanced #10 : 10
PastBalanced #11 : 11

-------------------------------------------------------------------------------
Scenario: Test CBankAccount operator=
     Given: 1. Initialze one bank data, 2. Set sample past balances to
            originalAccount
      When: Copy account using operator=
      Then: Sum account should be equal to the each sum of the partial value
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:214
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:242: 
PASSED:
  REQUIRE( copyAccount.getBankName() == originalAccount.getBankName() )
with expansion:
  "foo Bank" == "foo Bank"

/hw3_solution/hw3_solution/testBankAccount.cpp:243: 
PASSED:
  REQUIRE( copyAccount.getBalances() == originalAccount.getBalances() )
with expansion:
  123 == 123

/hw3_solution/hw3_solution/testBankAccount.cpp:244: 
PASSED:
  REQUIRE( copyAccount.getInterestRate() == originalAccount.getInterestRate() )
with expansion:
  1.23 == 1.23

/hw3_solution/hw3_solution/testBankAccount.cpp:245: 
PASSED:
  REQUIRE( copyAccount.getPastBalances() == originalAccount.getPastBalances() )
with expansion:
  0x00007fd0b1c0bc00 == 0x00007fd0b1c0bc00

-------------------------------------------------------------------------------
Scenario: Test string replace,         ( This replace implementation just parse
          starts with bank name to before ','         If more exact parsing,
          it's needed to use vector objects, and NLP skills )
     Given: 1. Original bank name, New bank name, and Sample sentence exist
      When:  In the sample sentence,              1. Find bank name position,  
                       2. Change original bank name to new name in the sample
            sentence
      Then: Bank name should starts with 11, ends with 25 in the sample.
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:254
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:284: 
PASSED:
  REQUIRE( bankNameStartPos == 12 - 1 )
with expansion:
  11 == 11

/hw3_solution/hw3_solution/testBankAccount.cpp:285: 
PASSED:
  REQUIRE( bankNameEndPos == 26 - 1 )
with expansion:
  25 == 25

-------------------------------------------------------------------------------
Scenario: Test string replace,         ( This replace implementation just parse
          starts with bank name to before ','         If more exact parsing,
          it's needed to use vector objects, and NLP skills )
     Given: 1. Original bank name, New bank name, and Sample sentence exist
      When:  In the sample sentence,              1. Find bank name position,  
                       2. Change original bank name to new name in the sample
            sentence
       And: Original bank name should be changed to new bank name in the
            sentence
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:254
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:289: 
PASSED:
  REQUIRE( modifiedSampleSentence != sampleSentence )
with expansion:
  "Welcome to Korean ExFchange Bankon's leading financial institution and home
  for all of your personal financial needs"
  !=
  "Welcome to Bank of America, the nation's leading financial institution and
  home for all of your personal financial needs"

/hw3_solution/hw3_solution/testBankAccount.cpp:290: 
PASSED:
  REQUIRE( modifiedSampleSentence.find(newBankName) )
with expansion:
  true

-------------------------------------------------------------------------------
Scenario: Test string replace using class methods
     Given: 1. Original bank name, New bank name, 2. Class instance exists
      When:  In the sample sentence,              1. Find bank name position,  
                       2. Change original bank name to new name in the sample
            sentence             USING METHODS
      Then: Bank name should starts with 11, ends with 25 in the sample.
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:296
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:320: 
PASSED:
  REQUIRE( get<0>(bankNamePos) == 12 - 1 )
with expansion:
  11 == 11

/hw3_solution/hw3_solution/testBankAccount.cpp:321: 
PASSED:
  REQUIRE( get<1>(bankNamePos) == 26 - 1 )
with expansion:
  25 == 25

-------------------------------------------------------------------------------
Scenario: Test string replace using class methods
     Given: 1. Original bank name, New bank name, 2. Class instance exists
      When:  In the sample sentence,              1. Find bank name position,  
                       2. Change original bank name to new name in the sample
            sentence             USING METHODS
       And: Original bank name should be changed to new bank name in the
            sentence
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:296
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:325: 
PASSED:
  REQUIRE( modifiedSentence != sampleSentence )
with expansion:
  "Welcome to Korean ExFchange Bankon's leading financial institution and home
  for all of your personal financial needs"
  !=
  "Welcome to Bank of America, the nation's leading financial institution and
  home for all of your personal financial needs"

/hw3_solution/hw3_solution/testBankAccount.cpp:326: 
PASSED:
  REQUIRE( modifiedSentence.find(newBankName) )
with expansion:
  true

-------------------------------------------------------------------------------
Scenario: Test compound interest
     Given: Three CBankAccount instance exists, each instances have different
            interest rate
      When: Set Compount values data using CalCompoundValue
      Then: Compound value should be equal to the Calculated Compound value
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:353
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  100.0 == 100.0

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  100.0 == 100.0

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  100.0 == 100.0

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  101.0 == 101.0

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  102.0 == 102.0

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  104.0 == 104.0

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  102.01 == 102.01

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  104.04 == 104.04

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  108.16 == 108.16

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  103.0301 == 103.0301

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  106.1208 == 106.1208

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  112.4864 == 112.4864

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  104.060401 == 104.060401

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  108.243216 == 108.243216

/hw3_solution/hw3_solution/testBankAccount.cpp:404: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] == accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  116.985856 == 116.985856

-------------------------------------------------------------------------------
Scenario: Test compound interest
     Given: Three CBankAccount instance exists, each instances have different
            interest rate
      When: Set Compount values data using CalCompoundValue
  And when: Delete the allocated Memory
       And: The Deallocated variable value should be deleted
-------------------------------------------------------------------------------
/hw3_solution/hw3_solution/testBankAccount.cpp:353
...............................................................................

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  -0.0 != 100.0

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  0.0 != 100.0

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  100.0 != 100.0

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  -0.0 != 101.0

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  2320358383399720556484361647137702729473312564732534390129468725132276174684-
  16.0
  !=
  102.0

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  104.0 != 104.0

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  0.0 != 102.01

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  0.0 != 104.04

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  0.0 != 108.16

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  0.0 != 103.0301

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  0.0 != 106.1208

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  0.0 != 112.4864

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  5986265615468036265967755285077648595010454020793702427961256678208309520891-
  7557255576587651517383583983484127923588954451086322141867841888621046612554-
  560964932536992257802240.0
  !=
  104.060401

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  6524642312674151164303516179263048819418117689309306549971033945488679086560-
  7971385990199549674327848445425550539243593643906287518767184527948957035471-
  7399121465086886649425559552.0
  !=
  108.243216

/hw3_solution/hw3_solution/testBankAccount.cpp:425: 
PASSED:
  REQUIRE( compoundValueBundle[row][col] != accountsBundle[col].getBalances() * pow(1 + accountsBundle[col].getInterestRate(), row) )
with expansion:
  5285555291328887614102858826097943368487370158817202161718564534429690395967-
  7292886816556450374826573446399387858976994363303689136556517614885130304752-
  80440551638907414265284526080.0
  !=
  116.985856

===============================================================================
All tests passed (71 assertions in 12 test cases)


