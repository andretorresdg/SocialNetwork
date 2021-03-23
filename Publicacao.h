#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#include <string>

#include "Perfil.h"
#include "Professor.h"

class Professor;
class Perfil;

class Publicacao {
protected:

    string texto;
    Perfil* autor;
    int curtidas;

public:

    Publicacao(Perfil* autor, string texto);
    virtual ~Publicacao();

    Perfil* getAutor();
    string getTexto();


    virtual void curtir(Perfil* quemCurtiu) = 0;
    virtual int getCurtidas();


    virtual void imprimir();

};

#endif // PUBLICACAO_H
