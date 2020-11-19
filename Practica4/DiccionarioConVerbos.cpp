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

DiccionarioConVerbos::DiccionarioConVerbos(string _nombreDicc, string _nombreDiccVerbos) {
    
    if(_nombreDicc != "" && _nombreDiccVerbos != ""){
        string palabra;
        ifstream fe(_nombreDicc);
        
        while(fe) {
            fe >> palabra;
            Palabra pal (palabra, this, 0, nullptr);
            palabras[palabra] = (pal);
        }
        
        ifstream fe2(_nombreDiccVerbos);
        string palabra2;
        
        while(fe2){
            fe2 >> palabra2;
            Palabra pal2 (palabra2, this, 0, nullptr);
            palabras[palabra2] = (pal2);
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
    palabras = orig.palabras;
}

DiccionarioConVerbos::~DiccionarioConVerbos() {
}


/**
 * Función encargada de buscar una palabra del diccionario
 * @param termino: clave por la que buscaremos la palabra
 * @return: un puntero a la palabra;
 */
Palabra* DiccionarioConVerbos::buscarTermino(string termino) {
    Palabra *palBuscada;
    
    map<string,Palabra>::iterator it = palabras.find(termino);
    palBuscada = &it->second;
    
    if(palBuscada->getPalabra() == termino)
    return palBuscada;
    
    else
        return nullptr;
    
    
}

/**
 * Función encargada de insertar en el diccionario la palabras que no se encuentren en el mismo.
 * @param pal: palabra a insertar.
 */
void DiccionarioConVerbos::inseraInexistente(Palabra pal) {
    palabras[pal.getPalabra()] = pal;
}

/**
 * Función para saber el tamaño del mapa 
 * @return: tamaño mapa.
 */
unsigned int DiccionarioConVerbos::tamMapa() {
    return palabras.size();
}

list<Palabra> DiccionarioConVerbos::buscarFamilias(string raiz) {
    list<Palabra> listaFamilia;
    auto it = palabras.lower_bound(raiz);
    size_t found = it->first.find(raiz);
    while(found != string::npos){
        
        Palabra *pal = &it->second;
        listaFamilia.push_back(*pal);
        
        it.operator ++();
        found = it->first.find(raiz);
    
    
    }
    return listaFamilia;
}
