/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DiccionarioConVerbos.h
 * Author: Adrian
 *
 * Created on 15 de noviembre de 2020, 14:02
 */

#ifndef DICCIONARIOCONVERBOS_H
#define DICCIONARIOCONVERBOS_H
#include <string>
#include <map>
#include "Palabra.h"
#include <fstream>
#include "Documento.h"
#include "THashPalabra.h"

using namespace std;

class DiccionarioConVerbos {
private:
    string nombreDicc;
    string nombreDiccVerbos;
    THashPalabra terminos;
public:
    DiccionarioConVerbos();
    DiccionarioConVerbos(string _nombreDicc, string _nombreDiccVerbos, float carga, unsigned tamDatos);
    DiccionarioConVerbos(const DiccionarioConVerbos& orig);
    DiccionarioConVerbos& operator=(const DiccionarioConVerbos &dicc);
    Palabra* buscarTermino(unsigned long clave, string termino);
    unsigned int MAxColisiones();
    float promedioCol();
    unsigned int tamTabla();
    float factCarga();
    bool insertaTabla(Palabra &pal);
    unsigned int colisiones();
    void palEnDocumento();
    virtual ~DiccionarioConVerbos();
    void borrarPalInicioDado( char letra);

};

#endif /* DICCIONARIOCONVERBOS_H */

