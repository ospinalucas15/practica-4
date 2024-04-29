#include <iostream>
#include <limits>
#include "CuentaCorriente.h"

using namespace std;

void problema2(){

    int opcion;
    bool flag = true;

    CuentaCorriente *cuenta = new CuentaCorriente();

    string nombre;
    string apellidos;
    string direccion;
    string telefono;
    int cedula, clave;
    double saldo, retiro, abono;


    cout << "-----------------------" << endl;
    cout << "|Menu                  |" << endl;
    cout << "|1. Crear cuenta       |" << endl;
    cout << "|2. Ingresar datos     |" << endl;
    cout << "-----------------------" << endl;

    cin >> opcion;

    if (opcion == 1){

        CuentaCorriente *cuenta = new CuentaCorriente(); //Se crea objeto global 'cuenta' con by default constructor
    }
    else {
        
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese el apellido: ";
        cin >> apellidos;
        cout << "Ingrese la direccion: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(std::cin, direccion);
        cout << "Ingrese el telefono: ";
        cin >> telefono;
        cout << "Ingrese el saldo: ";
        cin >> saldo;

        delete cuenta;

        CuentaCorriente *cuenta = new CuentaCorriente(nombre, apellidos, direccion, telefono, saldo);
        //Se crea objeto 'cuenta' con constructor parametrizado

    }

    while (flag == true) {

        cout << "---------------------------------" << endl;
        cout << "|Menu                           |" << endl;
        cout << "|1. Ingresar dinero             |" << endl;
        cout << "|2. Retirar dinero              |" << endl;
        cout << "|3. Modificar nombre            |" << endl;
        cout << "|4. Modificar apellido          |" << endl;
        cout << "|5. Modificar direccion         |" << endl;
        cout << "|6. Modificar telefono          |" << endl;
        cout << "|7. Consultar cuenta            |" << endl;
        cout << "|8. Salir                       |" << endl;
        cout << "---------------------------------" << endl;

        cin >> opcion;

        switch (opcion){
            case 1:

                cout << "Ingrese el valor a abonar: ";
                cin >> abono;

                cuenta->ingresarDinero(abono);

                cout << "Su nuevo saldo es: " << cuenta->getSaldo() << endl;

                break;
            case 2:

                cout << "Ingrese el valor a retirar: ";
                cin >> retiro;


                if (cuenta->saldoNegativo(retiro) == 1){

                    cout << "Saldo negativo. Intente otra vez" << endl;
                }
                else {
                    cout << "Usted ha retirado: " << retiro << endl;
                    cout << "Su nuevo saldo es: " << cuenta->getSaldo() << endl; 
                }

                break;
            case 3:

                cout << "Ingrese el nuevo nombre: ";
                cin >> nombre;

                cuenta->setName(nombre);

                cout << "El nuevo nombre de usuario es: " << cuenta->getName() << endl; 

                break;
            case 4:

                cout << "Ingrese el nuevo apellido: ";
                cin >> apellidos;

                cuenta->setApellidos(apellidos);
                
                cout << "El nuevo apellido es: " << cuenta->getApellidos() << endl;

                break;
            case 5:

                cout << "Ingrese nueva direccion: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, direccion);

                cuenta->setAdress(direccion);

                cout << "La nueva direccion es: " << cuenta->getAdress() << endl;

                break;
            case 6:

                cout << "Ingrese nuevo telefono: ";
                cin >> telefono;

                cuenta->setPhone(telefono);

                cout << "El nuevo telefono es: " << cuenta->getPhone() << endl;

                break;
            case 7:

                cout << "Datos de la cuenta" << endl;

                cuenta->consultarCuenta();
                break;
            default:

                flag = false;
        } 
    }

    delete cuenta;

}
