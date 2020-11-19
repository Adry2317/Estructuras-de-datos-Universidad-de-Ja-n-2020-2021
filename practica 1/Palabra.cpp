/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.cpp
 * Author: Adrian
 * 
 * Created on 4 de octubre de 2020, 16:37
 */

#include <stdexcept>

#include "Palabra.h"

/**
 * Constructor por defecto que inicializa la palabra a "".
 */
Palabra::Palabra():palabra("") {
}


/**
 * Constructor parametrizado
 * @param pal.
 */
Palabra::Palabra(string pal){
    palabra = pal;
}


/**
 * Constructor copia 
 * @param orig: palabra de la cual copiaremos los datos.
 */
Palabra::Palabra(const Palabra& orig) {
    palabra = orig.palabra;
}


string Palabra::getPalabra(){
    return this->palabra;
}


/**
 * Operador de asignación
 * @param pal: palabra que será asignada
 * @return: devuelve una palabra.
 */
Palabra& Palabra::operator=(const Palabra &pal){
    if(this != &pal){
        palabra = pal.palabra;
        
        
    }else{
        throw std::invalid_argument("Las palabras ya son iguales");
    }
    return *this;
}


/**
 * Operador menor
 * @param palMenor: palabra con la que se comparará
 * @return: devuelve un booleano  
 */
bool Palabra::operator<(const Palabra &palMenor){
    return(this->palabra < palMenor.palabra);
}


/**
 * Operador mayor
 * @param palMenor: palabra con la que se comparará
 * @return: devuelve un booleano  
 */
bool Palabra::operator>(const Palabra &palMayor){
    return (this->palabra > palMayor.palabra);
}


bool Palabra::anagramaEficiente(Palabra pal, Palabra pal2){
   
    sort(pal2.palabra.begin(), pal2.palabra.end());
   sort(pal.palabra.begin(), pal.palabra.end());
    
    if(pal2.palabra == pal.palabra){
        return true;
    }
    return false;
} 


bool Palabra::palindromo(Palabra pal1, Palabra pal2){
    return(pal1.palabra == pal2.palabra);
}


/**
 * Función de generar todas las permutaciones de una palabra
 * @param pal: palabra de la cual obtendremos las permutaciones.
 * @param level: contador auxiliar, para la recursividad
 * @param v: vector donde se almacenaran las permutaciones de las palabras 
 */
void Palabra::getCombinaciones(Palabra pal, int level, VDinamico<Palabra>& v){
    
     if(level == pal.palabra.size()){
        v.insertar(pal);
    }
    for(int i = level; pal.palabra[i]; i++){
        swap(pal.palabra[level], pal.palabra[i]);
        getCombinaciones(pal.palabra, level +1, v);
        swap(pal.palabra[level], pal.palabra[i]);
    }
}






/**
 * Función encargada de poner la palabra del revés
 * @return: devuelve la palabra al revés 
 */
Palabra Palabra::reves(){
    string alReves = palabra;
   
    
    int aux = palabra.length();
    for(int i = 0; i < aux/2; i++){
        swap(alReves[i], alReves[aux -i -1]);
    }
    
    Palabra palReves(alReves);
    return palReves;
    
}

Palabra:: ~Palabra(){
}

