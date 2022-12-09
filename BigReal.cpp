#include "BigReal.h"



bool BigReal :: checkValidInput (string input)
{
    regex validInput("[-+]?[0-9]+([.]?[0-9]+)?");
    return regex_match(input, validInput);
}

BigReal::BigReal()
{
    number = "";
    signNumber = '+';
}

BigReal ::BigReal(double realNumber) {
    realNumber = 0.0;
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

    other.Number = 0;
    other.signNumber = '\0' ;
}

BigReal &BigReal::operator=(BigReal &&other) {
   if (&other != this){
        this->Number = other.Number  ;
        this->signNumber = other.signNumber ;

        other.Number = 0;
        other.signNumber = '\0';
    }

    return *this;
}


BigReal& BigReal::operator=(BigReal& other)
{
    if (&other != this){
        this->Number = other.Number  ;
        this->signNumber = other.signNumber ;
    }

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

void  matchzeros(string &f1, string& f2)
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

void subcarry(string& r,string& carry){
    char s;
    if(r[0] == '-'){
        s = r[0];
        r.erase(0,1);
        while (r.length() > carry.length()) {
            carry.insert(carry.begin(), '0');
        }
        BigDecimalInt c1(r),c2(carry),c3;
        c3 = c1 - c2;
        r = c3.getNumber();
        r.insert(r.begin(),s);
    }
    else{
        while (r.length() > carry.length()) {
            carry.insert(carry.begin(), '0');
        }
        BigDecimalInt c1(r),c2(carry),c3;
        c3 = c1 - c2;
        r = c3.getNumber();
    }

}
void addcarry(string& r,string& carry){
    char s;

    if(r[0] == '-'){
        s = r[0];
        r.erase(0,1);
        while (r.length() > carry.length()) {
            carry.insert(carry.begin(), '0');
        }
        BigDecimalInt c1(r),c2(carry),c3;
        c3 = c1 + c2;
        r = c3.getNumber();
        r.insert(r.begin(),s);
    }
    else{
        while (r.length() > carry.length()) {
            carry.insert(carry.begin(), '0');
        }
        BigDecimalInt c1(r),c2(carry),c3;
        c3 = c1 + c2;
        r = c3.getNumber();
    }

}

BigReal BigReal::operator+(BigReal& number2) {
    int check,count=0;
    string Carry = "1", r, f1 = fraction, f2 = number2.fraction;
    BigReal FinalResult;
    BigDecimalInt r1 = whole + number2.whole;
    r = r1.getNumber();
    matchzeros(f1, f2);

    for (int i = 0; i < f1.length(); ++i) {
        if ((int) f1[i] > (int) f2[i]) {
            check = 1;
            break;
        } else if ((int) f1[i] < (int) f2[i]) {
            check = 2;
            break;
        }
        else{
            count++;
        }
    }
    if(f1.length() == count){
        check = 3;
    }
    if (signNumber == '-' && number2.signNumber == '+') {

        if (check == 1) {
            if(r == "0"){
                r = "-0";
            }
            if(r[0] == '-') {
                BigDecimalInt num1(f1), num2(f2), num;
                num = num1 - num2;
                f1 = num.getNumber();
                while (count != 0){
                    f1.insert(f1.begin(),'0');
                    count--;
                }
            }
            else{
                f2.insert(f2.begin(), '1');
                BigDecimalInt num1(f1), num2(f2), num;
                num = num2 - num1;
                f1 = num.getNumber();
                subcarry(r, Carry);
            }

        } else if (check == 2) {
            if(r == "0"){
                BigDecimalInt num1(f1), num2(f2), num;
                num = num2 - num1;
                f1 = num.getNumber();
                while (count != 0){
                    f1.insert(f1.begin(),'0');
                    count--;
                }
            }
            else if(r[0] == '-'){
                f1.insert(f1.begin(), '1');
                BigDecimalInt num1(f1), num2(f2), num;
                num = num1 - num2;
                f1 = num.getNumber();
                subcarry(r, Carry);
            }
            else {
                BigDecimalInt num1(f1), num2(f2), num;
                num = num2 - num1;
                f1 = num.getNumber();
                while (count != 0){
                    f1.insert(f1.begin(),'0');
                    count--;
                }
            }
        }
        else if (check == 3){
            f1 = "0";
        }
    }
    else if (signNumber == '+' && number2.signNumber == '-') {
        if (check == 1) {
            if(r == "0"){
                BigDecimalInt num1(f1), num2(f2), num;
                num = num1 - num2;
                f1 = num.getNumber();
                while (count != 0){
                    f1.insert(f1.begin(),'0');
                    count--;
                }
            }
            else if(r[0] == '-'){
                f2.insert(f2.begin(), '1');
                BigDecimalInt num1(f1), num2(f2), num;
                num = num2 - num1;
                f1 = num.getNumber();
                subcarry(r, Carry);
            }
            else {
                BigDecimalInt num1(f1), num2(f2), num;
                num = num1 - num2;
                f1 = num.getNumber();
                while (count != 0){
                    f1.insert(f1.begin(),'0');
                    count--;
                }
            }
        } else if (check == 2) {
            if(r == "0") {
                r = "-0";
            }
            if (r[0] == '-'){
                BigDecimalInt num1(f1), num2(f2), num;
                num = num2 - num1;
                f1 = num.getNumber();
                while (count != 0){
                    f1.insert(f1.begin(),'0');
                    count--;
                }
            }
            else{
            f1.insert(f1.begin(), '1');
            BigDecimalInt num1(f1), num2(f2), num;
            num = num1 - num2;
            f1 = num.getNumber();
            subcarry(r, Carry);
            }
        }
        else if(check == 3){
            f1 = "0";
        }
    }
    else  {
        BigDecimalInt num1(f1), num2(f2), num;
        num = num1 + num2;
        f1 = num.getNumber();
        if(f1.length() > f2.length()){
            f1.erase(0,1);
            addcarry(r, Carry);
        }
    }
    FinalResult.number = r + "." + f1;
    return FinalResult;

}

BigReal BigReal :: operator-(BigReal& number2) {
    int check,count =0;
    string Carry = "1", r, f1 = fraction, f2 = number2.fraction;
    BigReal FinalResult;
    BigDecimalInt r1 = whole - number2.whole;
    r = r1.getNumber();
    matchzeros(f1, f2);

    for (int i = 0; i < f1.length(); ++i) {
        if ((int) f1[i] > (int) f2[i]) {
            check = 1;
            break;
        } else if ((int) f1[i] < (int) f2[i]) {
            check = 2;
            break;
        }
        else{
            count++;
        }
    }
    if(f1.length() == count){
        check = 3;
    }
    if (signNumber == '-' && number2.signNumber == '+') {
        BigDecimalInt num1(f1), num2(f2), num;
        num = num1 + num2;
        f1 = num.getNumber();
        if(f1.length() > f2.length()){
            f1.erase(0,1);
            addcarry(r, Carry);
        }
    }
    else if (signNumber == '+' && number2.signNumber == '-') {
        BigDecimalInt num1(f1), num2(f2), num;
        num = num1 + num2;
        f1 = num.getNumber();
        if(f1.length() > f2.length()){
            f1.erase(0,1);
            addcarry(r, Carry);
        }
    }
    else  {
        if (check == 1) {
            if(r == "0"){
                BigDecimalInt num1(f1), num2(f2), num;
                num = num1 - num2;
                f1 = num.getNumber();
                while (count != 0){
                    f1.insert(f1.begin(),'0');
                    count--;
                }
            }
            else if(r[0] == '-'){
                f2.insert(f2.begin(), '1');
                BigDecimalInt num1(f1), num2(f2), num;
                num = num2 - num1;
                f1 = num.getNumber();
                subcarry(r, Carry);
            }
            else {
                BigDecimalInt num1(f1), num2(f2), num;
                num = num1 - num2;
                f1 = num.getNumber();
                while (count != 0){
                    f1.insert(f1.begin(),'0');
                    count--;
                }
            }
        } else if (check == 2) {
            if(r == "0") {
                r = "-0";
            }
            if (r[0] == '-'){
                BigDecimalInt num1(f1), num2(f2), num;
                num = num2 - num1;
                f1 = num.getNumber();
                while (count != 0){
                    f1.insert(f1.begin(),'0');
                    count--;
                }
            }
            else{
                f1.insert(f1.begin(), '1');
                BigDecimalInt num1(f1), num2(f2), num;
                num = num1 - num2;
                f1 = num.getNumber();
                subcarry(r, Carry);
            }
        }
        else if(check == 3){
            f1 = "0";
        }
    }
    FinalResult.number = r + "." + f1;
    return FinalResult;
}

bool BigReal :: operator < (BigReal& anotherReal)
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

bool BigReal :: operator > (BigReal& anotherReal)
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

bool BigReal :: operator == (BigReal &anotherReal)
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

ostream &operator << (ostream &out, const BigReal& num)
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
istream& operator >> (istream& out, BigReal& num)
{
    string str1;
    out >> str1;
    num.setNumber(str1);
    return out;
}
