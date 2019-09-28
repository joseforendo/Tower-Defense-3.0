#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
#include <ctime>
class CTorre
{
private:
	int x, y, ancho, alto;
	int indy, indx;
	int vida;
	CLista<CProyectil*>* proyectiles;
public:
	CTorre(int indy_)
	{
		proyectiles = new CLista<CProyectil*>();
		indy = indy_;
		indx = 0;
		ancho = alto = 100;
		x = 0;
		y = 0;
		vida = 40;
	}
	CLista<CProyectil*>* getProyectiles()
	{
		return proyectiles;
	}
	int Getindy()
	{
		return indy;
	}
	void Modificarcoordenadas(int x_, int y_)
	{
		x = x_;
		y = y_;
	}
	void Mostrar(Graphics^g)
	{
		if (proyectiles->darn() < 4)
		{
			int auxx = x + 15;
			int auxy = y + rand() % alto;
			int deltax = 30;
			int deltay = 0;
			int spritetype = 2;
			CProyectil*niu = new CProyectil(auxx, auxy, deltax, deltay, spritetype);
			proyectiles->insertarenalinicio(niu);
		}
		if (vida >= 0 && vida < 10)
		{
			indx = 3;
		}
		if (vida >= 10 && vida < 20)
		{
			indx = 2;
		}
		if (vida >= 20 && vida < 30)
		{
			indx = 1;
		}
		if (vida >= 30 && vida < 40)
		{
			indx = 0;
		}
		Bitmap^b = gcnew Bitmap("TORRES.png");
		Rectangle CanvasMichael = Rectangle(indx*ancho, indy*alto, ancho, alto);
		/*g->DrawRectangle(Pens::LightBlue,x, y, 100,100);*/
		g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
		delete b;
	}
	int Getx()
	{
		return x;
	}
	int Gety()
	{
		return y;
	}
	int Getancho()
	{
		return ancho;
	}
	int Getalto()
	{
		return alto;
	}
	void Setvida(int vida_)
	{
		vida = vida_;
	}
	int Getvida()
	{
		return vida;
	}
};
