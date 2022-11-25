#pragma once

#include "Form_Search.h"
#include "Global_Var.h"

namespace POOProjet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ commande_ToolStripMenuItem;
	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ personnel_ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ client_ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ stock_ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ statistique_ToolStripMenuItem;









	private: System::Windows::Forms::ToolStripMenuItem^ panierMoyenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ chiffreDaffaireToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ réapprovisionnementToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ totalDesAchatsClientToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ top10VenteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ facture_ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ articlesLesMoinsVendusToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ valeurCommercialeDuStockToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ valeurDachatDuStockToolStripMenuItem;



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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->commande_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->personnel_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->client_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stock_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statistique_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panierMoyenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chiffreDaffaireToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->réapprovisionnementToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->totalDesAchatsClientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->top10VenteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->articlesLesMoinsVendusToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->valeurCommercialeDuStockToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->valeurDachatDuStockToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facture_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->commande_ToolStripMenuItem,
					this->personnel_ToolStripMenuItem, this->client_ToolStripMenuItem, this->stock_ToolStripMenuItem, this->statistique_ToolStripMenuItem,
					this->facture_ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(532, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// commande_ToolStripMenuItem
			// 
			this->commande_ToolStripMenuItem->Name = L"commande_ToolStripMenuItem";
			this->commande_ToolStripMenuItem->Size = System::Drawing::Size(100, 24);
			this->commande_ToolStripMenuItem->Text = L"Commande";
			this->commande_ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::commande_ToolStripMenuItem_Click);
			// 
			// personnel_ToolStripMenuItem
			// 
			this->personnel_ToolStripMenuItem->Name = L"personnel_ToolStripMenuItem";
			this->personnel_ToolStripMenuItem->Size = System::Drawing::Size(86, 24);
			this->personnel_ToolStripMenuItem->Text = L"Personnel";
			this->personnel_ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::personnel_ToolStripMenuItem_Click);
			// 
			// client_ToolStripMenuItem
			// 
			this->client_ToolStripMenuItem->Name = L"client_ToolStripMenuItem";
			this->client_ToolStripMenuItem->Size = System::Drawing::Size(61, 24);
			this->client_ToolStripMenuItem->Text = L"Client";
			// 
			// stock_ToolStripMenuItem
			// 
			this->stock_ToolStripMenuItem->Name = L"stock_ToolStripMenuItem";
			this->stock_ToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->stock_ToolStripMenuItem->Text = L"Stock";
			// 
			// statistique_ToolStripMenuItem
			// 
			this->statistique_ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->panierMoyenToolStripMenuItem,
					this->chiffreDaffaireToolStripMenuItem, this->réapprovisionnementToolStripMenuItem, this->totalDesAchatsClientToolStripMenuItem,
					this->top10VenteToolStripMenuItem, this->articlesLesMoinsVendusToolStripMenuItem, this->valeurCommercialeDuStockToolStripMenuItem,
					this->valeurDachatDuStockToolStripMenuItem
			});
			this->statistique_ToolStripMenuItem->Name = L"statistique_ToolStripMenuItem";
			this->statistique_ToolStripMenuItem->Size = System::Drawing::Size(93, 24);
			this->statistique_ToolStripMenuItem->Text = L"Statistique";
			// 
			// panierMoyenToolStripMenuItem
			// 
			this->panierMoyenToolStripMenuItem->Name = L"panierMoyenToolStripMenuItem";
			this->panierMoyenToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->panierMoyenToolStripMenuItem->Text = L"Panier moyen ";
			// 
			// chiffreDaffaireToolStripMenuItem
			// 
			this->chiffreDaffaireToolStripMenuItem->Name = L"chiffreDaffaireToolStripMenuItem";
			this->chiffreDaffaireToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->chiffreDaffaireToolStripMenuItem->Text = L"Chiffre d’affaire ";
			// 
			// réapprovisionnementToolStripMenuItem
			// 
			this->réapprovisionnementToolStripMenuItem->Name = L"réapprovisionnementToolStripMenuItem";
			this->réapprovisionnementToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->réapprovisionnementToolStripMenuItem->Text = L"Réapprovisionnement produit";
			// 
			// totalDesAchatsClientToolStripMenuItem
			// 
			this->totalDesAchatsClientToolStripMenuItem->Name = L"totalDesAchatsClientToolStripMenuItem";
			this->totalDesAchatsClientToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->totalDesAchatsClientToolStripMenuItem->Text = L"Total des achats client";
			// 
			// top10VenteToolStripMenuItem
			// 
			this->top10VenteToolStripMenuItem->Name = L"top10VenteToolStripMenuItem";
			this->top10VenteToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->top10VenteToolStripMenuItem->Text = L"10 articles les plus vendus";
			// 
			// articlesLesMoinsVendusToolStripMenuItem
			// 
			this->articlesLesMoinsVendusToolStripMenuItem->Name = L"articlesLesMoinsVendusToolStripMenuItem";
			this->articlesLesMoinsVendusToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->articlesLesMoinsVendusToolStripMenuItem->Text = L"10 articles les moins vendus";
			// 
			// valeurCommercialeDuStockToolStripMenuItem
			// 
			this->valeurCommercialeDuStockToolStripMenuItem->Name = L"valeurCommercialeDuStockToolStripMenuItem";
			this->valeurCommercialeDuStockToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->valeurCommercialeDuStockToolStripMenuItem->Text = L"Valeur commerciale du stock";
			// 
			// valeurDachatDuStockToolStripMenuItem
			// 
			this->valeurDachatDuStockToolStripMenuItem->Name = L"valeurDachatDuStockToolStripMenuItem";
			this->valeurDachatDuStockToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->valeurDachatDuStockToolStripMenuItem->Text = L"Valeur d’achat du stock";
			// 
			// facture_ToolStripMenuItem
			// 
			this->facture_ToolStripMenuItem->Name = L"facture_ToolStripMenuItem";
			this->facture_ToolStripMenuItem->Size = System::Drawing::Size(70, 24);
			this->facture_ToolStripMenuItem->Text = L"Facture";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 33);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(550, 80);
			this->MinimumSize = System::Drawing::Size(550, 80);
			this->Name = L"MyForm";
			this->Text = L"POO Groupe 1";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void commande_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	EnumVar::type_Seach clicInfo = EnumVar::type_Seach(EnumVar::COMMAND);
	Form_Search^ aaa = gcnew Form_Search(clicInfo);
	aaa->ShowDialog();


	/*POOProjet::Form_Search form_Search;
	form_Search.Text = "Search Commande";
	form_Search.ShowDialog();*/
}
private: System::Void personnel_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	EnumVar::type_Seach clicInfo = EnumVar::type_Seach(EnumVar::PERSONNEL);
	Form_Search^ aaa = gcnew Form_Search(clicInfo);
	aaa->ShowDialog();
}
};
}
