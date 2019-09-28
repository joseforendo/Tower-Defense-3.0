#pragma once
using namespace std;
using namespace System;
#include <conio.h>
#include <iostream>

template<class T>
class CNodo
{
public:
	T valor;
	CNodo<T>* siguiente;
	CNodo(T valor_)
	{
		valor = valor_;
		siguiente = nullptr;
	}
	~CNodo()
	{
		valor = NULL;
		siguiente = NULL;
	}
};
