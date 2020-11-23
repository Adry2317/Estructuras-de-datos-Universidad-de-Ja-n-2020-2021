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
#include "GestorTextos.h"
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    string documento = "quijote.txt";
    string diccionario = "dicc-espanol.txt";
    string diccVerbos = "verbos_conjugados_desordenados.txt";
    string documento2 = "tiaTula.txt";
    
    try{
    GestorTextos gestor(documento, diccionario, diccVerbos);
    cout<<"El tamaño antes de insertar palabras existentes es: "<<gestor.tamDiccionario()<<endl;

    Documento *doc1 = gestor.buscarDocumento(documento);
    doc1->chequearTexto();
    cout<<"El tamaño después de insertar palabras existentes es: "<<gestor.tamDiccionario()<<endl;
   
    gestor.addDocumento(documento2);
    Documento *doc2 = gestor.buscarDocumento(documento2);
    doc2->chequearTexto();
    cout<<"El tamaño después de chequear el segudno documento: "<<gestor.tamDiccionario()<<endl;
   
   
    //Muestra familia flor
    string flor = "flor";
    list<Palabra> famFlor = gestor.buscarFamilias(flor);

    list<Palabra>::iterator it = famFlor.begin();
    while(it != famFlor.end()){
        cout<<it->getPalabra()<<endl;
        it.operator ++();
    }


    //Muestra familia sal
    string sal = "sal";
    list<Palabra> famSal = gestor.buscarFamilias(sal);

    list<Palabra>::iterator it2 = famSal.begin();
    while(it2 != famSal.end()){
        cout<<it2->getPalabra()<<endl;
        it2.operator ++();
    }


    //Muestra Familia mar
    string mar = "mar";
    list<Palabra> famMar = gestor.buscarFamilias(mar);

    list<Palabra>::iterator it3 = famMar.begin();
    while(it3 != famMar.end()){
        cout<<it3->getPalabra()<<endl;
        it3.operator ++();
    }

    string aux = "mancha";
    Palabra *pal1;
    pal1= gestor.buscarTermino(aux);
    string aux2 = "estaban";
    Palabra *pal2 = gestor.buscarTermino(aux2);
    
    cout <<"La ocncurrencia de la palabra mancha es:" << pal1->getOcurrencias()<<endl;
    cout <<"La concurrencia de la palbra estaban es: " << pal2->getOcurrencias()<<endl;
   
   
    gestor.mostrarPalabrasAsociadaDocumento();
    }catch(std::invalid_argument &e){
        cerr<<e.what();
    }
   return 0;
}

