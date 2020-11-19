/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.h
 * Author: Adrian
 *
 * Created on 17 de octubre de 2020, 16:07
 */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <string>
#include "VDinamico.h"
#include "Palabra.h"
using namespace std;




class Diccionario {
private:
    string nombreFich;
    VDinamico<Palabra> terminos;
public:
    Diccionario();
    Diccionario(string _nombreFich);
    Diccionario(const Diccionario& orig);
    void cargaDiccionario(string nombreFich);
    virtual ~Diccionario();

    string getNombreFich();
    int getTamDicc();
    bool buscarBinaria(Palabra pal);
    Palabra& getPalabras (int pos);    
     
    
};

#endif /* DICCIONARIO_H */

