#include "pch.h"
#include "main.cpp"
#include "lib.h"
#include <iostream>
#include <sstream>
TEST(StructTask, DefaultConstructor) {
	ASSERT_NO_THROW(Task());
}
TEST(StructTask, InitConstructorDivide) {
    Task t;
    t = t.exact(1, 2, op_divide);
	EXPECT_EQ(t.answer, 0);
}
TEST(StructTask, DivisionByZeroThrow) {
    Task t;
    EXPECT_ANY_THROW(t = t.exact(1, 0, op_divide));
}
TEST(StructTask, InitConstructorMultiple) {
	Task t;
    t = t.exact(2, 5, op_multiplicate);
	EXPECT_EQ(t.answer, 10);
}
TEST(StructTask, InitConstructorADD) {
	Task t;
    t = t.exact(2, 5, op_add);
	EXPECT_EQ(t.answer, 7);
}
TEST(StructTask, InitConstructorSubtract) {
	Task t;
    t = t.exact(2, 5, op_subtract);
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


TEST(MathTest, ExactCase) {
    // эмулируем ввод пользователя
    std::string user_input = "25 -5 4 150 15";
    std::istringstream fake_cin(user_input);
    std::ostringstream fake_cout;

    // перенаправляем стандартные потоки на фейки
    auto old_cin = std::cin.rdbuf(fake_cin.rdbuf());
    auto old_cout = std::cout.rdbuf(fake_cout.rdbuf());

    {
        
        MathTest test(5, 1, 10);

        
        test.set_current_task(0, Task::exact(10, 15, op_add));
        test.set_current_task(1, Task::exact(10, 15, op_subtract));
        test.set_current_task(2, Task::exact(11, 5, op_subtract));
        test.set_current_task(3, Task::exact(10, 15, op_multiplicate));
        test.set_current_task(4, Task::exact(50, 5, op_divide));
        
        test.run();
    }
    // возвращаем потоки на место чтобы не сломать будущие тесты
    std::cin.rdbuf(old_cin);
    std::cout.rdbuf(old_cout);

    // получаем весь вывод программы в одну строку
    std::string output = fake_cout.str();

    // проверяем вывод 
    EXPECT_NE(output.find("10 + 15"), std::string::npos);
    EXPECT_NE(output.find("10 - 15"), std::string::npos);
    EXPECT_NE(output.find("11 - 5"), std::string::npos);
    EXPECT_NE(output.find("10 * 15"), std::string::npos);
    EXPECT_NE(output.find("50 / 5"), std::string::npos);

    
    EXPECT_NE(output.find("3 / 5"), std::string::npos);

    // проверяем оценку (3/5 = 60%, это больше 50, значит оценка C)
    EXPECT_NE(output.find("mark : C"), std::string::npos);

   
}
TEST(MathTest, ExactCaseVisualTest) {
    // эмулируем ввод пользователя
    std::string user_input = "25 -5 4 150 15";
    std::istringstream fake_cin(user_input);
    std::ostringstream fake_cout;

    // перенаправляем стандартные потоки на фейки
    auto old_cin = std::cin.rdbuf(fake_cin.rdbuf());
    auto old_cout = std::cout.rdbuf(fake_cout.rdbuf());

    {

        MathTest test(5, 1, 10);


        test.set_current_task(0, Task::exact(10, 15, op_add));
        test.set_current_task(1, Task::exact(10, 15, op_subtract));
        test.set_current_task(2, Task::exact(11, 5, op_subtract));
        test.set_current_task(3, Task::exact(10, 15, op_multiplicate));
        test.set_current_task(4, Task::exact(50, 5, op_divide));

        test.run();
    }
    std::string output = fake_cout.str();

    std::cerr << system("chcp 65001") << "\n\n========== ВИЗУАЛЬНАЯ ПРОВЕРКА ТАБЛИЦЫ ==========\n" << output << "\n=================================================\n\n";

    // возвращаем потоки на место чтобы не сломать будущие тесты
    std::cin.rdbuf(old_cin);
    std::cout.rdbuf(old_cout);
}

