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
#include "Palabra.h"
#include "VDinamico.h"
using namespace std;

class Documento {
private:
    string nombreFich;
    ListaEnlazada<Palabra> inexistentes;
    VDinamico<Palabra> documento;
public:
    Documento();
    Documento( string _nombreFich);
    Documento(const Documento& orig);
    virtual ~Documento();
    
    void cargaDocumento(string _nombreFich);
    void addInexistente(Palabra pal);
    Palabra& getPalabra(int pos);
    int getTamDocumento();
    
    ListaEnlazada<Palabra>& getLista();

};

#endif /* DOCUMENTO_H */

