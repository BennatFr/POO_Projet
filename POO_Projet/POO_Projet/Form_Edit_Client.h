#pragma once

#include "Client.h"

namespace POOProjet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form_Edit_Client
	/// </summary>
	public ref class Form_Edit_Client : public System::Windows::Forms::Form
	{
	public:
		Form_Edit_Client(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

		Form_Edit_Client(Client^ client) {
			InitializeComponent();

			this->client = client;
			this->Text = "[POO] v1.0 | Modification Client | N°" + client->getClientID();

			this->label1->Text = "Nom de famille";
			this->label2->Text = "Prénom";
			this->label3->Text = "Date d'anniversaire";
			this->label4->Text = "Date premier achat site";
			this->label5->Text = "Adresse de livraison";
			this->label6->Text = "Adresse de facturation";
			this->dataGridView1->ColumnCount = 7;
			this->dataGridView1->Columns[0]->Name = "ID Adresse";
			this->dataGridView1->Columns[1]->Name = "Numéro de rue";
			this->dataGridView1->Columns[2]->Name = "Rue";
			this->dataGridView1->Columns[3]->Name = "Ville";
			this->dataGridView1->Columns[4]->Name = "Code postal";
			this->dataGridView1->Columns[5]->Name = "Pays";
			this->dataGridView1->Columns[6]->Name = "Information additionnel";
			this->dataGridView1->Columns[0]->ReadOnly = true;

			this->dataGridView2->ColumnCount = 7;
			this->dataGridView2->Columns[0]->Name = "ID Adresse";
			this->dataGridView2->Columns[1]->Name = "Numéro de rue";
			this->dataGridView2->Columns[2]->Name = "Rue";
			this->dataGridView2->Columns[3]->Name = "Ville";
			this->dataGridView2->Columns[4]->Name = "Code postal";
			this->dataGridView2->Columns[5]->Name = "Pays";
			this->dataGridView2->Columns[6]->Name = "Information additionnel";
			this->dataGridView1->Columns[0]->ReadOnly = true;

			this->textBox1->Text = client->getPeople()->getLastName();
			this->textBox2->Text = client->getPeople()->getFirstName();
			this->dateTimePicker1->Value = client->getClient()->getBirthdate();
			this->dateTimePicker2->Value = client->getClient()->getFirstBuyWebsite();

			this->textBox1->MaxLength = 50;
			this->textBox2->MaxLength = 50;
			this->dateTimePicker1->MinDate = DateTime(2000, 1, 1);
			this->dateTimePicker1->MaxDate = DateTime::Today;
			this->dateTimePicker2->MinDate = DateTime(2000, 1, 1);
			this->dateTimePicker2->MaxDate = DateTime::Today;

			if (client->getClientID() != 0) {
				rechercheAddress();
			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form_Edit_Client()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Client^ client;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(599, 28);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(967, 318);
			this->dataGridView1->TabIndex = 0;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(599, 378);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(967, 318);
			this->dataGridView2->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(531, 22);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 69);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(531, 22);
			this->textBox2->TabIndex = 4;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(12, 126);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(229, 22);
			this->dateTimePicker1->TabIndex = 6;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(314, 126);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(229, 22);
			this->dateTimePicker2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 107);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(311, 107);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(596, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(596, 359);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"label6";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1362, 714);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(204, 52);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Sauvegarder";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_Edit_Client::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1410, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Ajouter une addresse";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form_Edit_Client::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1410, 352);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 23);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Ajouter une addresse";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form_Edit_Client::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1222, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(172, 23);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Supprimer une addresse";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form_Edit_Client::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1222, 352);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(172, 23);
			this->button5->TabIndex = 16;
			this->button5->Text = L"Supprimer une addresse";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form_Edit_Client::button5_Click);
			// 
			// Form_Edit_Client
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1578, 778);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form_Edit_Client";
			this->Text = L"Form_Edit_Client";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		client->getPeople()->setLastName(this->textBox1->Text);
		client->getPeople()->setFirstName(this->textBox2->Text);
		client->getClient()->setBirthdate(this->dateTimePicker1->Value);
		client->getClient()->setFirstBuyWebsite(this->dateTimePicker2->Value);

		this->client->setListAddress(gcnew List_Address());
		getAddressFromGrid(this->dataGridView1, 0);
		getAddressFromGrid(this->dataGridView2, 1);
		int result;
		if (this->client->getClientID() == 0) {
			result = this->client->insert();
		} else {
			result = this->client->update();
		}
		if (result == 0) {
			MessageBox::Show("Les données de l'utilisateur ont bien été sauvegardées.", "Succés !", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		} else {
			MessageBox::Show("Une erreur est survenue.", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView1->Rows->Add();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView2->Rows->Add();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		deleteRow(this->dataGridView1);
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		deleteRow(this->dataGridView2);
	}


		   System::Void deleteRow(System::Windows::Forms::DataGridView^ dataGridView) {
			   if (dataGridView->SelectedCells->Count == 0) {
				   MessageBox::Show("Veuillez selectionner une addresse", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }
			   int row = dataGridView->SelectedCells[0]->RowIndex;
			   if (dataGridView->Rows->Count <= row) {
				   MessageBox::Show("Veuillez selectionner une addresse", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }
			   String^ IDAddressSelect = dataGridView->Rows[row]->Cells[0]->Value->ToString();
			   if (IDAddressSelect == "") {
				   MessageBox::Show("Veuillez selectionner une addresse", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }
			   else {
				   System::Windows::Forms::DialogResult result = MessageBox::Show("Supprimer l'address n°" + IDAddressSelect, "Suppression !", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
				   if (result == System::Windows::Forms::DialogResult::Yes) {
					   Address^ address = gcnew Address(Convert::ToInt32(IDAddressSelect), true);
					   address->getClientAddress()->setIdClient(this->client->getClientID());
					   address->del();
					   System::Windows::Forms::DialogResult result = MessageBox::Show("L'addresse n°" + IDAddressSelect + " a était supprimé", "Succés !", MessageBoxButtons::OK, MessageBoxIcon::Information);
				   }
			   }
			   rechercheAddress();
		   }
		   System::Void rechercheAddress() {
			   this->dataGridView1->Rows->Clear();
			   this->dataGridView2->Rows->Clear();
			   this->client->setListAddress((gcnew Client(this->client->getClientID()))->getListAddress());
			   Address^ address;
			   System::Windows::Forms::DataGridView^ dataGridView;
			   int index;
			   for (int i = 0; i < this->client->getListAddress()->getSize(); i++) {
				   address = this->client->getListAddress()->get(i);
				   if (!address->getClientAddress()->isBilling()) {
					   dataGridView = this->dataGridView1;
				   }
				   else {
					   dataGridView = this->dataGridView2;
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

		   System::Void getAddressFromGrid(System::Windows::Forms::DataGridView^ dataGridView, int bill) {
			   System::Windows::Forms::DataGridViewRow^ row;
			   int IDAddress;
			   for (int i = 0; i < dataGridView->Rows->Count; i++) {
				   row = dataGridView->Rows[i];
				   if (row->Cells["Numéro de rue"]->Value->ToString() == nullptr || row->Cells["Rue"]->Value->ToString() == nullptr || row->Cells["Ville"]->Value->ToString() == nullptr || row->Cells["Code postal"]->Value->ToString() == nullptr || row->Cells["Pays"]->Value->ToString() == nullptr || row->Cells["Numéro de rue"]->Value->ToString() == "" || row->Cells["Rue"]->Value->ToString() == "" || row->Cells["Ville"]->Value->ToString() == "" || row->Cells["Code postal"]->Value->ToString() == "" || row->Cells["Pays"]->Value->ToString() == "") {
					   MessageBox::Show("Une ou plusieurs adresse ont des données manquantes.", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
					   return;
				   }
				   if (row->Cells["ID Adresse"]->Value == "") {
					   IDAddress = 0;
				   }
				   else {
					   IDAddress = Convert::ToInt32(row->Cells["ID Adresse"]->Value);
				   }
				   DB_Address^ address = gcnew DB_Address(IDAddress, Convert::ToInt32(row->Cells["Numéro de rue"]->Value->ToString()), row->Cells["Rue"]->Value->ToString(), row->Cells["Information additionnel"]->Value->ToString(), 0, 0);
				   DB_City^ city = gcnew DB_City(0, row->Cells["Ville"]->Value->ToString(), row->Cells["Code postal"]->Value->ToString());
				   DB_Country^ country = gcnew DB_Country(0, row->Cells["Pays"]->Value->ToString());
				   DB_Client_Address^ clientAddress = gcnew DB_Client_Address(0, 0, bill);
				   Address^ tempo = gcnew Address(address, city, country, clientAddress);
				   this->client->getListAddress()->setLast(tempo);
			   }
		   }

	};
}