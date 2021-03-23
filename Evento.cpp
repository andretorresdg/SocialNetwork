#include "Evento.h"
#include "Publicacao.h"
#include "Perfil.h"

#include <iostream>

using namespace std;

//Construtor e Destrutor
Evento::Evento (Perfil* autor, string texto, string data) : Publicacao(autor, texto) {
    this->data = data;
}

Evento::~Evento () {
}

// Getter para Data
string Evento::getData () {
    return data;
}

// Método Curtir
void Evento::curtir (Perfil* quemCurtiu) {
    this->curtidas++;
}
