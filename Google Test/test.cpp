#include "pch.h"
#include "main.cpp"
#include <iostream>
TEST(StructTask, DefaultConstructor) {
	ASSERT_NO_THROW(Task());
}
TEST(StructTask, InitConstructorDivide) {
	Task t(1,2,op_divide);
	EXPECT_EQ(t.answer, 2);
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
	EXPECT_EQ(t.answer, 3);
}
TEST(StructTask, InitConstructorRandom) {
	ASSERT_NO_THROW(Task t(2, 5, op_random));
}

