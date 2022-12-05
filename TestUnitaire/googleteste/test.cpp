#include "pch.h"
#include "../TestUnitaire/add.h"
add t;

TEST(TestCaseName, TestName) {
	add a = add(4, 1);
	//a.addd();
	EXPECT_EQ(5, a.addd());
}