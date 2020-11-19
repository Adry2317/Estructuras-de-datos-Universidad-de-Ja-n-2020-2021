/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParPalabras.cpp
 * Author: Adrian
 * 
 * Created on 4 de octubre de 2020, 17:00
 */

#include <stdexcept>

#include "ParPalabras.h"
#include "Palabra.h"

/**
 * Constructor por defecto.
 * Se inicializan ambas palabras a un string vacío.
 */
ParPalabras::ParPalabras():pal1(""),pal2("") {
}


/**
 * COnstructor parametrizado.
 * @param palabra1
 * @param palabra2
 */
ParPalabras::ParPalabras(string palabra1, string palabra2){
    pal1 = palabra1;
    pal2 = palabra2;
}


/**
 * Constructor copia.
 * @param orig: Par de palabras del cual copiaremos los valores.
 */
ParPalabras::ParPalabras(const ParPalabras& orig) {
    pal1 = orig.pal1;
    pal2 = orig.pal2;
}

void ParPalabras::setPal1(string palabra1){
    this->pal1 = palabra1;
}

void ParPalabras::setPal2(string palabra2){
    this->pal2 = palabra2;
}
/**
 * Operador de asignación
 * @param parDePalabras: palabra que será asognmada
 * @return: la palabra con los nuevos valores asignados.
 */

    ParPalabras& ParPalabras::operator=(const ParPalabras &parDePalabras){
    if(this != &parDePalabras){
        pal1 = parDePalabras.pal1;
        pal2 = parDePalabras.pal2;
        
        return *this;
    }else{
        throw std::invalid_argument("Ambos pared de palabras ya son iguales");
    }
    
}
    
    
 
    
string ParPalabras::getPal1(){
    return this->pal1;
}    

string ParPalabras::getPal2(){
    return this->pal2;
}

ParPalabras::~ParPalabras() {
}

