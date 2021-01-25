/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MallaRegular.h
 * Author: Adrian
 *
 * Created on 29 de diciembre de 2020, 20:09
 */

#ifndef MALLAREGULAR_H
#define MALLAREGULAR_H
#include <list>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "UTM.h"
using namespace std;
template <typename T>

class Casilla{
    
    
    public:
        list<T> puntos;
       /**
        * Constructor de la clase casilla.
        */
        Casilla(): puntos() {}
        
        /**
         * Función que inserta dentro de la casilla
         * @param dato: dato a insertar.
         */
        void insertar( const T &dato ){ puntos.push_back(dato); }
        
        
        /**
         * Función que busca un valor.
         * @param dato: dato a buscar
         * @return: devuelve el puntero al dato, o 0 si no se encuentra.
         */
        T *buscar( const T &dato ){
            
            for (  auto it = puntos.begin(); it != puntos.end(); it++ ){
                if ( *it == dato ){
                    return &it;
                }
            }
            return 0;
        }
        
        
        /**
         * Función encargada de borrar un dato de la casilla.
         * @param dato: Dato el cual vamos a borrar.
         * @return: true si se encuentra y se ha borrado, y false si no se encuentra.
         */
        bool borrar ( const T &dato ){
            
            for( auto it = puntos.begin(); it != puntos.end(); it++ ){
                
                if ( *it == dato ){
                    puntos.erase( it );
                    return true;
                }
                
            }
            return false;
        }
        
        /**
         * Función para conocer la cantidad de puntos.
         * @return: devuelve el numero de puntos 
         */
        unsigned int tamlista(){
            return puntos.size();
        }
    
};

template <typename T>
class MallaRegular {
private:
    float xMin, yMin, xMax, yMax; //Tamaño de la malla.
    float tamaCasillaX, tamaCasillaY; //Tamaño de las casillas.
    int nDivX, nDivy;
    
    unsigned int maxElementosPorCelda = 0;
    unsigned int elementosCelda = 0; 
    unsigned int celdasOcupadas = 0;
    vector<vector<Casilla<T>>> mallaReg; 
    
    
    /**
     * Función para obtener la casilla.
     * @param x: coordenada x.
     * @param y: coordenada y.
     * @return:  devuelve la casilla.
     */
    Casilla<T> *obtenerCasilla( float x, float y ){
        
        int i = ( x - xMin ) / tamaCasillaX;
        int j = ( y - yMin ) / tamaCasillaY;
        return &mallaReg[j][i];
    }
    
    
    
public:
    MallaRegular(){}
    
    /*Constructor parametrizado de la malla regular*/
    MallaRegular( float axMin, float ayMin, float axMax, float ayMax, float _nDivx, float _nDivy ):xMin(axMin),
            yMin(ayMin), xMax(axMax), yMax(ayMax), nDivX(_nDivx), nDivy(_nDivy)
    {
        tamaCasillaX = ( xMax - xMin ) / nDivX;
        tamaCasillaY = ( yMax - yMin ) / nDivy;
        
        mallaReg.insert( mallaReg.begin(), nDivX, vector <Casilla<T>> (nDivy));
    
    }
    
    /**
     * Función de insertar dentro de una casilla
     * @param x: coordenada x.
     * @param y: coordenada y.
     * @param dato: dato a insertar
     */
    void insertar( float x, float y , const T &dato){
        Casilla<T> *c = obtenerCasilla( x , y );
        c->insertar( dato );
        
        if( c->tamlista() > maxElementosPorCelda ){
            maxElementosPorCelda = c->tamlista();
        }
        elementosCelda++;
      
    }
    
    /**
     * Función encargada de borrar un dato de la malla regular
     * @param x: coordenada x.
     * @param y: coordenada y.
     * @param dato: dato a borrar.
     * @return: true si se ha borrado, false si no.
     */
    bool borrar( float x, float y, const T& dato){
        Casilla<T> *c = obtenerCasilla( x , y );
        return c->borrar( dato );
    }
    
    
    /**
     * Función para buscar un dato.
     * @param x: coordenada x.
     * @param y: coordenada y.
     * @param dato: dato a buscar.
     * @return: devuelve el dato buscado.
     */
    T* buscar( float x, float y, const T& dato){
        Casilla<T> *c = obtenerCasilla( x , y );
        
       return c->buscar( dato );
        
    }
    
    
    /**
     * Función para conocer el máximo de elementos por celda.
     * @return: el número máximo de Elementos por celda.
     */
    unsigned MaxElementosPorCelda(){
        return maxElementosPorCelda;
    }
    
    
    /**
     * Función para conocer la media de elementos por celda
     * @return: media de elementos por celda.
     */
    float promedioElementosPorCelda(){
        for( auto it = mallaReg.begin(); it != mallaReg.end(); it++ ){
            for( auto it2 = it->begin(); it2 != it->end(); it2++ ){
                
                celdasOcupadas++;
            }
        }
        
        float media = (float)elementosCelda / (float)celdasOcupadas;
        
        return media;
    }
    
    
    
    list<T> buscarRango(float rxmin, float rymin, float rxMax, float rymax){
        
        if(rxMax > xMax && rxmin < xMin && rymax > yMax && rymin < yMin ){
            throw std::invalid_argument("los parámetros pasados sobrepasan los limites de la malla");
        }else{
            list<T> valores;
            
          int  iniX = (rxmin - xMin) / tamaCasillaX;
          int  iniY = (rymin - yMin) / tamaCasillaY;
          int aux3 = 0;
          
          int finX = (rxMax - xMin) / tamaCasillaX;
          int finY = (rymax - yMin) / tamaCasillaY;
          
          if( iniX < 0 ){
              iniX = 0;
          }
          if (iniY < 0 ) {
              iniY = 0;
          }
          if ( finX > tamaCasillaX){
              finX = nDivX -1;
          }
          if (finY > tamaCasillaY){
              finY = nDivy -1;
          }
          
          for( int i = iniX; i <= finX; i++){
              
              for(int j = iniY; j <= finY; j++){
                  
                  
                  Casilla<T> c = mallaReg[j][i];
                  
                  for( auto it = c.puntos.begin(); it != c.puntos.end(); it++ ){
                      
                      T aux = it.operator *();
                      UTM auxUTM = aux->getPosicion();
                      if( auxUTM.latitud <= rymax && auxUTM.latitud >= rymin && auxUTM.longitud <= rxMax && auxUTM.longitud >= rxmin ){
                         valores.push_back(aux); 
                      }
                      
                      
                     
                  }
              }
          }
            
          return valores;  
        }
    }
    
    /***********************Metodos get*************************/
    
    float getXmin(){
        return xMin;
    }    
    
    float getXmax(){
        return xMax;
    }
    
    float getYmin(){
        return yMin;
    }
    
    float getYmax(){
        return yMax;
    }
    
    float getTamaCasillaX(){
        return tamaCasillaX;
    }
    
    float getTamaCasillaY(){
        return tamaCasillaY;
    }
    
    int tamMalla(){
        return mallaReg.size();
    }
    
    
    /**********************************************************/
   


};

#endif /* MALLAREGULAR_H */

