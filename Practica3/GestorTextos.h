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
#include"Diccionario.h"
#include "Documento.h"
#include "VDinamico.h"
class GestorTextos {
private:
VDinamico<Documento> documentos;
Diccionario diccionario;
    
public:
    GestorTextos();
    GestorTextos(string _documento, string _diccionario, string _verbos);
    GestorTextos(const GestorTextos& orig);
    virtual ~GestorTextos();
    int auxiliarAlturaAVLVerbos();
    void addDocumento (string _documento);
    Documento getDocumento( int numDoc);
    
};

#endif /* GESTORTEXTOS_H */

