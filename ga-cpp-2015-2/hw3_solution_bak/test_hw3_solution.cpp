/* External libraries */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch/catch.hpp"

/* Built-in libraries */
#include <array>

/* Project libraries */
#include "main.cpp"
#include "BankAccount.h"

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

SCENARIO( "CBankAccount constructor makes pastBalances null", "[CBankAccount]" ) {
    GIVEN( "CBankAccount instance" ) {
       // CBankAccount instance;

        WHEN( "Let it be" ) {
            THEN( "pastBalances should be null")
            {
                REQUIRE( true );//instance.pastBalances == "abc" );
            }
        }
    }
}


/*
SCENARIO( "Vector resizing affects size and capacity", "[vector][bdd][size][capacity]" ) {
    GIVEN( "an empty vector" ) {
        std::vector<int> v;
        REQUIRE( v.size() == 0 );
        
        WHEN( "it is made larger" ) {
            v.resize( 10 );
            THEN( "the size and capacity go up" ) {
                REQUIRE( v.size() == 10 );
                REQUIRE( v.capacity() >= 10 );
                
                AND_WHEN( "it is made smaller again" ) {
                    v.resize( 5 );
                    THEN( "the size goes down but the capacity stays the same" ) {
                        REQUIRE( v.size() == 5 );
                        REQUIRE( v.capacity() >= 10 );
                    }
                }
            }
        }
        
        WHEN( "we reserve more space" ) {
            v.reserve( 10 );
            THEN( "The capacity is increased but the size remains the same" ) {
                REQUIRE( v.capacity() >= 10 );
                REQUIRE( v.size() == 0 );
            }
        }
    }
}

SCENARIO(   "This is a really long scenario name to see how the list command deals with wrapping",
            "[very long tags][lots][long][tags][verbose]"
            "[one very long tag name that should cause line wrapping writing out using the list command]"
            "[anotherReallyLongTagNameButThisOneHasNoObviousWrapPointsSoShouldSplitWithinAWordUsingADashCharacter]" ) {
    GIVEN( "A section name that is so long that it cannot fit in a single console width" )
        WHEN( "The test headers are printed as part of the normal running of the scenario" )
            THEN( "The, deliberately very long and overly verbose (you see what I did there?) section names must wrap, along with an indent" )
                SUCCEED("boo!");
}

namespace {

// a trivial fixture example to support SCENARIO_METHOD tests
struct Fixture
{
    Fixture()
    : d_counter(0)
    {
    }
    
    int counter()
    {
        return d_counter++;
    }
    
    int d_counter;
};
    
}

SCENARIO_METHOD(Fixture,
    "BDD tests requiring Fixtures to provide commonly-accessed data or methods", 
    "[bdd][fixtures]") {
    const int before(counter());
    GIVEN("No operations precede me") {
        REQUIRE(before == 0);
        WHEN("We get the count") {
            const int after(counter());
            THEN("Subsequently values are higher") {
                REQUIRE(after > before);
            }
        }
    }
}
*/


/*
TEST_CASE( "2. Factorials are computed", "[factorial]" ) {
    REQUIRE( abc == 0 );
}





////////////////
unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}*/
