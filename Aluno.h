#ifndef ALUNO_H
#define ALUNO_H
#include "Perfil.h"
#include "Pessoa.h"


class Perfil;
class Pessoa;
class Publicacao;

class Aluno : public Pessoa {

public:

    Aluno(int numeroUSP, string nome, string email);
    Aluno(int id, int numeroUSP, string nome, string email);
    virtual ~Aluno();

    void adicionarSeguidor(Perfil* seguidor);

};

#endif // ALUNO_H
