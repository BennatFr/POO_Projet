#include "Row.h"

Row::Row(System::Data::DataSet^ dataSet)
{
	this->dataSet = dataSet;
}

Row::Row(System::Data::DataSet^ dataSet, System::String^ table)
{
	this->dataSet = dataSet;
	this->table = table;
}

Row::Row(System::Data::DataSet^ dataSet, System::String^ table, int row)
{
	this->dataSet = dataSet;
	this->table = table;
	this->row = row;
}

System::Data::DataSet^ Row::getDataSet()
{
	return this->dataSet;
}

System::String^ Row::getTable()
{
	return this->table;
}

int Row::getRow()
{
	return this->row;
}

void Row::setDataSet(System::Data::DataSet^ dataSet)
{
	this->dataSet = dataSet;
}

void Row::setTable(System::String^ table)
{
	this->table = table;
}

void Row::setRow(int row)
{
	this->row = row;
}

System::String^ Row::getString(int column) {
	return this->dataSet->Tables[this->table]->Rows[this->row]->ItemArray[column]->ToString();
}

int Row::getInt(int column) {
	return System::Convert::ToInt32(this->getString(column));
}

bool Row::getBool(int column) {
	return System::Convert::ToBoolean(this->getString(column));
}