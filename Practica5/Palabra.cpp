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
#include <cstring>
#include "DiccionarioConVerbos.h"
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
Palabra::Palabra(string pal, int _ocurrencias){
    palabra = pal;
    ocurrencia = _ocurrencias;
    
}


/**
 * Constructor copia 
 * @param orig: palabra de la cual copiaremos los datos.
 */
Palabra::Palabra(const Palabra& orig) {
    palabra = orig.palabra;
    ocurrencia = orig.ocurrencia;
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
        ocurrencia = pal.ocurrencia;
        
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


/**
 * Sobrecarga del operador ==
 * @param palIgual: palabra la cual vamos a comparar
 * @return: si son iguales devuelve true, sino devuelve false;
 */
bool Palabra::operator==(const Palabra& palIgual) {
    if(palIgual.palabra == palabra){
        return true;
    }else{
        return false;
    }
}

/**
 * Función que sobrecarga el operador !=, para comparar si dos palabras son distintas.
 * @param pal: palabra a comparar.
 * @return: devuelve true si son distintas y false si no lo son.
 */
bool Palabra::operator!=(const Palabra& pal) {
    if(this->palabra != pal.palabra){
        return true;
    }else{
        return false;
    }
    
}


/*
 * Sobrecarga del operador<<, para poder mostrar la palabra a través del AVL.
 */
ostream& operator<<(ostream& out, Palabra pal) {
    out << pal.palabra;
}




/**
 * Función encargada de buscar un anagrama a partir de una palabra;
 * @param pal: palabra 1
 * @param pal2: palabra 2
 * @return: si son anagramas devuelve true, sino false
 */
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
 * Función encargada de poner la palabra del revés
 * @return: devuelve la palabra al revés 
 */
Palabra Palabra::reves(){
    string alReves = palabra;
   
    
    int aux = palabra.length();
    for(int i = 0; i < aux/2; i++){
        swap(alReves[i], alReves[aux -i -1]);
    }
    
    Palabra palReves(alReves, 0);
    return palReves;
    
}

/**
 * Función encargada de limpiar una palabra de caracteres especiales
 * @param palabra
 * @return 
 */
string Palabra::limpiar(Palabra palabra) {
    string palabraLimpia = palabra.getPalabra();
    
    char caract[] = ("¿" "?" "-" "_" "." "," ";" "'" "(" ")" "1" "2" "3" "4" "5" "6" "7" "8" "9" "!" "¡" "0" "\"" "*" );
                    
    for (int i = 0; i < strlen(caract); i++){
        palabraLimpia.erase(std::remove(palabraLimpia.begin(), palabraLimpia.end(), caract[i]),palabraLimpia.end());
    }
    return palabraLimpia;
}

/**
 * Función que incrementa la ocurrencia de la palabra
 */
void Palabra::incrementaOcurrencia() {
     ocurrencia++;
}

int Palabra::getOcurrencias() {
    return ocurrencia;
}






Palabra:: ~Palabra(){
}

