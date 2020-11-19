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



#include "Diccionario.h"

Diccionario::Diccionario():nombreFich("") {

}


Diccionario::Diccionario(string _nombreFich, string _Verbos):nombreFich(_nombreFich) {
    if(_nombreFich != "" && _Verbos != ""){
        cargaDiccionario(nombreFich);
        this->terminos.ordenar(); 
        
        try{
        this->verbos = VerbosConjugados(_Verbos); 
        }catch(invalid_argument &e){
            cerr<<e.what();
        }
        
    }else{
        throw invalid_argument("El nombre de los archivos está vacío");
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
         
         }catch(invalid_argument &e){
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

/**
 * Función para obtener una palabra del diccionario.
 * @param pos: posicioón donde se encuentra la palabra.
 * @return 
 */
Palabra& Diccionario::getPalabras(int pos) {
    return (this->terminos[pos]);
}

/**
 * Funciíon para saber si lapalabra se encuentra en el diccionario o en los verbos conjugados.
 * @param pal: palabra a buscar.
 * @return: devuelve true si se encuentra en al menos uno de ellos, sino false.
 */
bool Diccionario::buscar(Palabra pal) {
    
    if(buscarBinaria(pal) == true && verbos.buscar(pal) == true)
        return true;
    
    else if(buscarBinaria(pal) == true && verbos.buscar(pal)== false)
        return true;
    
else if(buscarBinaria(pal) == false && verbos.buscar(pal) == true)
        return true;
    
    else
        return false;
     
    
   
}

int Diccionario::alturaverbosConjugados() {
    return verbos.alturaAVLverbosConjugados();
}


clock_t Diccionario::getTiemposVector() {
    return terminos.getTiempoBusqueda();
}

clock_t Diccionario::getTiemposAVL() {
    return this->verbos.getTiemposVector();
}
