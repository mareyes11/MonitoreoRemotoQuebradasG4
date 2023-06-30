#pragma once

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
	/// Resumen de instalarNodoMonitoreo
	/// </summary>
	public ref class frmInstalarNodoMonitoreo : public System::Windows::Forms::Form
	{
	public:
		frmInstalarNodoMonitoreo(void)
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
		~frmInstalarNodoMonitoreo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::GroupBox^ groupBox3;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::IO::Ports::SerialPort^ serialPort1;


	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;


	private: System::Windows::Forms::Label^ label6;


	private: System::Windows::Forms::Label^ labelTemperatura;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ labelHumedad;
	private: System::Windows::Forms::ProgressBar^ progressBarHumedad;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ labelRawData;
	private: System::Windows::Forms::TrackBar^ trackBarTemperatura;
	private: System::Windows::Forms::CheckBox^ checkBoxLluvia;



	private: System::ComponentModel::IContainer^ components;

		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxLluvia = (gcnew System::Windows::Forms::CheckBox());
			this->labelTemperatura = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->trackBarTemperatura = (gcnew System::Windows::Forms::TrackBar());
			this->labelHumedad = (gcnew System::Windows::Forms::Label());
			this->progressBarHumedad = (gcnew System::Windows::Forms::ProgressBar());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->labelRawData = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarTemperatura))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(11, 64);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(426, 107);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del Nodo";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->Location = System::Drawing::Point(294, 30);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 15);
			this->label5->TabIndex = 9;
			this->label5->Text = L"idNodo ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(228, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"ID del Nodo:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(269, 70);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(69, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(180, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Ubicacion Y (Px):";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(98, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(59, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Ubicacion X (Px):";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(72, 27);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(150, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Quebrada: ";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button1);
			this->groupBox3->Controls->Add(this->pictureBox1);
			this->groupBox3->Location = System::Drawing::Point(7, 177);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->groupBox3->Size = System::Drawing::Size(429, 286);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Previsualizacion";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F));
			this->button1->Location = System::Drawing::Point(28, 34);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 24);
			this->button1->TabIndex = 1;
			this->button1->Text = L"TEST ALARMA";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(7, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(420, 261);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBoxLluvia);
			this->groupBox2->Controls->Add(this->labelTemperatura);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->trackBarTemperatura);
			this->groupBox2->Controls->Add(this->labelHumedad);
			this->groupBox2->Controls->Add(this->progressBarHumedad);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Location = System::Drawing::Point(7, 469);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(432, 113);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Data sensores";
			this->groupBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmInstalarNodoMonitoreo::groupBox2_Paint);
			// 
			// checkBoxLluvia
			// 
			this->checkBoxLluvia->AutoCheck = false;
			this->checkBoxLluvia->AutoSize = true;
			this->checkBoxLluvia->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->checkBoxLluvia->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->checkBoxLluvia->Location = System::Drawing::Point(102, 19);
			this->checkBoxLluvia->Name = L"checkBoxLluvia";
			this->checkBoxLluvia->Size = System::Drawing::Size(105, 17);
			this->checkBoxLluvia->TabIndex = 18;
			this->checkBoxLluvia->Text = L"Lluvia detectada";
			this->checkBoxLluvia->UseVisualStyleBackColor = false;
			// 
			// labelTemperatura
			// 
			this->labelTemperatura->AutoSize = true;
			this->labelTemperatura->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelTemperatura->Location = System::Drawing::Point(39, 48);
			this->labelTemperatura->Name = L"labelTemperatura";
			this->labelTemperatura->Size = System::Drawing::Size(32, 15);
			this->labelTemperatura->TabIndex = 10;
			this->labelTemperatura->Text = L"temp";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->label9->Location = System::Drawing::Point(39, 83);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 9);
			this->label9->TabIndex = 11;
			this->label9->Text = L"-20°C";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->label8->Location = System::Drawing::Point(39, 16);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(26, 9);
			this->label8->TabIndex = 10;
			this->label8->Text = L"100°C";
			// 
			// trackBarTemperatura
			// 
			this->trackBarTemperatura->Enabled = false;
			this->trackBarTemperatura->Location = System::Drawing::Point(7, 16);
			this->trackBarTemperatura->Maximum = 100;
			this->trackBarTemperatura->Minimum = -20;
			this->trackBarTemperatura->Name = L"trackBarTemperatura";
			this->trackBarTemperatura->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarTemperatura->Size = System::Drawing::Size(45, 78);
			this->trackBarTemperatura->SmallChange = 10;
			this->trackBarTemperatura->TabIndex = 2;
			this->trackBarTemperatura->TickFrequency = 10;
			// 
			// labelHumedad
			// 
			this->labelHumedad->AutoSize = true;
			this->labelHumedad->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelHumedad->Location = System::Drawing::Point(155, 96);
			this->labelHumedad->Name = L"labelHumedad";
			this->labelHumedad->Size = System::Drawing::Size(29, 15);
			this->labelHumedad->TabIndex = 14;
			this->labelHumedad->Text = L"hum";
			// 
			// progressBarHumedad
			// 
			this->progressBarHumedad->Location = System::Drawing::Point(102, 72);
			this->progressBarHumedad->Name = L"progressBarHumedad";
			this->progressBarHumedad->Size = System::Drawing::Size(113, 20);
			this->progressBarHumedad->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBarHumedad->TabIndex = 12;
			this->progressBarHumedad->Value = 50;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->label11->Location = System::Drawing::Point(189, 58);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(26, 11);
			this->label11->TabIndex = 15;
			this->label11->Text = L"100%";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->label12->Location = System::Drawing::Point(101, 58);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(18, 11);
			this->label12->TabIndex = 16;
			this->label12->Text = L"0%";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(99, 96);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(56, 13);
			this->label14->TabIndex = 13;
			this->label14->Text = L"Humedad:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1, 97);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(67, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Temperatura";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(280, 588);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 25);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Instalar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(367, 588);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 25);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Cancelar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::button3_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->comboBox2);
			this->groupBox4->Controls->Add(this->button4);
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Location = System::Drawing::Point(11, 9);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(426, 54);
			this->groupBox4->TabIndex = 10;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Conexion";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(85, 18);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(133, 21);
			this->comboBox2->TabIndex = 11;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::comboBox2_SelectedIndexChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(232, 18);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(89, 22);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Conectar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::button4_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(14, 22);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(67, 13);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Puerto Serial";
			// 
			// serialPort1
			// 
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &frmInstalarNodoMonitoreo::serialPort1_DataReceived);
			// 
			// labelRawData
			// 
			this->labelRawData->AutoSize = true;
			this->labelRawData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelRawData->Location = System::Drawing::Point(9, 594);
			this->labelRawData->Name = L"labelRawData";
			this->labelRawData->Size = System::Drawing::Size(63, 15);
			this->labelRawData->TabIndex = 17;
			this->labelRawData->Text = L"tramaDatos";
			// 
			// frmInstalarNodoMonitoreo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(448, 620);
			this->Controls->Add(this->labelRawData);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmInstalarNodoMonitoreo";
			this->Text = L"Instalacion de nodo de monitoreo";
			this->Load += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::frmInstalarNodoMonitoreo_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarTemperatura))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		if (conectado)
			serialPort1->Close();
	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	
		   List<Quebrada^>^ quebradasDisponibles;
		   QuebradaController^ objQuebradaConrtoller = gcnew QuebradaController();
	private: System::Void frmInstalarNodoMonitoreo_Load(System::Object^ sender, System::EventArgs^ e) {
		array<String^>^ listaPuertos = serialPort1->GetPortNames();
		this->comboBox2->Items->Clear();
		for (int i = 0; i < listaPuertos->Length; i++) {
			this->comboBox2->Items->Add(listaPuertos[i]);
		}
		
		quebradasDisponibles = objQuebradaConrtoller->buscarTodasQuebradas();
		this->comboBox1->Items->Clear(); /*Borra todos los valores que tenga el combo box*/
		for (int i = 0; i < quebradasDisponibles->Count; i++) {
			this->comboBox1->Items->Add(quebradasDisponibles[i]->getNombre());
		}
		NodosController^ objNodoController = gcnew NodosController();

		this->pictureBox1->Image = nullptr;
		this->pictureBox1->Image = this->pictureBox1->Image->FromFile("1.jpg");
	}

	Boolean conectado = false;
	Boolean alarma_test = false;

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!conectado) {
			String^ comName = this->comboBox2->Text;
			serialPort1->PortName = comName;
			serialPort1->BaudRate = 38400;
			serialPort1->Open();
		if (serialPort1->IsOpen) {
			button4->Text = "Desconectar";
			conectado = true;
			}
			
		}
		else if (conectado) {
			serialPort1->Close();
			button4->Text = "Conectar";
			conectado = false;
		}
		

	
	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
	String^ codigoQuebradaSeleccionada = Convert::ToString(quebradasDisponibles[this->comboBox1->SelectedIndex]->getCodigo());
	this->pictureBox1->Image = nullptr;
	this->pictureBox1->Image = this->pictureBox1->Image->FromFile(codigoQuebradaSeleccionada + ".jpg");


}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (conectado && !alarma_test) {
		serialPort1->WriteLine("ALRM_on");
		alarma_test = true;
		this->button1->Text = "APAGAR ALARMA";
	}
	else if(conectado) {
		serialPort1->WriteLine("ALRM_off");
		this->button1->Text = "TEST ALARMA";
		alarma_test = false;
	}
}
	   array<String^>^ datosSeparados;
	   String^ lectura;
private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
	lectura = serialPort1->ReadLine();
	String^ separador = " ";
	datosSeparados = lectura->Split(separador->ToCharArray());
	this->groupBox2->Invalidate();
	/*Salida datos serial :
	nodoID | incX_deg | incY_deg | accX_g | accY_g | accZ_g | tBMP_degC | pBMP_Pa | hSoil_per | rain | alarm */
	//=progressBarHumedad->Value = Convert::ToInt32(datosSeparados[8]);
	
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void groupBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	if (conectado) {
		this->labelRawData->Text = lectura;
		this->progressBarHumedad->Value = Convert::ToInt32(datosSeparados[8]) * 100 / 1024;
		this->labelHumedad->Text = Convert::ToString(Convert::ToInt32(datosSeparados[8]) * 100 / 1024) + "%";
		this->labelTemperatura->Text = Convert::ToString(datosSeparados[6]) + "°C";
		this->trackBarTemperatura->Value = Convert::ToDouble(datosSeparados[6]);
		if (Convert::ToInt32(datosSeparados[9]) == 1) {
			this->checkBoxLluvia->Checked = true;
		}
		else this->checkBoxLluvia->Checked = false;
	}
	

}
};
}
