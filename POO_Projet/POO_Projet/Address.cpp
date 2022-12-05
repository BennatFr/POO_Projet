#include "Address.h"
#include "Row.h"

Address::Address() {
	this->address = gcnew DB_Address();
	this->city = gcnew DB_City;
	this->country = gcnew DB_Country;
}

Address::Address(int idAddress, bool clientAddress) {
	System::String^ sqlRequest;
	if (clientAddress) {
		sqlRequest = "SELECT AddressCC.ID_Address, AddressCC.ID_City, AddressCC.ID_Country, AddressCC.street_Number, AddressCC.street, AddressCC.additionnal_Data, AddressCC.nameCountry, AddressCC.nameCity, AddressCC.postal_Number, Get_Client_Address.is_Billing FROM (SELECT AddressC.ID_Address, AddressC.ID_City, AddressC.ID_Country, AddressC.street_Number, AddressC.street, AddressC.additionnal_Data, AddressC.nameCountry, City.name AS nameCity , City.postal_Number FROM (SELECT Address.ID_Address, Address.ID_City, Address.ID_Country, Address.street_Number, Address.street, Address.additionnal_Data, Country.name AS nameCountry FROM (SELECT * FROM Address WHERE ID_Address = " + idAddress + ") AS Address INNER JOIN Country ON Address.ID_Country = Country.ID_Country) AS AddressC INNER JOIN City ON AddressC.ID_City = City.ID_City) AS AddressCC INNER JOIN Get_Client_Address ON AddressCC.ID_Address = Get_Client_Address.ID_Address";
	} else {
		sqlRequest = "SELECT AddressC.ID_Address, AddressC.ID_City, AddressC.ID_Country, AddressC.street_Number, AddressC.street, AddressC.additionnal_Data, AddressC.name, City.name, City.postal_Number FROM (SELECT Address.ID_Address, Address.ID_City, Address.ID_Country, Address.street_Number, Address.street, Address.additionnal_Data, Country.name FROM (SELECT * FROM Address WHERE ID_Address = " + idAddress + ") AS Address INNER JOIN Country ON Address.ID_Country = Country.ID_Country) AS AddressC INNER JOIN City ON AddressC.ID_City = City.ID_City";
	}
	Row^ result = connection->selectRow(sqlRequest, "Address", 0);
	//int ID_Address, int street_Number, System::String^ street, System::String^ additionnal_Data, int ID_City, int ID_Country
	this->address = gcnew DB_Address(result->getInt(0), result->getInt(3), result->getString(4), result->getString(5), result->getInt(1), result->getInt(2));
	//int ID_City, System::String^ name, System::String^ postal_number
	this->city = gcnew DB_City(result->getInt(1), result->getString(7), result->getString(8));
	//int ID_Country, System::String^ name
	this->country = gcnew DB_Country(result->getInt(2), result->getString(6));
	if (clientAddress) {
		//int idClient, int idAddress, bool billing
		this->client_Address = gcnew DB_Client_Address(0, result->getInt(0), result->getBool(9));
	}
}

Address::Address(DB_Address^ address, DB_City^ city, DB_Country^ country) {
	this->address = address;
	this->city = city;
	this->country = country;
}

Address::Address(DB_Address^ address, DB_City^ city, DB_Country^ country, DB_Client_Address^ client_Address) {
	this->address = address;
	this->city = city;
	this->country = country;
	this->client_Address = client_Address;
}

DB_Address^ Address::getAddress() {
	return this->address;
}

DB_City^ Address::getCity() {
	return this->city;
}

DB_Country^ Address::getCountry() {
	return this->country;
}

DB_Client_Address^ Address::getClientAddress() {
	return this->client_Address;
}

void Address::setAddress(DB_Address^ address) {
	this->address = address;
}

void Address::setCity(DB_City^ city) {
	this->city = city;
}

void Address::setCountry(DB_Country^ country) {
	this->country = country;
}

void Address::setClientAddress(DB_Client_Address^ client_Address) {
	this->client_Address = client_Address;
}

void Address::setIDAddress(int id) {
	this->getAddress()->setIDAddress(id);
	if (this->getClientAddress() != nullptr) {
		this->getClientAddress()->setIdAddress(id);
	}
}

void Address::setIDCountry(int id) {
	this->getAddress()->setIDCountry(id);
	this->getCountry()->setIDCountry(id);
}

void Address::setIDCity(int id) {
	this->getAddress()->setIDCity(id);
	this->getCity()->setIDCity(id);
}

int Address::save() {
	System::String^ sqlRequest;
	if (this->getCountry() != nullptr) {
		sqlRequest = "SELECT Count(*) FROM Country WHERE name = '" + this->getCountry()->getName() + "'";
		Row^ result = connection->selectRow(sqlRequest, "Country", 0);
		if (result->getInt(0) == 0) {
			sqlRequest = "INSERT INTO Country VALUES ('" + this->getCountry()->getName() + "')";
			connection->execute(sqlRequest);
			sqlRequest = "SELECT TOP 1 * FROM Country ORDER BY ID_Country DESC";
			result = connection->selectRow(sqlRequest, "Country", 0);
			this->setIDCountry(result->getInt(0));
		} else {
			sqlRequest = "SELECT * FROM Country WHERE name = '" + this->getCountry()->getName() + "'";
			result = connection->selectRow(sqlRequest, "Country", 0);
			this->setIDCountry(result->getInt(0));
		}
	}

	if (this->getCity() != nullptr) {
		sqlRequest = "SELECT Count(*) FROM City WHERE name = '" + this->getCity()->getName() + "' AND postal_Number = '" + this->getCity()->getPostalNumber() + "'";
		Row^ result = connection->selectRow(sqlRequest, "City", 0);
		if (result->getInt(0) == 0) {
			sqlRequest = "INSERT INTO City VALUES ('" + this->getCity()->getName() + "', '" + this->getCity()->getPostalNumber() + "')";
			connection->execute(sqlRequest);
			sqlRequest = "SELECT TOP 1 * FROM City ORDER BY ID_City DESC";
			result = connection->selectRow(sqlRequest, "City", 0);
			this->setIDCity(result->getInt(0));
		} else {
			sqlRequest = "UPDATE Country SET name = '" + this->getCountry()->getName() + "' WHERE ID_Country = " + this->getCountry()->getIDCountry();
			connection->execute(sqlRequest);
		}
	}
	return 0;
}

int Address::insert(int ID_Client) {
	System::String^ sqlRequest;
	this->save();
	if (this->getAddress() != nullptr) {
		if (this->getAddress()->getIDCity() == 0) {
			sqlRequest = "SELECT Count(*) FROM City WHERE name = '" + this->getCity()->getName() + "' AND postal_Number = '" + this->getCity()->getPostalNumber() + "'";
			Row^ result = connection->selectRow(sqlRequest, "City", 0);
			if (result->getInt(0) == 0) {
				sqlRequest = "INSERT INTO City VALUES ('" + this->getCity()->getName() + "', '" + this->getCity()->getPostalNumber() + "')";
				connection->execute(sqlRequest);
			}
			sqlRequest = "SELECT TOP 1 * FROM City ORDER BY ID_City DESC";
			result = connection->selectRow(sqlRequest, "City", 0);
			this->setIDCity(result->getInt(0));
		}
		if (this->getAddress()->getIDCountry() == 0) {
			sqlRequest = "SELECT * FROM Country WHERE name = '" + this->getCountry()->getName() + "'";
			Row^ result = connection->selectRow(sqlRequest, "Country", 0);
			if (result->getInt(0) == 0) {
				sqlRequest = "INSERT INTO Country VALUES ('" + this->getCountry()->getName() + "')";
				connection->execute(sqlRequest);
			}
			sqlRequest = "SELECT TOP 1 * FROM Country ORDER BY ID_Country DESC";
			result = connection->selectRow(sqlRequest, "Country", 0);
			this->setIDCountry(result->getInt(0));
		}
		sqlRequest = "INSERT INTO Address VALUES (" + this->getAddress()->getStreetNumber() + ", '" + this->getAddress()->getStreet() + "', '" + this->getAddress()->getAdditionnalData() + "', " + this->getAddress()->getIDCity() + ", " + this->getAddress()->getIDCountry() + ")";
		connection->execute(sqlRequest);
		sqlRequest = "SELECT TOP 1 * FROM Address ORDER BY ID_Address DESC";
		Row^ result = connection->selectRow(sqlRequest, "Address", 0);
		this->setIDAddress(result->getInt(0));
	}

	if (this->getClientAddress() != nullptr) {
		sqlRequest = "INSERT INTO Get_Client_Address VALUES (" + ID_Client + ", " + this->getAddress()->getIDAddress() + ", " + System::Convert::ToInt32(this->getClientAddress()->isBilling()) + ")";
		connection->execute(sqlRequest);
	}

	return 0;
}

int Address::update() {
	System::String^ sqlRequest;
	this->save();
	if (this->getAddress() != nullptr) {
		sqlRequest = "UPDATE Address SET street_Number = " + this->getAddress()->getStreetNumber() + ", street = '" + this->getAddress()->getStreet() + "', additionnal_Data = '" + this->getAddress()->getAdditionnalData() + "', ID_City = " + this->getAddress()->getIDCity() + ", ID_Country = " + this->getAddress()->getIDCountry() + " WHERE ID_Address = " + this->getAddress()->getIDAddress();
		connection->execute(sqlRequest);
	}
	return 0;
}

int Address::del() {
	System::String^ sqlRequest;
	if (this->client_Address != nullptr) {
		sqlRequest = "DELETE FROM Get_Client_Address WHERE ID_Address = " + this->getAddress()->getIDAddress() + " AND ID_Client = " + this->getClientAddress()->getIdClient();
		connection->execute(sqlRequest);
		sqlRequest = "SELECT Count(*) FROM Get_Client_Address WHERE ID_Address = " + this->getAddress()->getIDAddress();
		Row^ result = connection->selectRow(sqlRequest, "Get_Client_Address", 0);
		if (result->getInt(0) > 0) {
			return 0;
		}
	}
	sqlRequest = "DELETE FROM Address WHERE ID_Address = " + this->getAddress()->getIDAddress();
	connection->execute(sqlRequest);
}
