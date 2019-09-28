#pragma once
using namespace std;
using namespace System;
#include <conio.h>
#include <iostream>
#include "CNodo.h"
template<class T>
class CPila
{
private:
	CNodo<T>*inicio;
	int n;
public:
	int darn()
	{
		return n;
	}
	CPila()
	{
		inicio = NULL;
		n = 0;
	}
	~CPila()
	{
		while (inicio != NULL)
		{
			CNodo<T>*aux = inicio;
			inicio = inicio->siguiente;
			delete aux;
			aux = NULL;
			n--;
		}
	}
	void insertarenalinicio(T valor)
	{
		CNodo<T>*temp = new CNodo<T>(valor);

		auto c_inicio = [&]() {
			inicio = temp;
			temp = nullptr;
			n++;
		};

		auto c_else = [&]() {
			temp->siguiente = inicio;
			inicio = temp;
			temp = nullptr;
			n++;
		};

		if (inicio == NULL)
		{
			c_inicio();
		}
		else
		{
			c_else();
		}
	}
	T eliminaralinicio()
	{
		if (n > 0)
		{
			if (inicio != NULL)
			{
				CNodo<T>*aux = inicio->siguiente;
				CTorre*devolver = inicio->valor;
				inicio = NULL;
				inicio = aux;
				n--;
				return devolver;
			}
		}
	}
	CNodo<T>* Getprimero()
	{
		return inicio;
	}
};
