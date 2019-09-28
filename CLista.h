#pragma once
using namespace std;
using namespace System;
#include <conio.h>
#include <iostream>
#include "CNodo.h"
template<class T>
class CLista
{
private:
	CNodo<T>*inicio;
	CNodo<T>*final;
	int n;
public:
	int darn()
	{
		return n;
	}
	CLista()
	{
		inicio = NULL;
		final = NULL;
		n = 0;
	}
	~CLista()
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
		if (inicio == NULL)
		{
			inicio = temp;
			final = temp;
			temp = NULL;
			n++;
		}
		else
		{
			temp->siguiente = inicio;
			inicio = temp;
			temp = NULL;
			n++;
		}
	}
	void insertaralfinal(T valor)
	{
		CNodo<T>*temp = new CNodo<T>(valor);
		if (final == NULL)
		{
			insertarenalinicio(valor);
		}
		else
		{
			final->siguiente = temp;
			final = temp;
			temp = NULL;
			n++;
		}
	}
	void eliminaralinicio()
	{
		if (n > 0)
		{
			if (inicio != NULL)
			{
				CNodo<T>*aux = inicio->siguiente;
				inicio = NULL;
				inicio = aux;
				n--;
				if (n == 0)
				{
					final = NULL;
				}
			}
		}
	}
	void eliminarenposición(int pos)
	{
		if (pos == 0)
		{
			eliminaralinicio();
		}
		else
		{
			if (pos < n)
			{
				CNodo<T> *aux = inicio;
				while (pos - 1)
				{
					aux = aux->siguiente;
					pos--;
				}
				CNodo<T> *aux2;
				aux2 = aux->siguiente->siguiente;
				aux->siguiente->siguiente = NULL;
				aux->siguiente = aux2;
				aux = NULL;
				aux2 = NULL;
				n--;
			}
		}
	}

	CNodo<T>* Getpos(int pos, CNodo<T> *node)
	{
		if (pos == 0)
		{
			return node;
		}
		else
		{
			return Getpos(pos - 1, node->siguiente);
		}
	}

	CNodo<T> *Getpos(int pos)
	{
		return Getpos(pos, inicio);
	}
};
