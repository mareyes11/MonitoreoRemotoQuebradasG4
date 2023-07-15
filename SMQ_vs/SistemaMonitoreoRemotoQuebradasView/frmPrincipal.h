#pragma once
#include "frmInstalarNodoMonitoreo.h"
#include "frmMantQuebrada.h"
#include "frmMantNodos.h"
#include "frmMantUsuarios.h"
#include "frmTestNodo.h"

namespace SistemaMonitoreoRemotoQuebradasView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaMonitoreoRemotoQuebradasModel;
	using namespace SistemaMonitoreoRemotoQuebradasController;

	/// <summary>
	/// Resumen de frmPrincipal
	/// </summary>
	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	public:
		frmPrincipal(void)
		{
			InitializeComponent();
			this->objUsuarioLogeado = gcnew Usuario();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmPrincipal(Usuario^ objUsuario)
		{
			InitializeComponent();
			this->objUsuarioLogeado = objUsuario;
			//
			//TODO: agregar código de constructor aquí
			//
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStripMenuItem^ quebradasToolStripMenuItem;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ crearToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ nodoMonitoreoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ agregarNodoToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ testToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ alertasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ automaticasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ configuracionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manualesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ configuracionToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ reportesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ diarioToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ generarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ consultarToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ListBox^ listBox1;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ToolStripMenuItem^ usuariosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mantenimientoUsuariosToolStripMenuItem;

	protected:

	protected:

	private: Usuario^ objUsuarioLogeado;
	private: List<Quebrada^>^ quebradasDisponibles;
	private: QuebradaController^ objQuebradaController = gcnew QuebradaController();
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelUsuario;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmPrincipal::typeid));
			this->quebradasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->crearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nodoMonitoreoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->agregarNodoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->alertasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->automaticasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->configuracionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manualesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->configuracionToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reportesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->diarioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->consultarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->usuariosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mantenimientoUsuariosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelUsuario = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// quebradasToolStripMenuItem
			// 
			this->quebradasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->crearToolStripMenuItem });
			this->quebradasToolStripMenuItem->Name = L"quebradasToolStripMenuItem";
			this->quebradasToolStripMenuItem->Size = System::Drawing::Size(76, 20);
			this->quebradasToolStripMenuItem->Text = L"Quebradas";
			// 
			// crearToolStripMenuItem
			// 
			this->crearToolStripMenuItem->Name = L"crearToolStripMenuItem";
			this->crearToolStripMenuItem->Size = System::Drawing::Size(182, 22);
			this->crearToolStripMenuItem->Text = L"Gestionar quebradas";
			this->crearToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::crearToolStripMenuItem_Click);
			// 
			// nodoMonitoreoToolStripMenuItem
			// 
			this->nodoMonitoreoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->agregarNodoToolStripMenuItem,
					this->testToolStripMenuItem
			});
			this->nodoMonitoreoToolStripMenuItem->Name = L"nodoMonitoreoToolStripMenuItem";
			this->nodoMonitoreoToolStripMenuItem->Size = System::Drawing::Size(129, 20);
			this->nodoMonitoreoToolStripMenuItem->Text = L"Nodos de Monitoreo";
			// 
			// agregarNodoToolStripMenuItem
			// 
			this->agregarNodoToolStripMenuItem->Name = L"agregarNodoToolStripMenuItem";
			this->agregarNodoToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->agregarNodoToolStripMenuItem->Text = L"Gestionar nodos";
			this->agregarNodoToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::agregarNodoToolStripMenuItem_Click);
			// 
			// testToolStripMenuItem
			// 
			this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			this->testToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->testToolStripMenuItem->Text = L"Test";
			this->testToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::testToolStripMenuItem_Click);
			// 
			// alertasToolStripMenuItem
			// 
			this->alertasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->automaticasToolStripMenuItem,
					this->manualesToolStripMenuItem
			});
			this->alertasToolStripMenuItem->Name = L"alertasToolStripMenuItem";
			this->alertasToolStripMenuItem->Size = System::Drawing::Size(193, 20);
			this->alertasToolStripMenuItem->Text = L"Alertas fuera de valores normales";
			// 
			// automaticasToolStripMenuItem
			// 
			this->automaticasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->configuracionToolStripMenuItem });
			this->automaticasToolStripMenuItem->Name = L"automaticasToolStripMenuItem";
			this->automaticasToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->automaticasToolStripMenuItem->Text = L"Automaticas";
			// 
			// configuracionToolStripMenuItem
			// 
			this->configuracionToolStripMenuItem->Name = L"configuracionToolStripMenuItem";
			this->configuracionToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->configuracionToolStripMenuItem->Text = L"Configuracion";
			// 
			// manualesToolStripMenuItem
			// 
			this->manualesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->configuracionToolStripMenuItem1 });
			this->manualesToolStripMenuItem->Name = L"manualesToolStripMenuItem";
			this->manualesToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->manualesToolStripMenuItem->Text = L"Manuales";
			// 
			// configuracionToolStripMenuItem1
			// 
			this->configuracionToolStripMenuItem1->Name = L"configuracionToolStripMenuItem1";
			this->configuracionToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->configuracionToolStripMenuItem1->Text = L"Configuracion";
			// 
			// reportesToolStripMenuItem
			// 
			this->reportesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->diarioToolStripMenuItem });
			this->reportesToolStripMenuItem->Name = L"reportesToolStripMenuItem";
			this->reportesToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->reportesToolStripMenuItem->Text = L"Reportes";
			// 
			// diarioToolStripMenuItem
			// 
			this->diarioToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->generarToolStripMenuItem,
					this->consultarToolStripMenuItem
			});
			this->diarioToolStripMenuItem->Name = L"diarioToolStripMenuItem";
			this->diarioToolStripMenuItem->Size = System::Drawing::Size(105, 22);
			this->diarioToolStripMenuItem->Text = L"Diario";
			// 
			// generarToolStripMenuItem
			// 
			this->generarToolStripMenuItem->Name = L"generarToolStripMenuItem";
			this->generarToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->generarToolStripMenuItem->Text = L"Generar";
			// 
			// consultarToolStripMenuItem
			// 
			this->consultarToolStripMenuItem->Name = L"consultarToolStripMenuItem";
			this->consultarToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->consultarToolStripMenuItem->Text = L"Consultar";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->quebradasToolStripMenuItem,
					this->nodoMonitoreoToolStripMenuItem, this->alertasToolStripMenuItem, this->reportesToolStripMenuItem, this->usuariosToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(744, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// usuariosToolStripMenuItem
			// 
			this->usuariosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->mantenimientoUsuariosToolStripMenuItem });
			this->usuariosToolStripMenuItem->Name = L"usuariosToolStripMenuItem";
			this->usuariosToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->usuariosToolStripMenuItem->Text = L"Usuarios";
			this->usuariosToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::usuariosToolStripMenuItem_Click);
			// 
			// mantenimientoUsuariosToolStripMenuItem
			// 
			this->mantenimientoUsuariosToolStripMenuItem->Name = L"mantenimientoUsuariosToolStripMenuItem";
			this->mantenimientoUsuariosToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->mantenimientoUsuariosToolStripMenuItem->Text = L"Mantenimiento Usuarios";
			this->mantenimientoUsuariosToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::mantenimientoUsuariosToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(139, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 450);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &frmPrincipal::pictureBox1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(5, 102);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(128, 459);
			this->listBox1->TabIndex = 4;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmPrincipal::listBox1_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(5, 81);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(128, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"VISTAS";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Location = System::Drawing::Point(139, 483);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(600, 78);
			this->panel1->TabIndex = 7;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->labelUsuario);
			this->panel2->Location = System::Drawing::Point(5, 27);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(128, 48);
			this->panel2->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(37, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"USUARIO";
			// 
			// labelUsuario
			// 
			this->labelUsuario->AutoSize = true;
			this->labelUsuario->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->labelUsuario->Location = System::Drawing::Point(22, 23);
			this->labelUsuario->Name = L"labelUsuario";
			this->labelUsuario->Size = System::Drawing::Size(46, 18);
			this->labelUsuario->TabIndex = 0;
			this->labelUsuario->Text = L"label1";
			this->labelUsuario->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(744, 569);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"frmPrincipal";
			this->Text = L"Sistema de monitoreo remoto de quebradas";
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void agregarNodoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (objUsuarioLogeado->getNivelAcceso() == 1 || objUsuarioLogeado->getNivelAcceso() == 2) {
			frmMantNodos^ ventanaMantNodos = gcnew frmMantNodos;
			//ventanaInstalarNodo->MdiParent = this; //Activar para cuando se requiera que sea ventana modal, contenida y sin retorno
			ventanaMantNodos->ShowDialog();
		}
		else {
			MessageBox::Show("No tiene permisos para ingresar a esa función");
		}
	}
	
private: System::Void crearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (objUsuarioLogeado->getNivelAcceso() == 1 || objUsuarioLogeado->getNivelAcceso() == 2) {
		frmMantQuebrada^ ventanamMantQuebradas = gcnew frmMantQuebrada;
		ventanamMantQuebradas->Show();
	}
	else {
		MessageBox::Show("No tiene permisos para ingresar a esa función");
	}

	}
private: System::Void quebradasToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void nodosDeMonitoreoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	actualizaImagenQuebrada();
}
private: void actualizaImagenQuebrada() {
	String^ codigoQuebradaSeleccionada = Convert::ToString(quebradasDisponibles[this->listBox1->SelectedIndex]->getCodigo());
	this->pictureBox1->Image = nullptr;
	this->pictureBox1->Image = this->pictureBox1->Image->FromFile(codigoQuebradaSeleccionada + ".jpg");

}
private: System::Void mantenimientoUsuariosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (objUsuarioLogeado->getNivelAcceso() == 1) {
		frmMantUsuarios^ ventanaMantUsuarios = gcnew frmMantUsuarios;
		ventanaMantUsuarios->Show();
	}
	else {
		MessageBox::Show("No tiene permisos para ingresar a esa función");
	}
}
private: System::Void usuariosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void testToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	frmTestNodo^ ventanaTestNodo = gcnew frmTestNodo;
	ventanaTestNodo->Show();
}
private: System::Void frmPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	
	/*Precarga Quebradas disponibles*/
	quebradasDisponibles = this->objQuebradaController->buscarTodasQuebradas();
	this->listBox1->Items->Clear(); /*Borra todos los valores que tenga el combo box*/
	for (int i = 0; i < quebradasDisponibles->Count; i++) {
		this->listBox1->Items->Add(quebradasDisponibles[i]->getNombre());
	}
	this->listBox1->SelectedIndex = 0;//Autoseleeciona la primera de la lista de quebradas disponibles

	/*Carga la imagen correspondiente*/
	actualizaImagenQuebrada();
	this->labelUsuario->Text = this->objUsuarioLogeado->getNombre() + " " + this->objUsuarioLogeado->getApellido();
}
};
}
