#pragma once
#include "CManejador.h"
namespace CastleDefense {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class Game : public System::Windows::Forms::Form
	{
	private:
		Graphics^g;
		BufferedGraphicsContext^context;
		BufferedGraphics^buffer;
		CManejador*manejador;
		int saven;
		int newgame;
	public:
		Game(int saven_, int newgame_)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(g, this->ClientRectangle);
			manejador = new CManejador(g);
			saven = saven_;
			newgame = newgame_;
		}
	protected:
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Game::timer1_Tick);
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1360, 788);
			this->Cursor = System::Windows::Forms::Cursors::Cross;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Game";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Game_Load(System::Object^  sender, System::EventArgs^  e)
	{
		timer1->Interval = 50;
		timer1->Enabled = true;
		if (newgame == 0)
		{
			manejador->Cargar(saven);
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		Bitmap^mapa = gcnew Bitmap("mapa2.png");
		Random x;
		manejador->Settiempo(manejador->Gettiempo() + 50);
		Rectangle map = Rectangle(0, 0, buffer->Graphics->VisibleClipBounds.Width, buffer->Graphics->VisibleClipBounds.Height);
		buffer->Graphics->DrawImage(mapa, 0, 0, map, GraphicsUnit::Pixel);
		manejador->CrearEnemigo(buffer->Graphics->VisibleClipBounds.Width, x.Next(0, g->VisibleClipBounds.Height - 80));
		manejador->MovimientoGeneral(buffer->Graphics,this);
		manejador->Guardar(saven);
		buffer->Render(g);
	}
	private: System::Void Game_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (e->KeyData == Keys::O)
		{
			timer1->Enabled = false;
			this->Close();
		}
		manejador->Setdireccion(e->KeyData);
	}
	private: System::Void Game_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		manejador->Setdireccion(Keys::Space);
	}
	};
}
