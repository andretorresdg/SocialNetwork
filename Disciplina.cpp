#include "Disciplina.h"
#include "Perfil.h"
#include "Publicacao.h"

#include <stdexcept>
#include <string>
#include <iostream>


using namespace std;


Disciplina::Disciplina (string sigla, string nome, Professor* responsavel) : Perfil(nome) {
     this->sigla = sigla;
     this->responsavel = responsavel;


     adicionarSeguidor(responsavel);
}

Disciplina::Disciplina (int id, string sigla, string nome, Professor* responsavel) : Perfil (id, nome) {
     this->sigla = sigla;
     this->responsavel = responsavel;
}

Disciplina::~Disciplina () {
}

//Getters para Responsavel e Sigla
Professor* Disciplina::getResponsavel () {
    return responsavel;
}

string Disciplina::getSigla () {
    return sigla;
}


void Disciplina::adicionarSeguidor(Perfil* seguidor) {


    vector<Perfil*>::iterator o = seguidores->begin();
    int errou = 0;
    while (o != seguidores->end()) {
        if ((*o) == seguidor) {
            throw new invalid_argument("Esse perfil ja e seguido");
            errou = 1;
        }
        o++;
    }

    if (this->getId() == seguidor->getId()) {
        throw new invalid_argument("Voce tentou seguir a si mesmo");

    } else if (errou == 0) {
        seguidores->push_back(seguidor);
    }



}
