
    #include "BigReal.h"


    int main()
    {
        string s1,s2;

        cin>>s1;
        cin>>s2;
        BigReal a(s1),b(s2), c();
        if(a==b)
        {
            cout<<"done"<<endl;
        }
        cout<<a.sign()<<endl;
        cout<<a.size()<<endl;
        cout<<b<<endl;
        // cin>>c;
        // cout<<c;




    return 0;
    }
