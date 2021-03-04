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
    else if (numToConvert == 1 || numToConvert == -1){
        retVal = '1';
    }
    else if (numToConvert == 2 || numToConvert == -2){
        retVal = '2';
    }
    else if (numToConvert == 3 || numToConvert == -3){
        retVal = '3';
    }
    else if (numToConvert == 4 || numToConvert == -4){
        retVal = '4';
    }
    else if (numToConvert == 5 || numToConvert == -5){
        retVal = '5';
    }
    else if (numToConvert == 6 || numToConvert == -6){
        retVal = '6';
    }
    else if (numToConvert == 7 || numToConvert == -7){
        retVal = '7';
    }
    else if (numToConvert == 8 || numToConvert == -8){
        retVal = '8';
    }
    else if (numToConvert == 9 || numToConvert == -9){
        retVal = '9';
    }
    return retVal;
}

int findStringLength(char str[]){ //returns the number of characters in the string including the nullCharacter at the end
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++){
        length++;
    }
    return length + 1; //adds one because I want to know the length with the '\0' 
}

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
        if (d1 == 0 || d2 == 0){
            return false;
        }


        bool resultIsNegative = false; //stores whether or not number is negative so to allow for addition of - to the beginning of the string

        int improperNumerator1 = (c1 * d1) + n1; //turns the first number into an improper fraction
        int improperNumerator2 = (c2 * d2) + n2;
        
        
        long long commonDenominator = d1 * d2; 

        improperNumerator1 = improperNumerator1 * (commonDenominator / d1); //converts the improper fraction two a fraction with the common denominator, thus allowing for addition of the two numerators
        improperNumerator2 = improperNumerator2 * (commonDenominator / d2);

        int summedNumerator = improperNumerator1 + improperNumerator2; //add up the numerators and then split up mantissa and characteristic again, but the two numbers are added together
        int summedCharacteristic = summedNumerator / commonDenominator; 
        long long summedMantissa = summedNumerator % commonDenominator;

        if (summedNumerator < 0){ 
            resultIsNegative = true;
        }

    if (count_digit(summedCharacteristic) < len) { //makes sure that the string can hold at least the characteristic
    
        long long decimalPrecision = 1;
        for (int i = 0; i < len  - (count_digit(summedCharacteristic) + 1); i++){ //this sets decimal precision i.e. how many numbers we want after decimal point, this is determined by len parameter
            decimalPrecision = decimalPrecision * 10;
        }

        long long mantissaDecimalFormat = summedMantissa * (decimalPrecision / commonDenominator); //this will be zero if previous for loop never looped
        

        int characteristicStart;
        long long reducingMantissa = mantissaDecimalFormat;
        if (mantissaDecimalFormat != 0){
            for (int i = len - 1; i >= count_digit(summedCharacteristic) + 1; i--){ //this places the mantissa in the result string and then adds a decimal point before it
                result[i] = intToChar(reducingMantissa % 10);
                reducingMantissa = reducingMantissa / 10;
                if (reducingMantissa == 0){
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
            for (int i = len - 1; i >= 1; i--){
                if (result[i] != '0'){
                    result[i + 1] = '\0';
                    break;
                }
            }
        }

        if (resultIsNegative){ //this adds a negative to the beginning of the result string if the answer is negative
            int nullCharacterPosition;
            for (int i = 1; result[i] != '\0'; i++) { //moves every character up one index except for the last non nullCharacter that is then swapped later if we have the space or cut off if we dont
                char temp = result[i];
                result[i] = result[0];
                result[0] = temp;

                if (result[i + 1] == '\0'){
                    nullCharacterPosition = i + 1; //perserve this position so we can the last digit of the decimal here if len accomidates it
                } 
            }
            if (findStringLength(result) + 1 <= len) { //plus 1 to accomidate for the negative sign we are adding to the beginning
                result[nullCharacterPosition] = result[0];
                result[nullCharacterPosition + 1] = '\0';
            }
            result[0] = '-'; 
        }


        return true;
    }
    else {
        return false;
    }
}
//--
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) 
{
    return add(c1,n1,d1,-c2,-n2,d2,result,len); //subtract the second number passed in from the first number, just used add then reversed the sign of the second number
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
