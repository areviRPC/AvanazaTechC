
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

                            // 14.5.1 declaracion de la clase tabla dispersa

// declaro la estructura tipo casa
struct TipoCasa{
    char codigo[5];
    char poblacion[31];
    char direccion[51];
    int habitaciones;
    double precio;

};

//declaro la clase CasaRural que incluye la estructura casa
class CasaRural {
    protected: 
        char codigo[5];
        char poblacion[31];
        char direccion[51];
        int habitaciones;
        double precio;
        bool esAlta;
    public: 
        CasaRural(){} // constructor por defecto
        CasaRural(TipoCasa c){ // constructor sobrecargado (construye el objeto tipo casa)
            esAlta = true; 
            asigna(c); // metodo privado que inicializa los atributos de la casa 
        }
        ~CasaRural(){ 
            esAlta = false;
        }
        char* elCodigo(){ // usaremos el atributo "codigo" como clave 14.5.3
            return codigo;
        }
        bool OesAlta(){
            return esAlta;
        }
        void PesAlta(bool sw){
            esAlta = sw;
        }
        void muestra(){
            cout << "\n Casa Rural: " << codigo << endl;
            cout << "Poblacion: " << poblacion << endl;
            cout << "Direccion: " << direccion << endl;
            cout << "Precio por dia: " << precio << endl;
        }
    private: 
        void asigna(TipoCasa c){
            strcpy(poblacion, c.poblacion);
            strcpy(direccion, c.direccion);
            strcpy(codigo, c.codigo);
            habitaciones = c.habitaciones;
            precio = c.precio;
        }
};

                            // 14.5.1 declaracion de la clase Tabla dispersa

class TablaDispersa{
    protected:
        int final;
        int numElementos;
        double factorCarga;
        CasaRural **tabla;
    public: 
        TablaDispersa(int n);           // 14.5.2
        int direccion(char *clave);     // 14.5.3
        void insetar(CasaRural r);      // 14.5.4
        CasaRural* buscar(char* clave); // 14.5.5
        void eliminar(char *clave);     // 14.5.6
    private:
        long transformaCadena(char* c); // 14.5.3
};

                            // 14.5.2 inicializacion de la clase tabla dispersa

TablaDispersa::TablaDispersa(int n){
    
    tabla = new CasaRural*[n]; // arreglo de punteros
    final = n;

    for( int j = 0 ; j < final ; j++){
        tabla[j] = NULL; // se llama al constructor n veces inicianlizando en NULL
    }
    numElementos = 0;
    factorCarga = 0.0;
};

                            // 14.5.3 psocion de un elemento 

int TablaDispersa::direccion(char * clave){
    int i = 0;
    long p,d; 
    d = transformaCadena(clave); // se usa la clave para transformar la clave #codigo" en numero 
    p = d % final; // elejimos el metodo de division modular 

    while (tabla[p] != NULL && strcmp(tabla[p]->elCodigo(),clave) != 0){
        i++;
        p = (p + i) * i; 
        p = p % final; // considera el arbol como circular
    }
    return(int)p; // devuelve el indice en la tabla hash
}

//realiza la conversion de clave a numero por medio del ocodigo asci
long TablaDispersa::transformaCadena(char* c){  
    long d = 0;
    int len = strlen(c);
    for(int j = 0 ; j < len; j++){
        d = d * 27 + (int)c[j];
    }
    if ( d < 0 ){
        d = -d;
    }
    return d;
}


                            // 14.5.4 inserar un elemento a la tabla

// se busca la posicion que debe ocupar. La funcon direccion devuelve la posicion buscada

void TablaDispersa::insetar(CasaRural r){
    int posicion; 

    posicion = direccion(r.elCodigo()); // buscamos la posicion 14.5.3
    tabla[posicion] = new CasaRural(r); // creamos una nueva casa
    numElementos ++; // sumamos el numero de elementos
    factorCarga = (double)numElementos / final;
    if (factorCarga > 0.5){
        cout << "\n !! el factor de carga supera el 50% !!" << "conviene aumental el tamaño" << endl;
    } // alerta 


}

                        // 14.5.5 busqueda de un elemento

// busca la posicion a partir de la direccion dispersa correspodiente. devuelvle un puntero al elemento

CasaRural* TablaDispersa::buscar(char * clave){
    
    CasaRural *pr;
    int posicion;

    posicion = direccion(clave);
    pr = tabla[posicion];
    if (pr != NULL){ // verifia si la casa esta dada de alta
        if(!pr->OesAlta()){ 
            pr = NULL; // si la casa esta dada de alta el puntero es nulo
        }
    }
    return pr; // retorno el puntero
}

                    // 14.5.6 dar de alta un elemento 

// se determina la posicion del elemento en la tabla(direccion()) 
// si encuentra la posicion cambia su atributo "PesAlta" a false

void TablaDispersa::eliminar(char *clave){
    int posicion; 

    posicion = direccion(clave);
    if ( tabla[posicion] != NULL){
        tabla[posicion]->PesAlta(false);
    }
}

int main()
{
    // Creamos una tabla de 10 posiciones
    TablaDispersa tabla(10);

    // Creamos algunas casas
    TipoCasa c1 = {"A001", "Madrid", "Calle Falsa 123", 3, 100.0};
    TipoCasa c2 = {"B002", "Barcelona", "Avenida Real 45", 2, 85.5};
    TipoCasa c3 = {"C003", "Valencia", "Camino del Sol 9", 4, 120.75};

    // Insertamos en la tabla
    tabla.insetar(CasaRural(c1));
    tabla.insetar(CasaRural(c2));
    tabla.insetar(CasaRural(c3));

    // Buscamos una casa
    CasaRural* encontrada = tabla.buscar("B002");
    if (encontrada != nullptr) {
        cout << "\nCasa encontrada:" << endl;
        encontrada->muestra();
    } else {
        cout << "\nCasa no encontrada." << endl;
    }

    // Eliminamos una casa
    tabla.eliminar("B002");

    // Intentamos buscarla de nuevo
    encontrada = tabla.buscar("C003");
    if (encontrada != nullptr) {
        cout << "\nCasa encontrada después de eliminar (esto no debería pasar):" << endl;
        encontrada->muestra();
    } else {
        cout << "\nCasa correctamente eliminada (no se encontró)." << endl;
    }

    return 0;
}
