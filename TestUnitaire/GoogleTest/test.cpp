#include "pch.h"
#include "add.h"

add t;

TEST(TestCaseName, fourPlusOne) {
	add a = add(4, 1);
	//a.addd();
  EXPECT_EQ(5, a.addd());
}