#include "conversion.h"

using namespace std;

//Helper function to find the position of the decimal point inside numString. 
int pointOfDec(const char numString[])
{
    
    int j = 0;
    while (numString[j] != '.')
    {
        j++;
    };
    return j;
}


bool characteristic(const char numString[], int& c)
{
    //the first iteration of the power of ten.
    int powOfTen = 1;
    //initializing the final number.
    int finalNum = 0;

    for (int i = pointOfDec(numString) - 1; i >= 0; i--)
    {
        //takes numString at position i and subracts '0' from it which gives us the number in that position.
        int digit = numString[i] - '0';
        //multiplied houses the number inside digit multiplied by powOfTen.
        int multiplied = digit * powOfTen;
        //increases powOfTen for the next loop around. 
        powOfTen = powOfTen * 10;
        //adding the results of multiplied to finalNum each iteration.
        finalNum = finalNum + multiplied;
    }
    //assigning the results of these operations to the characteristics value
    c = finalNum;


    //as long as the result is higher than one, the bool is true. If not, false.
    if (c > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//--
bool mantissa(const char numString[], int& numerator, int& denominator)
{
    return true;
}
