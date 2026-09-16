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

};
int get_answer(int min, int max, Operations op) {
	if (min > max) {
		int buff = max;
		max = min;
		min = buff;
	}
	if (op == op_random) { op = Operations(rand() % 4); }
	switch (op) {
		case op_add:
			return min + max;
		case op_subtract:
			return max - min;
		case op_multiplicate:
			return min * max;
		case op_divide:
			return max / min;
	}
}