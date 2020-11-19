/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.h
 * Author: Adrian
 *
 * Created on 4 de octubre de 2020, 16:37
 */

#ifndef PALABRA_H
#define PALABRA_H
#include<string>
#include<algorithm>
#include<iostream>

#include "VDinamico.h"
using namespace std;

class Palabra {

private:
    string palabra;
    
public:
    Palabra();
    Palabra(string pal);
    Palabra(const Palabra& orig);
    
    string getPalabra();
    Palabra reves();
    bool operator<(const Palabra &palMenor);
    bool operator>(const Palabra &palMayor);
    Palabra& operator=(const Palabra &pal);
    bool palindromo(Palabra pal, Palabra pal2);
    bool anagramaEficiente(Palabra pal, Palabra pal2);
   
    void getCombinaciones(Palabra pal, int level,VDinamico<Palabra>& v);
    
    
    virtual ~Palabra();


};

#endif /* PALABRA_H */

