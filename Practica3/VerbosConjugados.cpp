/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VerbosConjugados.cpp
 * Author: Adrian
 * 
 * Created on 3 de noviembre de 2020, 23:12
 */

#include "VerbosConjugados.h"

/**
 * COnstructor por defecto de la clase verbosConjugados
 */
VerbosConjugados::VerbosConjugados():nombreArchivo("") {
}

/**
 * COnstructor parametrizado de la clase VerbosConjugados
 * @param _nombreArchivo: nombre del archivo el cual va a ser almacenado en un AVL;
 */
VerbosConjugados::VerbosConjugados(string _nombreArchivo):nombreArchivo(_nombreArchivo){
    if(_nombreArchivo == ""){
        throw invalid_argument("El nombre del archivo está vacío");
    }else{
        string palabra;
        ifstream fe(nombreArchivo);
    
    	while (fe) {
            string palabraLimpia = "";
		fe >> palabra;
                
                Palabra pal (palabra);
                this->vConjugados.insertar(pal);
				
	}
    }
    
}


/**
 * Constructor copia de la calse verbosConjugados
 * @param orig:Objeto el cual vamos a copiar.
 */
VerbosConjugados::VerbosConjugados(const VerbosConjugados& orig) {
    this->nombreArchivo = orig.nombreArchivo;
    this->vConjugados = orig.vConjugados;
}



/**
 * Función encargada de buscar una palbra dentro de los verbos conjugados.
 * @param pal: Palabra a buscar.
 * @return: devuelve true, si la palabra se encuentra  y false si no se encuentra.
 */
bool VerbosConjugados::buscar(Palabra pal) {
    Palabra resultado;
     return (vConjugados.buscaRrecursiva(pal, resultado));
     
}
int VerbosConjugados::alturaAVLverbosConjugados() {
    int altura;
    vConjugados.altura(altura);
  return altura;
   
}

clock_t VerbosConjugados::getTiemposVector() {
    return this->vConjugados.getTiempoBuqueda();
}


/**
 * Destructo de la calse Verbos conjugados.
 */
VerbosConjugados::~VerbosConjugados() {
}

