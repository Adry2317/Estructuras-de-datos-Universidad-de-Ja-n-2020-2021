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

Documento::Documento(string _nombreFich, DiccionarioConVerbos *_dicc1 ):nombreFich(_nombreFich),dicc1(_dicc1){
   
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



void Documento::chequearTexto() {
    if(nombreFich != ""){
        
        string palabra;
        ifstream fe(nombreFich);
        
        while(fe){
            fe >> palabra;
            Palabra aux (palabra, nullptr, 0, nullptr);
            string palabraLimpia = aux.limpiar(aux);
            
            
            for_each(palabraLimpia.begin(), palabraLimpia.end(), [](char & c){
                c = ::tolower(c);
            });
            Palabra *aux2 = dicc1->buscarTermino(palabraLimpia);
            
            if( aux2 == 0 ){
                Palabra palInsert(palabraLimpia, dicc1, 0,this);
                dicc1->inseraInexistente(palInsert);
                
            }else{
                aux2->incrementaOcurrencia();
                //cout<<"stop";
            }
            
        }
        
        
        
        
    }else{
        throw invalid_argument("El nombre del documento está en blanco");
    }
   
}






