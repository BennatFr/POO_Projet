#pragma once
ref class DB_Item {
private:
	int ID_Item;
	System::String^ reference;
	System::String^ name;
	float replenishment;
	float stock;
	float quantity;
	float discount;
	int ID_Type;
public:
	DB_Item();
	DB_Item(int ID_Item, System::String^ reference, System::String^ name, float replenishment, float stock, float quantity, float discount, int ID_Type);

	int getIDItem();
	System::String^ getReference();
	System::String^ getName();
	float getReplenishment();
	float getStock();
	float getQuantity();
	float getDiscount();
	int getIDType();

	void setIDItem(int ID_Item);
	void setReference(System::String^ reference);
	void setName(System::String^ name);
	void setReplenishment(float replenishment);
	void setStock(float stock);
	void setQuantity(float quantity);
	void setDiscount(float discount);
	void setIDType(int ID_Type);
};

