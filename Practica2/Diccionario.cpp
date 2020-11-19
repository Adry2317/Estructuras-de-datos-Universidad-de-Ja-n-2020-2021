/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.cpp
 * Author: Adrian
 * 
 * Created on 17 de octubre de 2020, 16:07
 */

#include <fstream>

#include "Diccionario.h"

Diccionario::Diccionario():nombreFich("") {

}


Diccionario::Diccionario(string _nombreFich):nombreFich(_nombreFich) {
    if(_nombreFich == ""){
        throw std::invalid_argument("El nombre del archivo del diccionario no es correcto");
    }else{
       cargaDiccionario(nombreFich);
    this->terminos.ordenar(); 
    }
    
}

Diccionario::Diccionario(const Diccionario& orig) {
    this->nombreFich = orig.nombreFich;
    this->terminos = orig.terminos;
          
}

Diccionario::~Diccionario() {
}


void Diccionario::cargaDiccionario(string nombreFich) {

     
     ifstream fe(nombreFich);
     string palabra;
     
     while(fe){
         fe >> palabra;
         Palabra pal (palabra);
          try{
             
        this->terminos.insertar(pal);
         
         }catch(std::invalid_argument &e){
             cerr<<e.what();
         }
     }
     fe.close();
     
     
  
}
 


string Diccionario::getNombreFich() {
    return this->nombreFich;
}

int Diccionario::getTamDicc() {
    return this->terminos.tam();
}


/**
 * Función que busca una palabra dentro del diccionario en tiempo logaritmico
 * @param pal: palabra a buscar.
 * @return: si encuentra la palabra devuelve true, sino false.
 */
bool Diccionario::buscarBinaria(Palabra pal) {
    int aux;
  aux = terminos.busquedaBin(pal);
  
  if(aux != -1)
      return true;
  
  else
      return false;
}

Palabra& Diccionario::getPalabras(int pos) {
    return (this->terminos[pos]);
}
