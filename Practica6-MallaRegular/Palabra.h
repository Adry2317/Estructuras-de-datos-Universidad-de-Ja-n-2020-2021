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
#include "Usuario.h"
#include <list>


using namespace std;
class DiccionarioConVerbos;
class Palabra {

private:
    string palabra;
    int ocurrencia;
    list<Usuario*> dichaPor;
   
public:
    Palabra();
   
    Palabra(string pal,int ocurrencia);
    Palabra(const Palabra& orig);
    
    string getPalabra();
    Palabra reves();
    bool operator<(const Palabra &palMenor);
    bool operator>(const Palabra &palMayor);
    Palabra& operator=(const Palabra &pal);
    bool operator!=(const Palabra &pal);
    bool operator==(const Palabra &palIgual);
    bool palindromo(Palabra pal, Palabra pal2);
    bool anagramaEficiente(Palabra pal, Palabra pal2);
    friend ostream& operator<< (ostream& out, Palabra pal);
    void incrementaOcurrencia();
    int getOcurrencias();
    string limpiar(Palabra palabra);
    void setUsuario( Usuario *usu);
    list<Usuario*> getUsuarios();
    
    
    
    virtual ~Palabra();


};

#endif /* PALABRA_H */

