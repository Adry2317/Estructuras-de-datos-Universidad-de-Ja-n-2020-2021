/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Documento.cpp
 * Author: Adrian
 * 
 * Created on 19 de octubre de 2020, 16:25
 */

#include <fstream>

#include "Documento.h"

/**
 * COnstructor por defecto de la clase Documento.
 */
Documento::Documento():nombreFich("") {
}

/**
 * COnstructor parametrizado de la clase documento.
 * @param _nombreFich: nombre del fichero.
 * @param _dicc1: puntero al diccionario.
 */
Documento::Documento(string _nombreFich, Diccionario *_dicc1 ):nombreFich(_nombreFich),dicc1(_dicc1){
    if(_nombreFich != ""){
        string palabra;
        ifstream fe(nombreFich);

            while (fe) {
                string palabraLimpia = "";
                    fe >> palabra;

                    Palabra pal (palabra);
                    this->palabrasDocumento.push_back(pal);

            }
    }else{
        throw invalid_argument("EL nombre del archivo está en blanco.");
    }
}

/**
 * Constructor copia de la calse documento.
 * @param orig: documento desde el cual vamos a copiar los datos.
 */
Documento::Documento(const Documento& orig) {
    this->dicc1 = orig.dicc1;
    this->inexistentes = orig.inexistentes;
    this->nombreFich = orig.nombreFich;
    this->palabrasDocumento = orig.palabrasDocumento;
}


/**
 * Destructor de la clase documento.
 */
Documento::~Documento() {
}



/**
 * Añade las palabras inexistentes a una lista de forma ordenada y sin repetir
 * @param pal: palabra a insertar.
 */
void Documento::addInexistente(Palabra pal) {
    
    inexistentes.insertaOrdenado(pal);
}

/**
 * Función para obtener una palabra del documento
 * @param pos: posición donde se encuentra la palabra
 * @return: devuelve la palabra
 */
Palabra& Documento::getPalabra(int pos) {

    return (this->palabrasDocumento[pos]);
}


/**
 * Función para conocer el tamaño del vector de palabras del documento.
 * @return: cantidad de palabras del documento.
 */
int Documento::getTamDocumento() {
    return palabrasDocumento.size();
}

void Documento::chequearTexto() {
    for(int i = 0; i < palabrasDocumento.size(); i++){
        Palabra pal = palabrasDocumento[i];
        string palLimpia = pal.limpiar(pal);
        Palabra palabraLimpia(palLimpia);
        
        if(dicc1->buscar(palabraLimpia) == false){
            inexistentes.push_back(palabraLimpia);
        }
    }
}

int Documento::getTamInexistente() {
    //return inexistentes.;
}

/*
void Documento::eliminarPropios() {
    Iterador<Palabra> it2 = inexistentes.iterador();
    
    while(it2.haySiguiente()){
            string palabra = it2.dato().getPalabra();
            if(palabra[0] == toupper(palabra[0])){
                string palabra2 = palabra;
                palabra2[0] = tolower(palabra[0]);
                Palabra pal(palabra2);
                if(dicc1->buscar(pal) == true)
                    inexistentes.borrar(it2);
            }
        it2.siguiente();
        
        }
}
*/
Diccionario* Documento::getDiccionario() {
    return this->dicc1;
}

