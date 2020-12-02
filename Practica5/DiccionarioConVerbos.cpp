/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DiccionarioConVerbos.cpp
 * Author: Adrian
 * 
 * Created on 15 de noviembre de 2020, 14:02
 */

#include <bits/stl_algobase.h>
#include <iosfwd>

#include "DiccionarioConVerbos.h"

DiccionarioConVerbos::DiccionarioConVerbos() {
}

DiccionarioConVerbos::DiccionarioConVerbos(string _nombreDicc, string _nombreDiccVerbos, float carga, unsigned tamDatos):
terminos(carga, tamDatos)
{
    
    
    unsigned long clave;
    
    if(_nombreDicc != "" && _nombreDiccVerbos != ""){
        string palabra;
        ifstream fe(_nombreDicc);
        
        while(fe) {
            fe >> palabra;
            Palabra pal (palabra, 0);
            
            clave = terminos.djb2( palabra );
            terminos.insertar( clave , pal );
        }
        
        ifstream fe2(_nombreDiccVerbos);
        string palabra2;
        
        while(fe2){
            fe2 >> palabra2;
            Palabra pal2 (palabra2, 0);
            clave = terminos.djb2( palabra2 );
            terminos.insertar( clave, pal2 );
        }
        
    }else{
        throw invalid_argument("El nombre de los archivos no puede estar vacío");
    }
}

/**
 * Constructor copia de la clase DiccionarioConVerbos
 * @param orig:Diccionario a copiar
 */
DiccionarioConVerbos::DiccionarioConVerbos(const DiccionarioConVerbos& orig) {
    nombreDicc = orig.nombreDicc;
    nombreDiccVerbos = orig.nombreDiccVerbos;
    
    terminos = orig.terminos;
}

DiccionarioConVerbos& DiccionarioConVerbos::operator=(const DiccionarioConVerbos& dicc) {
    if(this != &dicc){
        nombreDicc = dicc.nombreDicc;
        nombreDiccVerbos = dicc.nombreDiccVerbos;
        terminos = dicc.terminos;
        
    }else{
        throw std::invalid_argument("Los Diccionarios son iguales");
    }
    return *this;
}




DiccionarioConVerbos::~DiccionarioConVerbos() {
}

/**
* Función encargada de buscar un termino dentro de la tabla hash
 * @param termino: termino a buscar
 * @return: si existe devuelve un puntero a la palabra, sino devuelve nullptr.
 * @return 
 */
Palabra* DiccionarioConVerbos::buscarTermino( string termino) {
    Palabra *pal;
    unsigned long clave = terminos.djb2(termino);
    terminos.buscar( clave,termino, pal);
    if(pal != nullptr)
        return pal;
    
    else 
        return nullptr;
}


unsigned int DiccionarioConVerbos::MAxColisiones() {
    return terminos.maximoColisiones();
}


float DiccionarioConVerbos::factCarga() {
    return terminos._factorCarga();
}


unsigned int DiccionarioConVerbos::tamTabla() {
    return terminos.tamañoTabla();
}


float DiccionarioConVerbos::promedioCol() {
    return terminos.promedioColisiones();
}


bool DiccionarioConVerbos::insertaTabla(Palabra &pal) {
    string termino = pal.getPalabra();
    unsigned long clave = terminos.djb2(termino);
    
   return terminos.insertar(clave, pal);
}


unsigned int DiccionarioConVerbos::colisiones() {
    return terminos._colisiones();
}


bool DiccionarioConVerbos::borraPalabra( string termino) {
    unsigned long clave = terminos.djb2(termino);
    
    return terminos.borrar(clave, termino);
}













