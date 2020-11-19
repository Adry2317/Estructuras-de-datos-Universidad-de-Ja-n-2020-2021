/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VDinamico.h
 * Author: Adrian
 *
 * Created on 29 de septiembre de 2020, 19:58
 */

#ifndef VDINAMICO_H
#define VDINAMICO_H
#define UINT_MAX 65535
#include <algorithm>
#include <stdexcept>

#include <iostream>


template <class T>

class VDinamico {

private:    
     int potencia2 = 1;
    //Definimos el tamaño fisico.
    int tamFisico;
    //Definimos el tamaño lógico.
    int tamLogico;
    //Definimos el vector.
    T *vect;
    
    
    
    
    /**
     * Función encargada de aumentar el tamaño del vector a la potencia de 
     * 2 siguiente.
     */
    void aumenta(){
        T *vaux;
        tamFisico = tamFisico*2;
        vaux = new T[tamFisico];
        
        for (int i = 0; i < tamLogico; i++){
            vaux[i] = vect[i];
        }
        
        delete [] vect;
        vect = vaux;
        
        
    }
    
    
    
    
    /**
     * Funcion encargadade disminuir el tamaño del vector en el caso de que el 
     * tamño lógico es la tercera parte del tamaño fisico
     */
    void disminuye() {
        
        T* vaux = new T [tamFisico/2];
        
        for(int i = 0; i < tamLogico; i++){
            vaux[i] = vect[i];
        }
        tamFisico = tamFisico / 2;
        delete [] vect;
        
        vect = vaux;
        
    }
    
    
    
public:
    /**
     * Constructor por defecto.
     */
    VDinamico():tamFisico(1),tamLogico(0){
        vect = new T[tamFisico];
    };
    
    
    
    
    /**
     * Constructor parametrizado del vector dinámico.
     * @param tamL: tamaño lógico que se pasa al constructor.
     */
    VDinamico(unsigned int tamL):tamLogico(tamL){
        
            
        
        if(tamL >= 0){
            while(potencia2 <= tamL){
                potencia2 = potencia2 * 2;
            }
            
            tamFisico = potencia2;  
            
            vect = new T[tamFisico];
        }else{
           throw (std::invalid_argument ("El tamaño lógico dado en el constructor no puede se menor que 0"));
        }
    }
    
    
    
    
    
    /**
     * Constructor copia del vector dinámico.
     * @param orig: vector a copiar
     */
    VDinamico(const VDinamico& orig):tamFisico(orig.tamFisico),
                                     tamLogico(orig.tamLogico),
                                     potencia2(orig.potencia2) 
    {    
        vect = new T[tamFisico];
        
        for(int i = 0; i < tamLogico; i++){
            vect[i] = orig.vect[i];
            
        }
    }
    
    
    
    
    /**
     * Constructor copia parcial
     * @param orig: vector a copiar
     * @param inicio: Posición por la que se empieza a copiar
     * @param num: Número de elementos que vamos a copiar
     */
    VDinamico(const VDinamico& orig, unsigned int inicio, unsigned int num):
                                                  tamFisico(num),
                                                  tamLogico(num)
                                                  
    {
        //comprobamos que no vamos a copiar valores basura.
        if((tamLogico - inicio)>= num || (inicio >= 0 && inicio < tamLogico)){
            if(tamFisico%2 != 0){
                while(potencia2 <= tamFisico){
                    potencia2 *=2;
                }
            }
            
            vect = new T[tamFisico];
            
            for(int i = 0; i < num; i++){
                vect[i] = orig.vect[(inicio-1) + i];
            }
                
        }else{
            throw std::out_of_range ("No es posible la copia parcial de este vector");
        }
        
    }
    
    
    
    
    /**
     * Sobrecarga del operador de asignación
     * @param v: vector del cual vamos a asignar los valores
     * @return Devuelve un vector con los valores copiados
     */
    VDinamico<T>& operator=( const VDinamico &v){
        if(this != &v){
            
            delete [] vect;
            tamFisico = v.tamFisico;
            vect = new T[tamFisico];
            
            for (int i = 0; i < v.tamFisico; i++){
                vect[i] = v.vect[i];
            }
            this->tamLogico = v.tamLogico;
            
            
        }else{
            throw std::invalid_argument("Ambos vectores son los mismos");
        }
        return *this;
    }
    
    T& operator[](unsigned int pos){
        if(pos < 0 || pos > tamLogico)
            throw std::out_of_range("La posición a la que intenta acceder está fuera del rango");
        
        return vect[pos];
    }
    
    
    
    
    /**
     * Función para insertar dentro del vector
     * @param dato: Valor que vamos a insertar
     * @param pos: posicón donde vamos a insertar
     */
    void insertar (const T& dato, unsigned int pos = UINT_MAX){
        
        if(tamFisico == tamLogico){
            aumenta();
        }
        
        if (pos != UINT_MAX){
            if(pos > tamLogico || pos < 0){
                throw std::invalid_argument ("Posición del vector no válida");
            }
            
            for(int i = tamLogico-1; i>=pos; i--){
                vect[i+1] = vect[i];
            }
            
            vect[pos] = dato;
            tamLogico++;
            
        }else{
            //insercción al final.
            vect[tamLogico] = dato;
            tamLogico++;
        }
        
    }
    
    
    
    
    /**
     * Función para el borrado de datos en el vector dinámico.
     * @param pos: posición donde vamos a borrar los datos
     * si pos = UINT_MAX, se borrará la posición final
     * @return: devuelve el vector con el dato ya borrado.
     */
    void borrar(unsigned int pos = UINT_MAX){
       
        if( pos != UINT_MAX){
            
             if( pos < 0 || pos > tamLogico){
                throw std::invalid_argument("Posición del vecto no válida");
             }
             
            for(int i = pos; i < tamLogico; i++){
                vect[i] = vect[i+1];
            }
            tamLogico--;
            
                    
        }else{
            
           T* vaux = new T[tamLogico-1];
           for(int i = 0; i<tamLogico-1; i++){
               vaux[i] = vect[i];
           }
           delete [] vect;
           
           vect = new T[tamFisico];
           for(int i=0; i < tamLogico-1; i++){
               vect[i] = vaux[i];
           }
           tamLogico--;
           
        }
        
         if(tamLogico *3 < tamFisico){
            disminuye();            
        }
        
        
        
    }
    
    
    
    /**
     * Función encargada de ordenar el vector de palabras alfabéticamente.
     */
    void ordenar(){
        std::sort(vect, vect+tamLogico);
         
    }
    
    
    
    /**
     * Función encargada de ordenar alfabéticamente pero al revés
     */
    void ordenaRev() {
       
        int cont = 0;
        T aux;
        int tam = tamLogico;
        
        while(cont < tam/2){
            aux = vect[cont];
            vect[cont] = vect[tam -1 -cont];
            vect[tam -1 -cont] = aux;
            cont++;
        }

    }
    
    
    
    /**
     * Función que encuentra un dato dentro del vector.
     * @param dato: dato que vamos a buscar.
     * @return: devuelve la posición del vector en la que se encuentra ese dato.
     */
    int busquedaBin(T& dato){
        
        int inf = 0;
        int sup = tamLogico-1;
        
        
        while( inf <= sup){
            int mitad = (inf + sup)/2;
            
            if(vect[mitad] == dato){
                return mitad;
                
            }else if(vect[mitad] < dato){
                inf = mitad+1;
                
            }else{
                sup = mitad-1;
            }
        }
        
        return -1;
    }
    
    
    /**
     * Función para conocer el tamaño Lógico del vector dinamico.
     * @return: devuelve el tmaño lógico.
     */
    unsigned int tam(){
        return tamLogico;
    }
    
    /**
     * Destructor del Vector Dinámico.
     */
     ~VDinamico(){
         delete [] vect;
     };


};

#endif /* VDINAMICO_H */