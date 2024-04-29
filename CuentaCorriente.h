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
        CuentaCorriente(string nom, string apll, string dir, string tel, double sald);

        void setName(string _nombre);
        void setApellidos(string _appellidos);
        void setAdress(string _direccion);
        void setPhone(string _telefono);
        void setSaldo(double _saldo);
        
        string getName();
        string getApellidos();
        string getAdress();
        string getPhone();
        double getSaldo();
        
        bool saldoNegativo(double _retiro);
        void retirarDinero(double _retiro);
        void ingresarDinero(double _abono);
        void consultarCuenta(); 
        
};

#endif // CUENTACORRIENTE_H
