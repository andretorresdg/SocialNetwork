#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include "Perfil.h"
#include "Professor.h"

class Perfil;
class Professor;
class Publicacao;

class Disciplina : public Perfil {
protected:
    Professor* responsavel;
    string sigla;


public:


    Disciplina(string sigla, string nome, Professor* responsavel);
    Disciplina(int id, string sigla, string nome, Professor* responsavel);
    virtual ~Disciplina();


    Professor* getResponsavel();
    string getSigla();


    void adicionarSeguidor(Perfil* seguidor);

};

#endif // PUBLICACAO_H
