/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VerbosConjugados.h
 * Author: Adrian
 *
 * Created on 3 de noviembre de 2020, 23:12
 */

#ifndef VERBOSCONJUGADOS_H
#define VERBOSCONJUGADOS_H
#include "AVL.h"
#include "Palabra.h"
#include <string>
#include <fstream>


class VerbosConjugados {
    private:
        AVL<Palabra> vConjugados;
        string nombreArchivo;
    public:
        VerbosConjugados();
        VerbosConjugados(string _nombreArchivo);
        VerbosConjugados(const VerbosConjugados& orig);
        int alturaAVLverbosConjugados();
        bool buscar(Palabra pal);
        clock_t getTiemposVector();
        virtual ~VerbosConjugados();


};

#endif /* VERBOSCONJUGADOS_H */

