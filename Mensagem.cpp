#include "Mensagem.h"
#include "Perfil.h"
#include "Publicacao.h"

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;


void Mensagem::curtir (Perfil* quemCurtiu) {
    if (this->autor != quemCurtiu) {
        this->curtidas++;
    } else {
        throw new invalid_argument ("Curtir a propria mensagem");
    }
}


Mensagem::Mensagem (Perfil* autor, string texto): Publicacao (autor, texto) {
}

Mensagem::~Mensagem() {
}
