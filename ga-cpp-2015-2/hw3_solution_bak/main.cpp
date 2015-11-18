#include <string>
#include <iostream>
using namespace std;

int _main(int argc, char*argv[])
{
    string input;

    if(1 < argc) {
        input = argv[1];
    }
    else {
        cin >> input;
    }

    cout << input << endl;


    return 0;
}
