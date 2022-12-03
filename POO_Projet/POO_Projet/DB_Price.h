#pragma once
ref class DB_Price {
private:
	int ID_Price;
	float price;
	float VAT;
	System::DateTime date_Price;
	int ID_Item;
public:
	DB_Price();
	DB_Price(int ID_Price, float price, float VAT, System::DateTime date_Price, int ID_Item);

	int getIDPrice();
	float getPrice();
	float getVAT();
	System::DateTime getDatePrice();
	int getIDItem();

	void setIDPrice(int ID_Price);
	void setPrice(float price);
	void setVAT(float VAT);
	void setDatePrice(System::DateTime date_Price);
	void setIDItem(int ID_Item);
};

