/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   THashPalabra.h
 * Author: Adrian
 *
 * Created on 1 de diciembre de 2020, 11:38
 */

#ifndef THASHPALABRA_H
#define THASHPALABRA_H
#include "Palabra.h"
#include <cmath>
#include <vector>
using namespace std;
enum estado{
    vacio,
    ocupado,
    disponible
          
};

struct casilla{
    Palabra pal;
    string clave;
    
    estado estadoTabla;
    
    casilla ( Palabra _pal, string _clave ): pal( _pal ), clave( _clave ), estadoTabla(vacio){}
    casilla ( ): estadoTabla( vacio ){}
    
    
};


class THashPalabra {
private:
    vector <casilla> vectHash;
    unsigned long hash( unsigned long clave, int intento );
    float factorCarga;
    
    unsigned int slotVacios;
    unsigned int slotDisponibles = 0;
    unsigned int slotOcupados = 0;
    unsigned int maxColisiones = 0;
    unsigned int colisiones = 0;
    unsigned int tamTabla;
public:
    THashPalabra();
    THashPalabra(float _factorCarga, unsigned tamDatos);
    THashPalabra(const THashPalabra& orig);
    THashPalabra& operator=( const THashPalabra &Thash);
    unsigned long djb2 ( string str );
    bool insertar ( unsigned long clave, Palabra &pal);
    bool buscar( unsigned long clave, string &termino, Palabra *&pal);
    bool borrar ( unsigned long clave, string &termino );
    unsigned int numPalabras();
    unsigned int maximoColisiones();
    float promedioColisiones();
    unsigned int tamañoTabla();
    float _factorCarga();
    unsigned int _colisiones();
    
    virtual ~THashPalabra();


};

#endif /* THASHPALABRA_H */

