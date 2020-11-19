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
#include"VDinamico.h"
#include <exception>
#include "ParPalabras.h"
#include "Palabra.h"
#include<string>

using namespace std;



 void comprobar() {
     vector<string> dicc;

	ifstream is("dicc-espanol.txt");
	string palabra;

	while (is) {
		is >> palabra;
                
		dicc.push_back(palabra);
	}
	cout << dicc.size() << " palabras cargadas" << endl;

	is.close();
	is.open("quijote.txt");

	clock_t t_ini = clock();

	int validadas = 0, total = 0, p;
	while (is) {
		is >> palabra;
		++total;

		if (binary_search(dicc.begin(), dicc.end(), palabra)) {
			++validadas;
		}
	}
	cout <<"Total palabras: " << total << " validadas: " << validadas << endl;
	cout << "Tiempo implementación 1: " << ((clock() - t_ini) / CLOCKS_PER_SEC) << " segs." << endl;
}

    
 void cargaDatos(VDinamico<Palabra> &v){
     clock_t t_ini = clock();
     ifstream is("dicc-espanol.txt");
     string palabra;
     
     while(is) {
         is >> palabra;
         
         Palabra pal(palabra);
         try{
             
         v.insertar(pal);
         
         }catch(std::invalid_argument &e){
             cerr<<e.what();
         }
     }
     cout << "Palabras del diccionario cargadas"<<endl;
    cout << "Tiempo carga palabras en el vector: " << ((clock() - t_ini) / CLOCKS_PER_SEC) << " segs." << endl;
 }


int main(int argc, char** argv) {
   
    VDinamico<Palabra> vectDicc;
    VDinamico<ParPalabras> palindormo;
    VDinamico<ParPalabras> anagramas;
    cargaDatos(vectDicc);
     
    comprobar();
   
    
     
    /************************ordenar alfabéticamente el vector******************/
    clock_t t_ini3 = clock();
    vectDicc.ordenar();
    cout << "Tiempo ordenar vector al alfabéticamente: " << ((clock() - t_ini3) / CLOCKS_PER_SEC) << " segs." << endl;
    /***************************************************************************/
    
    
    
    /*******************Ordenar vector del revés**************************************/
    clock_t t_ini = clock();
    vectDicc.ordenaRev();
    
    try{
        for (int i = 0; i < vectDicc.tam();i++){
            cout<<vectDicc[i].getPalabra()<<endl;
        }
    }catch(std::out_of_range &e){
        cerr<<e.what();
    }
    
    cout << "Tiempo ordenar y mostar vector al revés: " << ((clock() - t_ini) / CLOCKS_PER_SEC) << " segs." << endl;
    /******************************************************************************/
    
    
    
    
    /**********************Busquedas de todos los palíndromos del diccionario*********************/
   
    try{
        
        clock_t t_ini4 = clock();
        int cont2 = 0;
        int cantidadPalindromos = 100;
        for(int i = 0; i < vectDicc.tam(); i++ ){
            Palabra alReves = vectDicc[i].reves();
            
            for(int j = 0; j < vectDicc.tam(); j++){

                if(j!=i){
                    if(alReves.palindromo(alReves, vectDicc[j])){
                        ParPalabras palindro(vectDicc[i].getPalabra(), vectDicc[j].getPalabra());
                        palindormo.insertar(palindro);
                        cont2++;
                    }
                    
                    if(cont2 == cantidadPalindromos){
                        j = vectDicc.tam();
                        i = vectDicc.tam();
                    }
                      
                }
            }
        }

        for (int i = 0; i < palindormo.tam(); i++){
            cout<<"Palindromo 1: "<<palindormo[i].getPal1()<<" Palíndormo 2: "<<palindormo[i].getPal2()<<endl;
        }

        cout<<"Número de palíndromos: "<<palindormo.tam()<<endl;

        cout << "Tiempo en buscar y mostrar los palindromos: " << ((clock() - t_ini4) / CLOCKS_PER_SEC) << " segs." << endl;
    }catch(std::out_of_range &e){
        cerr<<e.what();
    }
    
    
    /*************************Busqueda de Anagramas****************/
    cout<<endl;
    try{
        int anagrmasBuscar = 20;
        int cont = 0;
        clock_t t_ini2 = clock();
        
            for (int i = 0; i < vectDicc.tam(); i++){
                for (int j = 0; j < vectDicc.tam(); j++){
                    if( i != j){
                        if(vectDicc[i].anagramaEficiente(vectDicc[i],vectDicc[j])){
                            ParPalabras parAnagrama(vectDicc[i].getPalabra(),vectDicc[j].getPalabra());
                            anagramas.insertar(parAnagrama);
                            cont++;
                            if(cont == anagrmasBuscar){
                            j = vectDicc.tam();
                            i = vectDicc.tam();
                            }
                        }
                    }

                }
            }


        

        for(int i = 0; i < anagramas.tam(); i++){
            cout<<"Palabra 1: "<<anagramas[i].getPal1()<<", Palabra 2: "<<anagramas[i].getPal2()<<endl;

        }
        cout<<endl;
        cout << "Tiempo en buscar y mostrar "<<anagrmasBuscar<< " anagramas : " << ((clock() - t_ini2) / CLOCKS_PER_SEC) << " segs." << endl;

        /***************************************************************************/
    }catch(std::out_of_range &e){
        cerr<<e.what();
    }
    
    return 0;
    
}


