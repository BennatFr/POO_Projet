#include "Personnel.h"

using namespace System;

Personnel::Personnel(){
	this->personnel = gcnew DB_Personnel();
	this->address = gcnew Address();
	this->people = gcnew DB_People();
}

Personnel::Personnel(int ID_Personnel){
	this->address = gcnew Address(ID_Personnel);

	//SELECT Personnel.ID_People, Personnel.ID_Personnel, Personnel.hire_Date, people.last_Name, People.first_Name FROM Personnel INNER JOIN People ON Personnel.ID_People = People.ID_People
	System::String^ sqlRequest;
	Row^ result = connection->selectRow(sqlRequest, "Personnel");
	result->setRow(0);
	//int ID_Personnel, System::String^ hire_Date, int ID_Address, int ID_Superior, int ID_People
	this->personnel = gcnew DB_Personnel(result->getInt(0), result->getString(4), result->getInt(3), result->getInt(2), result->getInt(1));
	//int ID_People, System::String^ last_Name, System::String^ first_Name
	this->people = gcnew DB_People();
}

int Personnel::getPersonnelID() {
	return this->personnel->getIDPersonnel();
}

DB_Personnel^ Personnel::getPersonnel() {
	return this->personnel;
}

Address^ Personnel::getAddress()
{
	return this->address;
}

DB_People^ Personnel::getPeople() {
	return this->people;
}

void Personnel::setPersonnel(DB_Personnel^ personnel)
{
	this->personnel = personnel;
}

void Personnel::setAddress(Address^ address)
{
	this->address = address;
}

void Personnel::setPeople(DB_People^ people)
{
	this->people = people;
}


void Personnel::setIDPeople(int ID_People)
{
	this->getPeople()->setIDPeople(ID_People);
	this->getPersonnel()->setIDPeople(ID_People);
}

void Personnel::setIDAddress(int ID_Address)
{
	this->getPersonnel()->setIDAddress(ID_Address);
	this->getAddress()->setIDAddress(ID_Address);
}

/*bool Personnel::save() {
	// Verif country // a mettre dans class Country
	System::String^ sqlRequest = "SELECT Count(*) FROM Country WHERE name = '"+ this->getCountry()->getName() + "'";
	System::Data::DataSet^ verif = this->connection->select(sqlRequest, "Country");
	if (verif->Tables["Country"]->Rows[0]->ItemArray[0]->ToString() == "0") {
		return false;
	}
	// Verif city // a mettre dans class City
	sqlRequest = "SELECT Count(*) FROM City WHERE name = '" + this->getCity()->getName() + "' AND postal_Number = '"+ this->getCity()->getPostalNumber() + "'";
	verif = this->connection->select(sqlRequest, "City");
	if (verif->Tables["City"]->Rows[0]->ItemArray[0]->ToString() == "0") {
		return false;
	}
	delete verif;

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
}*/
