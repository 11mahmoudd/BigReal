#ifndef BIGREAL_H
#define BIGREAL_H

class BigReal
{
    public:
        BigReal(double realNumber = 0.0);
        BigReal (string realNumber);
        BigReal (BigDecimalInt bigInteger);
        BigReal(const BigReal& other);
        BigReal (BigReal&& other);
        BigReal& operator= (BigReal& other);
        BigReal& operator= (BigReal&& other);
        BigReal operator+ (BigReal& other);
        BigReal operator- (BigReal& other);
        bool operator < (BigReal anotherReal);
        bool operator > (BigReal anotherReal);
        int size();
        int sign();
        friend ostream& operator << (ostream& out, BigReal num);
        friend istream& operator >> (istream& out, BigReal num);
        bool checkVaild(string num);
        void setNumber( string num);
            BigReal (string num)
        {
            setNumber(num);
        }
    private:
        string number;
        int* ptrNum
        char signNumber;
};

#endif // BIGREAL_H
