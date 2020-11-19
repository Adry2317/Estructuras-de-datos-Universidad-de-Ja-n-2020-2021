/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Adrian
 *
 * Created on 29 de septiembre de 2020, 19:55
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <exception>
#include <unordered_map>
#include "GestorTextos.h"
#include "AVL.h"
#include <ctime>

using namespace std;






int main(int argc, char** argv) {
  
    string documento, diccionario, verbos;
    documento = "quijote.txt";
    diccionario = "dicc-espanol.txt";
    verbos = "verbos_conjugados_desordenados.txt";
    
    GestorTextos gestor(documento, diccionario, verbos);
    
    clock_t t_init;
    
    t_init = clock();
    
    unsigned int alturaArbol = gestor.auxiliarAlturaAVLVerbos();  
   
    cout<<"Tiempo en calcular la altura del arbol: "<<((clock() - t_init)/CLOCKS_PER_SEC)<<" segs."<<endl;
    
     cout<<"Altura del árbol AVL: "<<alturaArbol<<endl;
     
     Documento quijote = gestor.getDocumento(1);
     Diccionario *dicc = quijote.getDiccionario();
     quijote.chequearTexto();
    
     float tiempoVector = dicc->getTiemposVector();
     float tiempoAVL = dicc->getTiemposAVL();
     
     int tamInexistentes = quijote.getTamInexistente();
     cout<<"Tamaño de la lista de inexsitentes: "<<tamInexistentes<<endl;
     
     
     quijote.eliminarPropios();
     int tamInexistentes2 = quijote.getTamInexistente();
     cout<<"Tamaño de la lista de inexsitentes: "<<tamInexistentes2<<endl;
     
     cout<<"El tiempo de busqueda del vector es: "<< tiempoVector/CLOCKS_PER_SEC<<endl;
     cout<<"El tiempo de busqueda del AVL es: "<< tiempoAVL/CLOCKS_PER_SEC;
    return 0;
    
}
