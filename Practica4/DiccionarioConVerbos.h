/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DiccionarioConVerbos.h
 * Author: Adrian
 *
 * Created on 15 de noviembre de 2020, 14:02
 */

#ifndef DICCIONARIOCONVERBOS_H
#define DICCIONARIOCONVERBOS_H
#include <string>
#include <map>
#include "Palabra.h"
#include <fstream>
#include <list>
using namespace std;
class DiccionarioConVerbos {
private:
    string nombreDicc;
    string nombreDiccVerbos;
    map<string,Palabra> palabras;
public:
    DiccionarioConVerbos();
    DiccionarioConVerbos(string _nombreDicc, string _nombreDiccVerbos);
    DiccionarioConVerbos(const DiccionarioConVerbos& orig);
    Palabra* buscarTermino(string termino);
    void inseraInexistente( Palabra pal );
    list<Palabra> buscarFamilias( string raiz );
    unsigned int tamMapa();
    virtual ~DiccionarioConVerbos();


};

#endif /* DICCIONARIOCONVERBOS_H */

