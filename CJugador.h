#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
#include <ctime>
#include "CLista.h"
#include "CProyectil.h"
#include "CTorre.h"
#include "CPila.h"
class CJugador
{
private:
	int x, y, delta, ancho, alto;
	int vida;
	int indx;
	int dirección, ultimatecla;
	Keys keyDireccion;
	int gold;
	CLista<CProyectil*>* proyectiles;
	CPila<CTorre*>* torresenhangar;
	CLista<CTorre*>* torreenmapa;
public:
	CJugador(Graphics^g)
	{
		srand(time(NULL));
		proyectiles = new CLista<CProyectil*>();
		torresenhangar = new CPila<CTorre*>();
		torreenmapa = new CLista<CTorre*>();
		x = g->VisibleClipBounds.Width / 2;
		y = g->VisibleClipBounds.Height / 2;
		ancho = alto = 40;
		delta = 30;
		indx = 0;
		keyDireccion = Keys::Space;
		dirección = 8;
		ultimatecla = 8;
		vida = 30;
		gold = 2000;
	}
	void Setvida(int vida_)
	{
		vida = vida_;
	}
	int Getvida()
	{
		return vida;
	}
	void Setgold(int gold_)
	{
		gold = gold_;
	}
	int Getgold()
	{
		return gold;
	}
	CLista<CProyectil*>* getProyectiles()
	{
		return proyectiles;
	}
	CLista<CTorre*>* gettorres()
	{
		return torreenmapa;
	}
	void Mostrar(Graphics^g)
	{
		Bitmap^b = gcnew Bitmap("jugador.png");
		switch (dirección)
		{
		case 8:
		{
			indx = 0;
			Rectangle CanvasMichael = Rectangle(indx*ancho, 0, ancho, alto);
			g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
			break;
		}
		case 2:
		{indx = 2;
		Rectangle CanvasMichael = Rectangle(indx*ancho, 0, ancho, alto);
		g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
		break; }
		case 4:
		{indx = 3;
		Rectangle CanvasMichael = Rectangle(indx*ancho, 0, ancho, alto);
		g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
		break; }
		case 6:
		{indx = 1;
		Rectangle CanvasMichael = Rectangle(indx*ancho, 0, ancho, alto);
		g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
		break; }
		case 0:
			switch (ultimatecla)
			{
			case 8:
			{	indx = 0;
			Rectangle CanvasMichael = Rectangle(indx*ancho, 0, ancho, alto);
			g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
			break; }
			case 2:
			{indx = 2;
			Rectangle CanvasMichael = Rectangle(indx*ancho, 0, ancho, alto);
			g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
			break; }
			case 4:
			{indx = 3;
			Rectangle CanvasMichael = Rectangle(indx*ancho, 0, ancho, alto);
			g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
			break; }
			case 6:
			{indx = 1;
			Rectangle CanvasMichael = Rectangle(indx*ancho, 0, ancho, alto);
			g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
			break; }
			}
			break;
		}
		delete b;
	}
	void Mover(Graphics^g)
	{
		switch (keyDireccion)
		{
		case::Keys::Q:
		{
			if (proyectiles->darn() <= 50)
			{
				int auxx, auxy, deltax, deltay, spritetype;
				if (ultimatecla == 8)
				{
					auxx = x + rand() % ancho;
					auxy = y + 30;
					deltax = 0;
					deltay = -30;
					spritetype = 1;
				}
				else
					if (ultimatecla == 2)
					{
						auxx = x + rand() % ancho;
						auxy = y + 15;
						deltax = 0;
						deltay = 30;
						spritetype = 1;
					}
					else
						if (ultimatecla == 4)
						{
							auxx = x + 30;
							auxy = y + rand() % alto;
							deltax = -30;
							deltay = 0;
							spritetype = 2;
						}
						else
							if (ultimatecla == 6)
							{
								auxx = x + 15;
								auxy = y + rand() % alto;
								deltax = 30;
								deltay = 0;
								spritetype = 2;
							}
				CProyectil*niu = new CProyectil(auxx, auxy, deltax, deltay, spritetype);
				proyectiles->insertarenalinicio(niu);
			}
			break;
		}
		case Keys::W:
		{
			if (gold >= 1000)
			{
				gold -= 1000;
				int randsprite = rand() % 4;
				CTorre*niu = new CTorre(randsprite);
				torresenhangar->insertarenalinicio(niu);
			}
			break;
		}
		case Keys::E:
		{
			auto poner_torre = [&]()
			{
				if (torresenhangar->darn() > 0)
				{
					int auxx = 0;
					int auxy = 0;
					auxx = x - (x % 100);
					if (auxx < 300)
						auxx = 300;
					auxy = y - (y % 100);
					if (auxy > 600)
						auxy = 600;
					auxy += 30;
					torresenhangar->Getprimero()->valor->Modificarcoordenadas(auxx, auxy);
					torreenmapa->insertarenalinicio(torresenhangar->eliminaralinicio());
					keyDireccion = Keys::Right;
				}
			};
			poner_torre();
			break;
		}
		case Keys::Up:
		{
			if (y - delta > 0)
			{
				y -= delta;
			}
			dirección = 8;
			ultimatecla = 8;
			break;
		}
		case Keys::Down:
		{
			if (y + delta + alto < g->VisibleClipBounds.Height)
			{
				y += delta;
			}
			dirección = 2;
			ultimatecla = 2;
			break;
		}
		case Keys::Left:
		{
			if (x - delta > 0)
			{
				x -= delta;
			}
			dirección = 4;
			ultimatecla = 4;
			break;
		}
		case Keys::Right:
		{
			if (x + delta + ancho < g->VisibleClipBounds.Width)
			{
				x += delta;
			}
			dirección = 6;
			ultimatecla = 6;
			break;
		}
		case Keys::Space:
		{
			dirección = 0;
			break;
		}
		}
	}
	int Getx()
	{
		return x;
	}
	void Setx(int x_)
	{
		x = x_;
	}
	int Gety()
	{
		return y;
	}
	void Sety(int y_)
	{
		y = y_;
	}
	void Setk(Keys keyDireccion_)
	{
		keyDireccion = keyDireccion_;
	}
};
