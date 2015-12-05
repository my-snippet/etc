//
//  testHW4.cpp
//  hw4-solution
//
//  Created by wikibootup on 12/5/15.
//  Copyright © 2015 wikibootup. All rights reserved.
//
/* Project libraries */
#include "SSU.hpp"
#include "EE.hpp"

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

SCENARIO( "Test constructor", "[constructor]" ) {
    GIVEN( "a student data" ) {
        string firstStudentName = "foo";
        string firstStudentNumber = "123456";
        string firstStudentMajor = "Electorinc Engineering";
        
        WHEN( "declare SSU, CEE with set values" ) {
            CSSU ssuStudent(firstStudentName, firstStudentNumber);
            CEE eeStudent(firstStudentName, firstStudentNumber, firstStudentMajor);
            
            THEN( "CSSU instance value can be accessed")
            {
                REQUIRE(ssuStudent.getStudentName() == firstStudentName);
                REQUIRE(ssuStudent.getStudentNumber() == firstStudentNumber);
                
                AND_THEN("CEE instance value can be accessed") {
                    REQUIRE(eeStudent.getStudentName() == firstStudentName);
                    REQUIRE(eeStudent.getStudentNumber() == firstStudentNumber);
                    REQUIRE(eeStudent.getStudentMajor() == firstStudentMajor);
                }
            }
        }
    }
}
