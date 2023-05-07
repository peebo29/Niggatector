#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main()
{
    string filename = "niggasdetected.txt";  // name of the file to store the counter

    // read the current value of the counter from the file
    int counter = 0;
    ifstream infile(filename);
    if (infile.good())
    {
        infile >> counter;
    }
    infile.close();

    // increment the counter
    counter++;

    // save the updated counter back to the file
    ofstream outfile(filename);
    if (outfile.good())
    {
        outfile << counter;
    }
    outfile.close();

    // print the updated counter value
    cout << "Niggas Detected " << counter << endl;

    // prompt the user to run the program again
    cout << "Press 'enter' to detect the niggas again, or press any other key to stop detecting: ";

    // wait for user input
    bool should_run_again = false;
    if (cin.get() == '\n')
    {
        should_run_again = true;
    }

    if (should_run_again)
    {
        // start a new instance of the same program
        LPCTSTR program_name = TEXT("Niggatector.exe");
        HINSTANCE result = ShellExecute(NULL, NULL, program_name, NULL, NULL, SW_SHOW);
        if (result == NULL)
        {
            cout << "Error starting Niggatector: " << GetLastError() << endl;
        }
    }

    return 0;
}