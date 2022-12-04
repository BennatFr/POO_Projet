#pragma once

#include "Client.h"
#include "Item.h"
#include "Connection_DB.h"

namespace POOProjet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form_Command
	/// </summary>
	public ref class Form_Command : public System::Windows::Forms::Form
	{
	public:
		Form_Command(void)
		{
			InitializeComponent();

			this->numericUpDown_article2->Minimum = -2147483647;
			this->numericUpDown_article3->Minimum = 0;

			this->numericUpDown_article2->Maximum = 2147483647;
			this->numericUpDown_article3->Maximum = 1;

			this->dataGridView_client2->ColumnCount = 7;
			this->dataGridView_client2->Columns[0]->Name = "ID Adresse";
			this->dataGridView_client2->Columns[1]->Name = "Numéro de rue";
			this->dataGridView_client2->Columns[2]->Name = "Rue";
			this->dataGridView_client2->Columns[3]->Name = "Ville";
			this->dataGridView_client2->Columns[4]->Name = "Code postal";
			this->dataGridView_client2->Columns[5]->Name = "Pays";
			this->dataGridView_client2->Columns[6]->Name = "Information additionnel";

			this->dataGridView_client3->ColumnCount = 7;
			this->dataGridView_client3->Columns[0]->Name = "ID Adresse";
			this->dataGridView_client3->Columns[1]->Name = "Numéro de rue";
			this->dataGridView_client3->Columns[2]->Name = "Rue";
			this->dataGridView_client3->Columns[3]->Name = "Ville";
			this->dataGridView_client3->Columns[4]->Name = "Code postal";
			this->dataGridView_client3->Columns[5]->Name = "Pays";
			this->dataGridView_client3->Columns[6]->Name = "Information additionnel";

			this->dataGridView_article2->ColumnCount = 10;
			this->dataGridView_article2->Columns[0]->Name = "ID";
			this->dataGridView_article2->Columns[1]->Name = "Type";
			this->dataGridView_article2->Columns[2]->Name = "Nom";
			this->dataGridView_article2->Columns[3]->Name = "Référence";
			this->dataGridView_article2->Columns[4]->Name = "Quantité";
			this->dataGridView_article2->Columns[5]->Name = "Réduction";
			this->dataGridView_article2->Columns[6]->Name = "Prix /u";
			this->dataGridView_article2->Columns[7]->Name = "TVA";
			this->dataGridView_article2->Columns[8]->Name = "Prix HT";
			this->dataGridView_article2->Columns[9]->Name = "Prix TTC";
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form_Command()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Client^ client;
	private: Connection_DB^ connection;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_client2;

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_client1;
	private: System::Windows::Forms::TextBox^ textBox_client4;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox_client3;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_client2;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ dataGridView_client3;

	private: System::Windows::Forms::DataGridView^ dataGridView_client2;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DataGridView^ dataGridView_article2;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox_client2;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox_client1;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_client1;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::DataGridView^ dataGridView_client1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_article3;

	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_article2;

	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::DataGridView^ dataGridView_article1;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown_article1;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::ListBox^ listBox_article;

	private: System::Windows::Forms::Label^ Panier;

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView_client1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox_client2 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox_client1 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_client1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dataGridView_client3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView_client2 = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker_client2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_client1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox_client4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_client3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_client2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->Panier = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown_article3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_article2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->dataGridView_article1 = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDown_article1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->listBox_article = (gcnew System::Windows::Forms::ListBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->dataGridView_article2 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_client1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_client1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_client3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_client2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_client2))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_article3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_article2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_article1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_article1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_article2))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1326, 612);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView_client1);
			this->tabPage1->Controls->Add(this->textBox_client2);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->textBox_client1);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->numericUpDown_client1);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->dataGridView_client3);
			this->tabPage1->Controls->Add(this->dataGridView_client2);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->dateTimePicker_client2);
			this->tabPage1->Controls->Add(this->dateTimePicker_client1);
			this->tabPage1->Controls->Add(this->textBox_client4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->textBox_client3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->numericUpDown_client2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1318, 586);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Client";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// dataGridView_client1
			// 
			this->dataGridView_client1->AllowUserToAddRows = false;
			this->dataGridView_client1->AllowUserToDeleteRows = false;
			this->dataGridView_client1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_client1->Location = System::Drawing::Point(6, 88);
			this->dataGridView_client1->Name = L"dataGridView_client1";
			this->dataGridView_client1->ReadOnly = true;
			this->dataGridView_client1->Size = System::Drawing::Size(1303, 111);
			this->dataGridView_client1->TabIndex = 22;
			this->dataGridView_client1->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Form_Command::dataGridView_client1_CellMouseDoubleClick);
			// 
			// textBox_client2
			// 
			this->textBox_client2->Location = System::Drawing::Point(589, 19);
			this->textBox_client2->Name = L"textBox_client2";
			this->textBox_client2->Size = System::Drawing::Size(271, 20);
			this->textBox_client2->TabIndex = 21;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(586, 2);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(86, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"Prénom du client";
			// 
			// textBox_client1
			// 
			this->textBox_client1->Location = System::Drawing::Point(303, 19);
			this->textBox_client1->Name = L"textBox_client1";
			this->textBox_client1->Size = System::Drawing::Size(271, 20);
			this->textBox_client1->TabIndex = 19;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(300, 2);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(72, 13);
			this->label14->TabIndex = 18;
			this->label14->Text = L"Nom du client";
			// 
			// numericUpDown_client1
			// 
			this->numericUpDown_client1->Location = System::Drawing::Point(9, 19);
			this->numericUpDown_client1->Name = L"numericUpDown_client1";
			this->numericUpDown_client1->Size = System::Drawing::Size(271, 20);
			this->numericUpDown_client1->TabIndex = 17;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(6, 3);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(61, 13);
			this->label15->TabIndex = 16;
			this->label15->Text = L"ID du client";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 456);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(113, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Adresse de facturation";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 325);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(101, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Adresse de livraison";
			// 
			// dataGridView_client3
			// 
			this->dataGridView_client3->AllowUserToAddRows = false;
			this->dataGridView_client3->AllowUserToDeleteRows = false;
			this->dataGridView_client3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_client3->Location = System::Drawing::Point(6, 472);
			this->dataGridView_client3->Name = L"dataGridView_client3";
			this->dataGridView_client3->ReadOnly = true;
			this->dataGridView_client3->Size = System::Drawing::Size(1303, 108);
			this->dataGridView_client3->TabIndex = 13;
			// 
			// dataGridView_client2
			// 
			this->dataGridView_client2->AllowUserToAddRows = false;
			this->dataGridView_client2->AllowUserToDeleteRows = false;
			this->dataGridView_client2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_client2->Location = System::Drawing::Point(6, 341);
			this->dataGridView_client2->Name = L"dataGridView_client2";
			this->dataGridView_client2->ReadOnly = true;
			this->dataGridView_client2->Size = System::Drawing::Size(1303, 112);
			this->dataGridView_client2->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(300, 242);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(144, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Date premier achat sur le site";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(300, 202);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Date de naissance";
			// 
			// dateTimePicker_client2
			// 
			this->dateTimePicker_client2->Enabled = false;
			this->dateTimePicker_client2->Location = System::Drawing::Point(303, 258);
			this->dateTimePicker_client2->Name = L"dateTimePicker_client2";
			this->dateTimePicker_client2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_client2->TabIndex = 9;
			// 
			// dateTimePicker_client1
			// 
			this->dateTimePicker_client1->Enabled = false;
			this->dateTimePicker_client1->Location = System::Drawing::Point(303, 218);
			this->dateTimePicker_client1->Name = L"dateTimePicker_client1";
			this->dateTimePicker_client1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_client1->TabIndex = 8;
			// 
			// textBox_client4
			// 
			this->textBox_client4->Location = System::Drawing::Point(6, 302);
			this->textBox_client4->Name = L"textBox_client4";
			this->textBox_client4->ReadOnly = true;
			this->textBox_client4->Size = System::Drawing::Size(271, 20);
			this->textBox_client4->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 285);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Prénom du client";
			// 
			// textBox_client3
			// 
			this->textBox_client3->Location = System::Drawing::Point(6, 262);
			this->textBox_client3->Name = L"textBox_client3";
			this->textBox_client3->ReadOnly = true;
			this->textBox_client3->Size = System::Drawing::Size(271, 20);
			this->textBox_client3->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 245);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nom du client";
			// 
			// numericUpDown_client2
			// 
			this->numericUpDown_client2->Location = System::Drawing::Point(6, 218);
			this->numericUpDown_client2->Name = L"numericUpDown_client2";
			this->numericUpDown_client2->ReadOnly = true;
			this->numericUpDown_client2->Size = System::Drawing::Size(271, 20);
			this->numericUpDown_client2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 202);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"ID du client";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Recherche";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_Command::button1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->Panier);
			this->tabPage2->Controls->Add(this->button5);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->numericUpDown_article3);
			this->tabPage2->Controls->Add(this->label20);
			this->tabPage2->Controls->Add(this->numericUpDown_article2);
			this->tabPage2->Controls->Add(this->label19);
			this->tabPage2->Controls->Add(this->dataGridView_article1);
			this->tabPage2->Controls->Add(this->numericUpDown_article1);
			this->tabPage2->Controls->Add(this->label18);
			this->tabPage2->Controls->Add(this->textBox3);
			this->tabPage2->Controls->Add(this->label17);
			this->tabPage2->Controls->Add(this->textBox2);
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Controls->Add(this->listBox_article);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->dataGridView_article2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1318, 586);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Article";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// Panier
			// 
			this->Panier->AutoSize = true;
			this->Panier->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Panier->Location = System::Drawing::Point(6, 215);
			this->Panier->Name = L"Panier";
			this->Panier->Size = System::Drawing::Size(60, 20);
			this->Panier->TabIndex = 18;
			this->Panier->Text = L"Panier";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(148, 158);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(209, 46);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Recherche";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form_Command::button5_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1085, 158);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(217, 46);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Ajouter au panier";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form_Command::button2_Click);
			// 
			// numericUpDown_article3
			// 
			this->numericUpDown_article3->DecimalPlaces = 3;
			this->numericUpDown_article3->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown_article3->Location = System::Drawing::Point(1085, 65);
			this->numericUpDown_article3->Name = L"numericUpDown_article3";
			this->numericUpDown_article3->Size = System::Drawing::Size(209, 20);
			this->numericUpDown_article3->TabIndex = 15;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(1082, 49);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(56, 13);
			this->label20->TabIndex = 14;
			this->label20->Text = L"Réduction";
			// 
			// numericUpDown_article2
			// 
			this->numericUpDown_article2->DecimalPlaces = 3;
			this->numericUpDown_article2->Location = System::Drawing::Point(1085, 21);
			this->numericUpDown_article2->Name = L"numericUpDown_article2";
			this->numericUpDown_article2->Size = System::Drawing::Size(209, 20);
			this->numericUpDown_article2->TabIndex = 13;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(1082, 5);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(47, 13);
			this->label19->TabIndex = 12;
			this->label19->Text = L"Quantité";
			// 
			// dataGridView_article1
			// 
			this->dataGridView_article1->AllowUserToAddRows = false;
			this->dataGridView_article1->AllowUserToDeleteRows = false;
			this->dataGridView_article1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_article1->Location = System::Drawing::Point(378, 6);
			this->dataGridView_article1->Name = L"dataGridView_article1";
			this->dataGridView_article1->ReadOnly = true;
			this->dataGridView_article1->Size = System::Drawing::Size(698, 198);
			this->dataGridView_article1->TabIndex = 11;
			// 
			// numericUpDown_article1
			// 
			this->numericUpDown_article1->Location = System::Drawing::Point(148, 21);
			this->numericUpDown_article1->Name = L"numericUpDown_article1";
			this->numericUpDown_article1->Size = System::Drawing::Size(209, 20);
			this->numericUpDown_article1->TabIndex = 10;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(145, 92);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(107, 13);
			this->label18->TabIndex = 9;
			this->label18->Text = L"Référence de l\'article";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(148, 108);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(209, 20);
			this->textBox3->TabIndex = 8;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(145, 49);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(79, 13);
			this->label17->TabIndex = 7;
			this->label17->Text = L"Nom de l\'article";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(148, 65);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(209, 20);
			this->textBox2->TabIndex = 6;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(145, 5);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(68, 13);
			this->label16->TabIndex = 5;
			this->label16->Text = L"ID de l\'article";
			// 
			// listBox_article
			// 
			this->listBox_article->FormattingEnabled = true;
			this->listBox_article->Location = System::Drawing::Point(3, 5);
			this->listBox_article->Name = L"listBox_article";
			this->listBox_article->Size = System::Drawing::Size(135, 199);
			this->listBox_article->TabIndex = 3;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(993, 566);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 13);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Total HT";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::Color::Red;
			this->label8->Location = System::Drawing::Point(1082, 566);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Total TTC";
			// 
			// dataGridView_article2
			// 
			this->dataGridView_article2->AllowUserToAddRows = false;
			this->dataGridView_article2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_article2->Location = System::Drawing::Point(6, 238);
			this->dataGridView_article2->Name = L"dataGridView_article2";
			this->dataGridView_article2->ReadOnly = true;
			this->dataGridView_article2->Size = System::Drawing::Size(1306, 325);
			this->dataGridView_article2->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button4);
			this->tabPage3->Controls->Add(this->button3);
			this->tabPage3->Controls->Add(this->label12);
			this->tabPage3->Controls->Add(this->label10);
			this->tabPage3->Controls->Add(this->label11);
			this->tabPage3->Controls->Add(this->numericUpDown3);
			this->tabPage3->Controls->Add(this->numericUpDown2);
			this->tabPage3->Controls->Add(this->listBox1);
			this->tabPage3->Controls->Add(this->dataGridView4);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1318, 586);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Payment";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(167, 538);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(120, 37);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Ajouter le moyen de payment";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1237, 558);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Facturé";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(320, 519);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(73, 13);
			this->label12->TabIndex = 7;
			this->label12->Text = L"Reste a payer";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(944, 558);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(49, 13);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Total HT";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ForeColor = System::Drawing::Color::Red;
			this->label11->Location = System::Drawing::Point(1033, 558);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(55, 13);
			this->label11->TabIndex = 5;
			this->label11->Text = L"Total TTC";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->DecimalPlaces = 2;
			this->numericUpDown3->Location = System::Drawing::Point(167, 512);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 20);
			this->numericUpDown3->TabIndex = 4;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->DecimalPlaces = 2;
			this->numericUpDown2->Location = System::Drawing::Point(167, 485);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 3;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(6, 485);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(155, 95);
			this->listBox1->TabIndex = 2;
			// 
			// dataGridView4
			// 
			this->dataGridView4->AllowUserToAddRows = false;
			this->dataGridView4->AllowUserToDeleteRows = false;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Location = System::Drawing::Point(6, 6);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->Size = System::Drawing::Size(1296, 473);
			this->dataGridView4->TabIndex = 0;
			// 
			// Form_Command
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1350, 636);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form_Command";
			this->Text = L"Form_Command";
			this->Load += gcnew System::EventHandler(this, &Form_Command::Form_Command_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_client1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_client1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_client3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_client2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_client2))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_article3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_article2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_article1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_article1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_article2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ sqlRequest;
		if (this->numericUpDown_client1->Text != "0" && this->numericUpDown_client1->Text != "") {
			sqlRequest = "SELECT ID_Client, last_Name, first_Name, birthdate, first_Buy_Website FROM (SELECT * FROM Client WHERE ID_Client = " + this->numericUpDown_client1->Text + ") as Client INNER JOIN People ON CLient.ID_People = People.ID_People;";
		} else if (this->textBox_client1->Text != "0" && this->textBox_client2->Text != "") {
			sqlRequest = "SELECT ID_Client, last_Name, first_Name, birthdate, first_Buy_Website FROM Client JOIN [People] ON Client.ID_People = [People].[ID_People] WHERE [last_Name] LIKE  '" + this->textBox_client1->Text + "%' AND [first_Name] LIKE  '" + this->textBox_client2->Text + "%'";
		} else if (this->textBox_client1->Text != "") {
			sqlRequest = "SELECT ID_Client, last_Name, first_Name, birthdate, first_Buy_Website FROM Client JOIN [People] ON Client.ID_People = [People].[ID_People] WHERE [last_Name] LIKE  '" + this->textBox_client1->Text + "%'";
		} else if (this->textBox_client2->Text != "") {
			sqlRequest = "SELECT ID_Client, last_Name, first_Name, birthdate, first_Buy_Website FROM Client JOIN [People] ON Client.ID_People = [People].[ID_People] WHERE [first_Name] LIKE  '" + this->textBox_client2->Text + "%'";
		} else {
			MessageBox::Show("Tout les champs de recherche sont vide", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		this->dataGridView_client1->DataSource = connection->select(sqlRequest, "Client");
		this->dataGridView_client1->DataMember = "Client";
	}
	private: System::Void Form_Command_Load(System::Object^ sender, System::EventArgs^ e) {
		this->connection = gcnew Connection_DB();
		this->listBox_article->Items->Add("");
		this->listBox_article->SelectedIndex = 0;
		Row^ row = this->connection->selectRow("Select * From type", "Type", 0);
		for (int i = 0; i < row->getDataSet()->Tables["Type"]->Rows->Count; i++) {
			row->setRow(i);
			this->listBox_article->Items->Add(row->getString(1));
		}
	}

	private: System::Void dataGridView_client1_CellMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		String^ IDSelect = this->dataGridView_client1->Rows[e->RowIndex]->Cells[0]->Value->ToString();
		if (IDSelect == "") {
			MessageBox::Show("Veuillez selectionner une ligne", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		Client^ client = gcnew Client(Convert::ToInt32(IDSelect));
		this->client = client;
		this->numericUpDown_client2->Text = client->getClientID().ToString();
		this->textBox_client3->Text = client->getPeople()->getLastName();
		this->textBox_client4->Text = client->getPeople()->getFirstName();
		this->dateTimePicker_client1->Value = client->getClient()->getBirthdate();
		this->dateTimePicker_client2->Value = client->getClient()->getFirstBuyWebsite();

		this->dataGridView_client2->Rows->Clear();
		this->dataGridView_client3->Rows->Clear();
		Address^ address;
		System::Windows::Forms::DataGridView^ dataGridView;
		int index;
		for (int i = 0; i < this->client->getListAddress()->getSize(); i++) {
			address = this->client->getListAddress()->get(i);
			if (!address->getClientAddress()->isBilling()) {
				dataGridView = this->dataGridView_client2;
			} else {
				dataGridView = this->dataGridView_client3;
			}
			index = dataGridView->Rows->Count;
			dataGridView->Rows->Add();
			dataGridView->Rows[index]->Cells["ID Adresse"]->Value = address->getAddress()->getIDAddress();
			dataGridView->Rows[index]->Cells["Numéro de rue"]->Value = address->getAddress()->getStreetNumber();
			dataGridView->Rows[index]->Cells["Rue"]->Value = address->getAddress()->getStreet();
			dataGridView->Rows[index]->Cells["Ville"]->Value = address->getCity()->getName();
			dataGridView->Rows[index]->Cells["Code postal"]->Value = address->getCity()->getPostalNumber();
			dataGridView->Rows[index]->Cells["Pays"]->Value = address->getCountry()->getName();
			dataGridView->Rows[index]->Cells["Information additionnel"]->Value = address->getAddress()->getAdditionnalData();
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ sqlRequest;
		if (this->numericUpDown_article1->Text != "0" && this->numericUpDown_article1->Text != "") {
			sqlRequest = "SELECT ID_Item, Type.name as type, Item.name, reference, stock, replenishment FROM (SELECT * FROM Item WHERE ID_Item = " + this->numericUpDown_article1->Text + ") as Item INNER JOIN Type ON Item.ID_Type = Type.ID_Type;";
		}
		this->dataGridView_article1->DataSource = connection->select(sqlRequest, "Stock");
		this->dataGridView_article1->DataMember = "Stock";
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int indexSelection = this->dataGridView_article1->SelectedCells[0]->RowIndex;
		if (indexSelection == -1) {
			MessageBox::Show("Selectionner un article", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (this->numericUpDown_article2->Value == 0) {
			MessageBox::Show("Quantité null", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		this->dataGridView_article1->Rows[indexSelection]->Cells[0]->Value;
		int index = this->dataGridView_article2->Rows->Count;
		this->dataGridView_article2->Rows->Add();

		Item^ item = gcnew Item(Convert::ToInt32(this->dataGridView_article1->Rows[indexSelection]->Cells[0]->Value));

		item->getItem()->setQuantity((float)Convert::ToDecimal(this->numericUpDown_article2->Value));
		item->getItem()->setDiscount((float)Convert::ToDecimal(this->numericUpDown_article3->Value));

		this->dataGridView_article2->Rows[index]->Cells["ID"]->Value = this->dataGridView_article1->Rows[indexSelection]->Cells[0]->Value;
		this->dataGridView_article2->Rows[index]->Cells["Type"]->Value = this->dataGridView_article1->Rows[indexSelection]->Cells[1]->Value;
		this->dataGridView_article2->Rows[index]->Cells["Nom"]->Value = this->dataGridView_article1->Rows[indexSelection]->Cells[2]->Value;
		this->dataGridView_article2->Rows[index]->Cells["Référence"]->Value = this->dataGridView_article1->Rows[indexSelection]->Cells[3]->Value;
		this->dataGridView_article2->Rows[index]->Cells["Quantité"]->Value = this->numericUpDown_article2->Value;
		this->dataGridView_article2->Rows[index]->Cells["Réduction"]->Value = this->numericUpDown_article3->Value;
		this->dataGridView_article2->Rows[index]->Cells["Prix /u"]->Value = item->getFloatPriceUHT();
		this->dataGridView_article2->Rows[index]->Cells["TVA"]->Value = item->getFloatPriceUTTC();
		this->dataGridView_article2->Rows[index]->Cells["Prix HT"]->Value = item->getFloatPriceHT();
		this->dataGridView_article2->Rows[index]->Cells["Prix TTC"]->Value = item->getFloatPriceTTC();

	}
	};
}
