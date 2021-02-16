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

char intToChar(int numToConvert){ //apparently can't use atoi(). so i had to make this
    char retVal = '\0';
    if (numToConvert == 0){
        retVal = '0';
    }
    else if (numToConvert == 1){
        retVal = '1';
    }
    else if (numToConvert == 2){
        retVal = '2';
    }
    else if (numToConvert == 3){
        retVal = '3';
    }
    else if (numToConvert == 4){
        retVal = '4';
    }
    else if (numToConvert == 5){
        retVal = '5';
    }
    else if (numToConvert == 6){
        retVal = '6';
    }
    else if (numToConvert == 7){
        retVal = '7';
    }
    else if (numToConvert == 8){
        retVal = '8';
    }
    else if (numToConvert == 9){
        retVal = '9';
    }
    return retVal;
}

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
        int improperNumerator1 = (c1 * d1) + n1;
        int improperNumerator2 = (c2 * d2) + n2;
        int commonDenominator = d1 * d2;

        improperNumerator1 = improperNumerator1 * (commonDenominator / d1);
        improperNumerator2 = improperNumerator2 * (commonDenominator / d2);

        int summedNumerator = improperNumerator1 + improperNumerator2;
        int summedCharacteristic = summedNumerator / commonDenominator;
        int summedMantissa = summedNumerator % commonDenominator;

    if (count_digit(summedCharacteristic) < len) { //makes sure that the string can hold at least the characteristic
        int decimalPrecision = 1;
        for (int i = 0; i < len  - (count_digit(summedCharacteristic) + 1); i++){ //this sets decimal precision i.e. how many numbers we want after decimal point
            decimalPrecision = decimalPrecision * 10;
        }
        
        int mantissaDecimalFormat = summedMantissa * (decimalPrecision / commonDenominator); //this will be zero if previous for loop never looped
        
        int characteristicStart;
        if (mantissaDecimalFormat != 0){
            for (int i = len - 1; i >= count_digit(summedCharacteristic) + 1; i--){ //this places the mantissa in the result string and then adds a decimal point before it
                result[i] = intToChar(mantissaDecimalFormat % 10);
                mantissaDecimalFormat = mantissaDecimalFormat / 10;
                if (mantissaDecimalFormat == 0){
                    result[i-1] = '.';
                    characteristicStart = i - 2;
                }
            }
        }
        else{ //bug fix where if there was no mantissa due to length constraints then the output would be garbled
            characteristicStart = count_digit(summedCharacteristic) - 1;
        }

        for (int i = characteristicStart; i >= 0; i--){ //this places the characteristic in the result string
            result[i] = intToChar(summedCharacteristic % 10);
            summedCharacteristic = summedCharacteristic / 10;
        }
        
        if (result[len-1] != '0'){ //this deals with infinite repeating decimals
            result[len-1] = '\0';
        }
        else if (mantissaDecimalFormat == 0){ //gets rid of decimal point if the number ends up being a whole number
            for (int i = 0; i < len; i++){
                if (result[i] == '.'){
                    result[i] = '\0';
                }
            }
        }
        else { //this deals with decimals that terminate before they reach len argument
            for (int i = len - 1; i >= 0 + 1; i--){
                if (result[i] != '0'){
                    result[i + 1] = '\0';
                    break;
                }
            }
        }

        cout << result << endl;


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
