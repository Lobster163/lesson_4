#include "include/lesson_4.h"

int main()
{
    srand(time(0));
    ArrayInt myArray(15, 0);
    myArray.print();

    for (int i = 0; i < myArray.size(); ++i)
        myArray[i] = rand() % 30;
    myArray.print();

    myArray.pop_back();
    myArray.print();

    myArray.pop_front();
    myArray.print();

    myArray.sort();
    myArray.print();
}

