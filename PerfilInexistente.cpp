#include "PerfilInexistente.h"

#include <stdexcept>
#include<iostream>

using namespace std;

PerfilInexistente::PerfilInexistente ():
    logic_error ("Perfil Inexistente") {}


PerfilInexistente::~PerfilInexistente () {
}

