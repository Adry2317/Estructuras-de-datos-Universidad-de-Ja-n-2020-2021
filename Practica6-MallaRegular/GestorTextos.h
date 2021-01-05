/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestorTextos.h
 * Author: Adrian
 *
 * Created on 19 de octubre de 2020, 16:51
 */

#ifndef GESTORTEXTOS_H
#define GESTORTEXTOS_H
#include "DiccionarioConVerbos.h"

#include <vector>
#include <list>

class GestorTextos {
private:
    

DiccionarioConVerbos diccionario;
    
public:
    GestorTextos();
    GestorTextos(string _diccionario, string _verbos);
    GestorTextos(const GestorTextos& orig);
    virtual ~GestorTextos();
    GestorTextos& operator=(const GestorTextos &gestor);
    Palabra* buscarTermino( string termino, Usuario *usu );
    void insertaInexistentes( string termino, Usuario *usu );
    list<Usuario*> analizarTermino( string termino);
    
    
    
    
};

#endif /* GESTORTEXTOS_H */

