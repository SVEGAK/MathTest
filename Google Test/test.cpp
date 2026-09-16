#include "pch.h"
#include "main.cpp"
#include <iostream>
#include <sstream>
TEST(StructTask, DefaultConstructor) {
	ASSERT_NO_THROW(Task());
}
TEST(StructTask, InitConstructorDivide) {
	Task t(1,2,op_divide);
	EXPECT_EQ(t.answer, 0);
}
TEST(StructTask, InitConstructorMultiple) {
	Task t(2, 5, op_multiplicate);
	EXPECT_EQ(t.answer, 10);
}
TEST(StructTask, InitConstructorADD) {
	Task t(2, 5, op_add);
	EXPECT_EQ(t.answer, 7);
}
TEST(StructTask, InitConstructorSubtract) {
	Task t(2, 5, op_subtract);
	EXPECT_EQ(t.answer, -3);
}
TEST(StructTask, InitConstructorRandom) {
	ASSERT_NO_THROW(Task t(2, 5, op_random));
}

//MathTest

TEST(MathTest, DefaultConstructor) {
	ASSERT_NO_THROW(MathTest());
}

TEST(MathTest, ConstructorCountMinMax) {
	ASSERT_NO_THROW(MathTest(5, 1, 10));
}

TEST(MathTest, ConstructorCountMinMaxOp) {
	ASSERT_NO_THROW(MathTest(5, 1, 10, op_add));
	ASSERT_NO_THROW(MathTest(5, 1, 10, op_random));
}

TEST(MathTest, Destructor) {
	ASSERT_NO_THROW({
		MathTest t(5, 1, 10);
		});
}


TEST(MathTest, DestructorExplicitDelete) {
	MathTest* t = new MathTest(5, 1, 10);
	ASSERT_NO_THROW(delete t);
}


