#pragma once

#include <string>
#include <msclr\marshal_cppstd.h>

#include "Global_Var.h"
#include "Connection_DB.h"
#include "Form_Edit.h"
#include "Personnel.h"

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

		Form_Search(EnumVar::type_Seach typeOfResearch)
		{
			InitializeComponent();
			String^ titleText = "[POO] v1.0 ";
			this->label_error->Text = "";
			this->typeOfResearch = typeOfResearch;
			switch (typeOfResearch) {
			case EnumVar::COMMAND:
				this->Text = titleText + "Recherche Commande";
				break;
			case EnumVar::PERSONNEL:
				this->Text = titleText + "Recherche Personnel";
				this->label_research1->Text = "Id du Personnel";
				this->label_research2->Text = "Nom du Personnel";
				this->label_research3->Text = "Prénom du Personnel";
				this->dateTimePicker2->Hide();
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
	private: System::Windows::Forms::Label^ label_research1;
	private: System::Windows::Forms::TextBox^ textBox_research1;





	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: Connection_DB^ connection;
	private: EnumVar::type_Seach typeOfResearch;
	private: System::Windows::Forms::Label^ label_error;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox_research2;

	private: System::Windows::Forms::Label^ label_research2;
	private: System::Windows::Forms::TextBox^ textBox_research3;


	private: System::Windows::Forms::Label^ label_research3;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form_Search::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label_research1 = (gcnew System::Windows::Forms::Label());
			this->textBox_research1 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_error = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox_research2 = (gcnew System::Windows::Forms::TextBox());
			this->label_research2 = (gcnew System::Windows::Forms::Label());
			this->textBox_research3 = (gcnew System::Windows::Forms::TextBox());
			this->label_research3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(9, 10);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(718, 244);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Form_Search::dataGridView1_CellMouseDoubleClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(585, 395);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Rechercher";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_Search::button1_Click);
			// 
			// label_research1
			// 
			this->label_research1->AutoSize = true;
			this->label_research1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label_research1->Location = System::Drawing::Point(6, 256);
			this->label_research1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_research1->Name = L"label_research1";
			this->label_research1->Size = System::Drawing::Size(82, 13);
			this->label_research1->TabIndex = 2;
			this->label_research1->Text = L"label_research1";
			// 
			// textBox_research1
			// 
			this->textBox_research1->Location = System::Drawing::Point(9, 271);
			this->textBox_research1->Margin = System::Windows::Forms::Padding(2);
			this->textBox_research1->Name = L"textBox_research1";
			this->textBox_research1->Size = System::Drawing::Size(288, 20);
			this->textBox_research1->TabIndex = 3;
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
			// label_error
			// 
			this->label_error->AutoSize = true;
			this->label_error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->label_error->ForeColor = System::Drawing::Color::Red;
			this->label_error->Location = System::Drawing::Point(8, 10);
			this->label_error->Name = L"label_error";
			this->label_error->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label_error->Size = System::Drawing::Size(89, 20);
			this->label_error->TabIndex = 6;
			this->label_error->Text = L"label_error";
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(693, 395);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(34, 38);
			this->button2->TabIndex = 7;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// textBox_research2
			// 
			this->textBox_research2->Location = System::Drawing::Point(9, 308);
			this->textBox_research2->Margin = System::Windows::Forms::Padding(2);
			this->textBox_research2->Name = L"textBox_research2";
			this->textBox_research2->Size = System::Drawing::Size(288, 20);
			this->textBox_research2->TabIndex = 8;
			// 
			// label_research2
			// 
			this->label_research2->AutoSize = true;
			this->label_research2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label_research2->Location = System::Drawing::Point(6, 293);
			this->label_research2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_research2->Name = L"label_research2";
			this->label_research2->Size = System::Drawing::Size(82, 13);
			this->label_research2->TabIndex = 9;
			this->label_research2->Text = L"label_research2";
			// 
			// textBox_research3
			// 
			this->textBox_research3->Location = System::Drawing::Point(9, 345);
			this->textBox_research3->Margin = System::Windows::Forms::Padding(2);
			this->textBox_research3->Name = L"textBox_research3";
			this->textBox_research3->Size = System::Drawing::Size(288, 20);
			this->textBox_research3->TabIndex = 10;
			// 
			// label_research3
			// 
			this->label_research3->AutoSize = true;
			this->label_research3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label_research3->Location = System::Drawing::Point(6, 330);
			this->label_research3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_research3->Name = L"label_research3";
			this->label_research3->Size = System::Drawing::Size(82, 13);
			this->label_research3->TabIndex = 11;
			this->label_research3->Text = L"label_research3";
			// 
			// Form_Search
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 445);
			this->Controls->Add(this->label_research3);
			this->Controls->Add(this->textBox_research3);
			this->Controls->Add(this->label_research2);
			this->Controls->Add(this->textBox_research2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label_error);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox_research1);
			this->Controls->Add(this->label_research1);
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
			//Initialiser la connection
			this->connection = gcnew Connection_DB();
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->label_error->Text = "";
			String^ sqlRequest;
			switch (this->typeOfResearch) {
			case EnumVar::PERSONNEL:
				std::string ID_Personnel = msclr::interop::marshal_as<std::string>(this->textBox_research1->Text);
				if (ID_Personnel != "") {
					if (!is_number(ID_Personnel)) {
						this->label_error->Text = "L'identifiant n'est pas un nombre";
						return;
					}
					sqlRequest = gcnew String(("SELECT [POO_Projet].[dbo].[Personnel].[ID_Personnel], [POO_Projet].[dbo].[People].[last_Name], [POO_Projet].[dbo].[People].[first_Name], [POO_Projet].[dbo].[Personnel].[hire_Date] FROM [POO_Projet].[dbo].[Personnel] JOIN [POO_Projet].[dbo].[People] ON [POO_Projet].[dbo].[Personnel].[ID_People] = [POO_Projet].[dbo].[People].[ID_People] WHERE [ID_Personnel] = " + ID_Personnel).c_str());
				} else if (this->textBox_research2->Text != "" && this->textBox_research3->Text != "") {
					sqlRequest = "SELECT [Personnel].[ID_Personnel], [People].[last_Name], [People].[first_Name], [Personnel].[hire_Date] FROM [Personnel] JOIN [People] ON [Personnel].[ID_People] = [People].[ID_People] WHERE [last_Name] = '" + this->textBox_research2->Text + "' AND [first_Name] = '" + this->textBox_research3->Text + "'";
				} else if (this->textBox_research2->Text != "") {
					sqlRequest = "SELECT [Personnel].[ID_Personnel], [People].[last_Name], [People].[first_Name], [Personnel].[hire_Date] FROM [Personnel] JOIN [People] ON [Personnel].[ID_People] = [People].[ID_People] WHERE [last_Name] = '" + this->textBox_research2->Text + "'";
				} else if (this->textBox_research3->Text != "") {
					sqlRequest = "SELECT [Personnel].[ID_Personnel], [People].[last_Name], [People].[first_Name], [Personnel].[hire_Date] FROM [Personnel] JOIN [People] ON [Personnel].[ID_People] = [People].[ID_People] WHERE [first_Name] = '" + this->textBox_research3->Text + "'";
				} else {
					this->label_error->Text = "Tout les champs de recherche sont vide";
					return;
				}

				this->dataGridView1->DataSource = connection->select(sqlRequest, "Personnel");
				this->dataGridView1->DataMember = "Personnel";
				break;
			}
			//SQL
			//System::Data::DataSet^ result = connection->select("SELECT * FROM [POO_Projet].[dbo].[Personnel]", "Personnel");
			//Récupére la selection
			//this->dataGridView1->DataSource = result;
			//this->dataGridView1->DataMember = "Personnel";
			//Si ID =! ""
				//Faire une recherche de personnel seulement avec un ID
			//Sinon faire des recherche avec toute les données renseigner
				//NOM, Prénom, Ville ...
		//Afficher dans le data grid
		}
private: System::Void dataGridView1_CellMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
	String^ IDPersonnelSelect = this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString();
	Personnel^ personnel = gcnew Personnel(IDPersonnelSelect);
	Form_Edit^ formEdit = gcnew Form_Edit(personnel);
	formEdit->ShowDialog();
}
};
}
