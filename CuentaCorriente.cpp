#include "CuentaCorriente.h"
#include <string>
#include <iostream>

using namespace std;

CuentaCorriente::CuentaCorriente(){
    //Constructor by default

    nombre = "John";
    apellidos = "Doe Quintero";
    direccion = "Calle 48A #50-42 Piso 2";
    telefono = "546 55 48";
    saldo = 1500000.0;
}

CuentaCorriente::CuentaCorriente(string nom, string apll, string dir, string tel, double sald){
    //Parametrized constructor

    nombre = nom;
    apellidos = apll;
    direccion = dir;
    telefono = tel;
    saldo = sald;
}

void CuentaCorriente::setName(string _nombre){

    nombre = _nombre;
}

void CuentaCorriente::setApellidos(string _apellidos){

    apellidos = _apellidos;
}

void CuentaCorriente::setAdress(string _direccion){

    direccion = _direccion;
}

void CuentaCorriente::setPhone(string _telefono){

    telefono = _telefono;
}

void CuentaCorriente::setSaldo(double _saldo){

    saldo = _saldo;
}

string CuentaCorriente::getName(){

    return nombre; 
}

string CuentaCorriente::getApellidos(){
    
    return apellidos;
}

string CuentaCorriente::getAdress(){

    return direccion;
}

string CuentaCorriente::getPhone(){

    return telefono;
}

double CuentaCorriente::getSaldo(){

    return saldo;
}


bool CuentaCorriente::saldoNegativo(double _retiro){

    if ((saldo - _retiro) < 0){
        return 1;
    }
    else {
        return 0;
    }
}

void CuentaCorriente::retirarDinero(double _retiro){

    saldo -= _retiro;
}

void CuentaCorriente::ingresarDinero(double _abono){

    saldo += _abono;
}

void CuentaCorriente::consultarCuenta(){

    cout << "Nombre: " << nombre << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Saldo: " << saldo << endl; 
}