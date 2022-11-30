#include "Address.h"
#include "Row.h"

Address::Address() {
    this->address = gcnew DB_Address();
    this->city = gcnew DB_City;
    this->country = gcnew DB_Country;
}

Address::Address(int idAddress) {
    Address(idAddress, false);
}

Address::Address(int idAddress, bool clientAddress) {
    System::String^ sqlRequest;
    if (clientAddress) {
        sqlRequest = "SELECT AddressCC.ID_Address, AddressCC.ID_City, AddressCC.ID_Country, AddressCC.street_Number, AddressCC.street, AddressCC.additionnal_Data, AddressCC.name, AddressCC.name, AddressCC.postal_Number, Get_Client_Address.is_Billing FROM (SELECT AddressC.ID_Address, AddressC.ID_City, AddressC.ID_Country, AddressC.street_Number, AddressC.street, AddressC.additionnal_Data, AddressC.name, City.name AS nameCity , City.postal_Number FROM (SELECT Address.ID_Address, Address.ID_City, Address.ID_Country, Address.street_Number, Address.street, Address.additionnal_Data, Country.name FROM (SELECT * FROM Address WHERE ID_Address = "+ idAddress +") AS Address INNER JOIN Country ON Address.ID_Country = Country.ID_Country) AS AddressC INNER JOIN City ON AddressC.ID_City = City.ID_City) AS AddressCC INNER JOIN Get_Client_Address ON AddressCC.ID_Address = Get_Client_Address.ID_Address";
    } else {
        sqlRequest = "SELECT AddressC.ID_Address, AddressC.ID_City, AddressC.ID_Country, AddressC.street_Number, AddressC.street, AddressC.additionnal_Data, AddressC.name, City.name, City.postal_Number FROM (SELECT Address.ID_Address, Address.ID_City, Address.ID_Country, Address.street_Number, Address.street, Address.additionnal_Data, Country.name FROM (SELECT * FROM Address WHERE ID_Address = "+ idAddress +") AS Address INNER JOIN Country ON Address.ID_Country = Country.ID_Country) AS AddressC INNER JOIN City ON AddressC.ID_City = City.ID_City";
    }
    Row^ result = connection->selectRow(sqlRequest, "Address");
    result->setRow(0);
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
