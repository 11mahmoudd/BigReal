#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include "BigReal.h"
#include "BigDecimalIntClass.h"

int main()
{
    while (true) {
        char option;
        BigReal c1, c2;
        cout << "---------------------------------------------------------" << endl;
        cout << "< Choose Operation >" << endl
             << "1- Addition Operation" << endl
             << "2- Subtraction Operation" << endl
             << "3- Exit" << endl;
        cin >> option;
        if (option != '1' && option != '2' && option != '3'){
            cout << "Invalid" << endl;
            continue;
        }
        cout << "---------------------------------------------------------" << endl;
        cout << "Enter The First Number : " << endl;
        cin >> c1;
        cout << "Enter The Second Number : " << endl;
        cin >> c2;
        cout << "----------------------------------------------------------" << endl;

        if (option == '1') {
            BigReal c3 = c1 + c2;
            cout << "The Result of addition = " << c3 << endl;
        } else if (option == '2') {
            BigReal c3 = c1 - c2;
            cout << "The Result of subtraction = " << c3 << endl;
        } else if (option == '3') {
            break;
        }
        if (c1 > c2) {
            cout << "The first number is greater than second one" << endl;
            cout << "----------------------------------------------------------" << endl;
        }
        if (c1 < c2) {
            cout << "The second number is greater than first one" << endl;
            cout << "----------------------------------------------------------" << endl;
        }
        if (c1 == c2) {
            cout << "Numbers are equal" << endl;
            cout << "----------------------------------------------------------" << endl;
        }
        cout << " Another Operation ? (y/n)" << endl;
        char option2;
        cin >> option2;
        if(option2 == 'y')
            continue;
        if(option2 == 'n')
            cout << "------- << thanks for your time :) >> -------" << endl;
        break;
    }
    return 0;
}
