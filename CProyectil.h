#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
class CProyectil
{
private:
	int x, y, ancho, alto, deltax, deltay;
	int spritetype;
public:
	CProyectil(int x_, int y_, int deltax_, int deltay_, int spritetype_)
	{
		x = x_;
		y = y_;
		deltax = deltax_;
		deltay = deltay_;
		spritetype = spritetype_;
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
	void Mostrar(Graphics^g)
	{
		if (spritetype == 1)
		{
			ancho = 5;
			alto = 8;
			Bitmap^b = gcnew Bitmap("bulletarriba.png");
			Rectangle CanvasMichael = Rectangle(0, 0, ancho, alto);
			g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
			delete b;
		}
		if (spritetype == 2)
		{
			ancho = 8;
			alto = 5;
			Bitmap^b = gcnew Bitmap("bulletderecha.png");
			Rectangle CanvasMichael = Rectangle(0, 0, ancho, alto);
			g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
			delete b;
		}
	}
	void Mover(Graphics^g)
	{
		if (x + deltax <= 10 || x + deltax + ancho >= g->VisibleClipBounds.Width - 10 || y + deltay <= 10 || y + deltay + alto >= g->VisibleClipBounds.Height - 10)
		{
			deltax = 0;
			deltay = 0;
		}
		else
		{
			x += deltax;
			y += deltay;
		}
	}
	int resultadomovimiento()
	{
		if (deltax == 0 && deltay == 0)
			return 0;
		else
			return 1;
	}
};
