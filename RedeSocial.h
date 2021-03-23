#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

#include "Perfil.h"

class Perfil;

class RedeSocial {
private:

    vector<Perfil*>* perfis;

public:

    //Construtores e Destrutores
    RedeSocial();
    virtual ~RedeSocial();

    // Getters sobre Perfis
    vector<Perfil*>* getPerfis();
    Perfil* getPerfil(int id);

    //Demais Metodos
    void adicionar(Perfil* perfil);
    void imprimir();

};

#endif // REDESOCIAL_H
