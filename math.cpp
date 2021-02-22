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
    //creates an area to store the decimals in
    char Mdecimal[len];
    char Mwhole[len];

    //Creates the improper fraction for both numbers
    int Mfraction1 = (c1 * d1) + n1;
    int Mfraction2 = (c2 * d2) + n2;

    //Multiplies the two improper fractions into one improper fraction
    int Mnumerator = Mfraction1 * Mfraction2;
    int Mdenominator = d1 * d2;

    //Gets the whole number from the fraction and the remainder of the fraction
    int Mnumber = Mnumerator / Mdenominator;
    int Mremainder = Mnumerator % Mdenominator;

    //Multiples the remainder until it is larger than the denominator and puts a zero for each time in the array
    int i = 0;
    for (int j = 0, j < 10, j++)
        if (Mremainder < c2) {
            Mremainder *= 10;
            Mdecimal[i] = 0;
            i++;
        }
        else {
            Mdecimal[i] = Mremainder / c2;
            Mremainder = sprintf(char_rem, "%d", (Mremainder % c2));
            i++;
        }

    result[0] = sprintf(char_num, "%d", Mnumber);

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
    //creates an area to store the decimals in
    char Ddecimal[len];
    char Mwhole[len];

    //Creates the improper fraction for both numbers
    int Dfraction1 = (c1 * d1) + n1;
    int Dfraction2 = (c2 * d2) + n2;

    //Divides the two fractions into one improper fraction
    int Dnumerator = Dfraction1 * d2;
    int Ddenominator = Dfraction2 * d1;

    //Gets the whole number from the fraction and the remainder of the fraction
    int Dnumber = Dnumerator / Ddenominator; 
    int Dremainder = Dnumerator % Ddenominator;

    //Divides the remainder until it is larger than the denominator and puts a zero for each time in the array
    int i = 0;
    for (int j = 0, j < 10, j++)
        if (Dremainder < c2) {
            Dremainder *= 10;
            Ddecimal[i] = 0;
            i++;
        }
        else {
            Ddecimal[i] = Dremainder / c2;
            Dremainder = sprintf(char_rem, "%d", (Dremainder % c2));
            i++;
        }

    result[0] = sprintf(char_num, "%d", Dnumber);
    int l = 0;
    for (int k = 1, k < len, k++) {
        result[k] = Ddecimal[l];
        l++;
    }

    return true;
}
