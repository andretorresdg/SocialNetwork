#include "Perfil.h"
#include "Pessoa.h"

#include <string>
#include <iostream>


Pessoa::Pessoa (int numeroUSP, string nome, string email) : Perfil(nome) {
     this->numeroUSP = numeroUSP;
     this->email = email;
}

Pessoa::Pessoa (int id, int numeroUSP, string nome, string email) : Perfil (id, nome) {
     this->numeroUSP = numeroUSP;
     this->email = email;
}

Pessoa::~Pessoa () {
}


int Pessoa::getNumeroUSP () {
    return numeroUSP;
}

string Pessoa::getEmail () {
    return email;
}
