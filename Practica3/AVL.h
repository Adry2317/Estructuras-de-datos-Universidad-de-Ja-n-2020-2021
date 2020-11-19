/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.h
 * Author: Adrian
 *
 * Created on 2 de noviembre de 2020, 18:41
 */

#ifndef AVL_H
#define AVL_H

#include <cstddef>
#include <iostream>
#include <ctime>
using namespace std;
/*****************************Clase nodo AVL****************************/
template <typename T>
class NodoArbol {
    
    
    public: 
        NodoArbol<T> *izq, *der;
        T dato;
        int bal;
        
        NodoArbol(T& ele):izq(0), der(0), bal(0), dato(ele){}
        
        NodoArbol( NodoArbol<T> *_izq, NodoArbol<T> *_der, T& ele){
            izq=_izq;
            der=_der;
            dato=ele;
            
        }
        
        ~NodoArbol() {};
};

template <class T>
class AVL {
    NodoArbol<T> *raiz;
    clock_t tiempoBusqueda=0;
    /***************************Funciones privadas***************************/
    private:
        /**
         * Función que rota a la izq los nodos del arbol para balancearlo.
         * @param p: Nodo que queremos rotar
         */
        void rotaIzquierda(NodoArbol<T>* &p){
            NodoArbol<T> *q = p, *r;
            
            p = r = q->der;
            q->der = r->izq;
            r->izq = q; //Y
            q->bal++;
            
            if( r->bal < 0 ){
                q->bal += -r->bal;
            }
            r->bal++;
            if ( q->bal > 0 ) {
                r->bal += q->bal;
            }
        }
        
        /**
         * Función que rota a la izq los nodos del arbol para balancearlo.
         * @param p: Nodo que queremos rotar
         */
        void rotaDerecha (NodoArbol<T>* &p){
            NodoArbol<T> *q = p, *l;
            
            p = l = q->izq;
            q->izq = l->der;
            l->der = q;
            q->bal--;
            
            if (l->bal > 0){
                q->bal -= l->bal;
            }
            
            l->bal--;
            
            if(q->bal < 0){
                l->bal -= -q->bal;
            }
        }
        
        
        /**
         * Función para insertar un dato dentro de un AVL.
         * @param c: se pasa un nodo
         * @param dato: el dato que vamos a insertar
         * @return : debuelve un 0 o un 1
         */
        int inserta(NodoArbol<T>* &c, T &dato){
                NodoArbol<T> *p = c;
            int deltaH = 0;
            
            if ( !p ){
                
                p = new NodoArbol<T> ( dato );
                c = p;
                deltaH = 1;
                
            }
            
            else if( dato > p->dato ){
                if(inserta ( p->der, dato )){
                    p->bal--;
                    
                    if ( p->bal == -1 ){
                    deltaH = 1;
                    }
                else if( p->bal == -2 ){
                    if(p->der->bal == 1)
                        rotaDerecha( p->der );
                    
                    rotaIzquierda( c );
                }
                }
                
            }
            
            else if ( dato < p->dato ) {
                if ( inserta( p->izq, dato) ){
                    p->bal++;
                    
                    if( p->bal == 1 )
                        deltaH = 1;
                    
                    else if ( p->bal == 2 ){
                        if( p->izq->bal == -1 )
                            rotaIzquierda( p->izq );
                        rotaDerecha( c );
                    }
                }
            }
            
            return deltaH;
        }
        
       /**
         * Función auxiliar que utilizamos para copiar nodos.
         * @param nodo: nodo que pasamos por parámetro para copiar.
         * @return devuelve un nodo
         */ 
        NodoArbol<T> *copiaAVL (NodoArbol<T> *nodo){
            NodoArbol<T> *copia;
            if(nodo == nullptr){
                copia = nullptr;
            }else{
                NodoArbol<T> *izquierda = copiaAVL (nodo->izq);
                NodoArbol<T> *derecha = copiaAVL (nodo->der);
                copia = new NodoArbol<T>(izquierda, derecha, nodo->dato);
            }
            return copia;
        }
        
        
        /**
          * Funcón que recorre el árbol en postOrden, y va eliminando
          * @param p: nodo por el que empieza.
          */
        void borraAVLpostOrden (NodoArbol<T> *p){
            if( p!=nullptr){
                borraAVLpostOrden(p->izq);
                borraAVLpostOrden(p->der);
                
                delete p;
            }
        }
        
        /**
          * Función auxiliar para buscar un elemento
          * @param ele: elemento a buscar.
          * @param p: nodo del cual partimos.
          * @return: devuelve lo obtenido en la busqueda.
          */
        NodoArbol<T> *buscarClave (T &ele, NodoArbol<T> *p){
            if (!p){
                return 0;
            }else if (ele < p->dato){
                return buscarClave(ele, p->izq);
                
            }else if( ele > p->dato){
                return buscarClave(ele, p->der);
            }else{
                return p;
            }
        }
      
        /**
         * Función que recorre los datos del AVL en "InOrden".
         * @param arbol: raiz del AVL a mostrar.
         */
        void recorreInOrden ( NodoArbol<T> *arbol){
            if( arbol == nullptr ){
                return;
            }else{
                recorreInOrden(arbol->izq);
                cout<<arbol->dato<< "-";
                cout<<endl;
                recorreInOrden( arbol->der);
            }
        }
        
        /**
         * Fucnión que recorre el arbol, para saber cuantos elementos tiene.
         * @param arbol: raíz del arbol a recorrer.
         * @param elementos: variable donde se alamacenará el numero de elementos del arbol.
         */
        void elementosArbol (NodoArbol<T> *arbol, unsigned int &elementos ){
            if ( !arbol ){
                return;
            }else{
                elementosArbol(arbol->izq, elementos);
                elementosArbol(arbol->der, elementos);
                
                elementos++;
            }
        }
        
        
        
         /**
          * Función auxiliar para calcular la altura del árbol
          * @param p: nodo del cual partimos.
          * @param aux: variable que hace de contador.
          * @param altura: variable que almacena la altura del arbol.
          */
         void AuxAltura( NodoArbol<T> *p, int aux, int &altura){
             if (p->izq) AuxAltura(p->izq,aux+1,altura);
             
             if(p->der) AuxAltura(p->der,aux+1,altura);
             
             if( this->raiz!=p &&aux > altura ) altura = aux;
         }
        
    /******************************Funciones públicas***************************************/    
    public:
        AVL(){
            raiz = 0;
        };
        
        /**
         * Constructor copia de una AVL
         * @param orig: Arbol que pasamos para copiar
         */
        AVL<T> (const AVL<T> &orig){
            this->raiz = copiaAVL(orig.raiz);
        }
        
        
        /**
         * Sobrecarga del operador de asignación para los AVL
         * @param orig: Arbol del cual queremos asignar valores.
         *  
         */
        void operator= (const AVL<T> &orig){
            if (this != &orig){
                borraAVLpostOrden(this->raiz);
                
                this->raiz = copiaAVL(orig.raiz);
            }
        }
        
        /**
         * Función para insertar valores al AVL (Con recursividad)
         * @param Dato: dato que queremos introducir.
         * @return: devuelve un 0 o 1
         */
        bool insertar(T &dato){
            return inserta(raiz,dato);
        }
        
        
        /**
         * Función que busca un elemento dentro de un AVL de forma recursiva
         * @param dato: dato a buscar.
         * @param result: resultado de la busqueda.
         * @return: devuelve true si lo ha encontrado, false si no lo ha encontrado.
         */
        bool buscaRrecursiva (T& dato, T& result){
            NodoArbol<T> *p = buscarClave(dato, this->raiz);
            clock_t t_init;
            t_init = clock();
            if(p){
                result = p->dato;
                tiempoBusqueda += clock() - t_init;
                return true;
            }else{
                return false;
            }
        }
        
        
        /**
         * Función que busca un dato dentro de un AVL de forma iterativa.
         * @param dato: dato a buscar.
         * @param result: resultado de la busqueda.
         * @return: devuelve true si se ha encontrado, sino se devuelve false.
         */
        bool buscaIt(T& dato, T& result){
            bool encontrado = false;
            
            NodoArbol<T> *auxiliar = this->raiz;
            
            while (encontrado = false && auxiliar != nullptr){
                if(dato == auxiliar->dato){
                    encontrado = true;
                }
                else if( dato < auxiliar->dato){
                    auxiliar = auxiliar->izq;
                }
                else{
                    auxiliar = auxiliar->der;
                }
            }
            result = auxiliar->dato;
            return encontrado;
        }
        
        
        /**
         * Función que muestra los elementos del AVL de manera  "InOrden"
         */
        void muestraInOrden(){
            cout<<"Recorrido del AVL en InOrden: ";
            recorreInOrden( this->raiz );
        }
        
        /**
         * Función que muestra el numero de elementos del arbol(AVL).
         * @param ele: parametro donde se almacenará el numero de elementos.
         * @return: devulve el numero de elementos del avl
         */
        void numElementosAVL( unsigned int &ele){
            ele = 0;
            elementosArbol(this->raiz, ele);
            
        }
        
        
          
        /**
         * Función que para saber la altura del árbol.
         * @param a: Pasamos un árbol
         * @param aux: variable que almacena la altrura del árbol.
         */ 
        void altura (int &aux){
             aux = 0; 
            
            AuxAltura( this->raiz, 0, aux);
            
            
        }
        
        
        clock_t getTiempoBuqueda(){
            return this->tiempoBusqueda;
        }
        
        
        /**
         * Destructor de la clase AVL.
         * Destrucción de forma recursiva y en postOrden.
         */
        virtual ~AVL(){
            borraAVLpostOrden(this->raiz);
        }


};

#endif /* AVL_H */

