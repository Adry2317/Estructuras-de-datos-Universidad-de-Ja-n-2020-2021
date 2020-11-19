/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParPalabras.h
 * Author: Adrian
 *
 * Created on 4 de octubre de 2020, 17:00
 */

#ifndef PARPALABRAS_H
#define PARPALABRAS_H
#include <string>
using namespace std;

class ParPalabras {
private:

    string pal1;    
    string pal2;
    
public:
    ParPalabras();
    ParPalabras(string palabra1, string palabra2);
    ParPalabras(const ParPalabras& orig);
    ParPalabras& operator=(const ParPalabras &parDePalabras);
    string getPal1();
    string getPal2();
    void setPal1(string palabra1);
    void setPal2(string palabra2);
    virtual ~ParPalabras();


};

#endif /* PARPALABRAS_H */

