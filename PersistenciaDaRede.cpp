#include "PersistenciaDaRede.h"
#include "Aluno.h"
#include "Perfil.h"
#include "Professor.h"
#include "Disciplina.h"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdexcept>


RedeSocial* PersistenciaDaRede::carregar () {

    RedeSocial *novaRede = new RedeSocial ();
    ifstream entrada (arquivo.c_str());

    if (entrada.fail()) {
        entrada.close();
        return novaRede;
    }

    int ultimoId;
    entrada >> ultimoId;

    int alunos;
    entrada >> alunos;

    for (int i = 0; i < alunos; i++) {
        int id;
        int nusp;
        string nome;
        string email;
        entrada >> id;
        entrada >> nusp;
        entrada >> nome;
        entrada >> email;
        Aluno *pNovo1 = new Aluno (id, nusp, nome, email);
        novaRede->adicionar(pNovo1);

    }

    int profs = 0;
    entrada >> profs;
    for (int i = 0; i < profs; i++) {
        int id;
        int nusp;
        string nome;
        string email;
        string departamento;
        entrada >> id;
        entrada >> nusp;
        entrada >> nome;
        entrada >> email;
        entrada >> departamento;
        Professor *pNovo1 = new Professor (id, nusp, nome, email, departamento);
        novaRede->adicionar(pNovo1);

    }

    int dics = 0;
    entrada >> dics;
    for (int i = 0; i < dics; i++) {
        int id;
        string sigla;
        string nome;
        int idResp;
        entrada >> id;
        entrada >> sigla;
        entrada >> nome;
        entrada >> idResp;
        Perfil* pPerfilResp = novaRede->getPerfil(idResp);
        if (dynamic_cast<Professor*>(pPerfilResp) != NULL) {
            Professor *pResp = dynamic_cast<Professor*>(pPerfilResp);
            Disciplina *pNovo1 = new Disciplina (id, sigla, nome, pResp);
            novaRede->adicionar(pNovo1);

        }

    }

    novaRede->getPerfil(1)->setUltimoId(ultimoId);

    int idPerfil, idSeguidor;
    entrada >> idPerfil;
    while (entrada) {
        entrada >> idSeguidor;
        Perfil* pPerfil = novaRede->getPerfil(idPerfil);
        pPerfil->adicionarSeguidor(novaRede->getPerfil(idSeguidor));
        entrada >> idPerfil;
    }

    if (!entrada.eof()) {
        throw new logic_error("Erro de leitura");
    }

    entrada.close();
    return novaRede;
}


PersistenciaDaRede::PersistenciaDaRede (string arquivo) {
    this->arquivo = arquivo;
}

PersistenciaDaRede::~PersistenciaDaRede () {

}

void PersistenciaDaRede::salvar (RedeSocial* r) {

    ofstream saida (arquivo.c_str());

    int ultimo = 0;
    if (dynamic_cast<Perfil*>(r->getPerfil(1)) != NULL) {
        Perfil* pPer = r->getPerfil(1);
        ultimo = pPer->getUltimoId();
    }
    saida << ultimo << endl;

    int contAlunos = 0, contProf = 0, contDisc = 0;
    vector<Perfil*>::iterator k = r->getPerfis()->begin();
    while (k != r->getPerfis()->end()) {

        if (dynamic_cast<Aluno*>(*k) != NULL) {
            contAlunos++;
        } else if (dynamic_cast<Professor*>(*k) != NULL) {
            contProf++;
        } else if (dynamic_cast<Disciplina*>(*k) != NULL) {
            contDisc++;
        }
        k++;
    }


    saida << contAlunos << endl;
    vector<Perfil*>::iterator t = r->getPerfis()->begin();
    while (t != r->getPerfis()->end()) {
        Aluno *pA = dynamic_cast<Aluno*>(*t);
        if (pA != NULL) {
            saida << pA->getId() << " "
            << pA->getNumeroUSP() << " "
            << pA->getNome() << " "
            << pA->getEmail() << endl;
        }
        t++;
    }


    saida << contProf << endl;
    vector<Perfil*>::iterator u = r->getPerfis()->begin();
    while (u != r->getPerfis()->end()) {
        Professor *pProf = dynamic_cast<Professor*>(*u);
        if (pProf != NULL) {
            saida << pProf->getId() << " "
            << pProf->getNumeroUSP() << " "
            << pProf->getNome() << " "
            << pProf->getEmail() << " " << pProf->getDepartamento() << endl;
        }
        u++;
    }


    saida << contDisc << endl;
    vector<Perfil*>::iterator v = r->getPerfis()->begin();
    while (v != r->getPerfis()->end()) {
        Disciplina *pDis = dynamic_cast<Disciplina*>(*v);
        if (pDis != NULL) {
            saida << pDis->getId() << " "
            << pDis->getSigla() << " "
            << pDis->getNome() << " "
            << pDis->getResponsavel()->getId() << endl;
        }
        v++;
    }


    vector<Perfil*>::iterator x = r->getPerfis()->begin();
    while (x != r->getPerfis()->end()) {
        vector<Perfil*>::iterator c = (*x)->getSeguidores()->begin();
        while (c != (*x)->getSeguidores()->end()) {
            saida << (*x)->getId() << " " << (*c)->getId() << endl;
            c++;
        }
        x++;
    }

    saida.close();
}

