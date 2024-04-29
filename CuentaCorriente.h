#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include <string>

using namespace std;

class CuentaCorriente{ 

    string nombre;
    string apellidos;
    string direccion;
    string telefono;
    int cedula, clave;
    double saldo;

    public:
        CuentaCorriente();
        CuentaCorriente(string nom, string apll, string dir, string tel, int ced, int clv , double sald);

        void setName(string _nombre);
        void setApellidos(string _appellidos);
        void setAdress(string _direccion);
        void setPhone(string _telefono);
        void setSaldo(double _saldo);
        void setCedula(int _cedula);
        void setClave(int _clave);
        
        string getName();
        string getApellidos();
        string getAdress();
        string getPhone();
        double getSaldo();
        int getCedula();
        int getClave();
        
        bool saldoNegativo(double _retiro);
        void retirarDinero(double _retiro);
        void ingresarDinero(double _abono);
        void consultarCuenta(); 
        
};

#endif // CUENTACORRIENTE_H
