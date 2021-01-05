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

GestorTextos::GestorTextos(string _diccionario, string _verbos) {
    
    DiccionarioConVerbos aux(_diccionario, _verbos);
    this->diccionario = aux;
 
   
    
    
    
}


/**
 * Constructor copia de la clase documento.
 * @param orig: Documento del cual vamos a copiar.
 */
GestorTextos::GestorTextos(const GestorTextos& orig) {
  
    this->diccionario = orig.diccionario;
    
   
}

/**
 * Sobre carga del operador de asignación
 * @param gestor: gestor desde el cual se van a asignar los valores
 * @return: devuelve el gestor con los datos del pasado.
 */
GestorTextos& GestorTextos::operator=(const GestorTextos& gestor) {
    if(this != &gestor){
       diccionario = gestor.diccionario;
       
    }else{
        throw std::invalid_argument("Los gestores son iguales");
    }
    return *this;
}

Palabra* GestorTextos::buscarTermino(string termino, Usuario* usu) {
    return diccionario.buscarTermino( termino, usu );
}

void GestorTextos::insertaInexistentes(string termino, Usuario* usu) {
    diccionario.insertaInexistentes( termino , usu );
}

list<Usuario*> GestorTextos::analizarTermino(string termino) {
    return diccionario.analizarTermino(termino);
}


GestorTextos::~GestorTextos() {
}





