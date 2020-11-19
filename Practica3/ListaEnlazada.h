/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaEnlazada.h
 * Author: Adrian
 *
 * Created on 13 de octubre de 2020, 11:16
 */

#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
#include <utility>
#include <stdexcept>

/*******************Clase Nodo********************/
template <class T>
class Nodo {
    public:
        T dato;
        Nodo *ant, *sig;

        Nodo(T &aDato, Nodo *aAnt, Nodo *aSig):dato(aDato), ant(aAnt), sig(aSig){}
        ~Nodo() {};
};


//Forward declaration.
template <class T> class ListaEnlazada;



/***********************Clase Iterador************************/
template <class T>
class Iterador {
        
        friend class ListaEnlazada<T>;
        Nodo<T> *nodo;
    public:
        Iterador(Nodo<T> *aNodo):nodo(aNodo){}
        
        bool hayAnterior() {return nodo->ant != 0; }
        bool haySiguiente() {return nodo->sig != 0; }
        void anterior () { nodo = nodo->ant;}
        void siguiente() { nodo = nodo->sig;}
        T &dato() {return nodo-> dato;}
        ~Iterador(){};
};



/*******************Clase ListaEnlazada******************/
template<class T>
class ListaEnlazada {
    Nodo<T> *cabecera, *cola;
    int tamLista;
    
public:
    
    /**
     * Constructor por defecto de la clase ListaEnlazada
     */
    ListaEnlazada<T>():cabecera(0), cola(0),tamLista(0){}
    
    
    /**
     * Constructor copia de la clae ListaEnlazada
     * @param orig: Lista desde la cual vamos a copiar los datos
     * @return devuelve la cola copiada.
     */
    ListaEnlazada<T>(const ListaEnlazada<T>& orig){
        Nodo<T> *copia;
        copia = orig.cabecera;
        this->cabecera = 0;
        this->cola = 0;
        
        while (copia != 0){
            T dato = copia->dato;
            Nodo<T> *auxiliar = new Nodo<T>(dato, this->cola,0);
            
            if( this->cabecera == 0) {
                this->cabecera = auxiliar;
            }
            else if(this->cola != 0){
                this->cola->sig = auxiliar;
            }
            
            copia = copia->sig;
            this->cola = auxiliar;            
            
            
        }
        this->tamLista = orig.tamLista;
        
    }
    
    
    /**
     * Sobrecarga del operador =
     * @param orig: lista desde la cual asignaremos los valores.
     * @return devuelve la lista con los valores ya asignados.
     */
    ListaEnlazada<T>& operator= (const ListaEnlazada<T> &orig){
        if(this != &orig){
            
            while(this->cabecera != 0){
                Nodo<T> *borrado = this->cabecera;
                this->cabecera = this->cabecera->sig;
                delete borrado;
            }
            this->cola = 0;
        
            
            Nodo<T> *auxiliar = orig.cabecera;
            while (auxiliar != 0){
                Nodo<T> *copia = new Nodo<T>(auxiliar->dato,this->cola,0);
                
                if(this->cola != 0){
                    this->cola->sig = copia;
                }else if(cabecera == 0){
                    this->cabecera = copia;
                }
                this->cola = copia;
                auxiliar = auxiliar->sig;
            }
        
        }else{
            throw std::invalid_argument ("Ambas lístas son las mismas");
        }
        
       return *this; 
    }
    
    
    /**
     * Función que devuelve el primer elemento de la lista.
     * @returndevuelve el primer elemento de la lista.
     */
    T& inicio(){
        return this->cabecera->dato;
    }
    
    /**
     * 
     * @return: Devuelve el ultimo elemento de la lista. 
     */
    T& fin(){
        return this->cola->dato;
    }
    
    
    Iterador<T> iterador(){
        return Iterador<T> (this->cabecera);
        
    }
    
   /**
    * Función que inserta al inicio de de una ListaEnlazada
    * @param dato: dato que vamos a insertar.
    */ 
   void insertarInicio(T&dato){
       Nodo<T> *auxiliar = new Nodo<T>(dato, 0, cabecera);
       
       if(cabecera != 0){
           cabecera->ant = auxiliar;
       }
       else if(cola == 0){
           this->cola = auxiliar;
       }
       this->cabecera = auxiliar;
       tamLista++;
   } 
   
   /**
    * Función encargada de insertar al final de la lista enlazada
    * @param dato
    */
   void insertarFinal (T& dato){
       Nodo<T> *auxiliar = new Nodo<T>(dato,cola,0);
       
       if (cola != 0){
           this->cola->sig = auxiliar;
       }
       else if(cabecera == 0){
           this->cabecera = auxiliar;
       }
       this->cola = auxiliar;
       tamLista++;
       
   }
   
   
   /**
    * Funcioón que inserta un dato en la posición anterior apuntada por un iterador
    * @param i: iterador
    * @param dato: dato a insertar
    */
   void inserta(Iterador<T> &i, T &dato){
       
       Nodo<T> *insertar = this->cabecera;
       
       
       //posicionamos el nodo "insertar" a la posicion dada por el iterador.
       while (insertar != i.nodo){
           insertar = insertar->sig;
       }
       
       //si el anterior es 0 se inserta al principio.
       if(insertar->ant == 0){
           Nodo<T> *auxiliar = new Nodo<T>(dato, 0,insertar);
           this->cabecera->ant = auxiliar;
           this->cabecera = auxiliar;
       }
       else{
           Nodo<T> *auxiliar = new Nodo<T>(dato,insertar->ant,insertar);
           insertar->ant->sig = auxiliar;
           insertar->ant = auxiliar;
       }
       tamLista++;
   }
   
   
   
   /**
    * Función encargada de borrar el inicio de la lista.
    */
   void borraInicio(){
       Nodo<T> *borrar = this->cabecera;
       this->cabecera = this->cabecera->sig;
       delete borrar;
       
       if(cabecera != 0){
           cabecera->ant = 0;
       }else{
           cola = 0;
       }
       tamLista--;
   }
   
   /**
    * Función encargada de borrar al final de la lista
    */
   void borrarFinal(){
       Nodo<T> *borrar = this->cola;
       this->cola = cola->ant;
       delete borrar;
       
       if(cola != 0){
           this->cola->sig = 0;
       }else{
           cabecera = 0;
       }
       tamLista--;
   }
   
   
   /**
    * Función encargada de borrar en una posición dada por el iterador
    * @param i posición del iterador.
    */
   void borrar (Iterador<T> &i){
       
       Nodo<T> *borrar = this->cabecera;
       
       
       while (borrar != i.nodo){
           borrar = borrar->sig;
       }
       
       //si el borrado es en la cabecera.
       if(borrar->ant == 0){
           this->cabecera = this->cabecera->sig;
           delete borrar;
           this->cabecera->ant = 0;
       }
       //borrado en la cola
       else if(borrar->sig ==0){
           this->cola = this->cola->ant;
           delete borrar;
           this->cola->sig = 0;
       }
       //borrado en medio
       else{
           borrar->sig->ant = borrar->ant;
           borrar->ant->sig = borrar->sig;
           delete borrar;
       }
       tamLista--;
   }
    
    
   /**
    * Función que inserta un valor ordenado.
    * @param dato: valor a insertar.
    * @return: devuelve false si la lista no se encontraba ordenada, bool si se puede insertar;
    */
   bool insertaOrdenado ( T& dato){
    
       
      if(cabecera == 0){
            Nodo<T> *auxiliar = new Nodo<T>(dato, 0, cabecera);
       
            if(cabecera != 0){
                cabecera->ant = auxiliar;
            }
            else if(cola == 0){
                this->cola = auxiliar;
            }
            this->cabecera = auxiliar;
            tamLista++;
            
           return true;
       }
       bool repetido = false;
       bool parar = false;
       Nodo<T> *aux  =this->cabecera;
       while(aux->sig!=nullptr && repetido == false ){
           aux = aux->sig;
           if(aux->dato == dato){
               repetido = true;
           }
           if(aux->dato< dato){
               parar = true;
           }
           
       }
       if(repetido == false){
           Nodo<T> *aux2 = this->cabecera;
           while(aux2 !=nullptr && aux2->dato < dato){
               aux2 = aux2->sig;
           }
           Nodo<T> *auxiliar = new Nodo<T>(dato,cola,0);
       
            if(dato < cabecera->dato){
                insertarInicio(dato);
            }
           if (aux2 != nullptr){
               Nodo<T> *insertaMed = new Nodo<T> (dato, aux2->ant, aux2);
               aux2->ant->sig = insertaMed;
               aux2->ant = insertaMed;
           }
           else{
                Nodo<T> *auxiliar = new Nodo<T>(dato,cola,0);
       
                if (cola != 0){
                    this->cola->sig = auxiliar;
                }
                else if(cabecera == 0){
                    this->cabecera = auxiliar;
                }
                this->cola = auxiliar;
                tamLista++;
           }
           
           tamLista++;
       }
       
       
        
       
       
       return true;
   }
   
   /**
    * Función para conocer el tamaño de la lista
    * @return: devuelve el tamaño de la lista.
    */
   int getTamLista(){
       return this->tamLista;
   }
   
   /**
    * Destructor de la clase ListaEnlazada.
    */
   ~ListaEnlazada(){
       while ( cola != 0) {
             borrarFinal();    
       }
       
   }
};


#endif /* LISTAENLAZADA_H */


