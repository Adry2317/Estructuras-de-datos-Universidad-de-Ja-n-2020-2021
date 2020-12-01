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
#include <string.h>

#include "Documento.h"
#include "DiccionarioConVerbos.h"
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

Documento::Documento(string _nombreFich, DiccionarioConVerbos *_dicc1 ):
nombreFich(_nombreFich),dicc1(_dicc1){
   
}

/**
 * Constructor copia de la calse documento.
 * @param orig: documento desde el cual vamos a copiar los datos.
 */
Documento::Documento(const Documento& orig) {
    nombreFich = orig.nombreFich;
    dicc1 = orig.dicc1;
   
    
}


/**
 * Destructor de la clase documento.
 */
Documento::~Documento() {
}

/**
 * Sobre Carga del operador de asignacion
 * @param doc: documento del cual vamos a asignar los valores
 * @return: devuelve el documento con los valores del que le hemos pasado
 */
Documento& Documento::operator=(const Documento& doc) {
    if (this != &doc){
        dicc1 = doc.dicc1;
        nombreFich = doc.nombreFich;
    }else{
        throw std::invalid_argument("Los documentos son iguales");
    }
    return *this;
}


/**
 * Función encargada de chequear el documento, si la palabra no existe en el diccionario
 * se inserta en el mapa, si existe se incrementa la ocurrencia
 */
void Documento::chequearTexto() {
    if(nombreFich != ""){
        
        string palabra;
        ifstream fe(nombreFich);
        
        while(fe){
            fe >> palabra;
            Palabra aux (palabra, nullptr, 0);
            string palabraLimpia = aux.limpiar(aux);
            
            for_each(palabraLimpia.begin(), palabraLimpia.end(), [](char & c){
                c = ::tolower(c);
            });
            
            Palabra *aux2 = dicc1->buscarTermino(palabraLimpia);
            
            if( aux2 == nullptr ){
                Palabra palInsert(palabraLimpia, nullptr, 0);
                dicc1->inseraInexistente(palInsert, this);
                
            }else{
                aux2->incrementaOcurrencia();
                if(aux.getDocumento() != this){
                  aux2->setDocumento(this);  
                }
                
            }
            
        }
        
        
        
        
    }else{
        throw invalid_argument("El nombre del documento está en blanco");
    }
   
    
    
}

string Documento::getNombreFich() {
    return nombreFich;
}





