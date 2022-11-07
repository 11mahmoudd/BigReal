
#include "BigReal.h"



bool BigReal :: checkValidInput (string input)
{
    regex validInput("[-+]?[0-9]+[.]?[0-9]+");
    return regex_match( input, validInput);
}


BigReal::BigReal(string number)
{
    setNumber(number);

}

BigReal::BigReal(BigDecimalInt bigInteger)
{
    number = bigInteger.getNumber();
}

BigReal::BigReal(const BigReal &other) {
    this->Number = other.Number  ;
    this->signNumber = other.signNumber ;
}

BigReal::BigReal(BigReal &&other) {
    Number = other.Number ;
    signNumber = other.signNumber ;

    other.Number[0] = '\0' ;
    other.signNumber = '\0' ;
}

BigReal &BigReal::operator=(BigReal &&other) {
    this->Number = other.Number  ;
    this->signNumber = other.signNumber ;

    other.Number[0] = '\0' ;
    other.signNumber = '\0' ;

    return *this;
}


 BigReal& BigReal::operator=(BigReal& other)
 {
     if (&other != this){
         delete [] Number;
         this->Number = other.Number  ;
         this->signNumber = other.signNumber ;
     }
     other.Number = nullptr;
     other.signNumber = '\0';

     return *this;
 }

void BigReal :: setNumber(string num)
{
bool validNumber = checkValidInput(num);
    if(validNumber)
    {
        number = num;
        if(number[0] == '+')
        {
            number.erase(0,1);
            signNumber = '+';
        }
        else if (number[0] == '-')
        {
            number.erase(0,1);
            signNumber = '-';
        }
        else
        {
            signNumber = '+';
        }
    }
    else
    {
        cout << "Invalid" << "\n";
        exit(1);
    }
}


bool BigReal :: operator < (const BigReal anotherReal)
{
    string whole1,whole2,fraction1,fraction2;

    whole1=number;
    whole2=anotherReal.number;
    int pose = whole1.find(".") ;
    fraction1=whole1.substr(pose+1);
    whole1=whole1.substr(0,pose);
    pose = whole2.find(".") ;
    fraction2=whole2.substr(pose+1);
    whole2=whole2.substr(0,pose);

    if(whole1!=whole2)
    {
        string comp1 = "", comp2 = "";
        long long len1 = whole1.length(), len2 = whole2.length();
        while (len1 < len2){
            comp1 += '0';
            len1++;
        }
        while (len2 < len1){
            comp2 += '0';
            len2++;
        }
        comp1 += whole1;
        comp2 += whole2;
        if(signNumber == '-' && anotherReal.signNumber == '+')
        {
            return true;
        }
        else if(signNumber == '+' && anotherReal.signNumber == '-')
        {
            return false;
        }
        else if(signNumber == '+' && anotherReal.signNumber == '+')
        {
            return comp1 < comp2;
        }
        else
        {
            return comp1 > comp2;
        }
    }
    else
    {
        string comp1 = "", comp2 = "";
        long long len1 = fraction1.length(), len2 = fraction2.length();
        while (len1 < len2){
            comp1 += '0';
            len1++;
        }
        while (len2 < len1){
            comp2 += '0';
            len2++;
        }
        comp1 += fraction1;
        comp2 += fraction2;

        if(signNumber == '-' && anotherReal.signNumber == '+')
        {
            return true;
        }
        else if(signNumber == '+' && anotherReal.signNumber == '-')
        {
            return false;
        }
        else if(signNumber == '+' && anotherReal.signNumber == '+')
        {
            return comp1 < comp2;
        }
        else
        {
            return comp1 > comp2;
        }
    }

}

bool BigReal :: operator > (BigReal anotherReal)
{
    string whole1,whole2,fraction1,fraction2;

    whole1=number;
    whole2=anotherReal.number;
    int pose = whole1.find(".") ;
    fraction1=whole1.substr(pose+1);
    whole1=whole1.substr(0,pose);
    pose = whole2.find(".") ;
    fraction2=whole2.substr(pose+1);
    whole2=whole2.substr(0,pose);

    if(whole1!=whole2)
    {
        string comp1 = "", comp2 = "";
        long long len1 = whole1.length(), len2 = whole2.length();
        while (len1 < len2){
            comp1 += '0';
            len1++;
        }
        while (len2 < len1){
            comp2 += '0';
            len2++;
        }
        comp1 += whole1;
        comp2 += whole2;
        if(signNumber == '-' && anotherReal.signNumber == '+')
        {
            return true;
        }
        else if(signNumber == '+' && anotherReal.signNumber == '-')
        {
            return false;
        }
        else if(signNumber == '+' && anotherReal.signNumber == '+')
        {
            return comp1 < comp2;
        }
        else
        {
            return comp1 > comp2;
        }
    }
    else
    {
        string comp1 = "", comp2 = "";
        long long len1 = fraction1.length(), len2 = fraction2.length();
        while (len1 < len2){
            comp1 += '0';
            len1++;
        }
        while (len2 < len1){
            comp2 += '0';
            len2++;
        }
        comp1 += fraction1;
        comp2 += fraction2;

        if(signNumber == '-' && anotherReal.signNumber == '+')
        {
            return false;
        }
        else if(signNumber == '+' && anotherReal.signNumber == '-')
        {
            return true;
        }
        else if(signNumber == '+' && anotherReal.signNumber == '+')
        {
            return comp1 > comp2;
        }
        else
        {
            return comp1 < comp2;
        }
    }
}
