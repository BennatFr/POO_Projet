#pragma once
#include "Row.h"

ref class Connection_DB {
private:
	System::String^ sSql;
	System::String^ sCnx;
	System::Data::SqlClient::SqlConnection^ oCnx;
	System::Data::SqlClient::SqlCommand^ oCmd;
	System::Data::SqlClient::SqlDataAdapter^ oDA;
	System::Data::DataSet^ oDs;
public:
	Connection_DB(void);
	System::Data::DataSet^ select(System::String^, System::String^);
	Row^ selectRow(System::String^, System::String^);
	void execute(System::String^);
	System::Data::SqlClient::SqlConnection^ getoCnx();
};