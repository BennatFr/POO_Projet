/*#include "pch.h"
#include "CppUnitTest.h"
#include "../POO_Projet/Personnel.h"
#include "../POO_Projet/DB_Personnel.h"
#include "../POO_Projet/Address.h"
#include "../POO_Projet/DB_People.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTestPersonnel {
	TEST_CLASS(UnitTestPersonnel) {
public:

	TEST_METHOD(TestMethod1) {
		//int ID_Personnel, System::DateTime hire_Date, int ID_Address, int ID_Superior, int ID_People
		DB_Personnel^ personnel = gcnew DB_Personnel(0, System::DateTime(), 0, 0, 0);
		//int ID_People, System::String^ last_Name, System::String^ first_Name
		Address^ address = gcnew Address(1, false);
		//int ID_People, System::String^ last_Name, System::String^ first_Name
		DB_People^ people = gcnew DB_People(1, "Ferrer", "Nathan");
		//DB_Personnel^ personnel, Address^ address, DB_People^ people
		Personnel^ p = gcnew Personnel(personnel, address, people);

		Assert::AreEqual(p->getPeople()->getLastName(), "Ferrer");
	}
	};
}*/