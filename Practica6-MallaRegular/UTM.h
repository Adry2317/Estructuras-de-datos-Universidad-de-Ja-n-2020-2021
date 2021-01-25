/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UTM.h
 * Author: Adrian
 *
 * Created on 30 de diciembre de 2020, 17:10
 */

#ifndef UTM_H
#define UTM_H


struct UTM{
    double longitud;
    double latitud;
    
    UTM (): latitud(0), longitud(0){}
    UTM ( double _latitud, double _longitud ):latitud(_latitud), longitud(_longitud){}
    
    
    
    /**
     * Sobrecarga del operador =
     * @param utm: utm del cual se van a asignar los valores
     * @return: puntero al utm.
     */
    UTM &operator= ( const UTM& utm) {
        if( this != &utm ){
            latitud = utm.latitud;
            longitud = utm.longitud;
        }
        return *this;
    }
    
    
    /**
     * Sobrecarga del operador == para la clase UTM
     * @param utm: utm a comparar.
     * @return: devuelve true, si son iguales y false si no lo son.
     */
    bool operator == ( const UTM &utm ){
        if ( ( latitud == utm.latitud ) && ( longitud = utm.longitud ) ){
            return true;
        }else{
            return false;
        }
            
    }
    
    
    
};

    

#endif /* UTM_H */
