#include "include/lesson_4.h"
using namespace std;

#include <algorithm>
#include <windows.h>
#include <stdio.h>

void print(const vector<int>& a)
{
    for (const int v : a)
        cout << v << " ";
    cout << endl;
}

void printCurrTime()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    cout << st.wMinute << ":" << st.wSecond << "." << st.wMilliseconds << endl;
}

int main()
{
    srand(time(0));   //if test need remove or comment

    //ArrayInt myArray(123456789, 0); //only for test
     ArrayInt myArray(20, 0);
    myArray.print();

    for (int i = 0; i < myArray.size(); ++i)
        myArray[i] = rand() % 30;
    myArray.print();

    myArray.pop_back();
    myArray.print();

    myArray.pop_front();
    myArray.print();

    //printCurrTime();  //for test
    myArray.sort();
    myArray.print();
    //printCurrTime();  //for test


    cout << "\np2\n";
    vector<int>number = { 0,2,9,7,11,66,4,3,2,0,1,7,8,96,54,33,10 };
    print(number);

    std::sort(number.begin(), number.end());
    number.erase(std::unique(number.begin(), number.end()), number.end());
    print(number);
    cout << "count uniq=" << number.size() << endl;

    cout << "\np3\n";
}

