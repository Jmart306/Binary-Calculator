// Project4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
int findMaxVal(vector<int> &arr);
int binString(vector<int>& arr);


int main()
{
    std::vector<int> arr;
    int binaryValue;
    int Decimal = 0;
    cout << "Enter a binary number, type any # besides 0 or 1 to end " << endl;
    do {
        cin >> binaryValue;

        arr.push_back(binaryValue);

    } while (binaryValue == 1 || binaryValue == 0);

   /* for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << "Number #" << i + 1 << ": " << arr.at(i) << endl;
    }
    */// DEBUG FUNCTION 

    int MaxVal = findMaxVal(arr);
    int binaryNumber = binString(arr);

    cout << "The binary number you typed equals " << binaryNumber << endl;
    cout << "The max value of this binary is " << MaxVal << endl;
    for (int i = 0; i < arr.size() - 1; i++)
    {
       // cout << "test" << endl; // DEBUG CODE
        int bValue = MaxVal / ( pow(2, i) ) ;
        int aValue = arr.at(i);
        Decimal += bValue * aValue;
    }
    cout << "The decimal value of your Binary is " << Decimal << endl;


    return 0;
}

//GIVES THE VALUE OF THE LARGEST SINGLE VALUE GIVEN BY YOUR BINARY NUMBER
int findMaxVal(vector<int> &arr)
{

    int maxVal = 1;
    for (int i = 1; i < arr.size() - 1; i++)
    {
       maxVal *= 2;
    }

    return maxVal;
}

// TURNS YOUR SEPERATED SINGLE BINARY VALUES INTO A CONNECTED BINARY NUMBER
int binString(vector<int>& arr)
{
    string binString = to_string(arr.at(0));
    for (int i = 1; i < arr.size() - 1; i++)
    {
        binString += to_string(arr.at(i));
    }
    int binary = stoi(binString);
    return binary;
}