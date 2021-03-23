#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>

#include "RedeSocial.h"
#include "Perfil.h"
#include "Publicacao.h"
#include "Mensagem.h"
#include "Disciplina.h"
#include "Evento.h"
#include "Professor.h"
#include "Aluno.h"
#include "Pessoa.h"
#include "PersistenciaDaRede.h"
#include "PerfilInexistente.h"

using namespace std;


int main() {

    int inputSelResponsavel = 0, inputComandoLogar = 0, inputSelecaoTelaPerfil = 0;
    int inputComandoPubliRecebidas = 0, inputTelaSeguirPerfil = 0;

    string inputNomeRede;
    int tela = 1;
    cout << "Arquivo: ";
    cin >> inputNomeRede;
    PersistenciaDaRede *persis = new PersistenciaDaRede(inputNomeRede);
    RedeSocial *redSocUm;

    try {
        redSocUm = persis->carregar();
    } catch (logic_error *e) {
        cout << endl << "Erro: " << e->what() << endl;
        delete e;
        return 0;
    }

    while (tela != 0) {

        int inputComandoInicial = 0;
        cout << endl << "Escolha uma opcao: " << endl;
        cout << "1) Cadastrar Perfil" << endl;
        cout << "2) Cadastrar Disciplina" << endl;
        cout << "3) Logar" << endl;
        cout << "0) Terminar" << endl;
        cin >> inputComandoInicial;

        if (inputComandoInicial == 1) {
            string inputNome, inputEmail, inputEProfessor, inputDepartamento;
            int inputNumeroUsp;

            cout << endl << "Informe os dados do perfil " << endl;
            cout << "Numero USP: ";
            cin >>  inputNumeroUsp;

            cout << endl << "Nome: ";
            cin.ignore (100, '\n');
            getline (cin, inputNome);

            cout << endl << "Email: ";
            cin >> inputEmail;

            cout << endl << "Professor (s/n): ";
            cin >> inputEProfessor;

            if (inputEProfessor == "n") {
                Aluno* pNovo = new Aluno (inputNumeroUsp, inputNome, inputEmail);
                try {
                    redSocUm->adicionar(pNovo);
                } catch (invalid_argument *e) {
                    cout << endl << "Erro: " << e->what() << endl;
                    delete e;
                    return 0;
                }

            } else if (inputEProfessor == "s") {
                cout << endl << "Departamento: ";
                cin >> inputDepartamento;

                Professor* profNovo = new Professor (inputNumeroUsp, inputNome, inputEmail, inputDepartamento);
                try {
                    redSocUm->adicionar(profNovo);
                } catch (invalid_argument *e) {
                    cout << endl << "Erro: " << e->what() << endl;
                    delete e;
                    return 0;
                }
            }

        } else if (inputComandoInicial == 2) {

            string inputSigla, inputNomeDisciplina;
            cout << endl << "Informe os dados da disciplina" << endl;
            cout << "Sigla: ";
            cin >> inputSigla;

            cout << endl << "Nome: ";
            cin.ignore(100, '\n');
            getline(cin, inputNomeDisciplina);

            cout << endl << "Responsavel: " << endl;
            redSocUm->imprimir();

            cin >> inputSelResponsavel;

            if (inputSelResponsavel != 0) {
                Perfil *tentarPerfil;
                try {
                    tentarPerfil = redSocUm->getPerfil(inputSelResponsavel);
                } catch (PerfilInexistente *e) {
                    cout << endl << "Erro: " << e->what() << endl;
                    delete e;
                    return 0;
                }
                Professor *pProf = dynamic_cast<Professor*>(tentarPerfil);
                if (pProf != NULL) {
                    Perfil* dNova = new Disciplina(inputSigla, inputNomeDisciplina, pProf);
                    try {
                        redSocUm->adicionar(dNova);
                    } catch (invalid_argument *e) {
                        cout << endl << "Erro: " << e->what() << endl;
                        delete e;
                        return 0;
                    }

                } else {
                    cout << endl << "Somente professores podem ser responsaveis por disciplinas" << endl;
                }
            }

        } else if (inputComandoInicial == 3) {

            cout << endl << "Escolha um perfil:" << endl;
            redSocUm->imprimir();
            cin >> inputComandoLogar;
            if (inputComandoLogar > 0) {
                Perfil *perfilSelecionadoZero;
                try {
                    perfilSelecionadoZero = redSocUm->getPerfil(inputComandoLogar);
                } catch (PerfilInexistente *e) {
                    cout << endl << "Erro: " << e->what() << endl;
                    delete e;
                    return 0;
                }

                int loopPerfilSelecionado = 1;
                while (loopPerfilSelecionado != 0) {
                    Aluno *pA = dynamic_cast<Aluno*>(redSocUm->getPerfil(inputComandoLogar));
                    Professor *pProf = dynamic_cast<Professor*>(redSocUm->getPerfil(inputComandoLogar));
                    Disciplina *pD = dynamic_cast<Disciplina*>(redSocUm->getPerfil(inputComandoLogar));

                    if (pA != NULL) {
                        cout << endl << endl <<  pA->getNumeroUSP() ;
                        cout << " - " << pA->getNome() << endl;

                    } else if (pProf != NULL) {
                        cout << endl << endl <<  pProf->getNumeroUSP() ;
                        cout << " - " << pProf->getNome() << endl;
                        cout << "Departamento " << pProf->getDepartamento() << endl;

                    } else if (pD != NULL) {
                        cout << endl << pD->getSigla();
                        cout << " - " << pD->getNome() << endl;
                    }
                    cout << "Seguidores: " << redSocUm->getPerfil(inputComandoLogar)->getSeguidores()->size() << endl;
                    cout << "---" << endl;
                    cout << "Escolha uma opcao: " << endl;
                    cout << "1) Ver publicacoes feitas" << endl;
                    cout << "2) Ver publicacoes recebidas" << endl;
                    cout << "3) Fazer publicacao" << endl;

                    if (pD != NULL) {
                    } else {
                        cout << "4) Seguir perfil" << endl;
                    }
                    cout << "0) Deslogar" << endl;
                    cin >> inputSelecaoTelaPerfil;
                    if (inputSelecaoTelaPerfil == 0) {
                        loopPerfilSelecionado = 0;

                    } else if (inputSelecaoTelaPerfil == 1) {

                        cout << endl << "Publicacoes feitas: " << endl;
                        if (redSocUm->getPerfis() > 0) {

                            list<Publicacao*>::iterator u = redSocUm->getPerfil(inputComandoLogar)->getPublicacoesFeitas()->begin();
                            while (u != redSocUm->getPerfil(inputComandoLogar)->getPublicacoesFeitas()->end()) {

                                if (dynamic_cast<Evento*>(*u) != NULL) {

                                    Evento *pEvent = dynamic_cast<Evento*>(*u);
                                    cout << pEvent->getData() << " - ";
                                }
                                (*u)->imprimir();
                                u++;
                            }
                            cout << endl;

                        }
                    } else if (inputSelecaoTelaPerfil == 2) {

                        cout << endl << "Publicacoes recebidas: " << endl;
                        list<Publicacao*>::iterator r = redSocUm->getPerfil(inputComandoLogar)->getPublicacoesRecebidas()->begin();
                        int numDePublis = 0;
                        while (r != redSocUm->getPerfil(inputComandoLogar)->getPublicacoesRecebidas()->end()) {

                            numDePublis++;
                            cout << numDePublis << ") ";
                            if (dynamic_cast<Evento*>(*r) != NULL) {
                                Evento *pEvent = dynamic_cast<Evento*>(*r);
                                cout << pEvent->getData() << " - ";
                            }
                            (*r)->imprimir();
                            r++;
                        }
                        cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
                        cin >> inputComandoPubliRecebidas;
                        if (inputComandoPubliRecebidas != 0) {

                            list<Publicacao*>::iterator w = redSocUm->getPerfil(inputComandoLogar)->getPublicacoesRecebidas()->begin();
                            advance(w, inputComandoPubliRecebidas-1);
                            if (dynamic_cast<Evento*>(*w) != NULL) {

                                Evento *pEvent = dynamic_cast<Evento*>(*w);
                                pEvent->curtir(redSocUm->getPerfil(inputComandoLogar));

                            } else if (dynamic_cast<Mensagem*>(*w) != NULL) {

                                Mensagem *pMsg = dynamic_cast<Mensagem*>(*w);
                                try {
                                    pMsg->curtir(redSocUm->getPerfil(inputComandoLogar));
                                } catch (invalid_argument *e) {
                                    cout << endl << "Erro: " << e->what() << endl;
                                    delete e;
                                    return 0;
                                }

                            }
                        }
                    } else if (inputSelecaoTelaPerfil == 3) {

                        string inputEvento, inputDataEvento, inputTextoPubli;
                        cout << endl << "Evento (s/n): ";
                        cin >> inputEvento;

                        if (inputEvento == "s") {

                            cout << endl << "Data: ";
                            cin >> inputDataEvento;
                            cout << endl << "Texto: ";
                            cin.ignore(100, '\n');
                            getline(cin, inputTextoPubli);
                            redSocUm->getPerfil(inputComandoLogar)->publicar(inputTextoPubli, inputDataEvento);

                        } else if (inputEvento == "n") {

                            cout << endl << "Texto: ";
                            cin.ignore(100, '\n');
                            getline(cin, inputTextoPubli);
                            redSocUm->getPerfil(inputComandoLogar)->publicar(inputTextoPubli);
                        }
                    } else if (inputSelecaoTelaPerfil == 4) {

                        if (pD == NULL) {

                            cout << endl << "Perfil: " << endl;
                            redSocUm->imprimir();
                            cin >> inputTelaSeguirPerfil;
                            Perfil *perfilSelecionado;
                            try {
                                perfilSelecionado = redSocUm->getPerfil(inputTelaSeguirPerfil);
                            } catch (PerfilInexistente *e) {
                                cout << endl << "Erro: " << e->what() << endl;
                                delete e;
                                return 0;
                            }

                            try {
                                redSocUm->getPerfil(inputTelaSeguirPerfil)->adicionarSeguidor(redSocUm->getPerfil(inputComandoLogar));
                            } catch (invalid_argument *e) {
                                cout << endl << "Erro: " << e->what() << endl;
                                delete e;
                                return 0;
                            }

                        }
                    }
                }
            }
        } else if (inputComandoInicial == 0) {
            string inputSalvar;
            cout << endl << "Deseja salvar? (s/n) ";
            cin >> inputSalvar;
            if (inputSalvar == "s") {
                    persis->salvar(redSocUm);
            }
            delete redSocUm;
            tela = 0;
        }
    }
}
