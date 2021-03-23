#ifndef PERFIL_H
#define PERFIL_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
class Publicacao;

class Perfil {
    static int ultimoId;

protected:

    string nome;
    int id;

    list<Publicacao*>* feitas;
    list<Publicacao*>* recebidas;
    vector<Perfil*>* seguidores;

public:


    Perfil(string nome);
    Perfil(int id, string nome);
    virtual ~Perfil();

    static void setUltimoId(int ultimoId);
    static int getUltimoId();


    int getId();
    string getNome();


    virtual void adicionarSeguidor(Perfil* seguidor) = 0;

    virtual void publicar(string texto);
    virtual void publicar(string texto, string data);

    virtual void receber(Publicacao* p);
    virtual list<Publicacao*>* getPublicacoesFeitas();
    virtual list<Publicacao*>* getPublicacoesRecebidas();

    virtual vector<Perfil*>* getSeguidores();


    virtual void imprimir();

};

#endif // PERFIL_H
