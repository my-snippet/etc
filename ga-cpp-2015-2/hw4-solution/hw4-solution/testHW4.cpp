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
                ofstream wfile(fileName);
                
                if (wfile.is_open()) {
                    for(int num=0; num<numOfStudent; num++) {
                        wfile <<
                            eeStudents[num].getStudentName() << "," <<
                            eeStudents[num].getStudentNumber() << "," <<
                            eeStudents[num].getStudentMajor() << "," << endl;
                    }
                    wfile.close();
                } else {
                    cout << "Unable to open file";
                }
                
                THEN( "Read data & compare it to the original data")
                {
                    string readString;
                    ifstream seqReadIO(fileName);
                    stringstream readLine;
                    string token;
                    
                    if (seqReadIO.is_open()) {
                            int num = 0;
                            while( getline(seqReadIO, readString) ) {
                                readLine << readString;
                                
                                getline(readLine, token, ',');
                                REQUIRE( token == eeStudents[num].getStudentName());
                                
                                getline(readLine, token, ',');
                                REQUIRE( token == eeStudents[num].getStudentNumber());
                                
                                getline(readLine, token, ',');
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
    
    /*
     This implementation is only allowable when both data size equal(old & new both),

     If the data size different, implement differently
     1. Copy all the remaining data,
     2. When insert data, be careful if the old data still remain, 
        or if the remaining data deleted. Use seekg carefully.
     */
    
    GIVEN( "a student data" ) {
        string studentName = "foo";
        string studentNumber = "123456";
        string studentMajor = "Electorinc Engineering";
        
        string newStudentNumber = "0000000";
        
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
                ofstream wfile(fileName);
                
                if (wfile.is_open()) {
                    for(int num=0; num<numOfStudent; num++) {
                        wfile <<
                        eeStudents[num].getStudentName() << "," <<
                        eeStudents[num].getStudentNumber() << "," <<
                        eeStudents[num].getStudentMajor() << "," << endl;
                    }
                    wfile.close();
                } else {
                    cout << "Unable to open file";
                }
                
                AND_WHEN( "Modify 5th instance data using random access")
                {
                    string readString;
                    fstream afile(fileName);
                    stringstream readLine;
                    string token;
                    long long targetDataPos = 0;
                    
                    // get old data from the 5th instance
                    string targetData = eeStudents[targetInstanceNumber-1].getStudentNumber();
                    // set new data to the 5th instance
                    eeStudents[targetInstanceNumber-1].setStudentNumber(newStudentNumber);
                    
                    if (afile.is_open()) {
                        long long pos = 0;
                        int num = 0;
                        
                        // Hardcoded, It should be changed to a function
                        // and for loop -> while recommended, but it has some problem.
                        while( getline(afile, readString) ) {
                            //cout << readString << endl;
                            if( readString.find(targetData) != string::npos ) {
                                readLine << readString;
                                long long tokenPos = 0;
                                
                                while(getline(readLine, token, ',')) {
                                    if(token == targetData) {
                                        // Move file pointer to the target data( It's used when test )
                                        targetDataPos = pos + tokenPos;
                                        
                                        
                                        // Backup the original remaining data
                                        string remainingData;
                                        getline(readLine, remainingData);
                                        
                                        // Modify target data to new data
                                        afile.seekg(targetDataPos);
                                        afile << eeStudents[targetInstanceNumber-1].getStudentNumber();
                                        afile.seekg(1, ios::cur);   // comma pass
                                        afile << remainingData;
                                        
                                        afile.seekg(targetDataPos);
                                        getline(afile, readString, ',');
                                        
                                        afile.seekg(targetDataPos);
                                        
                                        while( getline(afile, readString) ) {
                                            cout << readString << endl;
                                        }
                                        
                                        // To get out of the while loop
                                        afile.seekg(0, ios::end);
                                        break;
                                    }
                                    tokenPos = readLine.tellg();
                                }
                            }
                            pos = afile.tellg();
                        }
                    }
                    
                    THEN("Compare the file data to new data to check data is changed") {
                        
                        // Re-open because of the variable boundary
                        fstream afile(fileName);
                        afile.seekg(targetDataPos);
                        getline(afile, readString, ',');
                        
                        REQUIRE(readString == eeStudents[targetInstanceNumber-1].getStudentNumber());
                        
                        AND_THEN("file close & free dynamic data") {
                            delete[] eeStudents;
                            afile.close();
                        }
                    }
                }
            }
        }
    }
}
