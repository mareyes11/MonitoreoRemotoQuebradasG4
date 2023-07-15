#pragma once
#define PI 3.141592

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
	using namespace	System::Drawing;
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
	private: System::Windows::Forms::Button^ buttonCancelar;



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
	private: System::Windows::Forms::Label^ labelIncXY;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Label^ label17;

	private: burbujaNivel^ nivelInclinometro = gcnew burbujaNivel();
	private: NodoMonitoreo^ objNuevoNodo = gcnew NodoMonitoreo();
	private: List<Quebrada^>^ quebradasDisponibles;
	private: QuebradaController^ objQuebradaController = gcnew QuebradaController();
	private: NodosController^ objNodoController = gcnew NodosController();
	private: Boolean conectado = false;
	private: System::Windows::Forms::Label^ labelAltimetro;
	private: System::Windows::Forms::Label^ label18;
	private: Boolean alarma_test = false;
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
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->labelIncXY = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
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
			this->buttonCancelar = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->labelRawData = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->labelAltimetro = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarTemperatura))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->labelAltimetro);
			this->groupBox1->Controls->Add(this->label18);
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->dateTimePicker1);
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
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(250, 75);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(84, 13);
			this->label16->TabIndex = 11;
			this->label16->Text = L"Fecha creacion:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F));
			this->button1->Location = System::Drawing::Point(366, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 24);
			this->button1->TabIndex = 1;
			this->button1->Text = L"TEST ALARMA";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::button1_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Enabled = false;
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(342, 72);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(78, 20);
			this->dateTimePicker1->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->Location = System::Drawing::Point(302, 14);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 15);
			this->label5->TabIndex = 9;
			this->label5->Text = L"idNodo ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(229, 16);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"ID del Nodo:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(158, 69);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(69, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(114, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Y (Px):";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(50, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(59, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"X (Px):";
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
			this->groupBox3->Controls->Add(this->label17);
			this->groupBox3->Controls->Add(this->radioButton1);
			this->groupBox3->Controls->Add(this->pictureBox1);
			this->groupBox3->Location = System::Drawing::Point(11, 177);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->groupBox3->Size = System::Drawing::Size(420, 290);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(171, 268);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(83, 13);
			this->label17->TabIndex = 12;
			this->label17->Text = L"Previsualización";
			this->label17->Click += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::label17_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoCheck = false;
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::Black;
			this->radioButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->radioButton1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->radioButton1->Location = System::Drawing::Point(147, 79);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(60, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Nodo 1";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmInstalarNodoMonitoreo::radioButton1_MouseDown);
			this->radioButton1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmInstalarNodoMonitoreo::radioButton1_MouseMove);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(420, 265);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label15);
			this->groupBox2->Controls->Add(this->trackBar1);
			this->groupBox2->Controls->Add(this->labelIncXY);
			this->groupBox2->Controls->Add(this->label7);
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
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Location = System::Drawing::Point(7, 469);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(432, 122);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Data sensores";
			this->groupBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmInstalarNodoMonitoreo::groupBox2_Paint);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label15->Location = System::Drawing::Point(346, 44);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(32, 15);
			this->label15->TabIndex = 23;
			this->label15->Text = L"1.1m";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(361, 104);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(73, 13);
			this->label13->TabIndex = 22;
			this->label13->Text = L"Columna H2O";
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->trackBar1->Location = System::Drawing::Point(381, 10);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar1->Size = System::Drawing::Size(45, 90);
			this->trackBar1->TabIndex = 21;
			// 
			// labelIncXY
			// 
			this->labelIncXY->AutoSize = true;
			this->labelIncXY->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelIncXY->Location = System::Drawing::Point(282, 95);
			this->labelIncXY->Name = L"labelIncXY";
			this->labelIncXY->Size = System::Drawing::Size(38, 15);
			this->labelIncXY->TabIndex = 20;
			this->labelIncXY->Text = L"IncXY";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(221, 96);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Inclinacion:";
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
			this->labelTemperatura->Location = System::Drawing::Point(36, 44);
			this->labelTemperatura->Name = L"labelTemperatura";
			this->labelTemperatura->Size = System::Drawing::Size(32, 15);
			this->labelTemperatura->TabIndex = 10;
			this->labelTemperatura->Text = L"temp";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->label9->Location = System::Drawing::Point(25, 83);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 9);
			this->label9->TabIndex = 11;
			this->label9->Text = L"-20°C";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
			this->label8->Location = System::Drawing::Point(24, 18);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(26, 9);
			this->label8->TabIndex = 10;
			this->label8->Text = L"100°C";
			// 
			// trackBarTemperatura
			// 
			this->trackBarTemperatura->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->trackBarTemperatura->Location = System::Drawing::Point(7, 16);
			this->trackBarTemperatura->Maximum = 100;
			this->trackBarTemperatura->Minimum = -20;
			this->trackBarTemperatura->Name = L"trackBarTemperatura";
			this->trackBarTemperatura->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarTemperatura->Size = System::Drawing::Size(45, 78);
			this->trackBarTemperatura->SmallChange = 10;
			this->trackBarTemperatura->TabIndex = 2;
			this->trackBarTemperatura->TickFrequency = 15;
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
			this->button2->Location = System::Drawing::Point(280, 592);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 25);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Crear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::button2_Click);
			// 
			// buttonCancelar
			// 
			this->buttonCancelar->Location = System::Drawing::Point(364, 592);
			this->buttonCancelar->Name = L"buttonCancelar";
			this->buttonCancelar->Size = System::Drawing::Size(70, 25);
			this->buttonCancelar->TabIndex = 11;
			this->buttonCancelar->Text = L"Cancelar";
			this->buttonCancelar->UseVisualStyleBackColor = true;
			this->buttonCancelar->Click += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::button3_Click);
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
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(229, 45);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(53, 13);
			this->label18->TabIndex = 12;
			this->label18->Text = L"Altimetro: ";
			// 
			// labelAltimetro
			// 
			this->labelAltimetro->AutoSize = true;
			this->labelAltimetro->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelAltimetro->Location = System::Drawing::Point(302, 43);
			this->labelAltimetro->Name = L"labelAltimetro";
			this->labelAltimetro->Size = System::Drawing::Size(46, 15);
			this->labelAltimetro->TabIndex = 13;
			this->labelAltimetro->Text = L"idNodo ";
			// 
			// frmInstalarNodoMonitoreo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(448, 624);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->labelRawData);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->buttonCancelar);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmInstalarNodoMonitoreo";
			this->Text = L"Instalación de nodo de monitoreo";
			this->Load += gcnew System::EventHandler(this, &frmInstalarNodoMonitoreo::frmInstalarNodoMonitoreo_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarTemperatura))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {


		}
			   /*Accion luego de presionar boton Cancelar*/
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		if (conectado)
			serialPort1->Close();
	}
	/*Precarga informacion durante el evneto load del la ventana*/
	private: System::Void frmInstalarNodoMonitoreo_Load(System::Object^ sender, System::EventArgs^ e) {
		
		String^ idDisponible = Convert::ToString(objNodoController->getIdDisponible());
		this->label5->Text = idDisponible;
		array<String^>^ listaPuertos = serialPort1->GetPortNames();
		this->comboBox2->Items->Clear();
		for (int i = 0; i < listaPuertos->Length; i++) {
			this->comboBox2->Items->Add(listaPuertos[i]);
		}
		/*Precarga Quebradas disponibles*/
		quebradasDisponibles = objQuebradaController->buscarTodasQuebradas();
		this->comboBox1->Items->Clear(); /*Borra todos los valores que tenga el combo box*/
		for (int i = 0; i < quebradasDisponibles->Count; i++) {
			this->comboBox1->Items->Add(quebradasDisponibles[i]->getNombre());
		}
		this->comboBox1->SelectedIndex = 0;//Autoseleeciona la primera de la lista de quebradas disponibles
		
		/*Carga la imagen correspondiente*/
		actualizaImagenQuebrada();
		/*Inicializa dibujo burbuja nivel*/
		nivelInclinometro->setInicioX(240);
		nivelInclinometro->setInicioY(20);
		nivelInclinometro->setAncho(60);
		nivelInclinometro->setAngX(0);
		nivelInclinometro->setAngY(0);
		nivelInclinometro->setColor(Color::Black);
	}
		   /*Logica boton conectar/desconectar*/
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ COMNameSel = this->comboBox2->Text;
		if (!conectado && (COMNameSel != "")) {
			serialPort1->PortName = COMNameSel;
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
	private: void actualizaImagenQuebrada() {
		String^ codigoQuebradaSeleccionada = Convert::ToString(quebradasDisponibles[this->comboBox1->SelectedIndex]->getCodigo());
		this->pictureBox1->Image = nullptr;
		this->pictureBox1->Image = this->pictureBox1->Image->FromFile(codigoQuebradaSeleccionada + ".jpg");

	}
		   /*Accion cuando se cambia la seleccion en combobox de seleccion quebrada*/
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		actualizaImagenQuebrada();
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
	  
	private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
		String^ lectura = serialPort1->ReadLine();
		this->objNuevoNodo = objNodoController->cargarDataSensores(lectura, objNuevoNodo);
		this->groupBox2->Invalidate();
		/*Salida datos serial :
		nodoID | incX_deg | incY_deg | accX_g | accY_g | accZ_g | tBMP_degC | pBMP_Pa | hSoil_per | rain | alarm */
		//=progressBarHumedad->Value = Convert::ToInt32(datosSeparados[8]);
	
	}
	   /*Accion luego de precionar el boton crear Nodo*/
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int idNodoNuevo = Convert::ToInt32(this->label5->Text);
		int idQuebradaSeleccionada = Convert::ToInt32(quebradasDisponibles[this->comboBox1->SelectedIndex]->getCodigo());
		int posX = Convert::ToInt32(this->textBox1->Text);
		int posY = Convert::ToInt32(this->textBox2->Text);
		String^ comName = this->comboBox2->Text;
		String^ fechaCreacion = this->dateTimePicker1->Text;
		NodoMonitoreo^ nuevoNodo = gcnew NodoMonitoreo(idNodoNuevo, posX, posY, idQuebradaSeleccionada, comName, fechaCreacion);

		NodosController^ objNodoController = gcnew NodosController();
		List<NodoMonitoreo^>^ listaNodos = objNodoController->buscarTodosNodos();
		listaNodos->Add(nuevoNodo);
		objNodoController->escribirArchivoNodos(listaNodos);
		MessageBox::Show("Nodo creado en el sistema con exito");
		this->Close();
		if (conectado) {
			serialPort1->Close();
			conectado = false;
			}
	}
	private: System::Void groupBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ objGraphics = e->Graphics;
		if (conectado) {
			double humedad = Convert::ToInt32(this->objNuevoNodo->getSensorHumedad()->getHumedad());
			double temperatura = this->objNuevoNodo->getSensorTemperatura()->getTemperatura();
			double inclinacionX = this->objNuevoNodo->getSensorInc()->getIncX();
			double inclinacionY = this->objNuevoNodo->getSensorInc()->getIncY();
			int lluvia = this->objNuevoNodo->getSensorLluvia()->getValor();
			double pressure = this->objNuevoNodo->getSensorNivelAgua()->getPresion_hPa();
			double altitudEstimada = 44330.0 * (1.0 - Math::Pow((pressure / 1015.32),1/5.255));

			this->progressBarHumedad->Value = humedad;
			this->labelHumedad->Text = Convert::ToString(humedad) + "%";
			this->labelTemperatura->Text = Convert::ToString(temperatura) + "°C";
			this->trackBarTemperatura->Value = temperatura;
			this->labelIncXY->Text = Convert::ToString(inclinacionX) + "° " + Convert::ToString(inclinacionY) + "° ";
			this->nivelInclinometro->setAngX(inclinacionX);
			this->nivelInclinometro->setAngY(inclinacionY);
			this->labelAltimetro->Text = Convert::ToString((int)altitudEstimada)+ " msnm";
			if (lluvia == 1) {
				this->checkBoxLluvia->Checked = true;
			}
			else this->checkBoxLluvia->Checked = false;
		}
			Pen^ objLapiz = gcnew Pen(nivelInclinometro->getColor());
			int X = nivelInclinometro->getInicioX();
			int Y = nivelInclinometro->getInicioY();
			int A = nivelInclinometro->getAncho();
			objGraphics->DrawRectangle(objLapiz,X, Y, A, A);

			int X1 = X + A * 0.5;
			int Y1 = Y + A*0.1;
			int X2 = X + A * 0.5;
			int Y2 = Y + A*0.9;
			objGraphics->DrawLine(objLapiz,X1, Y1, X2, Y2);

			X1 = X + A * 0.1;
			Y1 = Y + A * 0.5;
			X2 = X + A * 0.9;
			Y2 = Y + A * 0.5;
			objGraphics->DrawLine(objLapiz, X1, Y1, X2, Y2);

			objLapiz->Color = Color::Red;
			int offsetX = this->nivelInclinometro->getAngX() * PI / 180 * A;
			int offsetY = this->nivelInclinometro->getAngY() * PI / 180 * A;
			X = X + A * 0.3 - offsetX;
			Y = Y + A * 0.3 + offsetY;
			A = A * 0.4;
			objGraphics->DrawEllipse(objLapiz, X, Y, A, A);

	}
	   private: Point MouseDownLocation;

	private: System::Void radioButton1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			MouseDownLocation = e->Location;
		}

	}
	private: System::Void radioButton1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			radioButton1->Left = e->X + radioButton1->Left - MouseDownLocation.X;
			radioButton1->Top = e->Y + radioButton1->Top - MouseDownLocation.Y;
			/*Se carga la pos X e Y estimada del circulo del radiobutton*/
			this->textBox1->Text = Convert::ToString(radioButton1->Left + 55);
			this->textBox2->Text = Convert::ToString(radioButton1->Top + 8);
		}
	}
	private: System::Void label17_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
