#pragma once
ref class DB_Command_Contain {
private:
	int ID_Contain;
	int ID_Command;
	int ID_Item;
	float quantity;
	float discount;
public:
	DB_Command_Contain();
	DB_Command_Contain(int ID_Contain, int ID_Command, int ID_Item, float quantity, float discount);

	int getIDContain();
	int getIDCommand();
	int getIDItem();
	float getQuantity();
	float getDiscount();

	void setIDContain(int ID_Contain);
	void setIDCommand(int ID_Command);
	void setIDItem(int ID_Item);
	void setQuantity(float quantity);
	void setDiscount(float discount);
};