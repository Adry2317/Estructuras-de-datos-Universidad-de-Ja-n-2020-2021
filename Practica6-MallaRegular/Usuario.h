/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: Adrian
 *
 * Created on 26 de diciembre de 2020, 23:56
 */

#ifndef USUARIO_H
#define USUARIO_H
#include<string>
#include "UTM.h"

using namespace std;
class Ziri;
class Usuario {
private:
   string nif;
   string clave;
   string nombre;
   UTM posicion;
   string frase;
   Ziri *enlaceZiri;  
public:
    Usuario();
    Usuario( string _nif, string _clave, string _nombre,double _latitud,double _longitud, string _frase, Ziri *_enlaceZiri);
    Usuario(const Usuario& orig);
    Usuario& operator= (const Usuario &usu);
    UTM getPosicion();
    string getNif();
    string getClave();
    string getFrase();
    string getNombre();
    bool login( string _nif, string pass );
    void escribeMensaje();
    virtual ~Usuario();


};

#endif /* USUARIO_H */

