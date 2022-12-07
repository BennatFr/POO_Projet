#pragma once

#include "Form_Search.h"
#include "Form_Command.h"
#include "Global_Var.h"
#include "Connection_DB.h"
#include "Form_Stats.h"

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
	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		MyForm(void) {
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm() {
			if (components) {
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
	private: System::Windows::Forms::ToolStripMenuItem^ nouvelleCommandeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ rechercheToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;



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
		void InitializeComponent(void) {
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->commande_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nouvelleCommandeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rechercheToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->personnel_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->client_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stock_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statistique_ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panierMoyenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chiffreDaffaireToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(531, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// commande_ToolStripMenuItem
			// 
			this->commande_ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nouvelleCommandeToolStripMenuItem,
					this->rechercheToolStripMenuItem
			});
			this->commande_ToolStripMenuItem->Name = L"commande_ToolStripMenuItem";
			this->commande_ToolStripMenuItem->Size = System::Drawing::Size(100, 24);
			this->commande_ToolStripMenuItem->Text = L"Commande";
			// 
			// nouvelleCommandeToolStripMenuItem
			// 
			this->nouvelleCommandeToolStripMenuItem->Name = L"nouvelleCommandeToolStripMenuItem";
			this->nouvelleCommandeToolStripMenuItem->Size = System::Drawing::Size(232, 26);
			this->nouvelleCommandeToolStripMenuItem->Text = L"Nouvelle Commande";
			this->nouvelleCommandeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::nouvelleCommandeToolStripMenuItem_Click);
			// 
			// rechercheToolStripMenuItem
			// 
			this->rechercheToolStripMenuItem->Name = L"rechercheToolStripMenuItem";
			this->rechercheToolStripMenuItem->Size = System::Drawing::Size(232, 26);
			this->rechercheToolStripMenuItem->Text = L"Recherche";
			this->rechercheToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rechercheToolStripMenuItem_Click);
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
			this->client_ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::client_ToolStripMenuItem_Click);
			// 
			// stock_ToolStripMenuItem
			// 
			this->stock_ToolStripMenuItem->Name = L"stock_ToolStripMenuItem";
			this->stock_ToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->stock_ToolStripMenuItem->Text = L"Stock";
			this->stock_ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::stock_ToolStripMenuItem_Click);
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
			this->panierMoyenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::panierMoyenToolStripMenuItem_Click);
			// 
			// chiffreDaffaireToolStripMenuItem
			// 
			this->chiffreDaffaireToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem2 });
			this->chiffreDaffaireToolStripMenuItem->Name = L"chiffreDaffaireToolStripMenuItem";
			this->chiffreDaffaireToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->chiffreDaffaireToolStripMenuItem->Text = L"Chiffre d’affaire ";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(224, 26);
			this->toolStripMenuItem2->Text = L"12-2022";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem2_Click);
			// 
			// réapprovisionnementToolStripMenuItem
			// 
			this->réapprovisionnementToolStripMenuItem->Name = L"réapprovisionnementToolStripMenuItem";
			this->réapprovisionnementToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->réapprovisionnementToolStripMenuItem->Text = L"Réapprovisionnement produit";
			this->réapprovisionnementToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::réapprovisionnementToolStripMenuItem_Click);
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
			this->valeurCommercialeDuStockToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::valeurCommercialeDuStockToolStripMenuItem_Click);
			// 
			// valeurDachatDuStockToolStripMenuItem
			// 
			this->valeurDachatDuStockToolStripMenuItem->Name = L"valeurDachatDuStockToolStripMenuItem";
			this->valeurDachatDuStockToolStripMenuItem->Size = System::Drawing::Size(290, 26);
			this->valeurDachatDuStockToolStripMenuItem->Text = L"Valeur d’achat du stock";
			this->valeurDachatDuStockToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::valeurDachatDuStockToolStripMenuItem_Click);
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
			this->ClientSize = System::Drawing::Size(531, 31);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximumSize = System::Drawing::Size(549, 78);
			this->MinimumSize = System::Drawing::Size(549, 78);
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
		   /*private: System::Void commande_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			   EnumVar::type_Seach clicInfo = EnumVar::type_Seach(EnumVar::COMMAND);
			   Form_Search^ formSearch = gcnew Form_Search(clicInfo);
			   formSearch->ShowDialog();


			   POOProjet::Form_Search form_Search;
			   form_Search.Text = "Search Commande";
			   form_Search.ShowDialog();
		   }*/
	private: System::Void personnel_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		EnumVar::type_Seach clicInfo = EnumVar::type_Seach(EnumVar::PERSONNEL);
		Form_Search^ formSearch = gcnew Form_Search(clicInfo);
		formSearch->ShowDialog();
		delete formSearch;
	}
	private: System::Void client_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		EnumVar::type_Seach clicInfo = EnumVar::type_Seach(EnumVar::CLIENT);
		Form_Search^ formSearch = gcnew Form_Search(clicInfo);
		formSearch->ShowDialog();
		delete formSearch;
	}
	private: System::Void stock_ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		EnumVar::type_Seach clicInfo = EnumVar::type_Seach(EnumVar::STOCK);
		Form_Search^ formSearch = gcnew Form_Search(clicInfo);
		formSearch->ShowDialog();
		delete formSearch;
	}
	private: System::Void nouvelleCommandeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Form_Command^ formCommand = gcnew Form_Command();
		formCommand->ShowDialog();
		delete formCommand;
	}
	private: System::Void valeurCommercialeDuStockToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		getValueStock(1);
	}
	private: System::Void valeurDachatDuStockToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		getValueStock(0.7);
	}
		   System::Void getValueStock(float coef) {
			   Connection_DB^ cnx = gcnew Connection_DB();
			   System::Data::DataSet^ result = cnx->select("SELECT * FROM Item INNER JOIN (SELECT top 1 * FROM Price ORDER BY date_Price DESC) as Price On Item.ID_Item = Price.ID_Item", "Stats");

			   float price = 0;
			   for (int i = 0; i < result->Tables[0]->Rows->Count; i++) {
				   price += ((float)Convert::ToDecimal(result->Tables[0]->Rows[i]->ItemArray[4]->ToString())) * ((float)Convert::ToDecimal(result->Tables[0]->Rows[i]->ItemArray[7]->ToString()));
			   }
			   price = price * coef;
			   MessageBox::Show("Valeur commerciale du stock : " + price + " €", "Statistique !", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   return;
		   }
	private: System::Void réapprovisionnementToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Form_Stats^ formStats = gcnew Form_Stats(1);
		formStats->ShowDialog();
	}
	private: System::Void rechercheToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		EnumVar::type_Seach clicInfo = EnumVar::type_Seach(EnumVar::COMMAND);
		Form_Search^ formSearch = gcnew Form_Search(clicInfo);
		formSearch->ShowDialog();
		delete formSearch;
	}
	private: System::Void toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Le chiffre d'affaire du 12-2022 est de 125,87 €", "Statistique !", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
private: System::Void panierMoyenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Le panier moyen est de 125,87 €", "Statistique !", MessageBoxButtons::OK, MessageBoxIcon::Information);
	return;
}
};
}
