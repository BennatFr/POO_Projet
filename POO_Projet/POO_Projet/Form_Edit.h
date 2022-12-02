#pragma once

#include "Personnel.h"

namespace POOProjet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form_Edit
	/// </summary>
	public ref class Form_Edit : public System::Windows::Forms::Form
	{
	public:
		Form_Edit(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

		Form_Edit(Personnel^ personnel)
		{
			InitializeComponent();

			if (personnel->getPersonnelID() == 0) {
				this->button2->Hide();
			}

			this->personnel = personnel;
			this->Text = "[POO] v1.0 | Modification Personnel | N°" + personnel->getPersonnelID();

			this->label1->Text = "Nom de famille";
			this->label2->Text = "Prénom";
			this->label3->Text = "ID du supérieur";
			this->label4->Text = "Numéro de rue";
			this->label5->Text = "Nom de la rue";
			this->label6->Text = "Information complémentaire";
			this->label7->Text = "Ville";
			this->label8->Text = "Code postal";
			this->label9->Text = "Pays";
			this->label10->Text = "Date de recrutement";

			this->textBox1->Text = personnel->getPeople()->getLastName();
			this->textBox2->Text = personnel->getPeople()->getFirstName();
			this->textBox3->Text = personnel->getPersonnel()->getIDSuperior().ToString();
			this->textBox4->Text = personnel->getAddress()->getAddress()->getStreetNumber().ToString();
			this->textBox5->Text = personnel->getAddress()->getAddress()->getStreet();
			this->textBox6->Text = personnel->getAddress()->getAddress()->getAdditionnalData();
			this->textBox7->Text = personnel->getAddress()->getCity()->getName();
			this->textBox8->Text = personnel->getAddress()->getCity()->getPostalNumber();
			this->textBox9->Text = personnel->getAddress()->getCountry()->getName();
			this->dateTimePicker1->Value = personnel->getPersonnel()->getHireDate();

			this->textBox1->MaxLength = 50;
			this->textBox2->MaxLength = 50;
			this->textBox3->MaxLength = 10;
			this->textBox4->MaxLength = 10;
			this->textBox5->MaxLength = 95;
			this->textBox6->MaxLength = 50;
			this->textBox7->MaxLength = 35;
			this->textBox8->MaxLength = 10;
			this->textBox9->MaxLength = 56;
			this->dateTimePicker1->MinDate = DateTime(2000, 1, 1);
			this->dateTimePicker1->MaxDate = DateTime::Today;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form_Edit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox8;




	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox7;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Button^ button2;

	private: Personnel^ personnel;
	private: System::Windows::Forms::Label^ label10;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(10, 24);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(254, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(10, 61);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(254, 20);
			this->textBox2->TabIndex = 1;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(363, 24);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(151, 20);
			this->dateTimePicker1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 7);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 45);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 82);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"label3";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(10, 98);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(254, 20);
			this->textBox3->TabIndex = 6;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(10, 194);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"label6";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(10, 210);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(254, 20);
			this->textBox6->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 157);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"label5";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 119);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"label4";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(10, 173);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(254, 20);
			this->textBox5->TabIndex = 9;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(10, 136);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(254, 20);
			this->textBox4->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(10, 269);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 17;
			this->label8->Text = L"label8";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(10, 285);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(254, 20);
			this->textBox8->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(10, 232);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"label7";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(10, 248);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(254, 20);
			this->textBox7->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(378, 299);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 45);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_Edit::button1_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(10, 308);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 20;
			this->label9->Text = L"label9";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(10, 324);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(254, 20);
			this->textBox9->TabIndex = 19;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(378, 248);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 45);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(360, 7);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 13);
			this->label10->TabIndex = 22;
			this->label10->Text = L"label10";
			// 
			// Form_Edit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(525, 365);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form_Edit";
			this->Text = L"Form_Edit";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->textBox1->Text == "") {
		MessageBox::Show("Le nom de famille est obligatoire ", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	this->personnel->getPeople()->setLastName(this->textBox1->Text);
	if (this->textBox2->Text == "") {
		MessageBox::Show("Le prénom est obligatoire ", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	this->personnel->getPeople()->setFirstName(this->textBox2->Text);
	this->personnel->getPersonnel()->setIDSuperior(Convert::ToInt32(this->textBox3->Text));
	this->personnel->getPersonnel()->setHireDate(Convert::ToDateTime(this->dateTimePicker1->Text));
	this->personnel->getAddress()->getAddress()->setStreetNumber(Convert::ToInt32(this->textBox4->Text));
	this->personnel->getAddress()->getAddress()->setStreet(this->textBox5->Text);
	this->personnel->getAddress()->getAddress()->setAdditionnalData(this->textBox6->Text);
	if (this->textBox7->Text == "") {
		MessageBox::Show("La ville est obligatoire ", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	this->personnel->getAddress()->getCity()->setName(this->textBox7->Text);
	if (this->textBox8->Text == "") {
		MessageBox::Show("Le code postal est obligatoire ", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	this->personnel->getAddress()->getCity()->setPostalNumber(this->textBox8->Text);
	if (this->textBox9->Text == "") {
		MessageBox::Show("Le pays est obligatoire ", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	this->personnel->getAddress()->getCountry()->setName(this->textBox9->Text);
	
	
	int output;
	if (this->Text == "[POO] v1.0 | Modification Personnel | N°0") {
		output = this->personnel->insert();
	} else {
		output = this->personnel->update();
	}
	switch (output) {
	case 0:
		MessageBox::Show("Les données de l'utilisateur ont bien été sauvegardées.", "Succés !", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
		break;
	case 1:
		MessageBox::Show("L'identifiant du supérieur n'existe pas", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
		break;
	default:
		MessageBox::Show("Une erreur est survenue", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
		break;

	}
}
};
}
