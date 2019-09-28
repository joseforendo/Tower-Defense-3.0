#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
class CEnemigo
{
private:
	int x, y, delta, ancho, alto;
	int indx;
	int vida;
public:
	int resultadomovimiento()
	{
		return delta;
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
	CEnemigo(int x_, int y_)
	{
		vida = 7;
		ancho = alto = 46;
		x = x_ - ancho;
		y = y_;
		delta = 2;
		indx = 0;
	}
	void Mostrar(Graphics^g)
	{
		Bitmap^b = gcnew Bitmap("enemigo.png");
		Rectangle CanvasMichael = Rectangle(indx*ancho, 0, ancho, alto);
		g->DrawImage(b, x, y, CanvasMichael, GraphicsUnit::Pixel);
		indx++;
		if (indx > 5)
			indx = 0;
		delete b;
	}
	void Mover(Graphics^g)
	{
		if (x - delta < 0)
			delta = 0;
		x -= delta;
	}
};
