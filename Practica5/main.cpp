/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Adrian
 *
 * Created on 15 de noviembre de 2020, 13:52
 */

#include <cstdlib>

#include "Documento.h"
#include "GestorTextos.h"
#include <string>
#include "THashPalabra.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   
    string documento = "quijote.txt";
    string diccionario = "dicc-espanol.txt";
    string diccVerbos = "verbos_conjugados_desordenados.txt";
    
    /**********************Código utilizado para el entrenamiento************************/
//    DiccionarioConVerbos dicc (diccionario, diccVerbos, 0.83, 607462 );
//    
//    cout<<"Promedio de colisiones: "<<dicc.promedioCol()<<endl;
//    cout<<"Max Colisiones: "<<dicc.MAxColisiones()<<endl;
//    cout<<"Factor Carga: "<<dicc.factCarga()<<endl;
//    cout<<"El tamaño de la tabla de es: "<<dicc.tamTabla();
    
    
    GestorTextos gestor (documento, diccionario, diccVerbos, 0.71, 607462);
    string termino = "wifi";
    Palabra palInsert(termino, 0);
    
    unsigned int colAntes = gestor.colisiones();
    
    gestor.insertarTabla(palInsert);
    
    cout<<"El número de colisiones al insertar la palabra es: "<<gestor.colisiones() - colAntes<<endl;
    
   return 0;
}

