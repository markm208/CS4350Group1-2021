#include <iostream>
#include "math.h"

using namespace std;

int count_digit(int number) { //counts the number of digits in an integer
   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    if (count_digit(c1 + c2) <= len) { //makes sure that the string can hold at least the characteristic
        int improperNumerator1 = (c1 * d1) + n1;
        int improperNumerator2 = (c2 * d2) + n2;
        int commonDenominator = d1 * d2;

        improperNumerator1 = improperNumerator1 * (commonDenominator / d1);
        improperNumerator2 = improperNumerator2 * (commonDenominator / d2);

        cout << improperNumerator1 + improperNumerator2 << " over " << commonDenominator << endl;

        return true;
    }
    else {
        return false;
    }
}
//--
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return true;
}
//--
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return true;
}
//--
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return true;
}
