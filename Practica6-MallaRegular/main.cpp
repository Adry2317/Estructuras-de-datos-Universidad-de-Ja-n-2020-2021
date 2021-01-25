/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Adrian
 *
 * Created on 26 de diciembre de 2020, 23:42
 */

#include <cstdlib>
#include "Ziri.h"
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    Ziri ziri;
    map<string, Usuario> usuarios;
    
    /*********************Lectura de usuarios*********************/
    ifstream fe;
    string linea;
    int total = 0;
    string _nif, pass, nombre,direccion,latitud, longitud, frase;
    double dlat, dlong;
    
    //asocioamos el flujo al fichero
    fe.open( "usuarios_frases_win.csv" );
    
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
                
                getline(ss,_nif,';');
                getline(ss,pass,';');
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
                
                
                Usuario usu(_nif, pass, nombre, dlat, dlong, fraseLimpia, &ziri);
                
                usuarios[_nif] = usu;
               
                
             
           
                
            }
           
        }
        fe.close(); //cerramos el flujo de entrada.
        
    }
    /*************************************************************/
    
    
    cout<<"El número de usuarios en la aplicación es de: "<<ziri.cantidadUsuarios()<<endl;
    
    /***********************inicio de sesión****************************/
    map<string,Usuario>::iterator it = usuarios.begin();
    int cont = usuarios.size()-50;
    int i = 0;
    for( it; it != usuarios.end(); it++){
        if ( i < cont ){
            Usuario *usu2 = &it->second;
            string nif, clave;
            nif = usu2->getNif();
            clave = usu2->getClave();
            usu2->login( nif, clave );
            usu2->escribeMensaje();
            i++;
        }
        
    }
    /*****************************************************************/
    
    cout<<"Usuarios conectados: "<<ziri.usuariosConectados()<<endl;
     
    
    string nif, clave;
    nif = "34923452L";
    clave = "pU7Pqq";
    
    Usuario *usu;
    usu = ziri.nuevoUsuarioConectado( nif, clave );
    
    if( usu == nullptr ){
        cout<<"El usuario no se ha conectado, clave invalida."<<endl;
    }else{
        cout<<"El usuario se ha conectado satisfactoriamente"<<endl;
    }
    
    
    
    
    list<Usuario*> listaUsuarios;
    listaUsuarios = ziri.analizartermino("casa");
    
    list<Usuario*>::iterator it2;
    
    for( it2 = listaUsuarios.begin(); it2 != listaUsuarios.end(); it2 ++){
        Usuario *usu = it2.operator *();
        cout<<"Nombre: "<<usu->getNombre()<<", NIF: "<<usu->getNif()<<endl;
    }
    
    list<Usuario*> usuarios1;
    usuarios1 = ziri.buscarTerminoRango("ganas", 3.0,37.0,4.0,38.0);
    cout<<"Usuarios que han escrito 'ganas': "<<usuarios1.size()<<endl;
    cout<<"Concurrencia palabra 'ganas': "<<ziri.OcurrenciaPal("ganas")<<endl;
    
    list<Usuario*> usuarios2;
    usuarios2 = ziri.buscarTerminoRango("es", 3.0,37.0,4.0,38.0);
    cout<<"Usuarios de Jaen que han escrito 'es': "<<usuarios2.size()<<endl;
    cout<<"Concurrencia palabra 'es': "<<ziri.OcurrenciaPal("es")<<endl;
    
    list<Usuario*> usuarios3;
    usuarios2 = ziri.buscarTerminoRango("extranjero", 3.0,37.0,4.0,38.0);
    cout<<"Usuarios de Jaen que han escrito 'extranjero': "<<usuarios2.size()<<endl;
    cout<<"Concurrencia palabra 'extranjero': "<<ziri.OcurrenciaPal("extranjero");
    
    
    return 0;
}


