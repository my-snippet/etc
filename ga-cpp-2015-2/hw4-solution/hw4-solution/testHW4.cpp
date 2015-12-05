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
#include <fstream>

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
        string studentName = "foo";
        string studentNumber = "123456";
        string studentMajor = "Electorinc Engineering";
        
        WHEN( "declare SSU, CEE with set values" ) {
            CSSU ssuStudent(studentName, studentNumber);
            CEE eeStudent(studentName, studentNumber, studentMajor);
            
            THEN( "CSSU instance value can be accessed")
            {
                REQUIRE(ssuStudent.getStudentName() == studentName);
                REQUIRE(ssuStudent.getStudentNumber() == studentNumber);
                
                AND_THEN("CEE instance value can be accessed") {
                    REQUIRE(eeStudent.getStudentName() == studentName);
                    REQUIRE(eeStudent.getStudentNumber() == studentNumber);
                    REQUIRE(eeStudent.getStudentMajor() == studentMajor);
                }
            }
        }
    }
}

SCENARIO( "Test basic file IO", "[IO]" ) {
    GIVEN( "a student data" ) {
        string studentName = "foo";
        string studentNumber = "123456";
        string studentMajor = "Electorinc Engineering";
        
        WHEN( "declare CEE array & set values" ) {
            const int numOfStudent = 10;
            CEE * eeStudents = new CEE [numOfStudent];
            
            for(int num=0; num<numOfStudent; num++) {
                eeStudents[num].setStudentInfo(studentName + to_string(num),
                                               studentNumber + to_string(num),
                                               studentMajor + to_string(num));
            }
            
            THEN( "CSSU instance value can be accessed")
            {
                AND_THEN("") {
                    delete[] eeStudents;
                }
            }
        }
    }
}
