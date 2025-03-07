#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H
#include "estudiant.h"
#include "professor.h"

const int MAX_ESTUDIANTS = 50;

class Assignatura
{
public:
    // Afegir constructors

    Assignatura() : m_nom (""), m_nEstudiants(0){}
    //L'array no s'ha de inicialitzar
    Assignatura(string nom) : m_nom(nom), m_nEstudiants(0){}
    Assignatura(string nom, string nomProfessor, string mailProfessor, string despatx, 
        int nEstudiants, string estudiants[MAX_ESTUDIANTS][2]);
    //Array bidimensional
    //estudiants[i][0] = nom
    //estudiants[i][1] = niu

    void afegeixEstudiant(string nom, string niu);
    bool afegeixNota(string niu, float nota);
    float calculaNotaMitjana(string niu);
    string getNomProfessor(); 
    string getMailProfessor(); 
    string getDespatxProfessor();
private:
    string m_nom;
    Estudiant m_estudiantsMatriculats[MAX_ESTUDIANTS];

    int m_nEstudiants;
    Professor m_professorAssignatura;

};

#endif