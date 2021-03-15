#include "math.h"

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return true;
}
//--
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return true;
}
//--
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    int count_digit(int number) { //counts the number of digits in an integer
        int count = 0;
        while (number != 0) {
            number = number / 10;
            count++;
        }
        return count;
    }

    char intToChar(int numToConvert) { //apparently can't use atoi(). so i had to make this
        char retVal = '\0';
        if (numToConvert == 0) {
            retVal = '0';
        }
        else if (numToConvert == 1 || numToConvert == -1) {
            retVal = '1';
        }
        else if (numToConvert == 2 || numToConvert == -2) {
            retVal = '2';
        }
        else if (numToConvert == 3 || numToConvert == -3) {
            retVal = '3';
        }
        else if (numToConvert == 4 || numToConvert == -4) {
            retVal = '4';
        }
        else if (numToConvert == 5 || numToConvert == -5) {
            retVal = '5';
        }
        else if (numToConvert == 6 || numToConvert == -6) {
            retVal = '6';
        }
        else if (numToConvert == 7 || numToConvert == -7) {
            retVal = '7';
        }
        else if (numToConvert == 8 || numToConvert == -8) {
            retVal = '8';
        }
        else if (numToConvert == 9 || numToConvert == -9) {
            retVal = '9';
        }
        return retVal;
    }

    result[len] = '\0';

    //creates an area to store the decimals in
    char Mdecimal[];
    char Mwhole[];

    //Creates the improper fraction for both numbers
    int Mfraction1 = (c1 * d1) + n1;
    int Mfraction2 = (c2 * d2) + n2;

    //Multiplies the two improper fractions into one improper fraction
    int Mnumerator = Mfraction1 * Mfraction2;
    int Mdenominator = d1 * d2;

    if (Mdenominator == 0)
        return false;

    //Gets the whole number from the fraction and the remainder of the fraction
    int Mnumber = Mnumerator / Mdenominator;
    int Mremainder = Mnumerator % Mdenominator;

    //Multiples the remainder until it is larger than the denominator and puts a zero for each time in the array
    int i = count_digit(Mnumber);
    for (int j = 0; j < 10; j++)
        if (i < len) {
            if (Mremainder < c2) {
                Mremainder *= 10;
                Mdecimal[i] = '0';
                i++;
            }
            else {
                Mdecimal[i] = intToChar(Mremainder / c2);
                i++;
            }
        }
    //result[0] = 

    int l = 0;
    for (int k = 1, k < len, k++) {
        result[k] = Mdecimal[l];
        l++;
    }


    return true;
}
//--
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    int count_digit(int number) { //counts the number of digits in an integer
        int count = 0;
        while (number != 0) {
            number = number / 10;
            count++;
        }
        return count;
    }

    char intToChar(int numToConvert) {
        char retVal = '\0';
        if (numToConvert == 0) {
            retVal = '0';
        }
        else if (numToConvert == 1 || numToConvert == -1) {
            retVal = '1';
        }
        else if (numToConvert == 2 || numToConvert == -2) {
            retVal = '2';
        }
        else if (numToConvert == 3 || numToConvert == -3) {
            retVal = '3';
        }
        else if (numToConvert == 4 || numToConvert == -4) {
            retVal = '4';
        }
        else if (numToConvert == 5 || numToConvert == -5) {
            retVal = '5';
        }
        else if (numToConvert == 6 || numToConvert == -6) {
            retVal = '6';
        }
        else if (numToConvert == 7 || numToConvert == -7) {
            retVal = '7';
        }
        else if (numToConvert == 8 || numToConvert == -8) {
            retVal = '8';
        }
        else if (numToConvert == 9 || numToConvert == -9) {
            retVal = '9';
        }
        return retVal;
    }

    result[len] = '\0';

    //creates an area to store the decimals in
    char Ddecimal[len];
    char Mwhole[len];

    //Creates the improper fraction for both numbers
    int Dfraction1 = (c1 * d1) + n1;
    int Dfraction2 = (c2 * d2) + n2;

    //Divides the two fractions into one improper fraction
    int Dnumerator = Dfraction1 * d2;
    int Ddenominator = Dfraction2 * d1;

    if (Ddenominator == 0)
        return false;

    //Gets the whole number from the fraction and the remainder of the fraction
    int Dnumber = Dnumerator / Ddenominator;
    int Dremainder = Dnumerator % Ddenominator;

    //Divides the remainder until it is larger than the denominator and puts a zero for each time in the array
    int i = count_digit(Dnumber);
    for (int j = 0; j < 10; j++)
        if (i < len) {
            if (Dremainder < c2) {
                Dremainder *= 10;
                Ddecimal[i] = '0';
                i++;
            }
            else {
                Ddecimal[i] = intToChar(Dremainder / c2);
                i++;
            }
        }
 
    int l = 0;
    for (int k = 1, k < len, k++) {
        result[k] = Ddecimal[l];
        l++;
    }

    return true;
}
