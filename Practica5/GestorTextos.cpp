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

/**
 * Sobre carga del operador de asignación
 * @param gestor: gestor desde el cual se van a asignar los valores
 * @return: devuelve el gestor con los datos del pasado.
 */
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


/**
 * Función que añade un documento
 * @param _documento: nombre del documento a insertar.
 */
void GestorTextos::addDocumento(string _documento) {
   
    Documento doc (_documento, &diccionario);
    documentos.push_back(doc);
    
}

/**
 * Función encargada de buscar un termino dentro del diccionario
 * @param termino: termino a buscar
 * @return: si existe devuelve un puntero a la palabra, sino devuelve nullptr.
 */
Palabra* GestorTextos::buscarTermino( string termino) {
    Palabra *pal = diccionario.buscarTermino( termino);
    
    if (pal != nullptr){
        return pal;
    }
    else{
        return nullptr;
    }
}


/**
 * Función para insertar en la tabla hash
 * @param pal: palabra a insertar.
 * @return: devuelve true si se ha insertado y false si no se ha insertado.
 */
bool GestorTextos::insertarTabla(Palabra &pal) {
    return diccionario.insertaTabla(pal);
}


/**
 * Función para borrar en la tabla hash
 * @param pal: palabra a insertar.
 * @return: devuelve true si se ha borrado y false si no se ha borrado.
 */
bool GestorTextos::borraPalabra( string termino) {
    return diccionario.borraPalabra(termino);
}


/**
 * Función que devuelve el numero de colisiones
 * @return 
 */
unsigned int GestorTextos::colisiones() {
    return diccionario.colisiones();
}

Documento* GestorTextos::buscarDocumento(string doc) {
    for( list<Documento>::iterator it = documentos.begin(); it!=documentos.end(); it++){
        if(it->getNombreFich() == doc){
            return &it.operator *();
        }
    }
    return nullptr;
}
