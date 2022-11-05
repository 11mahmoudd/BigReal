#ifndef BIGREAL_H
#define BIGREAL_H

class BigReal
{
    public:
        BigReal();
        bool operator < (BigReal anotherReal);
        bool operator > (BigReal anotherReal);
        void setNumber( string num);
            BigReal (string num)
        {
            setNumber(num);
        }

    protected:

    private:
    string number;
    char signNumber;
};

#endif // BIGREAL_H
