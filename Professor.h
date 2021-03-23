#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Perfil.h"
#include "Pessoa.h"

class Perfil;
class Pessoa;
class Publicacao;

class Professor : public Pessoa {

private:

    string departamento;

public:

    Professor(int numeroUSP, string nome, string email, string departamento);
    Professor(int id, int numeroUSP, string nome, string email, string departamento);
    virtual ~Professor();


    string getDepartamento();


    void adicionarSeguidor(Perfil* seguidor);

};

#endif // PROFESSOR_H
