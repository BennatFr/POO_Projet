#include "Payment.h"

ref class List_Payment {
private:
	List_Payment^ next;
	Payment^ value;
public:
	List_Payment();
	List_Payment(Payment^ payment);
	List_Payment(List_Payment^ listPayment, Payment^ payment);

	void setFirst(Payment^ payment);
	void setLast(Payment^ payment);
	void set(Payment^ payment, int i);

	Payment^ getFirst();
	Payment^ getLast();
	Payment^ get(int i);

	List_Payment^ getLastList();
	List_Payment^ getList(int i);

	int getSize();
};
