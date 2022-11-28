#include "Personnel.h"

using namespace System;

Personnel::Personnel(){
}

Personnel::Personnel(System::String^ ID_Personnel){
	this->connection = gcnew Connection_DB();
	System::String^ sqlRequest = "SELECT * FROM[POO_Projet].[dbo].[Personnel]INNER JOIN[POO_Projet].[dbo].[Address] ON[POO_Projet].[dbo].[Personnel].[ID_Address] = [POO_Projet].[dbo].[Address].[ID_Address]INNER JOIN[POO_Projet].[dbo].[Country]ON[POO_Projet].[dbo].[Address].[ID_Country] = [POO_Projet].[dbo].[Country].[ID_Country]INNER JOIN[POO_Projet].[dbo].[City]ON[POO_Projet].[dbo].[Address].[ID_City] = [POO_Projet].[dbo].[City].[ID_City]INNER JOIN[POO_Projet].[dbo].[People]ON[POO_Projet].[dbo].[Personnel].[ID_People] = [POO_Projet].[dbo].[People].[ID_People]WHERE[POO_Projet].[dbo].[Personnel].[ID_Personnel] = ";
	//System::String^ sqlRequest = gcnew System::String((a + ID_Personnel).c_str());
	System::Data::DataSet^ result = connection->select(sqlRequest + ID_Personnel, "Personnel");
	//personnel
	int ID_Personnel_Int = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[0]->ToString());
	System::String^ hire_Date = result->Tables["Personnel"]->Rows[0]->ItemArray[1]->ToString();
	int ID_Address = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[5]->ToString());
	int ID_Superior = 0;
	if (result->Tables["Personnel"]->Rows[0]->ItemArray[3] != System::DBNull::Value) {
		ID_Superior = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[3]->ToString());
	} else {
		ID_Superior = 0;
	}
	int ID_People = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[4]->ToString());
	this->personnel = gcnew DB_Personnel(ID_Personnel_Int, "", ID_Address, ID_Superior, ID_People);
	//address
	int street_Number = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[6]->ToString());
	System::String^ street = result->Tables["Personnel"]->Rows[0]->ItemArray[7]->ToString();
	System::String^ additionnal_Data = result->Tables["Personnel"]->Rows[0]->ItemArray[8]->ToString();
	int ID_City = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[9]->ToString());
	int ID_Country = int::Parse(result->Tables["Personnel"]->Rows[0]->ItemArray[10]->ToString());
	this->address = gcnew DB_Address(ID_Address, street_Number, street, additionnal_Data, ID_City, ID_Country);
	//city
	System::String^ city_Name = result->Tables["Personnel"]->Rows[0]->ItemArray[14]->ToString();
	System::String^ postal_Number = result->Tables["Personnel"]->Rows[0]->ItemArray[15]->ToString();
	this->city = gcnew DB_City(ID_City, city_Name, postal_Number);
	//country
	System::String^ country_Name = result->Tables["Personnel"]->Rows[0]->ItemArray[12]->ToString();
	this->country = gcnew DB_Country(ID_Country, country_Name);
	//people
	System::String^ last_Name = result->Tables["Personnel"]->Rows[0]->ItemArray[17]->ToString();
	System::String^ first_Name = result->Tables["Personnel"]->Rows[0]->ItemArray[18]->ToString();
	this->people = gcnew DB_People(ID_People, last_Name, first_Name);
}

int Personnel::getPersonnelID() {
	return this->personnel->getIDPersonnel();
}

DB_Personnel^ Personnel::getPersonnel() {
	return this->personnel;
}

DB_Address^ Personnel::getAddress() {
	return this->address;
}

DB_City^ Personnel::getCity() {
	return this->city;
}

DB_Country^ Personnel::getCountry() {
	return this->country;
}

DB_People^ Personnel::getPeople() {
	return this->people;
}
