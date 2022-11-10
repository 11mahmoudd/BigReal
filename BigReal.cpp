
#include "BigReal.h"


bool BigReal :: checkValidInput(string input)
{
    regex validInput("[-+]?[0-9]+([.]?[0-9]+)?");
    return regex_match(input, validInput);
}

BigReal::BigReal()
{
    //ctor
}


BigReal::BigReal (string realNumber)
{

    setNumber(realNumber);

}

BigReal::BigReal(BigDecimalInt bigInteger)
{
    number=bigInteger.getNumber();
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

        int pose = num.find('.') ;
        if(pose>=1)
        {
            string numm;
            fraction=num.substr(pose+1);
            numm=num.substr(0,pose);
            BigDecimalInt whl(numm);
            whole=whl;
        }
        else
        {
            BigDecimalInt whl(num);
            whole=whl;
        }




    }
    else
    {
        cout << "Invalid" << "\n";
        exit(1);
    }

}

void BigReal :: matchzeros(string f1, string f2)
{
    if (f1.size()>f2.size())
    {
        for(int i =f2.size() ; i<f1.size();i++)
        {
            f2+='0';
        }
    }
    else if(f1.size()<f2.size())
    {
        for(int i =f1.size() ; i<f2.size();i++)
        {
            f1+='0';
        }
    }
}


bool BigReal :: operator < (const BigReal anotherReal)
{
    if(signNumber=='+' && anotherReal.signNumber=='-')
    {
        return false;

    }
    if (signNumber=='-' && anotherReal.signNumber=='+')
    {
        return true;
    }
    string leftf=fraction;
    string rightf=anotherReal.fraction;
    matchzeros(leftf,rightf);

    if(whole==anotherReal.whole)
    {
        if(signNumber=='-')  //-3.555 < -3.65
        {
            return(leftf>rightf);
        }
        else
        {
            return(leftf<rightf);
        }
    }
    else
    {
        return(whole<anotherReal.whole);

    }
}



bool BigReal :: operator > (BigReal anotherReal)
{
    if(signNumber=='+' && anotherReal.signNumber=='-')
    {
        return true;

    }
    if (signNumber=='-' && anotherReal.signNumber=='+')
    {
        return false;
    }
    string leftf=fraction;
    string rightf=anotherReal.fraction;
    matchzeros(leftf,rightf);

    if(whole==anotherReal.whole)
    {
        if(signNumber=='-')
        {
            return(leftf<rightf);
        }
        else
        {
            return(leftf>rightf);
        }
    }
    else
    {
        return(whole>anotherReal.whole);

    }
}

bool BigReal :: operator== (BigReal anotherReal)
{
    if (signNumber == anotherReal.signNumber && number == anotherReal.number)
    {
        return true;

    }
    else
    {
        return false;
    }
}

int BigReal :: size()
{
    return whole.size()+fraction.size();
}

int BigReal :: sign()
{
    if (signNumber == '+')
    {
        return true;
    }
    else
    {
        return false ;
    }
}

ostream& operator << (ostream& out, const BigReal& num)
{
    if(num.signNumber == '+')
    {
        out << num.number ;
    }
    else
    {
        if(num.number == "0")
        {
            out << num.number ;
        }
        else
        {
            out << num.signNumber << num.number ;
        }
    }
    return out;
}
istream& operator >> (istream& in, BigReal& num)
{

    cout<<"Enter the real number : ";
    in>>num.number;
    num.setNumber(num.number);
    return in;

}
