#ifndef EVENTO_H
#define EVENTO_H

#include "Publicacao.h"
#include "Professor.h"
#include "Perfil.h"

class Publicacao;

class Evento : public Publicacao {

private:

    string data;

public:


    Evento(Perfil* autor, string texto, string data);
    virtual ~Evento();


    void curtir(Perfil* quemCurtiu);

    string getData();
};

#endif // EVENTO_H
