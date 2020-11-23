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
#include "Documento.h"
#include <vector>
#include <list>
class GestorTextos {
private:
    
list<Documento> documentos;
DiccionarioConVerbos diccionario;
    
public:
    GestorTextos();
    GestorTextos(string _documento, string _diccionario, string _verbos);
    GestorTextos(const GestorTextos& orig);
    virtual ~GestorTextos();
    
    GestorTextos& operator=(const GestorTextos &gestor);
    void addDocumento (string _documento);
    Documento* buscarDocumento(string doc);
    Palabra* buscarTermino(string termino);
    list<Palabra> buscarFamilias(string raiz);
    
    int tamDiccionario();
    void mostrarPalabrasAsociadaDocumento();
};

#endif /* GESTORTEXTOS_H */

