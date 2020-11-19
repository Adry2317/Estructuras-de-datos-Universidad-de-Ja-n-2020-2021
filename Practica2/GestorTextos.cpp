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
 */
GestorTextos::GestorTextos(string _documento, string _diccionario) {
    this->texto = Documento(_documento);
    this->diccionario = Diccionario(_diccionario);
    
}

/**
 * Constructor copia de la clase documento.
 * @param orig: Documento del cual vamos a copiar.
 */
GestorTextos::GestorTextos(const GestorTextos& orig) {
    this->diccionario = orig.diccionario;
    this->texto = orig.texto;
}

GestorTextos::~GestorTextos() {
}

/**
 * Funcion encargada de chequear las palabras del textos, sino se encuentran
 * las almacena en una lista de inexistentes.
 */
void GestorTextos::chequearTexto() {

    for(int i = 0; i < texto.getTamDocumento(); i++){
       Palabra pal = texto.getPalabra(i); 
       string palLimpia = pal.limpiar(pal);
       Palabra palabraLimpia(palLimpia);
       
       if(diccionario.buscarBinaria(palabraLimpia) == false)
       texto.addInexistente(palabraLimpia);
            
    }
    

}

int GestorTextos::eliminarPropios() {
    ListaEnlazada<Palabra> aux = texto.getLista();
    Iterador<Palabra> it2 = aux.iterador();
    
    while(it2.haySiguiente()){
            string palabra = it2.dato().getPalabra();
            if(palabra[0] == toupper(palabra[0])){
                string palabra2 = palabra;
                palabra2[0] = tolower(palabra[0]);
                Palabra pal(palabra2);
                if(diccionario.buscarBinaria(pal)==false)
                aux.borrar(it2);
            }
        it2.siguiente();
        
        }
    return aux.getTamLista();
}







/**
 * Función que devuelve la lista 
 * @return: devuelve una lista. 
 */
ListaEnlazada<Palabra>& GestorTextos::getInexistentes() {
    return (texto.getLista());
}
