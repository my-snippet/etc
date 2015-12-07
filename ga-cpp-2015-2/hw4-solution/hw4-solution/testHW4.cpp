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
            
            AND_WHEN("Write instance(Student) data to a file") {
                const string fileName = "sequencialIO.csv";
                ofstream seqWriteIO(fileName);
                
                if (seqWriteIO.is_open()) {
                    for(int num=0; num<numOfStudent; num++) {
                        seqWriteIO <<
                            eeStudents[num].getStudentName() << "," <<
                            eeStudents[num].getStudentNumber() << "," <<
                            eeStudents[num].getStudentMajor() << "," << endl;
                    }
                    seqWriteIO.close();
                } else {
                    cout << "Unable to open file";
                }
                
                THEN( "Read data & compare it to the original data")
                {
                    string readString;
                    ifstream seqReadIO(fileName);
                    stringstream seqReadLine;
                    string token;
                    
                    if (seqReadIO.is_open()) {
                            int num = 0;
                            while( getline(seqReadIO, readString) ) {
                                seqReadLine << readString;
                                getline(seqReadLine, token, ',');
                                
                                REQUIRE( token == eeStudents[num].getStudentName());
                                
                                getline(seqReadLine, token, ',');
                                REQUIRE( token == eeStudents[num].getStudentNumber());
                                
                                getline(seqReadLine, token, ',');
                                REQUIRE( token == eeStudents[num].getStudentMajor());
                                
                                num++;
                            }
                        seqReadIO.close();
                    }
                    
                    AND_THEN("free dynamic data") {
                        delete[] eeStudents;
                    }
                }
            }
        }
    }
}

SCENARIO( "Test Random access IO", "[IO]" ) {

    /*
    1. Write instance data using random access IO.
    2. Find the position of 5th instance data using get methods & string find
    3. Modify the data as new data.
    4. Test it is changed.
     */
    
    GIVEN( "a student data" ) {
        string studentName = "foo";
        string studentNumber = "123456";
        string studentMajor = "Electorinc Engineering";
        
        string newStudentNumber = "654321000002929298383884";
        
        int targetInstanceNumber = 5;
        
        WHEN( "declare CEE array & set values" ) {
            const int numOfStudent = 7;
            CEE * eeStudents = new CEE [numOfStudent];
            
            for(int num=0; num<numOfStudent; num++) {
                eeStudents[num].setStudentInfo(studentName + to_string(num),
                                               studentNumber + to_string(num),
                                               studentMajor + to_string(num));
            }
            
            AND_WHEN("Write instance(Student) data to a file") {
                const string fileName = "sequencialIO.csv";
                ofstream seqWriteIO(fileName);
                
                if (seqWriteIO.is_open()) {
                    for(int num=0; num<numOfStudent; num++) {
                        seqWriteIO <<
                        eeStudents[num].getStudentName() << "," <<
                        eeStudents[num].getStudentNumber() << "," <<
                        eeStudents[num].getStudentMajor() << "," << endl;
                    }
                    seqWriteIO.close();
                } else {
                    cout << "Unable to open file";
                }
                
                THEN( "Modify 5th instance data & Compare it to the original data")
                {
                    string readString;
                    fstream afile(fileName);
                    
                    string targetData = eeStudents[targetInstanceNumber-1].getStudentName();
                    
                    // set new data to the 5th instance
                    eeStudents[targetInstanceNumber-1].setStudentNumber(newStudentNumber);
                    
                    if (afile.is_open()) {
                        long long pos = 0;
                        long long targetDataPos = -1;
                        
                        // Hardcoded, It should be changed to a function
                        while( getline(afile, readString, ',') ) {
                            
                            pos = afile.tellg();
                            
                            if(readString.find(targetData) != string::npos ) {
                                //targetDataPos = pos;    // Backup target pos
                                
                                cout << readString << endl;
                                
                                // Backup the original remaining line
                                getline(afile, readString, ',');
                                getline(afile, readString);
//                                cout << readString << endl;
                                
                                // Write new data & remaining line
                                afile.seekg(targetDataPos);
                                getline(afile, readString);
                                //cout << readString << endl;
                                /*
                                afile
                                    << eeStudents[targetInstanceNumber-1].getStudentNumber()
                                    << readString
                                    << endl;
                                */
                                break;
                            }
                        }
                        
                        afile.seekg(0);
                        while( getline(afile, readString, ',') ) {
                            //cout << readString << endl;
                        }
                        
                        afile.close();
                    }
                    
                    AND_THEN("free dynamic data") {
                        delete[] eeStudents;
                    }
                }
            }
        }
    }
}
