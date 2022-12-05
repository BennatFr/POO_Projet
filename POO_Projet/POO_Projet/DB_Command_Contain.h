#pragma once
ref class DB_Command_Contain {
private:
	int ID_Contain;
	int ID_Country;
	int ID_Item;
	float quantity;
	float discount;
public:
	DB_Command_Contain();
	DB_Command_Contain(int ID_Contain, int ID_Country, int ID_Item, float quantity, float discount);

	int getIDContain();
	int getIDCountry();
	int getIDItem();
	float getQuantity();
	float getDiscount();

	void setIDContain(int ID_Contain);
	void setIDCountry(int ID_Country);
	void setIDItem(int ID_Item);
	void setQuantity(float quantity);
	void setDiscount(float discount);
};