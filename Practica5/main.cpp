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
#include <vector>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   
    string documento = "quijote.txt";
    string diccionario = "dicc-espanol.txt";
    string diccVerbos = "verbos_conjugados_desordenados.txt";
    

    
    GestorTextos gestor (documento, diccionario, diccVerbos, 0.71, 607462);
    
    string termino = "wifi";
    Palabra palInsert(termino, 0);
    
    unsigned int colAntes = gestor.colisiones();
    
   if(gestor.insertarTabla(palInsert)){
       cout<<"La palabra se ha insertado correctamente"<<endl;
   } else {
       cout<<"La palabra no se ha podido insertar"<<endl;
   }
    
    cout<<"El número de colisiones al insertar la palabra es: "<<gestor.colisiones() - colAntes<<endl;
    
    
    
    
    /****************************Añadir palabras con W a un vector*****************************/
    vector<Palabra> palabrasW;
    string palabras_empiezanConW = "Letras_empiezan_con_W.txt";
    
    string palabra;
    ifstream fe(palabras_empiezanConW);
    
    while(fe){
        fe >> palabra;
        Palabra aux (palabra, 0);
        string palabraLimpia = aux.limpiar( aux );
        Palabra palLimpia( palabraLimpia, 0 );
        palabrasW.push_back( palLimpia );
    }
    /******************************************************************************************/
    
    
    for (int i = 0; i < palabrasW.size(); i++){
         
       
        Palabra borraPalabra = palabrasW[i];
        string termino = borraPalabra.getPalabra();
       if(gestor.borraPalabra( termino )){
           cout <<"Palabra "<<palabrasW[i].getPalabra()<<" eliminada."<<endl;
       }
        
    }
    
   string waterpolo = "waterpolo";
   Palabra Pal1(waterpolo,0);
   string windsurf = "windsurf";
   Palabra Pal2 (windsurf, 0);
   
   if(gestor.insertarTabla(Pal1) && gestor.insertarTabla(Pal2)){
       cout<<"Palabra "<<waterpolo<<" insertada correctamente"<<endl;
       cout<<"Palabra "<<windsurf<<" insertada correctamente"<<endl;
       
   }else{
       cout<<"Error al insertar las palabras";
   }
   
    
   return 0;
}

