#include "Item.h"

ref class List_Item {
private:
	List_Item^ next;
	Item^ value;
public:
	List_Item();
	List_Item(Item^ item);
	List_Item(List_Item^ listItem, Item^ item);

	void setFirst(Item^ item);
	void setLast(Item^ item);
	void set(Item^ item, int i);

	Item^ getFirst();
	Item^ getLast();
	Item^ get(int i);

	List_Item^ getLastList();
	List_Item^ getList(int i);

	int getSize();
};
