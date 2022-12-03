#pragma once
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
	/// Description résumée de Form_Edit_Stock
	/// </summary>
	public ref class Form_Edit_Stock : public System::Windows::Forms::Form
	{
	public:
		Form_Edit_Stock(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		Form_Edit_Stock(Item^ item) {
			InitializeComponent();

			this->item = item;
			this->Text = "[POO] v1.0 | Modification Article | N°" + item->getItemID();

			this->label1->Text = "Reference";
			this->label2->Text = "Name";
			this->label3->Text = "Stock min";
			this->label4->Text = "Stock";
			this->label5->Text = "Type";
			this->label6->Text = "Prix";
			this->label7->Text = "TVA";
			this->label8->Text = "Historique des prix";
			this->dataGridView1->ReadOnly = true;

			this->numericUpDown1->Minimum = -1;
			this->numericUpDown2->Minimum = 0;
			this->numericUpDown3->Minimum = 0;
			this->numericUpDown4->Minimum = 0;

			this->numericUpDown1->Maximum = 2147483647;
			this->numericUpDown2->Maximum = 2147483647;
			this->numericUpDown3->Maximum = 2147483647;
			this->numericUpDown4->Maximum = 1;

			this->textBox1->Text = item->getItem()->getReference();
			this->textBox2->Text = item->getItem()->getName();
			this->numericUpDown1->Text = item->getItem()->getReplenishment().ToString();
			this->numericUpDown2->Text = item->getItem()->getStock().ToString();
			this->textBox3->Text = item->getType()->getName();
			this->numericUpDown3->Text = item->getPrice()->getPrice().ToString();
			this->numericUpDown4->Text = item->getPrice()->getVAT().ToString();

			this->textBox1->MaxLength = 10;
			this->textBox2->MaxLength = 50;
			this->textBox3->MaxLength = 50;

			if (item->getItemID() != 0) {
				recherchePrice();
			} else {
				this->dataGridView1->ColumnCount = 3;
				this->dataGridView1->Columns[0]->Name = "Prix";
				this->dataGridView1->Columns[1]->Name = "TVA";
				this->dataGridView1->Columns[2]->Name = "Date";
			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form_Edit_Stock()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: Item^ item;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;

	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown4;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label8;






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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 9);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(11, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(254, 20);
			this->textBox1->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 49);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"label2";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(11, 66);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(254, 20);
			this->textBox2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 89);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 129);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(11, 169);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"label5";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(11, 186);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(254, 20);
			this->textBox3->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(11, 209);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(11, 249);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"label7";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(312, 26);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(374, 196);
			this->dataGridView1->TabIndex = 19;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form_Edit_Stock::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(543, 253);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 41);
			this->button1->TabIndex = 20;
			this->button1->Text = L"Sauvegarder";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_Edit_Stock::button1_Click);
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->DecimalPlaces = 3;
			this->numericUpDown4->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown4->Location = System::Drawing::Point(11, 265);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(254, 20);
			this->numericUpDown4->TabIndex = 21;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->DecimalPlaces = 2;
			this->numericUpDown3->Location = System::Drawing::Point(11, 225);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(254, 20);
			this->numericUpDown3->TabIndex = 22;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->DecimalPlaces = 3;
			this->numericUpDown2->Location = System::Drawing::Point(11, 146);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(254, 20);
			this->numericUpDown2->TabIndex = 23;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->DecimalPlaces = 3;
			this->numericUpDown1->Location = System::Drawing::Point(11, 105);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(254, 20);
			this->numericUpDown1->TabIndex = 24;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(309, 9);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 25;
			this->label8->Text = L"label8";
			// 
			// Form_Edit_Stock
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(695, 302);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form_Edit_Stock";
			this->Text = L"Form_Edit_Stock";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


			this->item->getItem()->setReference(this->textBox1->Text);
			this->item->getItem()->setName(this->textBox2->Text);
			this->item->getItem()->setReplenishment((float) this->numericUpDown1->Value);
			this->item->getItem()->setStock((float)this->numericUpDown2->Value);
			this->item->getType()->setName(this->textBox3->Text);
			this->item->getPrice()->setPrice((float)this->numericUpDown3->Value);
			this->item->getPrice()->setVAT((float)this->numericUpDown4->Value);
			this->item->getPrice()->setDatePrice(DateTime(DateTime::Today));

			int output;
			if (this->item->getItemID() == 0) {
				output = this->item->insert();
			} else {
				output = this->item->update();
			}

			switch (output) {
			case 0:
				MessageBox::Show("Les données de l'utilisateur ont bien été sauvegardées.", "Succés !", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
				break;
			default:
				MessageBox::Show("Une erreur est survenue", "Erreur !", MessageBoxButtons::OK, MessageBoxIcon::Error);
				break;
			}
		}

		System::Void recherchePrice(){
			Connection_DB^ connection = gcnew Connection_DB();
			System::String^ sqlRequest;
			Row^ result;
			sqlRequest = "SELECT Price, VAT, date_Price FROM Price WHERE ID_Item = "+this->item->getItemID() + " ORDER BY date_Price DESC";
			this->dataGridView1->DataSource = connection->select(sqlRequest, "Price");
			this->dataGridView1->DataMember = "Price";
			return;
		}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
