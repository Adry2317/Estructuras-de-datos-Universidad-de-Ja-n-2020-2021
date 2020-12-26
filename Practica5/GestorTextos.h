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
//#include "Documento.h"
#include <vector>
#include <list>

class GestorTextos {
private:
    
list<Documento> documentos;
DiccionarioConVerbos diccionario;
    
public:
    GestorTextos();
    GestorTextos(string _documento, string _diccionario, string _verbos, float carga, unsigned tamTabla);
    GestorTextos(const GestorTextos& orig);
    virtual ~GestorTextos();
    
    GestorTextos& operator=(const GestorTextos &gestor);
    void addDocumento (string _documento);
    bool insertarTabla(Palabra &pal);
    bool borraPalabra( string termino);
    Palabra* buscarTermino(  string termino);
    Documento* buscarDocumento( string doc );
    unsigned int colisiones();
    
    
};

#endif /* GESTORTEXTOS_H */

