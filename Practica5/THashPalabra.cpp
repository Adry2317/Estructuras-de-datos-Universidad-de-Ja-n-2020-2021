/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   THashPalabra.cpp
 * Author: Adrian
 * 
 * Created on 1 de diciembre de 2020, 11:38
 */

#include "THashPalabra.h"
#include <cstring>
#include "Palabra.h"
//Entreno

THashPalabra::THashPalabra() {
    
}




THashPalabra::THashPalabra(float _factorCarga, unsigned tamDatos):factorCarga(_factorCarga){
    unsigned aux = tamDatos/factorCarga;
    
    int cont = 0;
    bool primo = false;
    
    while(!primo){
        aux++;
        for (int i = 2; i < sqrt(aux); i++){
            if(aux%i == 0){
                cont++;
            }
        }
        if (cont < 1){
            primo = true;
        }else{
            cont = 0;
        }
    }
    
    tamTabla = aux;
    vectHash.resize(tamTabla);
    slotVacios = tamTabla;
}


/**
 * Cosntructor copia
 * @param orig: Tabla hash desde la que se copiaran los datos.
 */
THashPalabra::THashPalabra(const THashPalabra& orig) {
    factorCarga = orig.factorCarga;
    tamTabla = orig.tamTabla;
    
    slotVacios = orig.slotVacios;
    slotDisponibles = orig.slotDisponibles;
    slotOcupados = orig.slotOcupados;
    maxColisiones = orig.maxColisiones;
    colisiones = orig.colisiones;
    vectHash = orig.vectHash;
    
     
            
}

/**
 * Sobre carga del operador =
 * @param Thash: tabla hash a asignar.
 * @return tabla hash con los valores ya asignados.
 */
THashPalabra& THashPalabra::operator=(const THashPalabra& Thash) {
    if( this != &Thash){
        factorCarga = Thash.factorCarga;
        tamTabla = Thash.tamTabla;
       
        slotDisponibles = Thash.slotDisponibles;
        slotOcupados = Thash.slotOcupados;
        slotVacios = Thash.slotVacios;
        maxColisiones = Thash.maxColisiones;
        colisiones = Thash.colisiones;
        vectHash = Thash.vectHash;
        
        
    }else{
        throw std::invalid_argument("Las tablas hash son iguales");
               
    }
    return *this;
}

unsigned long THashPalabra::hash(unsigned long clave, int intento) {

 
    /**********************Cuadrática**********************/
//    unsigned long hash;
//    
//    return hash = (clave-intento*intento)%tamTabla;
    
    /******************Función de dispersión doble ****************/
//    unsigned int q = 10487;
//    unsigned long hash1, hash2, HASH;
//    int intentCuadrado = intento*intento;
//    hash1 = (clave + intentCuadrado)%tamTabla; //Parte modificada respecto a las diapositivas
//    hash2 = q - ( clave %q );
//    
//    HASH = (hash1 + intento * hash2 )%tamTabla;
//    
//    return HASH;
    
    
    /******************Función de dispersión doble 2****************/
    unsigned long hash1, hash2, HASH;
    hash1 = clave%tamTabla;
    hash2 = 1+(clave%(tamTabla-1));
    
    HASH = (hash1 + intento*hash2)%tamTabla;
    return HASH;
}





/**
 * Función que implementa el algoritmo de dan Bernstein (modificado)
 * @param str: cadena de caracteres para generar el hash
 * @return: el hash.
 */
unsigned long THashPalabra::djb2(string str) {
    unsigned long hash = 5381;
    char str2[str.length()];
    strcpy(str2, str.c_str()); //copia contenid del string en el vector char;
    int c;
    for (int i=0; i<str.length(); i++){
        c = (int)str2[i];
        
        hash = ((hash << 5)+ hash)+c;
    }
    
    
    
    return hash;
    
}


/**
 * Función que inserta dentro de la tabla hash
 * @param clave: clave de la palabra a insertar.
 * @param pal: palabra a insertar.
 * @return: devuelve true si se inserta y false si no se inserta.
 */
bool THashPalabra::insertar(unsigned long clave, Palabra& pal) {
    
    int intento = 0;
    unsigned long aux;
    
   
    
    int contador = 1000;
    
    while(contador != 0){
        aux = hash( clave , intento );
        auto aux2 = vectHash[aux];
        if( vectHash[aux].estadoTabla == disponible || vectHash[aux].estadoTabla == vacio ){
            
            vectHash[aux].clave = clave;
            vectHash[aux].pal = pal;
            vectHash[aux].estadoTabla = ocupado;
            slotVacios--;
            slotOcupados++;
            
            
            if ( intento > maxColisiones){
                maxColisiones = intento;
            }
            
            return true;
        }
        
        intento++;
        contador--;
        colisiones++;
        
        if ( intento > maxColisiones){
                maxColisiones = intento;
            }
    }
    return false;
}


/**
 * Función encargada de buscar una palabra dentro de la tabla hash
 * @param clave: clave de la palabra.
 * @param termino: termino de la palabra a buscar
 * @param pal: palabra a la que se le asignará la buscada.
 * @return: true si se ha encontrado o false si no se ha encontrado.
 */
bool THashPalabra::buscar(unsigned long clave, string& termino, Palabra *&pal) {
    unsigned long aux;
    int intento  = 0;
    
    int contador = 1000;
    
    while(contador != 0){
        aux = hash( clave, intento );
        
        if( vectHash[aux].estadoTabla == ocupado && vectHash[aux].pal.getPalabra() == termino){
            pal = &vectHash[aux].pal;
            return true;
        }
        intento ++;
        contador--;
    }
    pal = nullptr;
    return false;
}



/**
 * Función encargada de "borrar" un elemento de la tabla hash
 * @param clave: clave correspondiente a la palabra.
 * @param termino: termino de la palabra a buscar.
 * @return true si se borra la palabra false, si no se borra.
 */
bool THashPalabra::borrar(unsigned long clave, string& termino) {
    unsigned long aux;
    int intento = 0;
    int contador = 1000;
    
    while(contador != 0){
       aux = hash( clave , intento );
        
        if ((vectHash[aux].estadoTabla == ocupado) && (vectHash[aux].pal.getPalabra() == termino)){
            
            vectHash[aux].estadoTabla = disponible;
            slotDisponibles++;
            slotOcupados--;
            return true;
        }
        intento ++;
        contador--;
    }
    return false;
}


/**
 * 
 * @return Devuelve el numero de palabras dentro de la tabla hash
 */
unsigned int THashPalabra::numPalabras() {
    return slotOcupados;
}

/**
 * 
 * @return: devuelve el maximo de colisiones. 
 */
unsigned int THashPalabra::maximoColisiones() {
    return maxColisiones;
}


/**
 * 
 * @return: Devuelve el promedio de colisiones. 
 */
 float THashPalabra::promedioColisiones() {
    
    float col = (float) colisiones;
    float slotOc = (float) slotOcupados;
    
    return col / slotOc;
}

 
 /**
  * 
  * @return: Devuelve el factor de carga. 
  */
float THashPalabra::_factorCarga() {
    return factorCarga;
}


/**
 * 
 * @return devuelve el tamaño de la tabla.
 */
unsigned int THashPalabra::tamañoTabla() {
    return tamTabla;
}

/**
 * 
 * @return: devuelve el numero de colisiones 
 */
unsigned int THashPalabra::_colisiones() {
    return colisiones;
}


THashPalabra::~THashPalabra() {
  
}

