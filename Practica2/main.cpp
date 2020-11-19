#include <vector>
#include <fstream>
#include <cstdio>
#include <algorithm>

#include <exception>
#include "GestorTextos.h"

using namespace std;





int main(int argc, char** argv) {
  
    string documento, diccionario;
    documento = "quijote.txt";
    diccionario = "dicc-espanol.txt";
    
    try{
       GestorTextos gestor(documento, diccionario); 
       gestor.chequearTexto();
    
    
    
    ListaEnlazada<int> prueba;
    
   
    
 
    
    ListaEnlazada<Palabra> inex = gestor.getInexistentes();
    
    
        Iterador<Palabra> it = inex.iterador();
        int aux = 0;
        while(it.haySiguiente()!=0 && aux != 100){
        cout<<it.dato().getPalabra()<<endl;
        it.siguiente();
        aux++;
        }
        
        cout<<"Tamaño de la lista inexistentes antes de borrar nombres propios: "<<inex.getTamLista()<<endl;
        
       Iterador<Palabra> it2 = inex.iterador();
       
        while(it2.haySiguiente()!=0 ){
            string palabra = it2.dato().getPalabra();
            if(palabra[0] == toupper(palabra[0])){
                inex.borrar(it2);
            }
        it2.siguiente();
        
        }
    
       cout<<"Tamaño de la lista inexistentes, después de borrar nombres propios: "<<inex.getTamLista()<<endl;
       
    }catch(std::invalid_argument &e){
        cerr<<e.what();
    }
    return 0;
    
}
