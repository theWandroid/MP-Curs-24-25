#include "assignatura.h"

Assignatura::Assignatura(string nom, string nomProfessor, string mailProfessor, string despatx,
    int nEstudiants, 
    string estudiants[MAX_ESTUDIANTS][2]) : m_professorAssignatura(nomProfessor, mailProfessor, despatx)
{
    m_nom = nom;
    m_nEstudiants = nEstudiants;
    for (int i = 0; i < m_nEstudiants; i++)
    {
        m_estudiantsMatriculats[i].inicialitza(estudiants[i][0], estudiants[i][1]);
    }
}

int cercaEstudiant(Estudiant estudiants[], int nEstudiants, string niu) 
{
    bool trobat = false;
    int i = 0;
    while (!trobat && (i < nEstudiants))
    {
        if (estudiants[i].getNiu() == niu)
            trobat = true;
        else
            i++;
    }
    if (trobat)
        return i;
    else
        return -1;

}

void Assignatura::afegeixEstudiant(string nom, string niu) 
{
     
}

bool Assignatura::afegeixNota(string niu, float nota)
{

}

float Assignatura::calculaNotaMitjana(string niu)
{
 
}
