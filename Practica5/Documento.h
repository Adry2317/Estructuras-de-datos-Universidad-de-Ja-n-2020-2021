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

#include <vector>
#include <list>

class Palabra;
using namespace std;
class DiccionarioConVerbos;
class Documento {
private:
    string nombreFich;
    list<Palabra> palabras;
    DiccionarioConVerbos *dicc1;
public:
    Documento();
    Documento( string _nombreFich, DiccionarioConVerbos *_dicc1 );
    Documento(const Documento& orig);
    Documento& operator=(const Documento &doc);
    virtual ~Documento();
    
    void chequearTexto();
    string getNombreFich();
  
        
    
};

#endif /* DOCUMENTO_H */


