#ifndef BIGREAL_H
#define BIGREAL_H
#include<bits/stdc++.h>
#include <iostream>
#include<regex>
using namespace std;
#include "BigDecimalInt.h"

class BigReal
{
    public:
        BigReal();
        BigReal (string realNumber);
        BigReal(BigDecimalInt bigInteger);
        bool operator < (const BigDecimalInt& anotherDec);
        bool operator < (BigReal anotherReal);
        bool operator > (BigReal anotherReal);
        bool operator== (BigReal anotherReal);
        void setNumber( string num);
        int size();
        int sign();
        friend ostream& operator << (ostream& out,const BigReal& num);
        friend istream& operator >> (istream& in, BigReal& num);

    protected:

    private:
        void matchzeros(string f1, string f2);
        BigDecimalInt whole;
        string fraction;
        string number;
        char signNumber;
        bool checkValidInput(string input);
};

#endif // BIGREAL_H
