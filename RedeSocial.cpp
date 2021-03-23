#include "RedeSocial.h"
#include "Perfil.h"
#include "Aluno.h"
#include "Publicacao.h"
#include "Evento.h"
#include "Professor.h"
#include "Disciplina.h"
#include "PerfilInexistente.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;


RedeSocial::RedeSocial () {
    perfis = new vector<Perfil*>();
}

RedeSocial::~RedeSocial () {

    while (!perfis->empty()) {
        Perfil *ultimo = perfis->back();
        perfis->pop_back();
        delete ultimo;
    }
    delete perfis;

}

vector<Perfil*>* RedeSocial::getPerfis () {
    return perfis;
}


Perfil* RedeSocial::getPerfil (int id) {

    int achei = 0;
    vector<Perfil*>:: iterator o = getPerfis()->begin();
    while (o != getPerfis()->end()) {
        if ((*o)->getId() == id) {
            achei = 1;
            return (*o);
        }
        o++;
    }
    if (achei == 0) {
        throw new PerfilInexistente();
    }

}


void RedeSocial::adicionar (Perfil* perfil) {

    vector<Perfil*>::iterator q = find(perfis->begin(), perfis->end(), perfil);
    if (q != perfis->end()) {
        throw new invalid_argument("Ja foi adcionado este perfil");
    } else {
        perfis->push_back(perfil);
    }
}

void RedeSocial::imprimir() {

    vector<Perfil*>::iterator b = this->getPerfis()->begin();
    while (b != this->getPerfis()->end()) {
        cout << (*b)->getId() << ") " << (*b)->getNome() << endl;
        b++;
    }
    cout << "Digite o id ou 0 para cancelar: ";

}
