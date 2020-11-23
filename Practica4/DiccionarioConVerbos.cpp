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
            Palabra pal (palabra, this, 0);
            palabras[palabra] = (pal);
        }
        
        ifstream fe2(_nombreDiccVerbos);
        string palabra2;
        
        while(fe2){
            fe2 >> palabra2;
            Palabra pal2 (palabra2, this, 0);
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

DiccionarioConVerbos& DiccionarioConVerbos::operator=(const DiccionarioConVerbos& dicc) {
    if(this != &dicc){
        nombreDicc = dicc.nombreDicc;
        nombreDiccVerbos = dicc.nombreDiccVerbos;
        palabras = dicc.palabras;
        
    }else{
        throw std::invalid_argument("Los Diccionarios son iguales");
    }
    return *this;
}




DiccionarioConVerbos::~DiccionarioConVerbos() {
}


/**
 * Función encargada de buscar una palabra del diccionario
 * @param termino: clave por la que buscaremos la palabra
 * @return: un puntero a la palabra;
 */
Palabra* DiccionarioConVerbos::buscarTermino(string termino) {
    
    
    map<string,Palabra>::iterator it = palabras.find(termino);
    if(it != palabras.end()){
    Palabra *palBuscada = &it->second;
   
    return palBuscada;
    
    
    }else{
        return nullptr;
    }
}

/**
 * Función encargada de insertar en el diccionario la palabras que no se encuentren en el mismo.
 * @param pal: palabra a insertar.
 */
void DiccionarioConVerbos::inseraInexistente(Palabra pal,Documento *doc) {
    string clave = pal.getPalabra();
    Palabra insert = pal;
    insert.setDocumento(doc);
    palabras[clave] = insert;
    
    
    
    
    }

/**
 * Función para saber el tamaño del mapa 
 * @return: tamaño mapa.
 */
unsigned int DiccionarioConVerbos::tamMapa() {
    return palabras.size();
}



/**
 * Función encargada de buscar las familias de palabras dada una raíz
 * @param raiz: raíz a partir de la que se buscaran la familia de palabras
 * @return: una lista con la familia de palabras
 */
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

void DiccionarioConVerbos::palEnDocumento() {
 map<string, Palabra>::iterator it = palabras.begin();
 it.operator ++();
 int cont = 0;
 while (it != palabras.end()  && cont < 100){
     Palabra *pal = &it->second;
     if (pal->getDocumento() != nullptr ){
         cout<<pal->getPalabra()<<"-->"<<pal->getDocumento()->getNombreFich()<<endl;
        
         cont++;
         
     }
     it.operator ++();
 }
}
