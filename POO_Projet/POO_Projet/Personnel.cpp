#include "Personnel.h"

using namespace System;

Personnel::Personnel(){
}

Personnel::Personnel(System::String^ ID_Personnel){
	this->connection = gcnew Connection_DB();
	System::String^ sqlRequest = "SELECT * FROM[POO_Projet].[dbo].[Personnel]INNER JOIN[POO_Projet].[dbo].[Address] ON[POO_Projet].[dbo].[Personnel].[ID_Address] = [POO_Projet].[dbo].[Address].[ID_Address]INNER JOIN[POO_Projet].[dbo].[Country]ON[POO_Projet].[dbo].[Address].[ID_Country] = [POO_Projet].[dbo].[Country].[ID_Country]INNER JOIN[POO_Projet].[dbo].[City]ON[POO_Projet].[dbo].[Address].[ID_City] = [POO_Projet].[dbo].[City].[ID_City]INNER JOIN[POO_Projet].[dbo].[People]ON[POO_Projet].[dbo].[Personnel].[ID_People] = [POO_Projet].[dbo].[People].[ID_People]WHERE[POO_Projet].[dbo].[Personnel].[ID_Personnel] = ";
	//System::String^ sqlRequest = gcnew System::String((a + ID_Personnel).c_str());
	System::Data::DataSet^ result = connection->select(sqlRequest + ID_Personnel, "Personnel");

	int ID_Personnel_Int = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[0]->ToString());
	System::String^ hire_Date = result->Tables["Personnel"]->Rows[0]->ItemArray[1]->ToString();
	int ID_Address = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[5]->ToString());
	int ID_Superior = 0;
	if (result->Tables["Personnel"]->Rows[0]->ItemArray[3] != "NULL") {
		ID_Superior = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[3]->ToString());
	}
	int ID_People = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[4]->ToString());
	this->personnel = gcnew DB_Personnel(ID_Personnel_Int, "", ID_Address, ID_Superior, ID_People);
	this->address = gcnew DB_Address();
}

int Personnel::getPersonnelID()
{
	return this->personnel->getIDPersonnel();
}

DB_Personnel^ Personnel::getPersonnel()
{
	return this->personnel;
}

DB_Address^ Personnel::getAddress()
{
	return this->address;
}
