#pragma once

class Complex
{
public:

	void inicialitza(float real, float img);
	void mostrar();
	void recupera(float& real, float &img);
	Complex sumar();
	Complex restar();
	Complex multiplicar();
	bool compara();

	int m_partReal;
	int m_partImaginaria;

};

Complex avaluaOperacio(const char operacio, Complex& c1, Complex& c2);
