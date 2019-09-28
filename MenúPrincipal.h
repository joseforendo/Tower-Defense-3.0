#pragma once
#include "Game.h"
namespace CastleDefense {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Menúprincipal
	/// </summary>
	public ref class Menúprincipal : public System::Windows::Forms::Form
	{
	private:
		int newgame;
	public:
		Menúprincipal(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Menúprincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	protected:



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Menúprincipal::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(218, 524);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Nueva partida";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Menúprincipal::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(218, 566);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cargar partida";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Menúprincipal::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(218, 649);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(142, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Salir";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Menúprincipal::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(218, 541);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(142, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Slot1";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Menúprincipal::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(218, 582);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(142, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Slot2";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Menúprincipal::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(218, 621);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(142, 23);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Slot3";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Menúprincipal::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(218, 663);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(142, 23);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Regresar";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Menúprincipal::button7_Click);
			// 
			// Menúprincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(563, 720);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Menúprincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menúprincipal";
			this->Load += gcnew System::EventHandler(this, &Menúprincipal::Menúprincipal_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Menúprincipal_Load(System::Object^  sender, System::EventArgs^  e)
	{
		button1->Visible = true;
		button2->Visible = true;
		button3->Visible = true;
		button4->Visible = false;
		button5->Visible = false;
		button6->Visible = false;
		button7->Visible = false;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		button1->Visible = false;
		button2->Visible = false;
		button3->Visible = false;
		button4->Visible = true;
		button5->Visible = true;
		button6->Visible = true;
		button7->Visible = true;
		newgame = 1;
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		button1->Visible = false;
		button2->Visible = false;
		button3->Visible = false;
		button4->Visible = true;
		button5->Visible = true;
		button6->Visible = true;
		button7->Visible = true;
		newgame = 0;
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Game^game = gcnew Game(1, newgame);
		game->ShowDialog();
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Game^game = gcnew Game(2, newgame);
		game->ShowDialog();
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Game^game = gcnew Game(3, newgame);
		game->ShowDialog();
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		button1->Visible = true;
		button2->Visible = true;
		button3->Visible = true;
		button4->Visible = false;
		button5->Visible = false;
		button6->Visible = false;
		button7->Visible = false;
	}
	};
}
