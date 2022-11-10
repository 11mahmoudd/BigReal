#ifndef BIGREAL_H
#define BIGREAL_H
#include<bits/stdc++.h>
#include<regex>
using namespace std;
#include"BigDecimalIntClass.h"

class BigReal
{
public:


    BigReal();
    BigReal(double realNumber);
    BigReal (string realNumber);
    BigReal (BigDecimalInt bigInteger);
    BigReal(const BigReal& other);
    BigReal (BigReal&& other);
    BigReal& operator= (BigReal& other);
    BigReal& operator= (BigReal&& other);
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);
    bool operator == (BigReal& anotherReal);
    bool operator < (BigReal& anotherReal);
    bool operator > (BigReal& anotherReal);
    int size();
    int sign();
    friend ostream& operator << (ostream& out,const BigReal& num);
    friend istream& operator >> (istream& out, BigReal& num);

    void setNumber( string num);



private:

    int* Number;
    BigDecimalInt whole;
    string fraction;
    string number;
    char signNumber;
    bool checkValidInput(string input);
};

#endif // BIGREAL_H
