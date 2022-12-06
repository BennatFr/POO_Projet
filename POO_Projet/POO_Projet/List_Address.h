#include "Address.h"

ref class List_Address {
private:
	List_Address^ next;
	Address^ value;
public:
	List_Address();
	List_Address(Address^ address);
	List_Address(List_Address^ listAddress, Address^ address);

	~List_Address();

	void setFirst(Address^ address);
	void setLast(Address^ address);
	void set(Address^ address, int i);

	Address^ getFirst();
	Address^ getLast();
	Address^ get(int i);

	List_Address^ getLastList();
	List_Address^ getList(int i);

	int getSize();
};
