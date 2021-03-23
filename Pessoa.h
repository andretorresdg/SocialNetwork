#ifndef PESSOA_H
#define PESSOA_H
#include "Perfil.h"

class Perfil;

class Pessoa : public Perfil {

protected:
    string email;
    int numeroUSP;

public:

    Pessoa(int numeroUSP, string nome, string email);
    Pessoa(int id, int numeroUSP, string nome, string email);
    virtual ~Pessoa();

    virtual int getNumeroUSP();
    virtual string getEmail();

};

#endif // PESSOA_H
