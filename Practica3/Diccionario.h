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
#include "VerbosConjugados.h"
#include <stdexcept>
#include <fstream>
#include<ctime>
using namespace std;




class Diccionario {
private:
    string nombreFich;
    VDinamico<Palabra> terminos;
    VerbosConjugados verbos;
    
public:
    Diccionario();
    Diccionario(string _nombreFich, string _Vverboserbos);
    Diccionario(const Diccionario& orig);
    void cargaDiccionario(string nombreFich);
    virtual ~Diccionario();

    string getNombreFich();
    int getTamDicc();
    bool buscarBinaria(Palabra pal);
    Palabra& getPalabras (int pos);    
    bool buscar (Palabra pal);
    int alturaverbosConjugados();
    clock_t getTiemposVector();
    clock_t getTiemposAVL();
};

#endif /* DICCIONARIO_H */

