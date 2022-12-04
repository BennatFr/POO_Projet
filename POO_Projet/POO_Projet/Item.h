#pragma once

#include "Connection_DB.h"
#include "DB_Price.h"
#include "DB_Item.h"
#include "DB_Type.h"

ref class Item {
private:
	Connection_DB^ connection = gcnew Connection_DB();
	DB_Price^ price;
	DB_Item^ item;
	DB_Type^ type;
public:
	Item();
	Item(int ID_Item);
	Item(int ID_Item, int ID_Command, int row);
	Item(DB_Price^ price, DB_Item^ item, DB_Type^ type);

	DB_Price^ getPrice();
	DB_Item^ getItem();
	DB_Type^ getType();

	void setPrice(DB_Price^ price);
	void setItem(DB_Item^ item);
	void setType(DB_Type^ type);

	int getItemID();
	void setIDType(int ID_Type);
	void setIDItem(int ID_Item);

	int getPriceUHT();
	int getPriceUTTC();
	int getPriceHT();
	int getPriceTTC();

	float getFloatPriceUHT();
	float getFloatPriceUTTC();
	float getFloatPriceHT();
	float getFloatPriceTTC();


	int insert();
	int update();
};

