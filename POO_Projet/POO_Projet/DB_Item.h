#pragma once
ref class DB_Item {
private:
	int ID_Item;
	System::String^ reference;
	System::String^ name;
	float replenishment;
	float stock;
	int ID_Type;
public:
	DB_Item();
	DB_Item(int ID_Item, System::String^ reference, System::String^ name, float replenishment, float stock, int ID_Type);

	~DB_Item();

	int getIDItem();
	System::String^ getReference();
	System::String^ getName();
	float getReplenishment();
	float getStock();
	int getIDType();

	void setIDItem(int ID_Item);
	void setReference(System::String^ reference);
	void setName(System::String^ name);
	void setReplenishment(float replenishment);
	void setStock(float stock);
	void setIDType(int ID_Type);
};

