/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ziri.cpp
 * Author: Adrian
 * 
 * Created on 31 de diciembre de 2020, 0:57
 */

#include <fstream>
#include <unordered_map>

#include "Ziri.h"
#include "Palabra.h"

Ziri::Ziri() {
    float axMin = 500, ayMin = 500, axMax = -500, ayMax = -500;
    cargaUsuarios( "usuarios_frases_win.csv",axMin, ayMin, axMax, ayMax );
    usuarioUTM = MallaRegular<Usuario*>(axMin, ayMin, axMax+0.001, ayMax+0.001, 63,63);
    GestorTextos aux("dicc-espanol.txt", "verbos_conjugados_desordenados.txt" );
    gestor = aux;
    
    map<string,Usuario>::iterator it;
 
    
    for( it = usuariosNIF.begin(); it != usuariosNIF.end(); it++){
        Usuario *usu = &it->second;
        float longitud = (float)usu->getPosicion().longitud;
        float latitud = (float)usu->getPosicion().latitud;
        
        usuarioUTM.insertar(longitud, latitud, usu);    
    }
    
    
}

Ziri::Ziri(const Ziri& orig) {
    conectados = orig.conectados;
    gestor = orig.gestor;
    usuarioUTM = orig.usuarioUTM;
    usuariosNIF = orig.usuariosNIF;
}

Ziri& Ziri::operator=(const Ziri& orig) {
    if( this != &orig ){
        conectados = orig.conectados;
        gestor = orig.gestor;
        usuarioUTM = orig.usuarioUTM;
        usuariosNIF = orig.usuariosNIF;
    }
    return *this;
}


Ziri::~Ziri() {
}

void Ziri::cargaUsuarios(string nombreFich, float &axMin, float &ayMin, float &axMax, float &ayMax ) {
    ifstream fe; //flujo de entrada.
    string linea;
    int total = 0;
    int x = 1;
    //Variable para almacenar datos del fichero
    string nif, clave, nombre,direccion,latitud, longitud, frase;
    double dlat, dlong;
    
    //asocioamos el flujo al fichero
    fe.open( nombreFich );
    
    if ( fe.good() ){
        //mientras que no haya llegado al final del fichero
        while ( !fe.eof() ){
            getline(fe, linea);//Toma una linea del fichero
            stringstream ss; //Stream que trabaja sobre el buffer interno.
            
            if( linea != "" ){
                ++total;
            }
            
            if( total > 1 ){
                //inicializamos el contenido de ss;
                
                ss << linea;
                
                getline(ss,nif,';');
                getline(ss,clave,';');
                getline(ss,nombre,';');
                getline(ss,direccion,';');
                getline(ss,latitud,';');
                getline(ss,longitud,';');
                getline(ss,frase,'\r');
                Palabra pal (frase, 0);
                string fraseLimpia = pal.limpiar( pal );
                
                
                /************Cambiamos , por . en las latitudes y longitudes*******/
                string::size_type pos = latitud.find(",",0);
                 string::size_type pos2 = longitud.find(",",0);
                 
                if( pos < string::npos && pos2 < string::npos ){
                    latitud.replace(pos, string(",").length(), ".");
                    longitud.replace(pos2, string(",").length(), ".");
                }
                    
                
                /******************************************************************/
                dlat = stod(latitud);
                dlong = stod(longitud);
              
                
                
                Usuario usu(nif, clave, nombre, dlat, dlong, fraseLimpia, this);
                
                if(dlong < axMin ){
                    axMin = (float)dlong;
                }
                if( dlong > axMax){
                    axMax = (float)dlong;
                }
                
                if(dlat < ayMin){
                    ayMin = (float)dlat;
                }
                if(dlat > ayMax){
                    ayMax = (float)dlat;
                }
                
             
                usuariosNIF[nif] = usu;
                
            }
           
        }
        fe.close(); //cerramos el flujo de entrada.
        
    }
    
}

Usuario* Ziri::nuevoUsuarioConectado(string nif, string pass) {
    map<string, Usuario>::iterator it = usuariosNIF.find(nif);
    
    if( it->second.getClave() == pass){
        //comprobar puntero.
        conectados.push_back(&it->second);
        return &it->second;
    }
    return nullptr;
}

void Ziri::desconectarUsuario(string nif) {
    list<Usuario*>::iterator it;
    
    for ( it = conectados.begin(); it != conectados.end(); it++ ){
        Usuario *usu = it.operator *();
        if( usu->getNif() == nif ){
            conectados.erase(it);
        }
    }
}

void Ziri::recibeMensajeUsuario(string frase, Usuario* usu) {
    chequearTexto( frase, usu );
}


float Ziri::promedioUsuarios() {
    return usuarioUTM.promedioElementosPorCelda();
}

void Ziri::chequearTexto(string frase, Usuario* usu) {
    vector<string> palabras;
    
    //Separamos la frase por espacios en blanco, dejandola palabra a palabra
    char separador = ' ';
    for( size_t p=0, q=0; p != frase.npos; p=q)
        palabras.push_back(frase.substr(p+(p!=0),(q=frase.find(separador, p+1))-p-(p!=0)));
    
    for( int i = 0; i < palabras.size(); i++ ){
        
        Palabra *pal = gestor.buscarTermino( palabras[i], usu );
        
        if( pal == nullptr){
            gestor.insertaInexistentes( palabras[i], usu );
        }else{
            pal->incrementaOcurrencia();
            pal->setUsuario(usu);
        }
        
    }
}

list<Usuario*> Ziri::analizartermino( string palabra ) {
    return gestor.analizarTermino( palabra );
}

int Ziri::cantidadUsuarios() {
    return usuariosNIF.size();
}

int Ziri::usuariosConectados() {
    return conectados.size();
}



void Ziri::escribeMensajeConectados() {
    list<Usuario*>::iterator it;
    int i = 0;
    for(it = conectados.begin(); it != conectados.end(); it ++ ){
        Usuario *usu = it.operator *();
        usu->escribeMensaje();
        
        
    }
   
}

list<Usuario*> Ziri::buscarTerminoRango(string termino, float rxmin, float rymin, float rxMax, float rymax) {
    
    list<Usuario*> usuList;
    list<Usuario*> aux;
    list<Usuario*> ususFinal;
   
    aux =  usuarioUTM.buscarRango(rxmin, rymin, rxMax, rymax);
    
    list<Usuario*>::iterator it;
    list<Usuario*>::iterator it2;
    
    for( it = aux.begin(); it != aux.end(); it ++){
        
        Usuario *usu = it.operator *();
        Palabra *pal = gestor.buscarTermino(termino, usu);
        
        
        usuList = pal->getUsuarios();
        for(it2 = usuList.begin(); it2 != usuList.end(); it2++){
            Usuario *usu2 = it2.operator *();
            if(usu2->getNif() == usu->getNif()){
                ususFinal.push_back(usu);
                
            }
        }
    }
    
    return ususFinal;
   
}

int Ziri::OcurrenciaPal(string termino) {
    Palabra *pal;
   pal =  gestor.buscarTermino(termino, nullptr);
   return pal->getOcurrencias();
          
}
