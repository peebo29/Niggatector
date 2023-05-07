#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main()
{
    string filename = "niggasdetected.txt";

    int counter = 0;
    ifstream infile(filename);
    if (infile.good())
    {
        infile >> counter;
    }
    infile.close();

    counter++;

    ofstream outfile(filename);
    if (outfile.good())
    {
        outfile << counter;
    }
    outfile.close();

    cout << "Niggas Detected " << counter << endl;

    cout << "Press 'enter' to detect the niggas again, or press any other key to stop detecting: ";

    bool should_run_again = false;
    if (cin.get() == '\n')
    {
        should_run_again = true;
    }

    if (should_run_again)
    {
        LPCTSTR program_name = TEXT("Niggatector.exe");
        HINSTANCE result = ShellExecute(NULL, NULL, program_name, NULL, NULL, SW_SHOW);
        if (result == NULL)
        {
            cout << "Error starting Niggatector: " << GetLastError() << endl;
        }
    }

    return 0;
}