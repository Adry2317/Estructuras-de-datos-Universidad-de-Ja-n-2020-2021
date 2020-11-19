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
#include "DiccionarioConVerbos.h"
#include "Documento.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    string documento = "quijote.txt";
    string diccionario = "dicc-espanol.txt";
    string diccVerbos = "verbos_conjugados_desordenados";
    
    
    DiccionarioConVerbos dicc (diccionario, diccVerbos);
    Documento doc(documento, &dicc);
    
    cout<<"Antes "<<dicc.tamMapa()<<endl;
    
    doc.chequearTexto();
    
    cout<<"Ahora "<<dicc.tamMapa()<<endl;
            
  //  string aux = "ssss";
//    dicc.buscarTermino(aux);
    string mancha = "mancha";
    Palabra *pal = dicc.buscarTermino(mancha);
    
    cout<<pal->getOcurrencias();
    
    return 0;
}

