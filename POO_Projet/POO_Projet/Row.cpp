#include "Row.h"

Row::Row(System::Data::DataSet^ dataSet) {
	this->dataSet = dataSet;
}

Row::Row(System::Data::DataSet^ dataSet, System::String^ table) {
	this->dataSet = dataSet;
	this->table = table;
}

Row::Row(System::Data::DataSet^ dataSet, System::String^ table, int row) {
	this->dataSet = dataSet;
	this->table = table;
	this->row = row;
}

System::Data::DataSet^ Row::getDataSet() {
	return this->dataSet;
}

System::String^ Row::getTable() {
	return this->table;
}

int Row::getRow() {
	return this->row;
}

void Row::setDataSet(System::Data::DataSet^ dataSet) {
	this->dataSet = dataSet;
}

void Row::setTable(System::String^ table) {
	this->table = table;
}

void Row::setRow(int row) {
	this->row = row;
}

System::String^ Row::getString(int column) {
	if (this->dataSet->Tables[this->table]->Rows[this->row]->ItemArray[column] == System::DBNull::Value) {
		return nullptr;
	}
	return this->dataSet->Tables[this->table]->Rows[this->row]->ItemArray[column]->ToString();
}

int Row::getInt(int column) {
	System::String^ s = this->getString(column);
	if (s == nullptr) {
		return 0;
	}
	delete s;
	return System::Convert::ToInt32(this->getString(column));
}

float Row::getFloat(int column) {
	return (float)System::Convert::ToDecimal(this->getString(column));
}

bool Row::getBool(int column) {
	System::String^ s = this->getString(column);
	if (s == nullptr) {
		return nullptr;
	}
	delete s;
	return System::Convert::ToBoolean(this->getString(column));
}

System::DateTime Row::getDateTime(int column) {
	return System::Convert::ToDateTime(this->getString(column));
}
