    #include <iostream>
    #include<bits/stdc++.h>
    using namespace std;
    #include "BigReal.h"

    int main()
    {
        string s1,s2,s3,s4;
        cin>>s1>>s2;
        BigReal a(s1),b(s2),c(s3),d(s4) ;
        cout<< "< operator "<<(a <b) <<endl;
        cin>> s3>>s4;
        cout<< "> operator " <<(a > b) <<endl;

    return 0;
    }
