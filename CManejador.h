#pragma once
#include <fstream>
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
#include "CJugador.h"
#include "CEnemigo.h"
#include "CLista.h"
#include <conio.h>
#include <iostream>
#include <vector>
template<typename T, typename G>
bool Colisión(T a, G b)
{
	if (a->Getx() + a->Getancho() >= b->Getx())
	{
		if (b->Getx() + b->Getancho() >= a->Getx())
		{
			if (a->Gety() + a->Getalto() >= b->Gety())
			{
				if (b->Gety() + b->Getalto() >= a->Gety())
				{
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
class CManejador
{
private:
	CJugador*jugador;
	CLista<CEnemigo*>*enemigos;
	int tiempo;
public:
	CManejador(Graphics^g)
	{
		tiempo = 0;
		jugador = new CJugador(g);
		enemigos = new CLista<CEnemigo*>();
	}

	void movimientoEnemigos(int pos, Graphics ^g)
	{
		if (pos >= enemigos->darn())
		{
			return;
		}
		else
		{
			enemigos->Getpos(pos)->valor->Mover(g);
			movimientoEnemigos(pos + 1, g);
		}
	}

	void movimientoProyectilesJugador(int pos, Graphics ^g)
	{
		if (pos >= jugador->getProyectiles()->darn())
		{
			return;
		}
		else
		{
			jugador->getProyectiles()->Getpos(pos)->valor->Mover(g);
			movimientoProyectilesJugador(pos + 1, g);
		}
	}

	void MovimientoGeneral(Graphics^g, Form^esto)
	{
		jugador->Mover(g);
		movimientoEnemigos(0, g);
		movimientoProyectilesJugador(0, g);


		for (int i = 0; i < jugador->gettorres()->darn(); i++)
		{
			for (int j = 0; j < jugador->gettorres()->Getpos(i)->valor->getProyectiles()->darn(); j++)
			{
				jugador->gettorres()->Getpos(i)->valor->getProyectiles()->Getpos(j)->valor->Mover(g);
				if (jugador->gettorres()->Getpos(i)->valor->getProyectiles()->Getpos(j)->valor->resultadomovimiento() == 0)
				{
					//eliminar si está más allá del mapa para las torres
					jugador->gettorres()->Getpos(i)->valor->getProyectiles()->eliminarenposición(j);
					j--;
				}
			}
		}
		for (int i = 0; i < enemigos->darn(); i++)
		{
			if (enemigos->Getpos(i)->valor->resultadomovimiento() == 0)
			{
				//eliminar si está más allá del mapa
				enemigos->eliminarenposición(i);
				jugador->Setvida(jugador->Getvida() - 1);
				i--;
			}
		}
		for (int i = 0; i < enemigos->darn(); i++)
		{
			if (enemigos->Getpos(i)->valor->Getvida() <= 0)
			{
				//dar oro por destruir enemigos
				enemigos->eliminarenposición(i);
				jugador->Setgold(jugador->Getgold() + 100);
				i--;
			}
		}
		for (int i = 0; i < jugador->getProyectiles()->darn(); i++)
		{
			if (jugador->getProyectiles()->Getpos(i)->valor->resultadomovimiento() == 0)
			{
				//eliminar si está más alllá del mapa para el jugador
				jugador->getProyectiles()->eliminarenposición(i);
				i--;
			}
		}
		Drawing::Font^font = gcnew Drawing::Font("Arial", 14);
		SolidBrush^brush = gcnew SolidBrush(Color::Gold);
		float a = tiempo * 1.0 / 1000;
		g->DrawString("Tiempo : ", font, brush, g->VisibleClipBounds.Width - 300, 10);
		g->DrawString(Convert::ToString(a), font, brush, g->VisibleClipBounds.Width - 200, 10);
		g->DrawString("Vidas : ", font, brush, g->VisibleClipBounds.Width - 300, 30);
		g->DrawString(Convert::ToString(jugador->Getvida()), font, brush, g->VisibleClipBounds.Width - 200, 30);
		g->DrawString("Gold : ", font, brush, g->VisibleClipBounds.Width - 300, 50);
		g->DrawString(Convert::ToString(jugador->Getgold()), font, brush, g->VisibleClipBounds.Width - 200, 50);
		g->DrawString("Disparar:: Q ", font, brush, g->VisibleClipBounds.Width - 400, 70);
		g->DrawString("Comprar Torre:: W ", font, brush, g->VisibleClipBounds.Width - 400, 90);
		g->DrawString("Desplegar Torre:: E", font, brush, g->VisibleClipBounds.Width - 400, 110);
		g->DrawString("Salir:: O", font, brush, g->VisibleClipBounds.Width - 400, 130);
		jugador->Mostrar(g);
		for (int i = 0; i < jugador->gettorres()->darn(); i++)
		{
			jugador->gettorres()->Getpos(i)->valor->Mostrar(g);
		}
		for (int i = 0; i < enemigos->darn(); i++)
		{
			enemigos->Getpos(i)->valor->Mostrar(g);
		}
		for (int i = 0; i < jugador->getProyectiles()->darn(); i++)
		{
			jugador->getProyectiles()->Getpos(i)->valor->Mostrar(g);
		}
		for (int i = 0; i < jugador->gettorres()->darn(); i++)
		{
			for (int j = 0; j < jugador->gettorres()->Getpos(i)->valor->getProyectiles()->darn(); j++)
			{
				jugador->gettorres()->Getpos(i)->valor->getProyectiles()->Getpos(j)->valor->Mostrar(g);
			}
		}
		for (int e = 0; e < enemigos->darn(); e++)
		{
			for (int i = 0; i < jugador->gettorres()->darn(); ++i)
			{
				for (int j = 0; j < jugador->gettorres()->Getpos(i)->valor->getProyectiles()->darn(); j++)
				{
					if (Colisión<CProyectil*, CEnemigo*>(jugador->gettorres()->Getpos(i)->valor->getProyectiles()->Getpos(j)->valor, enemigos->Getpos(e)->valor))
					{
						enemigos->Getpos(e)->valor->Setvida(enemigos->Getpos(e)->valor->Getvida() - 1);//colision balas torre enemigos
						jugador->gettorres()->Getpos(i)->valor->getProyectiles()->eliminarenposición(j);
						j = jugador->gettorres()->Getpos(i)->valor->getProyectiles()->darn() + 1;
					}
				}
			}
			for (int i = 0; i < jugador->getProyectiles()->darn(); ++i)
			{
				if (Colisión<CProyectil*, CEnemigo*>(jugador->getProyectiles()->Getpos(i)->valor, enemigos->Getpos(e)->valor))
				{
					enemigos->Getpos(e)->valor->Setvida(enemigos->Getpos(e)->valor->Getvida() - 1);//colision bala jugador enemigos
					jugador->getProyectiles()->eliminarenposición(i);
					i = jugador->getProyectiles()->darn() + 1;

				}
			}
		}
		if (jugador->Getvida() <= 0)
		{
			esto->Close();
		}
	}
	void Guardar(int saven)
	{
		vector<string>cadenas;
		auto devolverstring = [&](int saven)
		{
			if (saven == 1)
			{
				cadenas.push_back("Slot1generalGame.txt");
				cadenas.push_back("Slot1torretas.txt");
			}
			else
				if (saven == 2)
				{
					cadenas.push_back("Slot2generalGame.txt");
					cadenas.push_back("Slot2torretas.txt");
				}
				else
					if (saven == 3)
					{
						cadenas.push_back("Slot3generalGame.txt");
						cadenas.push_back("Slot3torretas.txt");
					}
		};
		devolverstring(saven);
		ofstream archivo;
		archivo.open(cadenas.at(0), ios::out);
		if (archivo.is_open())
		{
			archivo << jugador->Getgold() << " " << jugador->Getvida() << " " << tiempo << endl;
		}
		archivo.close();

		ofstream archivo2;
		archivo2.open(cadenas.at(1), ios::out);
		if (archivo2.is_open())
		{
			for (int i = 0; i < jugador->gettorres()->darn(); i++)
			{
				archivo2 << jugador->gettorres()->Getpos(i)->valor->Getvida() << " " <<
					jugador->gettorres()->Getpos(i)->valor->Getindy() << " " <<
					jugador->gettorres()->Getpos(i)->valor->Getx() << " " <<
					jugador->gettorres()->Getpos(i)->valor->Gety() << endl;
			}
		}
		archivo2.close();
	}
	void Cargar(int saven)
	{
		vector<string>cadenas;
		auto devolverstring = [&](int saven)
		{
			if (saven == 1)
			{
				cadenas.push_back("Slot1generalGame.txt");
				cadenas.push_back("Slot1torretas.txt");
			}
			else
				if (saven == 2)
				{
					cadenas.push_back("Slot2generalGame.txt");
					cadenas.push_back("Slot2torretas.txt");
				}
				else
					if (saven == 3)
					{
						cadenas.push_back("Slot3generalGame.txt");
						cadenas.push_back("Slot3torretas.txt");
					}
		};
		devolverstring(saven);
		ifstream archivo;
		archivo.open(cadenas.at(0), ios::in);
		int a, b, c;
		if (archivo.is_open())
		{
			while (!archivo.eof())
			{
				archivo >> a >> b >> c;
				if (!archivo.eof())
				{
					archivo >> a >> b >> c;
					cout << endl;
				}
			}
		}
		archivo.close();
		jugador->Setgold(a); jugador->Setvida(b); tiempo = c;

		ifstream archivo2;
		archivo2.open(cadenas.at(1), ios::in);
		int a1, b2, c3, d4;
		if (archivo2.is_open())
		{
			while (!archivo2.eof())
			{
				archivo2 >> a1 >> b2 >> c3 >> d4;
				CTorre*niu = new CTorre(b2);
				niu->Setvida(a1);
				niu->Modificarcoordenadas(c3, d4);
				jugador->gettorres()->insertarenalinicio(niu);
			}
		}
		archivo2.close();
	}
	void CrearEnemigo(int x_, int y_)
	{
		if (enemigos->darn() <= 10)
		{
			CEnemigo*niu = new CEnemigo(x_, y_);
			enemigos->insertarenalinicio(niu);
		}
	}
	void Setdireccion(Keys k_)
	{
		jugador->Setk(k_);
	}
	void Settiempo(int tiempo_)
	{
		tiempo = tiempo_;
	}
	int Gettiempo()
	{
		return tiempo;
	}
};
