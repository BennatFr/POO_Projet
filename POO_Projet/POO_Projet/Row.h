#pragma once
ref class Row {
private:
	System::Data::DataSet^ dataSet;
	System::String^ table;
	int row = 0;
public:
	Row(System::Data::DataSet^ dataSet);
	Row(System::Data::DataSet^ dataSet, System::String^ table);
	Row(System::Data::DataSet^ dataSet, System::String^ table, int row);

	System::Data::DataSet^ getDataSet();
	System::String^ getTable();
	int getRow();

	void setDataSet(System::Data::DataSet^ dataSet);
	void setTable(System::String^ table);
	void setRow(int row);

	System::String^ getString(int column);
	int getInt(int column);
	bool getBool(int column);
	System::DateTime getDateTime(int column);
};

