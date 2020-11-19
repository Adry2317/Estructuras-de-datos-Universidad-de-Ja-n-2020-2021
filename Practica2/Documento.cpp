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

Documento::Documento():nombreFich("") {
}

Documento::Documento(string _nombreFich):nombreFich(_nombreFich){
    cargaDocumento(_nombreFich);
}

Documento::Documento(const Documento& orig) {
}

Documento::~Documento() {
}

void Documento::cargaDocumento(string _nombreFich) {
    string palabra;
    ifstream fe(_nombreFich);
    
    	while (fe) {
            string palabraLimpia = "";
		fe >> palabra;
                
                Palabra pal (palabra);
                this->documento.insertar(pal);
				
	}
}

void Documento::addInexistente(Palabra pal) {
    
    inexistentes.insertaOrdenado(pal);
}

Palabra& Documento::getPalabra(int pos) {

    return (this->documento[pos]);
}

int Documento::getTamDocumento() {
    return documento.tam();
}

ListaEnlazada<Palabra>& Documento::getLista() {

    return this->inexistentes;
}
