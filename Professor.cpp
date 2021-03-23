#include "Professor.h"
#include "Perfil.h"
#include "Pessoa.h"
#include "Publicacao.h"
#include "Mensagem.h"

#include <stdexcept>
#include <string>
#include <iostream>


using namespace std;


Professor::Professor(int numeroUSP, string nome, string email, string departamento) :  Pessoa(numeroUSP, nome, email) {
    this->departamento = departamento;
}

Professor::Professor(int id, int numeroUSP, string nome, string email, string departamento) :  Pessoa(id, numeroUSP, nome, email) {
    this->departamento = departamento;
}


Professor::~Professor(){

}


string Professor::getDepartamento() {
    return departamento;
}


void Professor::adicionarSeguidor (Perfil* seguidor) {

    vector<Perfil*>:: iterator o = seguidores->begin();
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
        string uniaoMsg = "Novo Seguidor: " + seguidor->getNome();
        Publicacao* publiN = new Mensagem (this ,uniaoMsg);
        receber(publiN);

    }

}
