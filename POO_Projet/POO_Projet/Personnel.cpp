#include "Personnel.h"

using namespace System;

Personnel::Personnel(){
	this->connection = gcnew Connection_DB();
	this->personnel = gcnew DB_Personnel();
	this->address = gcnew DB_Address();
	this->city = gcnew DB_City();
	this->country = gcnew DB_Country();
	this->people = gcnew DB_People();
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

void Personnel::setIDPeople(int ID_People)
{
	this->getPeople()->setIDPeople(ID_People);
	this->getPersonnel()->setIDPeople(ID_People);
}

void Personnel::setIDCity(int ID_City)
{
	this->getCity()->setIDCity(ID_City);
	this->getAddress()->setIDCity(ID_City);
}

void Personnel::setIDAddress(int ID_Address)
{
	this->getPersonnel()->setIDAddress(ID_Address);
	this->getAddress()->setIDAddress(ID_Address);
}

void Personnel::setIDCountry(int ID_Country)
{
	this->getCountry()->setIDCountry(ID_Country);
	this->getAddress()->setIDCity(ID_Country);
}

bool Personnel::save() {
	// Verif country
	System::String^ sqlRequest = "SELECT Count(*) FROM Country WHERE name = '"+ this->getCountry()->getName() + "'";
	System::Data::DataSet^ verif = this->connection->select(sqlRequest, "Country");
	if (verif->Tables["Country"]->Rows[0]->ItemArray[0]->ToString() == "0") {
		return false;
	}
	// Verif city
	sqlRequest = "SELECT Count(*) FROM City WHERE name = '" + this->getCity()->getName() + "' AND postal_Number = '"+ this->getCity()->getPostalNumber() + "'";
	verif = this->connection->select(sqlRequest, "City");
	if (verif->Tables["City"]->Rows[0]->ItemArray[0]->ToString() == "0") {
		return false;
	}

	sqlRequest = "SELECT * FROM Country WHERE name = '" + this->getCountry()->getName() + "'";
	System::Data::DataSet^ country = this->connection->select(sqlRequest, "Country");
	this->setIDCountry(Convert::ToInt32(country->Tables["Country"]->Rows[0]->ItemArray[0]->ToString()));


	sqlRequest = "SELECT * FROM City WHERE name = '" + this->getCity()->getName() + "' AND postal_Number = '" + this->getCity()->getPostalNumber() + "'";
	System::Data::DataSet^ city = this->connection->select(sqlRequest, "City");
	this->setIDCity(Convert::ToInt32(city->Tables["City"]->Rows[0]->ItemArray[0]->ToString()));

	if (this->getPersonnelID() == 0) {
		//PEOPLE
		sqlRequest = "INSERT INTO People VALUES ('" + this->getPeople()->getLastName() + "', '" + this->getPeople()->getFirstName() + "')";
		connection->execute(sqlRequest);

		sqlRequest = "SELECT * FROM People WHERE last_Name = '" + this->getPeople()->getLastName() + "' AND first_Name = '" + this->getPeople()->getFirstName() + "'";
		System::Data::DataSet^ people = this->connection->select(sqlRequest, "People");
		this->setIDPeople(Convert::ToInt32(city->Tables["People"]->Rows[0]->ItemArray[0]->ToString()));

		// Address
		sqlRequest = "INSERT INTO Address SET (" + this->getAddress()->getStreetNumber() + ", '" + this->getAddress()->getStreet() + "', '" + this->getAddress()->getAdditionnalData() + "', '" + this->getAddress()->getIDAddress() + "', '" + this->getAddress()->getIDCountry() + "')";
		connection->execute(sqlRequest);

		sqlRequest = "SELECT * FROM Address WHERE street_Number = '" + this->getAddress()->getStreetNumber() + "' AND street = '" + this->getAddress()->getStreet() + "' AND ID_City = '" + this->getAddress()->getIDCity() + "' AND ID_Country = '" + this->getAddress()->getIDCountry() + "'";
		System::Data::DataSet^ address = this->connection->select(sqlRequest, "Address");
		this->setIDPeople(Convert::ToInt32(city->Tables["Address"]->Rows[0]->ItemArray[0]->ToString()));

		sqlRequest = "INSERT INTO Personnel VALUES ('27-11-2022', '" + this->getAddress()->getIDAddress() + "', "+ System::DBNull::Value +", '"+ this->getPeople()->getIDPeople() + "')";
		connection->execute(sqlRequest);
	}

	//PEOPLE
	sqlRequest = "UPDATE People SET first_Name = '" + this->getPeople()->getFirstName() +"', last_Name = '"+ this->getPeople()->getLastName()  +"' WHERE ID_People = " + this->getPeople()->getIDPeople();
	connection->execute(sqlRequest);
	// Address
	sqlRequest = "UPDATE Address SET street_Number = '"+ this->getAddress()->getStreetNumber() + "', street = '"+ this->getAddress()->getStreet() +"', additionnal_Data = '"+ this->getAddress()->getAdditionnalData() +"', ID_City = '"+ this->getAddress()->getIDAddress() + "', ID_Country = '" + this->getAddress()->getIDCountry() + "' WHERE ID_Address = " + this->getAddress()->getIDAddress();
	connection->execute(sqlRequest);
}
