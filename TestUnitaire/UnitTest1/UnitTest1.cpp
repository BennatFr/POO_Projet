#include "pch.h"
#include "CppUnitTest.h"
#include "../TestUnitaire/add.h"

#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int num1 = 56;
int num2 = 3;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(aaaa)
		{
			int res = num1 + num2;
			std::cout << res;
			Assert::AreEqual(res, 599);
		}
	};
}
