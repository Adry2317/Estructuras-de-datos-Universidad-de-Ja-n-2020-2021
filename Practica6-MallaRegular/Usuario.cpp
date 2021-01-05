/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: Adrian
 * 
 * Created on 26 de diciembre de 2020, 23:56
 */

#include <stdexcept>
#include "Ziri.h"
#include "Usuario.h"

Usuario::Usuario() {
}

Usuario::Usuario(string _nif, string _clave, string _nombre,double _latitud,double _longitud ,string _frase,Ziri *_enlaceZiri):
                posicion(_latitud,_longitud),
                nif(_nif), clave(_clave),
                nombre(_nombre), frase(_frase),
                enlaceZiri(_enlaceZiri)
{
 
}


Usuario::Usuario(const Usuario& orig) {
    nif = orig.nif;
    clave = orig.clave;
    nombre = orig.nombre;
    posicion = orig.posicion;
    frase = orig.frase;
    enlaceZiri = orig.enlaceZiri;
    
}

Usuario& Usuario::operator=(const Usuario& usu) {
    if(this != &usu){
        nif = usu.nif;
        nombre = usu.nombre;
        clave = usu.clave;
        posicion = usu.posicion;
        frase = usu.frase;
        enlaceZiri = usu.enlaceZiri;
    }else{
        throw std::invalid_argument("Los usuarios son iguales.");
    }
    
    return *this;
}

UTM Usuario::getPosicion() {
    return posicion;
}

string Usuario::getClave() {
    return clave;
}

string Usuario::getFrase() {
    return frase;
}

string Usuario::getNif() {
    return nif;
}

bool Usuario::login(string _nif, string pass) {
    if( enlaceZiri->nuevoUsuarioConectado(_nif, pass) != nullptr){
        return true;
    }else{
        return false;
    }
}

void Usuario::escribeMensaje() {
    enlaceZiri->recibeMensajeUsuario(frase, this);
}



Usuario::~Usuario() {
}

string Usuario::getNombre() {
    return nombre;
}
