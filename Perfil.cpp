#include "Perfil.h"
#include "Pessoa.h"
#include "Publicacao.h"
#include "Mensagem.h"
#include "Evento.h"
#include "PersistenciaDaRede.h"

#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int Perfil::ultimoId = 0;


Perfil::Perfil (string nome) {
     this->nome  = nome;
     this->ultimoId = ultimoId + 1;
     this->id = ultimoId;
     this->feitas = new list<Publicacao*>();
     this->recebidas = new list<Publicacao*>();
     this->seguidores = new vector<Perfil*>();
}

Perfil::Perfil (int id, string nome) {
     this->nome  = nome;
     this->id = id;
     this->feitas = new list<Publicacao*>();
     this->recebidas = new list<Publicacao*>();
     this->seguidores = new vector<Perfil*>();
}

Perfil::~Perfil() {

}


string Perfil::getNome () {
    return nome;
}

list<Publicacao*>* Perfil::getPublicacoesFeitas () {
    return feitas;
}


list<Publicacao*>* Perfil::getPublicacoesRecebidas () {
    return recebidas;
}


vector<Perfil*>* Perfil::getSeguidores () {
     return seguidores;
}


void Perfil::publicar (string texto) {
    feitas->push_back(new Mensagem(this, texto));
    vector<Perfil*>::iterator m = seguidores->begin();
    while (m != seguidores->end()) {
        (*m)->receber(this->feitas->back());
        m++;
    }
}

void Perfil::publicar (string texto, string data) {
    feitas->push_back(new Evento(this, texto, data));
    vector<Perfil*>::iterator k = seguidores->begin();
    while (k != seguidores->end()) {
        (*k)->receber(this->feitas->back());
        k++;
    }
}

void Perfil::receber (Publicacao* p) {
    recebidas->push_back(p);
}

int Perfil::getUltimoId () {
    return Perfil::ultimoId;
}

void Perfil::setUltimoId (int ultimoId) {
    Perfil::ultimoId = ultimoId;
}

int Perfil::getId () {
    return id;
}



void Perfil::imprimir () {
    cout << endl << "Nome: " << this->getNome() << " - id: " << getId() << endl;
    if (seguidores->empty()) {
        cout << "Sem seguidor " << endl;
    } else {

        vector<Perfil*>::iterator b = seguidores->begin();
        while (b != seguidores->end()) {
            cout << "Seguidor " << (*b)->getNome() << endl;
            (*b)->imprimir();
            b++;
        }
    }
    cout << "Numero de publicacoes feitas: " << feitas->size() << endl;
    list<Publicacao*>::iterator i = feitas->begin();
    while (i != feitas->end()) {
        (*i)->imprimir();
        i++;
    }
    cout << "Numero de publicacoes recebidas: " << recebidas->size() << endl;
    list<Publicacao*>::iterator j = recebidas->begin();
    while (j != recebidas->end()) {
        (*j)->imprimir();
        j++;
    }
}
