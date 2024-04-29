#ifndef COMESTIBLES_H
#define COMESTIBLES_H
#include <string>

using namespace std;

//Plantilla de clase general
template<typename T>
class Producto {

    string nombre;
    string marca;
    int precio;
    int descuento;
    int inventario;
    float precioDescuento;
    T VenMatGar;

    public:

        void setNombre(string _nombre) {
            nombre = _nombre;
        }

        void setMarca(string _marca) {
            marca = _marca;
        }

        void setPrecio(int _precio){
            precio = _precio;
        }

        void setDescuento(int _descuento) {
            descuento = _descuento;
        }
        
        void setInventario(int _inventario){
            inventario = _inventario;
        }

        T setVenMatGar(T _VenMatGar) {
            VenMatGar = _VenMatGar;
        }


        string getNombre(){
            return nombre;
        }

        string getMarca(){
            return marca;
        }

        int getPrecio(){
            return precio;
        }

        float getDescuento(){
            return descuento;
        }

        int getInventario(){
            return inventario;
        }

        T getVenMatGar(){
            return VenMatGar;
        }
        
        float ajusteDescuento(){
            precioDescuento = precio - ((descuento * precio)/100);
            return precioDescuento;
        }


};

//Especialización de plantilla para string (comestibles y aseo)
template<>
class Producto<string>{

    string nombre;
    string marca;
    int precio;
    int descuento;
    int inventario;
    float precioDescuento;
    string VenMatGar;

    public:

        void setNombre(string _nombre) {
            nombre = _nombre;
        }

        void setMarca(string _marca) {
            marca = _marca;
        }

        void setPrecio(int _precio){
            precio = _precio;
        }

        void setDescuento(int _descuento) {
            descuento = _descuento;
        }
        
        void setInventario(int _inventario){
            inventario = _inventario;
        }

        void setVenMatGar(string _VenMatGar) {
            VenMatGar = _VenMatGar;
        }


        string getNombre(){
            return nombre;
        }

        string getMarca(){
            return marca;
        }

        int getPrecio(){
            return precio;
        }

        float getDescuento(){
            return descuento;
        }

        int getInventario(){
            return inventario;
        }

        string getVenMatGar(){
            return VenMatGar;
        }
        
        float ajusteDescuento(){
            precioDescuento = precio - ((descuento * precio)/100);
            return precioDescuento;
        }
};

//Especialización de plantilla para int (electronicos)
template<>
class Producto<int>{

    string nombre;
    string marca;
    int precio;
    int descuento;
    int inventario;
    float precioDescuento;
    int VenMatGar;

    public:

        void setNombre(string _nombre) {
            nombre = _nombre;
        }

        void setMarca(string _marca) {
            marca = _marca;
        }

        void setPrecio(int _precio){
            precio = _precio;
        }

        void setDescuento(int _descuento) {
            descuento = _descuento;
        }
        
        void setInventario(int _inventario){
            inventario = _inventario;
        }

        void setVenMatGar(int _VenMatGar) {
            VenMatGar = _VenMatGar;
        }


        string getNombre(){
            return nombre;
        }

        string getMarca(){
            return marca;
        }

        int getPrecio(){
            return precio;
        }

        float getDescuento(){
            return descuento;
        }

        int getInventario(){
            return inventario;
        }

        int getVenMatGar(){
            return VenMatGar;
        }
        
        float ajusteDescuento(){
            precioDescuento = precio - ((descuento * precio)/100);
            return precioDescuento;
        }
};
#endif