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

GestorTextos::GestorTextos(string _documento, string _diccionario, string _verbos) {
    try{
    this->diccionario = DiccionarioConVerbos(_diccionario, _verbos);
    Documento text(_documento, &diccionario);
    documentos.push_back(text);
    }catch(invalid_argument &e){
        cerr<<e.what();
    }
    
    
    
}


/**
 * Constructor copia de la clase documento.
 * @param orig: Documento del cual vamos a copiar.
 */


GestorTextos::GestorTextos(const GestorTextos& orig) {
  
    this->diccionario = orig.diccionario;
    this->documentos = orig.documentos;
   
}



GestorTextos::~GestorTextos() {
}

void GestorTextos::addDocumento(string _documento, int tipoDiccionario) {

    Documento nuevoDoc(_documento, &diccionario);
    documentos.push_back(nuevoDoc);
}





/*
Documento GestorTextos::getDocumento( int numDoc ) {
    return documentos[numDoc-1];
    
}
*/





