#include "Client.h"

Client::Client() {
	this->client = gcnew DB_Client();
	this->people = gcnew DB_People();
	this->list_Address = gcnew List_Address();
}

Client::Client(int ID_Client) {
	System::String^ sqlRequest = "SELECT * FROM Get_Client_Address WHERE ID_Client = " + ID_Client;
	System::Data::DataSet^ dataSet = connection->select(sqlRequest, "Get_Client_Address");
	for (int i = 0; i < dataSet->Tables["Get_Client_Address"]->Rows->Count; i++) {
		int ID_Address = System::Convert::ToInt32(dataSet->Tables["Get_Client_Address"]->Rows[i]->ItemArray[1]->ToString());
		list_Address->setLast(gcnew Address(ID_Address, true));
	}
	sqlRequest = "SELECT * FROM (SELECT * FROM Client WHERE ID_Client = " + ID_Client + ") as Client INNER JOIN People ON CLient.ID_People = People.ID_People";
	Row^ result = connection->selectRow(sqlRequest, "Client", 0);
	//int ID_Client, System::DateTime birthdate, System::DateTime first_Buy_Website, int ID_People
 	this->client = gcnew DB_Client(ID_Client, result->getDateTime(1), result->getDateTime(2), result->getInt(3));
	//int ID_People, System::String^ last_Name, System::String^ first_Name
	this->people = gcnew DB_People(result->getInt(3), result->getString(5), result->getString(6));
}

int Client::getClientID()
{
	return this->getClient()->getIDClient();
}

DB_Client^ Client::getClient() {
	return this->client;
}

DB_People^ Client::getPeople() {
	return this->people;
}

List_Address^ Client::getListAddress() {
	return this->list_Address;
}

void Client::setClient(DB_Client^ client) {
	this->client = client;
}

void Client::setPeople(DB_People^ people) {
	this->people = people;
}

void Client::setListAddress(List_Address^ list_Address) {
	this->list_Address = list_Address;
}

void Client::setIDPeople(int ID_People) {
	this->getClient()->setIDPeople(ID_People);
	this->getPeople()->setIDPeople(ID_People);
}

void Client::setIDAddress(int ID_Address) {
	throw gcnew System::NotImplementedException();
}

int Client::insert() {
	System::String^ sqlRequest;
	Row^ result;
	sqlRequest = "SELECT Count(*) FROM Client WHERE ID_Client = " + this->getClientID();
	result = connection->selectRow(sqlRequest, "Client", 0);
	if (result->getInt(0) == 0) {
		return 1;
	}

	if (this->getPeople() != nullptr) {
		sqlRequest = "INSERT INTO People VALUES ('" + this->getPeople()->getLastName() + "', '" + this->getPeople()->getFirstName() + "')";
		connection->execute(sqlRequest);
		sqlRequest = "SELECT TOP 1 * FROM People ORDER BY ID_People DESC";
		result = connection->selectRow(sqlRequest, "People", 0);
		this->setIDPeople(result->getInt(0));
	}
}

int Client::update() {
	return 0;
}

int Client::del() {
	for (int i = 0; i < this->getListAddress()->getSize(); i++) {
		this->getListAddress()->get(i)->del();
	}
	System::String^ sqlRequest;

	sqlRequest = "DELETE FROM People WHERE ID_People = " + this->getPeople()->getIDPeople();
	connection->execute(sqlRequest);
	sqlRequest = "DELETE FROM Client WHERE ID_Client = " + this->getClient()->getIDClient();
	connection->execute(sqlRequest);
	return 0;
	
}
