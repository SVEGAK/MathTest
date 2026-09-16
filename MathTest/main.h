#pragma once
#include <random>
enum Operations {op_add,op_subtract,op_multiplicate,op_divide,op_random };
struct Task {
	int num_1;
	int num_2;
	int answer;
	Operations op;
	Task();
	Task(int min, int max, Operations op);
	static Task exact(int n1, int n2, Operations operation);//аналог конструктора Task с контролируемыми значениями для тестов
};
class MathTest {
	Task* _tasks;
	int _count;
	int* _user_answers;
	int _correct_count;

	public:
	MathTest(int count = 1);
	MathTest(int count, int min, int max);
	MathTest(int count, int min, int max, Operations op);
	~MathTest();
	void run();
	void show_statistics();
	void insert_answer(size_t num);
	void output_cur_task(size_t number);
	void insert_answer_message();
	void set_current_task(size_t num, Task cur_task);
};
int get_answer(int num1, int num2, Operations op) {
	if (op == op_random) { op = Operations(rand() % 4); }
	switch (op) {
		case op_add:
			return num1 + num2;
		case op_subtract:
			return num1 - num2;
		case op_multiplicate:
			return num1 * num2;
		case op_divide:
			return num1 / num2;
	}
}