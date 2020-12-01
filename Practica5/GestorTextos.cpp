/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestorTextos.cpp
 * Author: Adrian
 * 
 * Created on 19 de octubre de 2020, 16:51
 */

#include "GestorTextos.h"

GestorTextos::GestorTextos() {
}
/**
 * Constructor clase documento
 * @param _documento: nombre del documento
 * @param _diccionario: nombre del archivo del diccionario
 * @param _verbos: nombre del diccionario de verbos.
 */

GestorTextos::GestorTextos(string _documento, string _diccionario, string _verbos, float carga, unsigned tamTabla) {
    
    DiccionarioConVerbos aux(_diccionario, _verbos, carga, tamTabla);
    this->diccionario = aux;
    Documento text(_documento, &diccionario);
    documentos.push_back(text);
   
    
    
    
}


/**
 * Constructor copia de la clase documento.
 * @param orig: Documento del cual vamos a copiar.
 */


GestorTextos::GestorTextos(const GestorTextos& orig) {
  
    this->diccionario = orig.diccionario;
    this->documentos = orig.documentos;
   
}

GestorTextos& GestorTextos::operator=(const GestorTextos& gestor) {
    if(this != &gestor){
       diccionario = gestor.diccionario;
       documentos = gestor.documentos;
    }else{
        throw std::invalid_argument("Los gestores son iguales");
    }
    return *this;
}



GestorTextos::~GestorTextos() {
}

void GestorTextos::addDocumento(string _documento) {
   
    Documento doc (_documento, &diccionario);
    documentos.push_back(doc);
    
}

/**
 * Función encargada de buscar un termino dentro del diccionario
 * @param termino: termino a buscar
 * @return: si existe devuelve un puntero a la palabra, sino devuelve nullptr.
 */
Palabra* GestorTextos::buscarTermino(unsigned long clave, string termino) {
    Palabra *pal = diccionario.buscarTermino(clave, termino);
    
    if (pal != nullptr){
        return pal;
    }
    else{
        return nullptr;
    }
}

bool GestorTextos::insertarTabla(Palabra &pal) {
    diccionario.insertaTabla(pal);
}

unsigned int GestorTextos::colisiones() {
    return diccionario.colisiones();
}
