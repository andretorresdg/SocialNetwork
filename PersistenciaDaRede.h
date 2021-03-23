#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H

#include <iostream>
#include <fstream>
#include <string>

#include "RedeSocial.h"
#include "Aluno.h"


class PersistenciaDaRede {
private:

    string arquivo;

public:

    PersistenciaDaRede(string arquivo);
    virtual ~PersistenciaDaRede();

    void salvar(RedeSocial* r);
    RedeSocial* carregar();

};

#endif // PERSISTENCIADAREDE_H





