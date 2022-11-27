#pragma once

#include <string>

#include "Global_Var.h"
#include "Connection_DB.h"

namespace POOProjet {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form_Search
	/// </summary>
	public ref class Form_Search : public System::Windows::Forms::Form
	{
	public:
		Form_Search(void)
		{
			InitializeComponent();
		}

		Form_Search(EnumVar::type_Seach title)
		{
			InitializeComponent();
			String^ titleText = "[POO] v1.0 ";
			//String^ titleText = gcnew String("dzbdjkez");
			switch (title) {
			case EnumVar::COMMAND:
				this->Text = titleText + "Recherche Commande";
				break;
			case EnumVar::PERSONNEL:
				this->Text = titleText + "Recherche Personnel";
				recherche1->Text = "Id du Personnel";
				break;
			default:
				this->Text = titleText + "Erreur";
				break;
			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form_Search()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ recherche1;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: Connection_DB^ connection;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->recherche1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(9, 10);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(718, 244);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(625, 396);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Rechercher";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_Search::button1_Click);
			// 
			// recherche1
			// 
			this->recherche1->AutoSize = true;
			this->recherche1->Location = System::Drawing::Point(9, 259);
			this->recherche1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->recherche1->Name = L"recherche1";
			this->recherche1->Size = System::Drawing::Size(61, 13);
			this->recherche1->TabIndex = 2;
			this->recherche1->Text = L"recherche1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 275);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(288, 20);
			this->textBox1->TabIndex = 3;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(625, 275);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(102, 20);
			this->dateTimePicker1->TabIndex = 4;
			this->dateTimePicker1->Value = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker2->Location = System::Drawing::Point(625, 301);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(102, 20);
			this->dateTimePicker2->TabIndex = 5;
			// 
			// Form_Search
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 445);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->recherche1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form_Search";
			this->Text = L"Form_Search";
			this->Load += gcnew System::EventHandler(this, &Form_Search::Form_Search_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void Form_Search_Load(System::Object^ sender, System::EventArgs^ e) {
			this->connection = gcnew Connection_DB();
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			//Initialiser la connection (voir si délai trop long le faire a l'ouverture de la page de recherche)
			//SQL
			System::Data::DataSet^ result = connection->select("SELECT * FROM [POO_Projet].[dbo].[Personnel]", "Personnel");
			//Récupére la selection
			this->dataGridView1->DataSource = result;
			this->dataGridView1->DataMember = "Personnel";
			//Si ID =! ""
				//Faire une recherche de personnel seulement avec un ID
			//Sinon faire des recherche avec toute les données renseigner
				//NOM, Prénom, Ville ...
		//Afficher dans le data grid
		}
};
}
