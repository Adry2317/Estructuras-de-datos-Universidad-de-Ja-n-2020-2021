/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Documento.h
 * Author: Adrian
 *
 * Created on 19 de octubre de 2020, 16:25
 */

#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include <string>
#include "ListaEnlazada.h"
#include "Diccionario.h"
#include <vector>
#include <list>
using namespace std;

class Documento {
private:
    string nombreFich;
    //ListaEnlazada<Palabra> inexistentes;
    list<Palabra> inexistentes;
    //VDinamico<Palabra> palabrasDocumento;
    vector<Palabra> palabrasDocumento;
   // Diccionario *dicc1;
public:
    Documento();
    Documento( string _nombreFich, Diccionario *_dicc1 );
    Documento(const Documento& orig);
    virtual ~Documento();
    
    void chequearTexto();
    void addInexistente(Palabra pal);
    Palabra& getPalabra(int pos);
    int getTamDocumento();
    int getTamInexistente();
    void eliminarPropios();
    Diccionario* getDiccionario();
        
    
};

#endif /* DOCUMENTO_H */

