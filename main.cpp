#include <iostream>
#include "problemas.h"

using namespace std;

int main()
{

    int opcion;

    cout << "-----------------------" << endl;
    cout << "|Menu                  |" << endl;
    cout << "|1. Problema 1         |" << endl;
    cout << "|2. Problema 2         |" << endl;
    cout << "|3. Problema 3         |" << endl;
    cout << "-----------------------" << endl;

    cin >> opcion;


    switch(opcion) {

        case 1:
            problema1();
            break;
        case 2:
            // problema2();
            break;
        default: 
            // problema3();
            cout << "Defalut main" << endl; 
    } 

    return 0;
}
