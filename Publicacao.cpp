#include "Perfil.h"
#include "Publicacao.h"
#include <iostream>

using namespace std;


Publicacao::Publicacao (Perfil* autor, string texto) {
   this->autor = autor;
   this->texto = texto;
   this->curtidas = 0;
}

Publicacao::~Publicacao () {
}


Perfil* Publicacao::getAutor () {
    return autor;
}
string Publicacao::getTexto () {
    return texto;
}


int Publicacao::getCurtidas () {
    return curtidas;
}


void Publicacao::imprimir () {
    cout << texto << " (" << autor->getNome() << ") ";
    cout << " [" << curtidas << "] " << endl;
}
