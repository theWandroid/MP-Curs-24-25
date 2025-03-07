#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
using namespace std;

class Professor
{

public:
	Professor() : m_nom(""), m_mail(""), m_despatx(0) {}
	Professor(string nom, string mail, string despatx) : m_nom(nom), m_mail(mail), m_despatx(despatx) {}

	~Professor();


	string getNom() { return m_nom; }
	string getMail() { return m_mail; }
	string getDespatx() { return m_despatx; }


private:
	string m_nom;
	string m_mail;
	string m_despatx;
};


#endif

