
    #include "BigReal.h"


    int main()
    {
        BigReal a,b, c;
        cin>>a>>b;
        if(a==b)
        {
            cout<<"match"<<endl;
        }
        else
        {
            cout<<"not match";
        }
        cout<<a.sign()<<endl;
        cout<<a.size()<<endl;
        cout<<a<<endl<<b;




    return 0;
    }
