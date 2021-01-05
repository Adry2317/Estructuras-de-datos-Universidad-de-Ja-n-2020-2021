/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ziri.h
 * Author: Adrian
 *
 * Created on 31 de diciembre de 2020, 0:57
 */

#ifndef ZIRI_H
#define ZIRI_H
#include "MallaRegular.h"
#include "Usuario.h"
#include "GestorTextos.h"
#include <map>
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class Ziri {
private:
    GestorTextos gestor;
    map<string, Usuario> usuariosNIF;
    MallaRegular<Usuario*> usuarioUTM;
    list<Usuario*> conectados;
public:
    Ziri();
    Ziri(const Ziri& orig);
    Ziri& operator=( const Ziri& orig);
    virtual ~Ziri();
    float promedioUsuarios();
    Usuario* nuevoUsuarioConectado( string nif, string pass );
    void desconectarUsuario( string nif );
    void recibeMensajeUsuario(string frase, Usuario *usu);
    void cargaUsuarios( string nombreFich, float &axMin, float &ayMin, float &axMax, float &ayMax );
    void chequearTexto( string frase, Usuario *usu );
    list<Usuario*> analizartermino( string palabra );
    list<Usuario*> buscarTerminoRango(string termino, float rxmin, float rymin, float rxMax, float rymax);
    int cantidadUsuarios();
    int usuariosConectados();
    int OcurrenciaPal(string termino);
    void escribeMensajeConectados();

};

#endif /* ZIRI_H */

