#include "Connection_DB.h"

Connection_DB::Connection_DB(void) {
	//PC MAIN DESKTOP-211D050
	//PC PRO LAPTOP-3UJO5NIH
	this->sCnx = "Data Source=DESKTOP-211D050;Initial Catalog=POO_Projet;Integrated Security=True";
	//this->sCnx = "Data Source=LAPTOP-3UJO5NIH;Initial Catalog=POO_Projet;Integrated Security=True";
	 
	this->sSql = "Initialisation";

	this->oCnx = gcnew System::Data::SqlClient::SqlConnection(this->sCnx);
	this->oCmd = gcnew System::Data::SqlClient::SqlCommand(this->sSql, this->oCnx);
	this->oDA = gcnew System::Data::SqlClient::SqlDataAdapter();
	this->oDs = gcnew System::Data::DataSet();

	this->oCmd->CommandType = System::Data::CommandType::Text;
}
System::Data::DataSet^ Connection_DB::select(System::String^ sSql, System::String^ sDataTableName) {
	this->oDs->Clear();
	this->sSql = sSql;
	this->oCmd->CommandText = this->sSql;
	this->oDA->SelectCommand = this->oCmd;
	this->oDA->Fill(this->oDs, sDataTableName);

	return this->oDs;
}
void Connection_DB::execute(System::String^ sSql) {
	this->sSql = sSql;
	this->oCmd->CommandText = this->sSql;
	this->oDA->SelectCommand = this->oCmd;
	this->oCnx->Open();
	this->oCmd->ExecuteNonQuery();
	this->oCnx->Close();
}

System::Data::SqlClient::SqlConnection^ Connection_DB::getoCnx() {
	return this->oCnx;
}
