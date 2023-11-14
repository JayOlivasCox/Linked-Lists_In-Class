#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

#include "LetterFrequency.h"

int main()
{
    ifstream inputFile;
    string infilename;

    cout << "Enter the input file name: \n";
    getline(cin, infilename);

    inputFile.open(infilename);

    if (!inputFile)
    {
        cout << "Failed to open " << infilename << " for reading.\n";
    }
    else
    {
        char sorted;
        cout << "Build sorted list? (y/n): \n";
        cin >> sorted;

        LetterFrequencyList fileList;

        char ch;
        while (inputFile >> ch) {
            if (isalpha(ch)) {
                ch = toupper(ch);
                if (sorted == 'y') {
                    fileList.insertInOrder(ch);
                }
                else {
                    fileList.append(ch);
                }
            }
        }

        inputFile.close();

        fileList.print();
    }
}