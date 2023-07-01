#pragma once
//#include "frmPrincipal.h"

#include "frmPrincipal.h"
namespace SistemaMonitoreoRemotoQuebradasView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaMonitoreoRemotoQuebradasController;
	using namespace SistemaMonitoreoRemotoQuebradasModel;

	/// <summary>
	/// Resumen de login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
	public:
		login(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->usuarioLogeado = gcnew Usuario();
		}
		login(Usuario^ objUsuarioLogeado)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->usuarioLogeado = objUsuarioLogeado;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;

	private: Usuario^ usuarioLogeado;



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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(193, 182);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Iniciar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &login::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(71, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Usuario (N° DNI):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(96, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Contraseña:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(167, 60);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(147, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(167, 107);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(147, 20);
			this->textBox2->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(341, 182);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 41);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Iniciar solo visualizacion";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &login::button2_Click);
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(453, 235);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"login";
			this->Text = L"login";
			this->Load += gcnew System::EventHandler(this, &login::login_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &login::login_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*Accion Boton logeo*/
		UsuarioController^ objUsuarioController = gcnew UsuarioController();
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (this->textBox1->Modified) {
			int codigoUsuario = Convert::ToInt32(this->textBox1->Text);
			String^ password = this->textBox2->Text;		
			Usuario^ objUsuario = objUsuarioController->buscarXCodigo(codigoUsuario);

			if (objUsuario->getPassword() == password) {
				MessageBox::Show("Acceso correcto - Bienvenido: " + objUsuario->getNombre());
				this->usuarioLogeado->setNombre(objUsuario->getNombre());
				this->usuarioLogeado->setApellido(objUsuario->getApellido());
				this->usuarioLogeado->setCodigo(objUsuario->getCodigo());
				this->usuarioLogeado->setNivelAcceso(objUsuario->getNivelAcceso());
				this->usuarioLogeado->setPassword(objUsuario->getPassword());
				//this->Close();

				frmPrincipal^ ventanaPrincipal = gcnew frmPrincipal(usuarioLogeado);
				this->Hide();
				ventanaPrincipal->Show();
				//this->Show(); 
			}
			else if (objUsuario->getCodigo() != 0) {
				MessageBox::Show("Contraseña incorrecta");
				//this->textBox1->Clear();
				this->textBox2->Clear();
			}
			else {
				MessageBox::Show("No se reconoce Usuario");
				this->textBox1->Clear();
				this->textBox2->Clear();

			}
		}
		else {
			MessageBox::Show("No se reconocen credenciales");
			this->textBox1->Clear();
			this->textBox2->Clear();
		}
		
		
	}
private: System::Void login_Load(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Usuario^ usuarioVisualizador = objUsuarioController->buscarXCodigo(1);
	usuarioVisualizador->setNombre("Visualizador");
	this->usuarioLogeado->setNombre(usuarioVisualizador->getNombre());
	this->usuarioLogeado->setApellido(usuarioVisualizador->getApellido());
	this->usuarioLogeado->setCodigo(usuarioVisualizador->getCodigo());
	this->usuarioLogeado->setNivelAcceso(usuarioVisualizador->getNivelAcceso());
	this->usuarioLogeado->setPassword(usuarioVisualizador->getPassword());
	frmPrincipal^ ventanaPrincipal = gcnew frmPrincipal(usuarioLogeado);
	this->Hide();
	ventanaPrincipal->Show();
	
}
private: System::Void login_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
}
};
}
