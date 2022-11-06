#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string suffixWithUnit(double number){
    //final result
    string res;
    //store decimal values
    string decString;
    string suffices[8] = {" Kilo", " Mega", " Giga", " Tera", " Peta", " Exa", " Zetta", " Yotta"};
    int unit = 0;
    double tmp = number;
    while (tmp >= (double) 1000){
        tmp = tmp / 1000;
        unit = unit + 1;
        //get decimal value
        double decimal = tmp - trunc(tmp);
        tmp = (double) trunc(tmp);
        //erase "0."
        string dec = to_string(decimal).substr(2);
        //erase trailing zeros
        dec.erase(dec.find_last_not_of('0') + 1, string::npos);
        //concatenate
        decString = dec + decString;
    }
    if (unit == 0){
        //get decimal value
        double decimal = tmp - (int) tmp;
        //erase "0."
        string dec = to_string(decimal).substr(2);
        //erase trailing zeros
        dec.erase(dec.find_last_not_of('0') + 1, string::npos);
        //concatenate
        decString = dec + decString;
        //get integer value
        int integer = (int) tmp;
        //produce final result
        res = to_string(integer);
        if (decString.length() != 0) res = res + "." + decString;
    }
    else{
        //get integer value
        int integer = (int) tmp;
        //produce final result
        res = to_string(integer);
        if (decString.length() != 0){   //add "."
            res = res + "." + decString;
        }
        res = res + suffices[unit-1];
    }
    return res;
}

int main(){
    double number;
    cin >> number;
    cout << suffixWithUnit(number);
}