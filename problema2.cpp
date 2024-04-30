#include <iostream>
#include <limits>
#include <vector>
#include "CuentaCorriente.h"

using namespace std;

void problema2() { 

    int opcion;
    bool flag1 = true;
    bool flag2 = true;
    int count = 0;

    vector<CuentaCorriente> cuentas;

    CuentaCorriente *cuenta = nullptr;
    string nombre, apellidos, direccion, telefono;
    int cedula, clave;
    double saldo, retiro, abono;

    cout << "-----------------------" << endl;
    cout << "| Menu                |" << endl;
    cout << "| 1. Crear cuenta     |" << endl;
    cout << "| 2. Ingresar datos   |" << endl;
    cout << "-----------------------" << endl;
    cin >> opcion;

    if (opcion == 1) {
        cuenta = new CuentaCorriente();  // Se crea objeto cuenta con el constructor por defecto
    } else {
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese el apellido: ";
        cin >> apellidos;
        cout << "Ingrese la dirección: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, direccion);
        cout << "Ingrese el teléfono: ";
        cin >> telefono;


        while (flag1 == true) {

            cout << "Ingrese la cédula: ";
            cin >> cedula;
            int count = 0;
            for (auto& cuenta : cuentas){
                if (cuenta.getCedula() == cedula){
                    cout << "Esta cedula ya esta registrada" << endl;
                    break;
                }
                else {
                    ++count;
                }
            }
            if (count == cuentas.size()){
                flag1 = false;
            }
        }


        cout << "Ingrese la clave: ";
        cin >> clave;
        cout << "Ingrese el saldo: ";
        cin >> saldo;


        delete cuenta; // Liberar memoria si ya había una cuenta creada
        cuenta = new CuentaCorriente(nombre, apellidos, direccion, telefono, cedula, clave, saldo);
    }

    while (flag2 == true) {

        cout << "---------------------------------" << endl;
        cout << "|Menu                           |" << endl;
        cout << "|1. Ingresar dinero             |" << endl;
        cout << "|2. Retirar dinero              |" << endl;
        cout << "|3. Modificar nombre            |" << endl;
        cout << "|4. Modificar apellido          |" << endl;
        cout << "|5. Modificar direccion         |" << endl;
        cout << "|6. Modificar telefono          |" << endl;
        cout << "|7. Modificar cedula            |" << endl;
        cout << "|8. Modificar clave             |" << endl;
        cout << "|9. Consultar cuenta            |" << endl;
        cout << "|10. Salir                      |" << endl;
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
                cout << "Ingrese la nueva cédula: ";
                cin >> cedula;
                              
                while (flag1 == true) {

                    cout << "Ingrese la cédula: ";
                    cin >> cedula;
                    int count = 0;
                    for (auto& cuenta : cuentas){
                        if (cuenta.getCedula() == cedula){
                            cout << "Esta cedula ya esta registrada" << endl;
                            break;
                        }
                        else {
                            ++count;
                        }
                    }
                    if (count == cuentas.size()){
                        flag1 = false;
                    }
                }
                        break;
            
            case 8:

                cout << "Ingrese la cedula: " << endl;
                cin >> cedula;
                
                count = 0;

                for (auto& cuenta : cuentas){
                    if (cuenta.getCedula() == cedula){
                        cout << "Ingrese la nueva clave: ";
                        cin >> clave;

                        cuenta.setClave(clave);
                        
                        ++count;
                    }
                }
                
                if (count != 0){
                    cout << "La cedula no existe" << endl;
                }

                cuenta->consultarCuenta();
                break;
            case 9:

                cout << "Datos de la cuenta" << endl;

                cuenta->consultarCuenta();
                cout << endl;
                break;
            default:

                flag2 = false;
        } 
    }

    delete cuenta;

}
