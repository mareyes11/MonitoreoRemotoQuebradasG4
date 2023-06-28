#pragma once
#include "frmCrearQuebrada.h"
#include "frmEditarQuebrada.h"

namespace SistemaMonitoreoRemotoQuebradasView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaMonitoreoRemotoQuebradasModel;
	using namespace SistemaMonitoreoRemotoQuebradasController;
	/// <summary>
	/// Resumen de frmMantQuebrada
	/// </summary>
	public ref class frmMantQuebrada : public System::Windows::Forms::Form
	{
	public:
		frmMantQuebrada(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantQuebrada()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;






	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;






	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;







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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(539, 94);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de busqueda";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(377, 33);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Limpiar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantQuebrada::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(458, 33);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantQuebrada::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(251, 35);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &frmMantQuebrada::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(79, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(224, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ID:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->Location = System::Drawing::Point(12, 126);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(656, 183);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Resultados";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(328, 315);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Nuevo";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantQuebrada::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(409, 315);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Editar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantQuebrada::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(490, 315);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Eliminar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmMantQuebrada::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(592, 315);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 10;
			this->button6->Text = L"Cancelar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &frmMantQuebrada::button6_Click);
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Fecha de creacion";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Radio de extension";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Ubicacion Y";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Ubicacion X";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Nombre";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Codigo";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column6, this->Column5
			});
			this->dataGridView1->GridColor = System::Drawing::SystemColors::MenuHighlight;
			this->dataGridView1->Location = System::Drawing::Point(6, 19);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(644, 150);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmMantQuebrada::dataGridView1_CellContentClick);
			// 
			// frmMantQuebrada
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(679, 355);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantQuebrada";
			this->Text = L"Mantenimiento de Quebradas";
			this->Load += gcnew System::EventHandler(this, &frmMantQuebrada::frmMantQuebrada_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Clear();
	textBox2->Clear();
}
	   //Boton buscar
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ quebradaBuscarNombre = this->textBox1->Text;
	String^ quebradaBuscarId = this->textBox2->Text;
	QuebradaController^ objQuebradaController = gcnew QuebradaController();
	List<Quebrada^>^ listaQuebradas = objQuebradaController->buscarQuebradasxNombxId(quebradaBuscarNombre, quebradaBuscarId);
	/*Ahora voy a mostrar las quebradas encontradas en la grilla*/
	mostrarGrilla(listaQuebradas);
}
private: void mostrarGrilla(List<Quebrada^>^ listaQuebradas) {
	this->dataGridView1->Rows->Clear();
	int final = listaQuebradas->Count;
	for (int i = 0; i < final; i++) {
		 Quebrada^ objQuebrada = listaQuebradas[i];
		 array<String^>^ filaQuebrada = gcnew array<String^>(6);
		 filaQuebrada[0] = Convert::ToString(objQuebrada->getCodigo());
		 filaQuebrada[1] = objQuebrada->getNombre();
		 filaQuebrada[2] = Convert::ToString(objQuebrada->getPosicionX());
		 filaQuebrada[3] = Convert::ToString(objQuebrada->getPosicionY());
		 filaQuebrada[4] = Convert::ToString(objQuebrada->getRadioExtension());
		 filaQuebrada[5] = objQuebrada->getFechaCreacion();
		 this->dataGridView1->Rows->Add(filaQuebrada);
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		frmCrearQuebrada^ ventanaCrearQuebrada = gcnew frmCrearQuebrada;
		ventanaCrearQuebrada->ShowDialog();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int codigoQuebradaEliminar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());
		QuebradaController^ objQuebradaController = gcnew QuebradaController();
		objQuebradaController->eliminarQuebrada(codigoQuebradaEliminar);
		List<Quebrada^>^ ListaActualizada = objQuebradaController->buscarTodasQuebradas();
		mostrarGrilla(ListaActualizada);
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void frmMantQuebrada_Load(System::Object^ sender, System::EventArgs^ e) {
	QuebradaController^ objQuebradaController = gcnew QuebradaController();
	List<Quebrada^>^ listaTodasQuebradas = objQuebradaController->buscarTodasQuebradas();
	mostrarGrilla(listaTodasQuebradas);
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
	int codigoQuebradaEditar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());
	QuebradaController^ objQuebradaController = gcnew QuebradaController();
	Quebrada^ QuebradaEncontrada = objQuebradaController->buscarQuebradaXCodigo(codigoQuebradaEditar);
	frmEditarQuebrada^ ventanaEditarQuebrada = gcnew frmEditarQuebrada(QuebradaEncontrada);
	ventanaEditarQuebrada->ShowDialog();
	}
};
}
