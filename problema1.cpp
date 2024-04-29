#include <iostream>
#include <map>
#include <limits>
#include <typeinfo> 
#include <vector>
#include "Producto.h"

using namespace std;


//Sobrecarga de funciones
void menuAggMod(string nombre, Producto<string>& _comestible);
void menuAggMod(string nombre, Producto<int>& _comestible);

int tipoProduct();


//Variables globales
string nombre;
string marca;
int precio;
int descuento;
int inventario;
int garantia;
int cantidad;
float precioDescuento;
string VenMat;


void problema1(){

    //Map para objetos comestible 
    map<string, Producto<string>> comestible;

    //Map para objetos aseo
    map<string, Producto<string>> aseo;

    //Map para objetos electronico
    map<string, Producto<int>> electronico;

    //Vectores para carrito de compras
    vector<Producto<string>> carritoString;
    vector<Producto<int>> carritoInt;
    vector<int> cantidades;

    int opcion;
    int count1 = 0, count2 = 0, count3 = 0;
    float precioTotal = 0;
    string objectName;
    string choise;

    cout << "Bienvendio a tiendas Justo y Bueno" << endl; 

    while (true){

        cout << "--------------------------" << endl;
        cout << "|           Menu         |" << endl;
        cout << "|1. Agregar productos    |" << endl;
        cout << "|2. Modificar productos  |" << endl;
        cout << "|3. Realizar compra      |" << endl;
        cout << "--------------------------" << endl;

        cin >> opcion;

        switch (opcion) {
            
            case 1:

                opcion = tipoProduct();
                
                if (opcion == 1){

                    ++count1;

                    cout << "Ingrese nombre: ";
                    cin >> nombre;

                    objectName = nombre + to_string(count1);                     
                    comestible[nombre] = Producto<string>();

                    menuAggMod(nombre, comestible[nombre]);
                    cout << "Ingrese la fecha de vencimiento: ";
                    cin >> VenMat; 
                    comestible[nombre].setVenMatGar(VenMat);

                }

                else if (opcion == 2){

                    ++count2;

                    cout << "Ingrese nombre: ";
                    cin >> nombre;

                    objectName = nombre + to_string(count2);                     
                    aseo[nombre] = Producto<string>();

                    menuAggMod(nombre, aseo[nombre]);
                    cout << "Ingrese el tipo de material: ";
                    cin >> VenMat;
                    aseo[nombre].setVenMatGar(VenMat);
                   
                }

                else if (opcion == 3) {

                    ++count3;

                    cout << "Ingrese nombre: ";
                    cin >> nombre;

                    objectName = nombre + to_string(count3);                     
                    electronico[nombre] = Producto<int>();

                    menuAggMod(nombre, electronico[nombre]);
                    cout << "Ingrese la garantia: ";
                    cin >> garantia;
                    electronico[nombre].setVenMatGar(garantia);
                }
        
                break;

            case 2:

                opcion = tipoProduct();

                if ((opcion == 1) && (comestible.empty() == false)){

                    cout << "INVENTARIO DE COMESTIBLES" << endl;

                    for (auto& par: comestible) {

                        cout << par.second.getNombre() << endl;
                    }

                    cout << endl;

                    cout << "Ingrese nombre de producto a modificar: ";
                    cin >> choise;

                    cout << "El producto a modificar es el siguiente: " << endl;
                    cout << endl;

                    cout << "Nombre: " << comestible[choise].getNombre() << endl;
                    cout << "Marca: " << comestible[choise].getMarca() << endl;
                    cout << "Precio: " << comestible[choise].getPrecio() << endl;
                    cout << "Descuento: " << comestible[choise].getDescuento() << endl;
                    cout << "Inventario: " << comestible[choise].getInventario() << endl;
                    cout << "Fecha de vencimiento: " << comestible[choise].getVenMatGar() << endl;
                    cout << "Precio con descuento: " << comestible[choise].ajusteDescuento() << endl;

                    cout << endl;
                    cout << "Ingrese los nuevos datos" << endl;
                    cout << endl;

                    cout << "Ingrese nombre: ";
                    cin >> nombre;

                    menuAggMod(nombre, comestible[nombre]);
                    cout << "Ingrese la fecha de vencimiento: ";
                    cin >> VenMat;                  
                    comestible[nombre].setVenMatGar(VenMat);
                }
                else if ((opcion == 2) && (aseo.empty() == false)){

                    cout << "INVENTARIO DE ASEO" << endl;

                    for (auto& par: aseo) {

                        cout << par.second.getNombre() << endl;
                    }

                    cout << endl;

                    cout << "Ingrese nombre de producto a modificar: ";
                    cin >> choise;


                    cout << "El producto a modificar es el siguiente: " << endl;
                    cout << endl;

                    cout << "Nombre: " << aseo[choise].getNombre() << endl;
                    cout << "Marca: " << aseo[choise].getMarca() << endl;
                    cout << "Precio: " << aseo[choise].getPrecio() << endl;
                    cout << "Descuento: " << aseo[choise].getDescuento() << endl;
                    cout << "Inventario: " << aseo[choise].getInventario() << endl;
                    cout << "Material: " << aseo[choise].getVenMatGar() << endl;
                    cout << "Precio con descuento: " << aseo[choise].ajusteDescuento() << endl;

                    cout << endl;
                    cout << "Ingrese los nuevos datos" << endl;
                    cout << endl;

                    cout << "Ingrese nombre: ";
                    cin >> nombre;

                    menuAggMod(nombre, aseo[nombre]);
                    cout << "Ingrese ingrese el tipo de material: ";
                    cin >> VenMat;                  
                    aseo[nombre].setVenMatGar(VenMat);
                }
                else if ((opcion == 3) && (electronico.empty() == false)) {

                    cout << "INVENTARIO DE ELECTRONICOS" << endl;

                    for (auto& par: electronico) {

                        cout << par.second.getNombre() << endl;
                    }

                    cout << endl;

                    cout << "Ingrese nombre de producto a modificar: ";
                    cin >> choise;

                    cout << "El producto a modificar es el siguiente: " << endl;
                    cout << endl;

                    cout << "Nombre: " << electronico[choise].getNombre() << endl;
                    cout << "Marca: " << electronico[choise].getMarca() << endl;
                    cout << "Precio: " << electronico[choise].getPrecio() << endl;
                    cout << "Descuento: " << electronico[choise].getDescuento() << endl;
                    cout << "Inventario: " << electronico[choise].getInventario() << endl;
                    cout << "Garantia: " << electronico[choise].getVenMatGar() << endl;
                    cout << "Precio con descuento: " << electronico[choise].ajusteDescuento() << endl;
                
                    cout << endl;
                    cout << "Ingrese los nuevos datos" << endl;
                    cout << endl;

                    cout << "Ingrese nombre: ";
                    cin >> nombre;

                    menuAggMod(nombre, electronico[nombre]);
                    cout << "Ingrese la garantia: ";
                    cin >> garantia;                  
                    electronico[nombre].setVenMatGar(garantia);

                }

                else {
                    cout << "Inventario vacio" << endl;
                }
                
                break;
            default:

                bool flag = true;

                while (flag == true){

                    cout << endl;
                    cout << "COMESTIBLES" << endl;

                    for (auto& par: comestible) {

                        cout << par.second.getNombre() << "  Cantidad:  " << par.second.getInventario() << endl;
                    }

                    cout << endl;
                    cout << "ASEO" << endl;

                    for (auto& par: aseo) {

                        cout << par.second.getNombre() << "  Cantidad:  " << par.second.getInventario() << endl;
                    }

                    cout << endl;
                    cout << "ELECTRONICOS" << endl;

                    for (auto& par: electronico) {

                        cout << par.second.getNombre() << "  Cantidad:  " << par.second.getInventario() << endl;
                    }

                    opcion = tipoProduct();

                    cout << "Escoja el producto que desea comprar: ";
                    cin >> choise;
                    cout << "Escoja cantidad: ";
                    cin >> cantidad;

                    if ((opcion == 1) && (comestible.empty() == false)) {

                        if ((comestible[choise].getInventario() - cantidad) > 0){
                            carritoString.push_back(comestible[choise]);
                            comestible[choise].setInventario(comestible[choise].getInventario() - cantidad);
                            precioTotal += cantidad * comestible[choise].ajusteDescuento();
                            cantidades.push_back(cantidad);
                        }

                        else {
                            cout << "Cantidad no disponible" << endl;
                            cout << "Hay " << comestible[choise].getInventario() << " unidades disponibles" << endl;
                        }
                    }

                    else if ((opcion == 2) && (aseo.empty() == false)){

                        if ((aseo[choise].getInventario() - cantidad) > 0){

                            carritoString.push_back(aseo[choise]);
                            aseo[choise].setInventario(aseo[choise].getInventario() - cantidad);
                            precioTotal += cantidad * aseo[choise].ajusteDescuento();
                            cantidades.push_back(cantidad);
                        }

                        else {
                            cout << "Cantidad no disponible" << endl;
                            cout << "Hay " << aseo[choise].getInventario() << " unidades disponibles" << endl;
                        }
                    }

                    else if ((opcion == 3) && (electronico.empty() == false)){

                        if ((electronico[choise].getInventario() - cantidad) > 0){

                            carritoInt.push_back(electronico[choise]);
                            electronico[choise].setInventario(electronico[choise].getInventario() - cantidad);
                            precioTotal += cantidad * electronico[choise].ajusteDescuento();
                            cantidades.push_back(cantidad);
                        }

                        else {
                            cout << "Cantidad no disponible" << endl;
                            cout << "Hay " << electronico[choise].getInventario() << " unidades disponibles" << endl;
                        }
                            

                    }

                    else {
                        cout << "Inventario vacio" << endl; 
                    }
                
                    cout << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "|1. Ver carrito y seguir comprando     |" << endl; 
                    cout << "|3. Pagar                              |" << endl;
                    cout << "----------------------------------------" << endl;           
                    cin >> opcion;

                    if (opcion == 1){
                        //mostrar recibo
                        cout << "----------Carrito-----------" << endl;

                        // for (size_t i = 0; i < carritoString.size(); ++i){
                        //     cout << carritoString[i] << cantidades[i] << " * " << carritoString[i] << endl;
                        // }

                        // for (size_t i = 0; i < carritoInt.size(); ++i){
                        //     cout << carritoInt[i] << cantidades 
                        // }
                        for (auto& obj : carritoString) {

                            cout << obj.getNombre() << "  Precio final: " << obj.ajusteDescuento() << endl;
                        }

                        for (auto& obj : carritoInt) {

                            cout << obj.getNombre() << endl;
                        }  

                        cout << "Total a pagar: " << precioTotal << endl;

                        cout << "----------------------------" << endl;

                    }
                    else if (opcion == 3){
                        flag == false;
                    }
                }

        }

    }

}


void menuAggMod(string nombre, Producto<string>& prod){ 

    prod.setNombre(nombre);

    cout << "Ingrese marca: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(std::cin, marca);
    prod.setMarca(marca);

    cout << "Ingrese precio: ";
    cin >> precio;
    prod.setPrecio(precio);

    cout << "Ingrese descuento: ";
    cin >> descuento;
    prod.setDescuento(descuento);

    cout << "Ingrese cantidad en inventario: ";
    cin >> inventario;
    prod.setInventario(inventario);

}

void menuAggMod(string nombre, Producto<int>& prod){ 
    
    prod.setNombre(nombre);

    cout << "Ingrese marca: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(std::cin, marca);
    prod.setMarca(marca);

    cout << "Ingrese precio: ";
    cin >> precio;
    prod.setPrecio(precio);

    cout << "Ingrese descuento: ";
    cin >> descuento;
    prod.setDescuento(descuento);

    cout << "Ingrese cantidad en inventario: ";
    cin >> inventario;
    prod.setInventario(inventario);

}

int tipoProduct(){

    int opcion;

    cout << "---------------------------" << endl;
    cout << "|  Escoja tipo de producto |" << endl;
    cout << "|1. Comestible             |" << endl;
    cout << "|2. Aseo                   |" << endl;
    cout << "|3. Electronico            |" << endl;
    cout << "---------------------------" << endl;

    cin >> opcion;

    return opcion;

}



