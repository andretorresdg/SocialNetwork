#ifndef MENSAGEM_H
#define MENSAGEM_H

#include "Publicacao.h"
#include "Mensagem.h"

class Publicacao;

class Mensagem : public Publicacao {

public:
    Mensagem(Perfil* autor, string texto);
    virtual ~Mensagem();

    void curtir(Perfil* quemCurtiu);
};


#endif // MENSAGEM_H
