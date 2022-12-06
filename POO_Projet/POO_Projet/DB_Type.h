#pragma once
ref class DB_Type {
private:
	int ID_Type;
	System::String^ name;
public:
	DB_Type();
	DB_Type(int ID_Type, System::String^ name);

	~DB_Type();

	int getIDType();
	System::String^ getName();

	void setIDType(int ID_Type);
	void setName(System::String^ name);
};

