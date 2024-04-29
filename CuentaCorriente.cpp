#include "CuentaCorriente.h"
#include <iostream>
#include <string>

using namespace std;

CuentaCorriente::CuentaCorriente() {
    // Constructor por defecto
    nombre = "John";
    apellidos = "Doe Quintero";
    direccion = "Calle 48A #50-42 Piso 2";
    telefono = "546 55 48";
    cedula = 123456789;
    clave = 4321;
    saldo = 1500000.0;
}

CuentaCorriente::CuentaCorriente(string nom, string apll, string dir, string tel, int ced, int clv, double sald) {
    // Constructor parametrizado
    nombre = nom;
    apellidos = apll;
    direccion = dir;
    telefono = tel;
    cedula = ced;
    clave = clv;
    saldo = sald;
}

void CuentaCorriente::setName(string _nombre) {
    nombre = _nombre;
}

void CuentaCorriente::setApellidos(string _apellidos) {
    apellidos = _apellidos;
}

void CuentaCorriente::setAdress(string _direccion) {
    direccion = _direccion;
}

void CuentaCorriente::setPhone(string _telefono) {
    telefono = _telefono;
}

void CuentaCorriente::setSaldo(double _saldo) {
    saldo = _saldo;
}

void CuentaCorriente::setCedula(int _cedula) {
    cedula = _cedula;
}

void CuentaCorriente::setClave(int _clave) {
    clave = _clave;
}

string CuentaCorriente::getName() {
    return nombre;
}

string CuentaCorriente::getApellidos() {
    return apellidos;
}

string CuentaCorriente::getAdress() {
    return direccion;
}

string CuentaCorriente::getPhone() {
    return telefono;
}

double CuentaCorriente::getSaldo() {
    return saldo;
}

int CuentaCorriente::getCedula() {
    return cedula;
}

int CuentaCorriente::getClave() {
    return clave;
}

bool CuentaCorriente::saldoNegativo(double _retiro) {
    return (saldo - _retiro) < 0;
}

void CuentaCorriente::retirarDinero(double _retiro) {
    if (!saldoNegativo(_retiro)) {
        saldo -= _retiro;
    } else {
        cout << "No se puede retirar, saldo insuficiente." << endl;
    }
}

void CuentaCorriente::ingresarDinero(double _abono) {
    saldo += _abono;
}

void CuentaCorriente::consultarCuenta() {
    cout << "Nombre: " << nombre << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Cedula: " << cedula;
}