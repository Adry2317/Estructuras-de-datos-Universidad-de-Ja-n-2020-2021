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

DiccionarioConVerbos::DiccionarioConVerbos(string _nombreDicc, string _nombreDiccVerbos)
{
    

    
    if(_nombreDicc != "" && _nombreDiccVerbos != ""){
        string palabra;
        ifstream fe(_nombreDicc);
        
        while(fe) {
            fe >> palabra;
            Palabra pal (palabra, 0);
            
            terminos[palabra] = pal;
        }
        
        ifstream fe2(_nombreDiccVerbos);
        string palabra2;
        
        while(fe2){
            fe2 >> palabra2;
            Palabra pal2 (palabra2, 0);
            string limpia = pal2.limpiar(pal2);
            
            
            terminos[palabra2] = pal2;
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
    
    
}

DiccionarioConVerbos& DiccionarioConVerbos::operator=(const DiccionarioConVerbos& dicc) {
    if(this != &dicc){
        nombreDicc = dicc.nombreDicc;
        nombreDiccVerbos = dicc.nombreDiccVerbos;
        
        
    }else{
        throw std::invalid_argument("Los Diccionarios son iguales");
    }
    return *this;
}




DiccionarioConVerbos::~DiccionarioConVerbos() {
}


Palabra* DiccionarioConVerbos::buscarTermino( string termino, Usuario *usu ) {
    Palabra *pal;
    map<string,Palabra>::iterator it = terminos.find( termino );
    
    if( it != terminos.end()){
        pal = &(it->second);
        return pal;
    }else{
        return nullptr;
    }
    
}

void DiccionarioConVerbos::insertaInexistentes(string termino, Usuario *usu) {
    Palabra pal( termino, 1 );
    pal.setUsuario( usu );
    terminos[ termino ] = pal;
}

list<Usuario*> DiccionarioConVerbos::analizarTermino(string termino) {
    map<string, Palabra>::iterator it;
    it = terminos.find(termino);
    list<Usuario*> usuarios;
    Palabra *pal = &it->second;
    usuarios = pal->getUsuarios();
    
    return usuarios;
}












