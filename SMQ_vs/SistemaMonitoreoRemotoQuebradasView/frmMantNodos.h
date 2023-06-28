#pragma once
#include "frmInstalarNodoMonitoreo.h"

namespace SistemaMonitoreoRemotoQuebradasView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaMonitoreoRemotoQuebradasController;
	using namespace SistemaMonitoreoRemotoQuebradasModel;

	/// <summary>
	/// Resumen de frmMantNodos
	/// </summary>
	public ref class frmMantNodos : public System::Windows::Forms::Form
	{
	public:
		frmMantNodos(void)
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
		~frmMantNodos()
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

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox2;

	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;






	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::TextBox^ textBox1;










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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(366, 91);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Busqueda por ID";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(165, 33);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Limpiar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantNodos::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(258, 33);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantNodos::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ID:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(12, 109);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(366, 91);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Busqueda por quebrada";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(79, 35);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 6;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(258, 35);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Buscar";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Quebrada:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->dataGridView1);
			this->groupBox3->Location = System::Drawing::Point(12, 226);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(656, 183);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Resultados";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column3, this->Column4, this->Column6, this->Column2
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
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID Nodo";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Ubicacion X";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Ubicacion Y";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"ID Quebrada";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Fecha creacion";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(585, 461);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 14;
			this->button6->Text = L"Cancelar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &frmMantNodos::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(483, 461);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 13;
			this->button5->Text = L"Eliminar";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(402, 461);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(321, 461);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 11;
			this->button7->Text = L"Nuevo";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &frmMantNodos::button7_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(43, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 6;
			// 
			// frmMantNodos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(678, 501);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantNodos";
			this->Text = L"frmMantNodos";
			this->Load += gcnew System::EventHandler(this, &frmMantNodos::frmMantNodos_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void frmMantNodos_Load(System::Object^ sender, System::EventArgs^ e) {
	NodosController^ objNodosController = gcnew NodosController();
	List<NodoMonitoreo^>^ listaTodosNodos = objNodosController->buscarTodosNodos();
	mostrarGrilla(listaTodosNodos);

	QuebradaController^ objQuebradaConrtoller = gcnew QuebradaController();
	List<Quebrada^>^ listaQuebradas = objQuebradaConrtoller->buscarTodasQuebradas();
	this->comboBox1->Items->Clear(); /*Borra todos los valores que tenga el combo box*/
	for (int i = 0; i < listaQuebradas->Count; i++) {
		this->comboBox1->Items->Add(listaQuebradas[i]->getNombre());
	}
	}

private: void mostrarGrilla(List<NodoMonitoreo^>^ lista) {
	this->dataGridView1->Rows->Clear();
	int final = lista->Count;
	if (final >= 1) {
		for (int i = 0; i < final; i++) {
			NodoMonitoreo^ objQuebrada = lista[i];
			array<String^>^ filaQuebrada = gcnew array<String^>(5);
			filaQuebrada[0] = Convert::ToString(objQuebrada->getId());
			filaQuebrada[1] = Convert::ToString(objQuebrada->getPosicionX());
			filaQuebrada[2] = Convert::ToString(objQuebrada->getPosicionY());
			filaQuebrada[3] = Convert::ToString(objQuebrada->getQuebradaId());
			filaQuebrada[4] = objQuebrada->getFechaCreacion();
			this->dataGridView1->Rows->Add(filaQuebrada);
		}
	}
	

}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	frmInstalarNodoMonitoreo^ ventanaInstNodo = gcnew frmInstalarNodoMonitoreo;
	//ventanaInstalarNodo->MdiParent = this; //Activar para cuando se requiera que sea ventana modal, contenida y sin retorno
	ventanaInstNodo->ShowDialog();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBox1->Clear();
}
	   /*Boton buscar x codigo - si textbox vacio busca todos*/
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	NodosController^ objNodoController = gcnew NodosController();
	List<NodoMonitoreo^>^ listaNMTemp = objNodoController->buscarTodosNodos();
	if ((this->textBox1->Modified) && (this->textBox1->Text != "")) {
		NodoMonitoreo^ nodoEncontrado = gcnew NodoMonitoreo();
		int nodoID = Convert::ToInt32(this->textBox1->Text);
		//NodoMonitoreo^ NodoBuscado = objNodoController->buscarNodoXId(nodoID);
		nodoEncontrado = objNodoController->buscarNodoXId(nodoID);
		listaNMTemp->Clear();
		listaNMTemp->Add(nodoEncontrado);
		mostrarGrilla(listaNMTemp);
	}
	else if (this->textBox1->Text == "") {
		mostrarGrilla(listaNMTemp);
	}
	
	}
};
}
