#include<bits/stdc++.h>
using namespace std;
#include "BigReal.h"


BigReal::BigReal()
{
    //ctor
}

void BigReal :: setNumber(string num)
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
